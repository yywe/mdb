/**
 * This part is mostly from SQLite 
 * Do the syntax analysis job
*/

%include {
#ifdef __cplusplus
extern "C" {
#endif

#include "../mdbtype.h"
#include "../mdbproto.h"

#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
}
#endif
}

%token_prefix TK_
%token_type {Token}
%default_type {Token}
%extra_argument {Parse *pParse}

%syntax_error{
	printf("syntax error!\n");
}

%name mdbParser

%nonassoc END_OF_FILE ILLEGAL SPACE UNCLOSED_STRING COMMENT FUNCTION COLUMN
	AGG_FUNCTION AGG_COLUMN CONST_FUNC.

input ::= cmdlist.
cmdlist ::= cmdlist ecmd.
cmdlist ::= ecmd.
ecmd ::= SEMI.
ecmd ::= explain cmdx SEMI.
cmdx ::= cmd.
explain ::= . {mdbBeginParse(pParse,0);}

////////////////////////Create table syntax///////////////////////////////////
cmd ::=create_table create_table_args.

create_table ::=CREATE TABLE nm(X).{
	mdbStartTable(pParse,&X);
	pParse->stype=CRT;
}


/* currently not support conslist_opt */
create_table_args ::=LP columnlist conslist_opt RP.{
	mdbEndTable(pParse);
}

columnlist ::=columnlist COMMA column.
columnlist ::=column.

column(A) ::=columnid(X) type carglist.

columnid(A) ::=nm(X).{
	mdbAddColumn(pParse,&X);
	A=X;
}
%type id {Token}
id(A) ::= ID(X). {A=X;}

%type ids {Token}
ids(A) ::= ID(X). {A=X;}
ids(A) ::= STRING(X). {A=X;}


%type nm {Token}
nm(A) ::= ID(X). {A=X;}
nm(A) ::= STRING(X). {A=X;}


%type typetoken {Token}

type ::=.
type ::=typetoken(X). {
	mdbAddColumnType(pParse,&X);
}

typetoken(A) ::=typename(X). {A=X;}
typetoken(A) ::=typename(X) LP signed RP(Y).{
	A.z=X.z;
	A.n=&Y.z[Y.n]-X.z;
}

typetoken(A) ::=typename(X) LP signed COMMA signed RP(Y).{
	A.z=X.z;
	A.n=&Y.z[Y.n]-X.z;
	/*
	char *tmp=(char *)malloc(A.n+1);
	bzero(tmp,A.n+1);
	strncpy(tmp,A.z,A.n);
	printf("typetoken:%s\n",tmp);
	*/
}

%type typename {Token}
typename(A) ::=ids(X). {A=X;}

%type signed {int}
signed(A) ::=plus_num(X). {A=atoi(reinterpret_cast<const char*>(X.z));}
signed(A) ::=minus_num(X). {A=-atoi(reinterpret_cast<const char*>(X.z));}


/*currently ,do not support expression and carglist and constriant */
carglist ::=carglist carg.
carglist ::=.
carg ::=CONSTRAINT nm ccons.
carg ::=ccons.
carg ::=DEFAULT id(X).

ccons ::=NULL onconf.
%type onconf {int}
onconf(A) ::=.


conslist_opt(A) ::=.
/////////////////////The drop table command///////////////////////////////

cmd ::=DROP TABLE nm(X).{
	pParse->stype=DROP;
	mdbDropTable(pParse,&X);
}
/////////////////the pragma command/////////////////////////

plus_num(A) ::=plus_opt number(X). {A=X;}
minus_num(A) ::=MINUS number(X). {A=X;}
number(A) ::=INTEGER(X). {A=X;}
number(A) ::=FLOAT(X). {A=X;}
plus_opt ::=PLUS.
plus_opt ::=.

