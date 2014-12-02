#ifndef _HANDLER_H_
#define _HANDLER_H_

#include "../mdbtype.h"

#ifdef __cpluscplus
extern "C" {
#endif
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <fcntl.h>

#ifdef __cpluscplus
}
#endif

#include <string>
using std::string;

class Handler{
	public:
		Handler(){

		}

		virtual ~Handler(){

		}
		virtual int createTbl(Table *ptbl);
		virtual int dropTbl(Table *ptbl);
};
#endif
