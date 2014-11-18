#ifndef _HEADER_H_
#define _HEADER_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct Token{
	const unsigned char *z;
    unsigned dyn:1;
    unsigned n:31;
}Token;
typedef struct Parse{
	const char *zSql;
}Parse;

#include <stdio.h>
#include <stdlib.h>
#include <parser.h>


#ifdef __cplusplus
}
#endif


#endif
