#ifndef _MDBPROTO_H_
#define _MDBPROTO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "mdbtype.h"
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

void mdbBeginParse(Parse *,int);
void mdbStartTable(Parse *,Token *);
void mdbAddColumn(Parse *,Token *);
void mdbAddColumnType(Parse *,Token *);
void mdbEndTable(Parse *);
void mdbDropTable(Parse *pParse,Token *tn);
void mdbInsert(Parse *pParse,Token *tn,IdList *pColumn,ExprList *pList);

Expr *mdbExpr(int op,Expr *pLeft,Expr *pRight,const Token *pToken);

IdList *mdbIdListAppend(IdList *pList, Token *pToken);
ExprList *mdbExprListAppend(ExprList *pList,Expr *pExpr,Token *pName);

void mdbExprSpan(Expr *pExpr,Token *pLeft,Token *pRight);
void mdbExprDelete(Expr *p);
void mdbIdListDelete(IdList *pList);
void mdbExprListDelete(ExprList *pList);

void freeTblRes(Table *ptbl);

#ifdef __cplusplus
}
#endif


#endif
