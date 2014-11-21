#ifndef _MDBTYPE_H_
#define _MDBTYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MAXLINESIZE 4096

typedef struct Token{
	const unsigned char *z;
    unsigned dyn:1;
    unsigned n:31;
}Token;
typedef struct Parse{
	const char *zSql;
	int explain;
}Parse;


#ifdef __cplusplus
}
#endif


#endif
