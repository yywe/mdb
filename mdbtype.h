#ifndef _MDBTYPE_H_
#define _MDBTYPE_H_

#include "sqlparser/lexer.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAXLINESIZE 4096

typedef unsigned char u8;

typedef struct Token{
//	const unsigned char *z;
	const  char *z;
    unsigned dyn:1;
    unsigned n:31;
}Token;

typedef struct Expr{
	u8 op;
	Expr *pLeft,*pRight;
	Token token;
	Token span;
}Expr;

typedef struct Column{
	char *colname;
	char *zType;
	Expr *pDflt;/*default value */
	u8 notNull;
	u8 isPrimaryKey;
	int extraarg1;
	int extraarg2;
}Column;

typedef struct Table{
	char *zName;
	char *creatsql;
	int nCol;
	Column *aCol;
	u8 hasPrimKey;
}Table;

//class Lexer;
typedef struct Parse{
	Lexer *lexer;
	const char *zSql;
	int explain;
	int errorcode;
	char errmsg[MAXLINESIZE];

	/* meet create table */
	Table *newtbl;
}Parse;




#ifdef __cplusplus
}
#endif


#endif
