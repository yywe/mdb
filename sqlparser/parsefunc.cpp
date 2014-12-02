#include "../mdbproto.h"
#include "../util/trace.h"

char *getNameFromToken(Token *t){
	char *pn=(char *)malloc(t->n+1);
	assert(pn!=0);
	bzero(pn,t->n+1);
	strncpy(pn,t->z,t->n);
	return pn;
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
