#include "../mdbproto.h"
#include "../util/trace.h"

char *getNameFromToken(Token *t){
	char *pn;
	if(t){
		pn=(char *)malloc(t->n+1);
		assert(pn!=0);
		bzero(pn,t->n+1);
		strncpy(pn,t->z,t->n);
	}else{
		pn=0;
	}
	
	return pn;
}

Expr *mdbExpr(int op,Expr *pLeft,Expr *pRight,const Token *pToken){
	Expr *pNew;
	pNew=(Expr *)malloc(sizeof(Expr));
	if(pNew==0){
		mdbExprDelete(pLeft);
		mdbExprDelete(pRight);
		return 0;
	}
	pNew->op=op;
	pNew->pLeft=pLeft;
	pNew->pRight=pRight;
	if(pToken){
		pNew->span=pNew->token=*pToken;
	}
	else if(pLeft&&pRight){
		mdbExprSpan(pNew,&pLeft->span,&pRight->span);
	}
	return pNew;
}
void mdbExprDelete(Expr *p){
	if(p==0) return;
	if(p->span.dyn) free((char*)p->span.z);
	if(p->token.dyn) free((char *)p->token.z);
	mdbExprDelete(p->pLeft);
	mdbExprDelete(p->pRight);
	free(p);
}
void mdbIdListDelete(IdList *pList){
	int i;
	if(pList==0) return;

	for(i=0;i<pList->nId;i++){
		free(pList->a[i].zName);
	}
	free(pList->a);
	free(pList);
}
 void mdbExprListDelete(ExprList *pList){
	 int i;
	 ExprList_item *pItem;
	 if(pList==0) return;
	 for(pItem=pList->a,i=0;i<pList->nExpr;i++,pItem++){
		 mdbExprDelete(pItem->pExpr);
		 free(pItem->zName);
	 }
	 free(pList->a);
	 free(pList);
 }
void mdbExprSpan(Expr *pExpr,Token *pLeft,Token *pRight){
	assert(pRight!=0);
	assert(pLeft!=0);
	if(pRight->z&&pLeft->z){
		if(pLeft->dyn==0&&pRight->dyn==0){
			pExpr->span.z=pLeft->z;
			pExpr->span.n=pRight->n+(pRight->z-pLeft->z);
		}else{
			pExpr->span.z=0;
		}
	}

}
int mdbArrayAllocate(void **ppArray,int szEntry,int initSize){
	char *p;
	int *an=(int *)&ppArray[1];
	if(an[0]>=an[1]){
		void *pNew;
		int newSize;
		newSize=an[1]*2+initSize;
		pNew=realloc(*ppArray,newSize*szEntry);
		if(pNew==0){
			return -1;
		}
		an[1]=newSize;
		*ppArray=pNew;
	}
	p=(char *)*ppArray;
	memset(&p[an[0]*szEntry],0,szEntry);
	return an[0]++;
}
IdList *mdbIdListAppend(IdList *pList, Token *pToken){
	int i;
	if(pList==0){
		pList=(IdList *)malloc(sizeof(IdList));
		if(pList==0) return 0;
		pList->nAlloc=0;
	}
	i=mdbArrayAllocate((void **)&pList->a,sizeof(pList->a[0]),5);
	if(i<0){
		mdbIdListDelete(pList);
		return 0;
	}
	pList->a[i].zName=getNameFromToken(pToken);
	return pList;
}

ExprList *mdbExprListAppend(ExprList *pList,Expr *pExpr,Token *pName){
	if(pList==0){
		pList=(ExprList *)malloc(sizeof(ExprList));
		if(pList==0){
			goto no_mem;
		}
		memset(pList,0,sizeof(ExprList));
	}
	if(pList->nAlloc<=pList->nExpr){
		struct ExprList_item *a;
		int n=pList->nAlloc*2+4;
		a=(ExprList_item *)realloc(pList->a,n*sizeof(pList->a[0]));
		if(a==0){
			goto no_mem;
		}
		pList->a=a;
		pList->nAlloc=n;
	}
	if(pExpr||pName){
		struct ExprList_item *pItem=&pList->a[pList->nExpr++];
		memset(pItem,0,sizeof(*pItem));
		pItem->zName=getNameFromToken(pName);
		pItem->pExpr=pExpr;
	}
	return pList;
no_mem:
	mdbExprDelete(pExpr);
	mdbExprListDelete(pList);
}
void freeTblRes(Table *ptbl){
	if(ptbl){
		if(ptbl->zName){
			free(ptbl->zName);
		}
		if(ptbl->aCol){
			int i;
			for(i=0;i<ptbl->nCol;i++){
				Column *pc=&ptbl->aCol[i];
				if(pc&&pc->colname){
					free(pc->colname);
				}
				if(pc&&pc->zType){
					free(pc->zType);
				}
			}
			free(ptbl->aCol);
		}
		free(ptbl);
	}
}

void mdbBeginParse(Parse  *pParse,int explainFlag){
    //Tracer::tracePrint(INFO,"parse query:\t %s\n",pParse->zSql);
	pParse->explain=explainFlag;
	pParse->errorcode=0;
}


 void mdbStartTable(Parse *pParse,Token *tblname){
//    Tracer::tracePrint(INFO,"%s:\tEnter Create table:\t %s\n",__FILE__,pParse->zSql);
	Table *ptbl=(Table *)malloc(sizeof(Table));
	if(!ptbl){
		pParse->errorcode=101;
		strcpy(pParse->errmsg,"allocate memory failed\n");
	}

	bzero(ptbl,sizeof(Table));
	ptbl->zName=(char *)malloc(tblname->n+1);
	assert(ptbl->zName);
	bzero(ptbl->zName,tblname->n+1);
	strncpy(ptbl->zName,(const char *)tblname->z,tblname->n);
	
	pParse->newtbl=ptbl;

	return ;
 }
void mdbAddColumn(Parse *pParse,Token *colname){
	Table *ptbl;
	Column *pCol;
	char *pcolz;
	int i;
	assert((ptbl=pParse->newtbl)!=0);
	pcolz=getNameFromToken(colname);
	for(i=0;i<ptbl->nCol;i++){
		if(strcmp(pcolz,ptbl->aCol[i].colname)==0){
			pParse->errorcode=102;
			strcpy(pParse->errmsg,"duplicate column name!");
			free(pcolz);
			return ;
		}
	}

	/* trick: to allocate every 7 colnames */
	if((ptbl->nCol&0x7)==0){
		Column *colNew=(Column *)realloc(ptbl->aCol,(ptbl->nCol+8)*sizeof(Column));
		if(colNew==0){
			free(pcolz);
		}
		ptbl->aCol=colNew;

	}
	pCol=&ptbl->aCol[ptbl->nCol];
	memset(pCol,0,sizeof(Column));
	pCol->colname=pcolz;
	ptbl->nCol++;

}
void mdbAddColumnType(Parse *pParse,Token *pType){
	Table *p;
	int i;
	Column *pCol;

	assert((p=pParse->newtbl)!=0);
	i=p->nCol-1;
	if(i<0) return ;
	pCol=&p->aCol[i];
	if(pCol->zType) free(pCol->zType);
	pCol->zType=getNameFromToken(pType);

}
void mdbEndTable(Parse *pParse){
	if(pParse->errorcode!=0){
		freeTblRes(pParse->newtbl);
		pParse->newtbl=NULL;
		return ;
	}
	pParse->newtbl->creatsql=pParse->zSql;
}
void mdbDropTable(Parse *pParse,Token *tn){
	if(pParse->errorcode!=0){
		Tracer::tracePrint(ERROR,"%s:\tdrop table error",__FILE__);
		return ;
	}
	Table *ptbl=(Table *)malloc(sizeof(Table));
	if(!ptbl){
		pParse->errorcode=101;
		strcpy(pParse->errmsg,"allocate memory failed\n");
	}
	bzero(ptbl,sizeof(Table));
	ptbl->zName=(char *)malloc(tn->n+1);
	assert(ptbl->zName);
	bzero(ptbl->zName,tn->n+1);
	strncpy(ptbl->zName,(const char *)tn->z,tn->n);
	pParse->newtbl=ptbl;
	return ;
}
void mdbInsert(Parse *pParse,Token *tn,IdList *pColumn,ExprList *pList){
	
}
