/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 6 "/home/whisly/mdb/sqlparser/parser.y"

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
#line 24 "/home/whisly/mdb/sqlparser/parser.cpp"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    mdbParserTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is mdbParserTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.
**    mdbParserARG_SDECL     A static variable declaration for the %extra_argument
**    mdbParserARG_PDECL     A parameter declaration for the %extra_argument
**    mdbParserARG_STORE     Code to store %extra_argument into yypParser
**    mdbParserARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 64
#define YYACTIONTYPE unsigned char
#define mdbParserTOKENTYPE Token
typedef union {
  mdbParserTOKENTYPE yy0;
  int yy4;
  IdList * yy10;
  ExprList* yy70;
  Expr * yy74;
  Token yy126;
  int yy127;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define mdbParserARG_SDECL Parse *pParse;
#define mdbParserARG_PDECL ,Parse *pParse
#define mdbParserARG_FETCH Parse *pParse = yypParser->pParse
#define mdbParserARG_STORE yypParser->pParse = pParse
#define YYNSTATE 86
#define YYNRULE 56
#define YYERRORSYMBOL 30
#define YYERRSYMDT yy127
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    70,    3,   51,   74,   77,   15,   16,   73,  143,    1,
 /*    10 */    85,    4,   75,   76,   51,   11,   17,   52,   16,   50,
 /*    20 */    33,   34,   53,   36,   41,   42,   39,   41,   42,    5,
 /*    30 */     7,    8,   56,   59,   43,   86,    6,   43,   20,   28,
 /*    40 */    25,   65,   91,   78,   69,    9,    3,    2,    4,   21,
 /*    50 */    22,  120,   14,   19,   27,   31,   32,   47,   49,   37,
 /*    60 */    38,   79,   84,   66,   67,   45,   46,   68,   69,   10,
 /*    70 */    71,   69,  123,   81,   82,   93,   13,   95,   12,   18,
 /*    80 */    23,   80,   24,   25,   29,   26,   30,   35,   44,   40,
 /*    90 */    54,   55,   94,   57,  121,   48,   58,   63,   61,   60,
 /*   100 */    64,   62,  122,   72,  124,  121,  121,   83,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */    14,   11,   39,   17,   18,   42,   43,   21,   31,   32,
 /*    10 */    33,   34,   26,   27,   39,   40,   44,   42,   43,   47,
 /*    20 */    48,   49,   12,   50,   51,   52,   50,   51,   52,   35,
 /*    30 */    36,   37,   22,   23,   61,    0,   11,   61,   19,   20,
 /*    40 */    21,   57,   11,   59,   60,   38,   11,   33,   34,   17,
 /*    50 */    18,   15,   16,   53,   54,   17,   18,   28,   29,   15,
 /*    60 */    16,   14,   39,   15,   16,   26,   27,   59,   60,   14,
 /*    70 */    59,   60,   25,   15,   16,   11,   15,   11,   41,   45,
 /*    80 */    39,   58,   54,   21,   17,   55,   46,   14,   62,   15,
 /*    90 */    13,   39,   14,   13,   11,   62,   39,   25,   39,   24,
 /*   100 */    14,   56,   11,   15,   25,   63,   63,   39,
};
#define YY_SHIFT_USE_DFLT (-15)
static const signed char yy_shift_ofst[] = {
 /*     0 */   -10,   35,  -15,  -15,   10,   25,  -15,   31,   55,   64,
 /*    10 */    32,   36,   61,   66,   32,  -15,   38,  -15,   19,  -15,
 /*    20 */    32,  -15,  -15,   62,  -15,  -15,  -15,  -15,   67,  -15,
 /*    30 */   -15,  -15,  -15,  -15,   73,   29,   44,  -15,   29,   74,
 /*    40 */   -15,  -15,  -15,   39,  -15,  -15,  -15,   39,  -15,  -15,
 /*    50 */   -15,  -15,  -15,   77,   32,   78,   80,   32,   83,   75,
 /*    60 */    32,   47,   72,   86,  -14,   48,   91,  -14,  -15,  -15,
 /*    70 */   -14,   88,  -15,  -15,  -15,  -15,  -15,  -15,  -15,   32,
 /*    80 */    58,   79,   32,  -15,  -15,  -15,
};
#define YY_REDUCE_USE_DFLT (-38)
static const signed char yy_reduce_ofst[] = {
 /*     0 */   -23,   14,  -38,  -38,   -6,  -38,  -38,  -38,    7,  -38,
 /*    10 */   -25,   37,  -38,  -38,  -37,  -38,  -28,   34,    0,  -38,
 /*    20 */    41,  -38,  -38,   28,  -38,   30,  -38,  -38,   40,  -38,
 /*    30 */   -38,  -38,  -38,  -38,  -38,  -27,  -38,  -38,  -24,  -38,
 /*    40 */   -38,  -38,  -38,   26,  -38,  -38,  -38,   33,  -38,  -38,
 /*    50 */   -38,  -38,  -38,  -38,   52,  -38,  -38,   57,  -38,  -38,
 /*    60 */    59,   45,  -38,  -38,  -16,  -38,  -38,    8,  -38,  -38,
 /*    70 */    11,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,   23,
 /*    80 */   -38,  -38,   68,  -38,  -38,  -38,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */    92,   92,   87,   89,  142,  142,   90,  142,  142,  142,
 /*    10 */   142,  142,  142,  142,  142,   96,  105,  114,   98,  113,
 /*    20 */   142,  103,  104,  142,  115,  119,  118,  116,  142,  100,
 /*    30 */   117,  101,  102,  106,  107,  141,  142,  108,  141,  142,
 /*    40 */   109,  111,  112,  142,  136,  138,  139,  142,  137,  140,
 /*    50 */   110,   99,   97,  142,  142,  142,  142,  142,  142,  142,
 /*    60 */   142,  142,  142,  142,  142,  142,  142,  142,  127,  129,
 /*    70 */   142,  142,  130,  131,  132,  133,  134,  135,  128,  142,
 /*    80 */   142,  142,  142,  125,  126,   88,
};
#define YY_SZ_ACTTAB int(sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammer, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  YYMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
  int yyerrcnt;                 /* Shifts left before out of the error */
  mdbParserARG_SDECL                /* A place to hold %extra_argument */
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void mdbParserTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "END_OF_FILE",   "ILLEGAL",       "SPACE",       
  "UNCLOSED_STRING",  "COMMENT",       "FUNCTION",      "COLUMN",      
  "AGG_FUNCTION",  "AGG_COLUMN",    "CONST_FUNC",    "SEMI",        
  "CREATE",        "TABLE",         "LP",            "RP",          
  "COMMA",         "ID",            "STRING",        "CONSTRAINT",  
  "DEFAULT",       "NULL",          "DROP",          "INSERT",      
  "INTO",          "VALUES",        "INTEGER",       "FLOAT",       
  "MINUS",         "PLUS",          "error",         "input",       
  "cmdlist",       "ecmd",          "explain",       "cmdx",        
  "cmd",           "create_table",  "create_table_args",  "nm",          
  "columnlist",    "conslist_opt",  "column",        "columnid",    
  "type",          "carglist",      "id",            "ids",         
  "typetoken",     "typename",      "signed",        "plus_num",    
  "minus_num",     "carg",          "ccons",         "onconf",      
  "inscollist_opt",  "itemlist",      "inscollist",    "expr",        
  "term",          "plus_opt",      "number",      
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "input ::= cmdlist",
 /*   1 */ "cmdlist ::= cmdlist ecmd",
 /*   2 */ "cmdlist ::= ecmd",
 /*   3 */ "ecmd ::= SEMI",
 /*   4 */ "ecmd ::= explain cmdx SEMI",
 /*   5 */ "cmdx ::= cmd",
 /*   6 */ "explain ::=",
 /*   7 */ "cmd ::= create_table create_table_args",
 /*   8 */ "create_table ::= CREATE TABLE nm",
 /*   9 */ "create_table_args ::= LP columnlist conslist_opt RP",
 /*  10 */ "columnlist ::= columnlist COMMA column",
 /*  11 */ "columnlist ::= column",
 /*  12 */ "column ::= columnid type carglist",
 /*  13 */ "columnid ::= nm",
 /*  14 */ "id ::= ID",
 /*  15 */ "ids ::= ID",
 /*  16 */ "ids ::= STRING",
 /*  17 */ "nm ::= ID",
 /*  18 */ "nm ::= STRING",
 /*  19 */ "type ::=",
 /*  20 */ "type ::= typetoken",
 /*  21 */ "typetoken ::= typename",
 /*  22 */ "typetoken ::= typename LP signed RP",
 /*  23 */ "typetoken ::= typename LP signed COMMA signed RP",
 /*  24 */ "typename ::= ids",
 /*  25 */ "signed ::= plus_num",
 /*  26 */ "signed ::= minus_num",
 /*  27 */ "carglist ::= carglist carg",
 /*  28 */ "carglist ::=",
 /*  29 */ "carg ::= CONSTRAINT nm ccons",
 /*  30 */ "carg ::= ccons",
 /*  31 */ "carg ::= DEFAULT id",
 /*  32 */ "ccons ::= NULL onconf",
 /*  33 */ "onconf ::=",
 /*  34 */ "conslist_opt ::=",
 /*  35 */ "cmd ::= DROP TABLE nm",
 /*  36 */ "cmd ::= INSERT INTO nm inscollist_opt VALUES LP itemlist RP",
 /*  37 */ "inscollist_opt ::=",
 /*  38 */ "inscollist_opt ::= LP inscollist RP",
 /*  39 */ "inscollist ::= inscollist COMMA nm",
 /*  40 */ "inscollist ::= nm",
 /*  41 */ "itemlist ::= itemlist COMMA expr",
 /*  42 */ "itemlist ::= expr",
 /*  43 */ "expr ::= term",
 /*  44 */ "expr ::= LP expr RP",
 /*  45 */ "term ::= NULL",
 /*  46 */ "expr ::= ID",
 /*  47 */ "term ::= INTEGER",
 /*  48 */ "term ::= FLOAT",
 /*  49 */ "term ::= STRING",
 /*  50 */ "plus_num ::= plus_opt number",
 /*  51 */ "minus_num ::= MINUS number",
 /*  52 */ "number ::= INTEGER",
 /*  53 */ "number ::= FLOAT",
 /*  54 */ "plus_opt ::= PLUS",
 /*  55 */ "plus_opt ::=",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *mdbParserTokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<int(sizeof(yyTokenName)/sizeof(yyTokenName[0])) ){
    return yyTokenName[tokenType];
  }else{
    return "Unknown";
  }
#else
  return "";
#endif
}

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to mdbParser and mdbParserFree.
*/
void *mdbParserAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(YYCODETYPE yymajor, YYMINORTYPE *yypminor){
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    case 56:
    case 58:
#line 138 "/home/whisly/mdb/sqlparser/parser.y"
{mdbIdListDelete((yypminor->yy10));}
#line 431 "/home/whisly/mdb/sqlparser/parser.cpp"
      break;
    case 57:
#line 150 "/home/whisly/mdb/sqlparser/parser.y"
{mdbExprListDelete((yypminor->yy70));}
#line 436 "/home/whisly/mdb/sqlparser/parser.cpp"
      break;
    case 59:
    case 60:
#line 159 "/home/whisly/mdb/sqlparser/parser.y"
{mdbExprDelete((yypminor->yy74));}
#line 442 "/home/whisly/mdb/sqlparser/parser.cpp"
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor( yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from mdbParserAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void mdbParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  /* if( pParser->yyidx<0 ) return YY_NO_ACTION;  */
  i = yy_shift_ofst[stateno];
  if( i==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
#ifdef YYFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
           && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
           yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
      }
#endif
      return yy_find_shift_action(pParser, iFallback);
    }
#endif
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  /* int stateno = pParser->yystack[pParser->yyidx].stateno; */
 
  i = yy_reduce_ofst[stateno];
  if( i==YY_REDUCE_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer ot the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
  if( yypParser->yyidx>=YYSTACKDEPTH ){
     mdbParserARG_FETCH;
     yypParser->yyidx--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     mdbParserARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = yyNewState;
  yytos->major = yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 31, 1 },
  { 32, 2 },
  { 32, 1 },
  { 33, 1 },
  { 33, 3 },
  { 35, 1 },
  { 34, 0 },
  { 36, 2 },
  { 37, 3 },
  { 38, 4 },
  { 40, 3 },
  { 40, 1 },
  { 42, 3 },
  { 43, 1 },
  { 46, 1 },
  { 47, 1 },
  { 47, 1 },
  { 39, 1 },
  { 39, 1 },
  { 44, 0 },
  { 44, 1 },
  { 48, 1 },
  { 48, 4 },
  { 48, 6 },
  { 49, 1 },
  { 50, 1 },
  { 50, 1 },
  { 45, 2 },
  { 45, 0 },
  { 53, 3 },
  { 53, 1 },
  { 53, 2 },
  { 54, 2 },
  { 55, 0 },
  { 41, 0 },
  { 36, 3 },
  { 36, 8 },
  { 56, 0 },
  { 56, 3 },
  { 58, 3 },
  { 58, 1 },
  { 57, 3 },
  { 57, 1 },
  { 59, 1 },
  { 59, 3 },
  { 60, 1 },
  { 59, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 51, 2 },
  { 52, 2 },
  { 62, 1 },
  { 62, 1 },
  { 61, 1 },
  { 61, 0 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  mdbParserARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<int(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

#ifndef NDEBUG
  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  */
  memset(&yygotominor, 0, sizeof(yygotominor));
#endif

  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 6:
#line 42 "/home/whisly/mdb/sqlparser/parser.y"
{mdbBeginParse(pParse,0);}
#line 725 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 8:
#line 47 "/home/whisly/mdb/sqlparser/parser.y"
{
	mdbStartTable(pParse,&yymsp[0].minor.yy126);
	pParse->stype=CRT;
}
#line 733 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 9:
#line 54 "/home/whisly/mdb/sqlparser/parser.y"
{
	mdbEndTable(pParse);
}
#line 740 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 13:
#line 63 "/home/whisly/mdb/sqlparser/parser.y"
{
	mdbAddColumn(pParse,&yymsp[0].minor.yy126);
	yygotominor.yy126=yymsp[0].minor.yy126;
}
#line 748 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 52:
      case 53:
#line 68 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy126=yymsp[0].minor.yy0;}
#line 759 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 20:
#line 83 "/home/whisly/mdb/sqlparser/parser.y"
{
	mdbAddColumnType(pParse,&yymsp[0].minor.yy126);
}
#line 766 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 21:
      case 24:
      case 50:
      case 51:
#line 87 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy126=yymsp[0].minor.yy126;}
#line 774 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 22:
#line 88 "/home/whisly/mdb/sqlparser/parser.y"
{
	yygotominor.yy126.z=yymsp[-3].minor.yy126.z;
	yygotominor.yy126.n=&yymsp[0].minor.yy0.z[yymsp[0].minor.yy0.n]-yymsp[-3].minor.yy126.z;
}
#line 782 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 23:
#line 93 "/home/whisly/mdb/sqlparser/parser.y"
{
	yygotominor.yy126.z=yymsp[-5].minor.yy126.z;
	yygotominor.yy126.n=&yymsp[0].minor.yy0.z[yymsp[0].minor.yy0.n]-yymsp[-5].minor.yy126.z;
	/*
	char *tmp=(char *)malloc(yygotominor.yy126.n+1);
	bzero(tmp,yygotominor.yy126.n+1);
	strncpy(tmp,yygotominor.yy126.z,yygotominor.yy126.n);
	printf("typetoken:%s\n",tmp);
	*/
}
#line 796 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 25:
#line 108 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy4=atoi(reinterpret_cast<const char*>(yymsp[0].minor.yy126.z));}
#line 801 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 26:
#line 109 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy4=-atoi(reinterpret_cast<const char*>(yymsp[0].minor.yy126.z));}
#line 806 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 35:
#line 127 "/home/whisly/mdb/sqlparser/parser.y"
{
	pParse->stype=DROP;
	mdbDropTable(pParse,&yymsp[0].minor.yy126);
}
#line 814 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 36:
#line 133 "/home/whisly/mdb/sqlparser/parser.y"
{
	mdbInsert(pParse,&yymsp[-5].minor.yy126,yymsp[-4].minor.yy10,yymsp[-1].minor.yy70);
}
#line 821 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 37:
#line 142 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy10=0;}
#line 826 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 38:
#line 143 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy10=yymsp[-1].minor.yy10;}
#line 831 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 39:
#line 145 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy10=mdbIdListAppend(yymsp[-2].minor.yy10,&yymsp[0].minor.yy126);}
#line 836 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 40:
#line 147 "/home/whisly/mdb/sqlparser/parser.y"
{ yygotominor.yy10=mdbIdListAppend(0,&yymsp[0].minor.yy126);}
#line 841 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 41:
#line 152 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy70=mdbExprListAppend(yymsp[-2].minor.yy70,yymsp[0].minor.yy74,0);}
#line 846 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 42:
#line 153 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy70=mdbExprListAppend(0,yymsp[0].minor.yy74,0);}
#line 851 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 43:
#line 163 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy74=yymsp[0].minor.yy74;}
#line 856 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 44:
#line 164 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy74=yymsp[-1].minor.yy74;mdbExprSpan(yygotominor.yy74,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 861 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 45:
#line 165 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy74 = mdbExpr(yymsp[0].major,0,0,&yymsp[0].minor.yy0);}
#line 866 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 46:
#line 166 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy74 = mdbExpr(TK_ID,0,0,&yymsp[0].minor.yy0);}
#line 871 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
      case 47:
      case 48:
      case 49:
#line 169 "/home/whisly/mdb/sqlparser/parser.y"
{yygotominor.yy74=mdbExpr(yymsp[0].major,0,0,&yymsp[0].minor.yy0);}
#line 878 "/home/whisly/mdb/sqlparser/parser.cpp"
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = yyact;
      yymsp->major = yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else if( yyact == YYNSTATE + YYNRULE + 1 ){
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  mdbParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  mdbParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  mdbParserARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 27 "/home/whisly/mdb/sqlparser/parser.y"

	printf("syntax error!\n");
#line 939 "/home/whisly/mdb/sqlparser/parser.cpp"
  mdbParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  mdbParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  mdbParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "mdbParserAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void mdbParser(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  mdbParserTOKENTYPE yyminor       /* The value for the token */
  mdbParserARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
    /* if( yymajor==0 ) return; // not sure why this was here... */
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  mdbParserARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,yymajor);
    if( yyact<YYNSTATE ){
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      if( yyendofinput && yypParser->yyidx>=0 ){
        yymajor = 0;
      }else{
        yymajor = YYNOCODE;
      }
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else if( yyact == YY_ERROR_ACTION ){
      int yymx;
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_shift_action(yypParser,YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }else{
      yy_accept(yypParser);
      yymajor = YYNOCODE;
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
