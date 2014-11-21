#ifndef _LEXER_H_
#define _LEXER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "parser.h"

#ifdef __cplusplus
}
#endif


class Lexer{
	public:
		Lexer(const char *sql):sqlstr(sql),tk_offset(0),tk_type(-1),tk_len(0){};
		int getNextToken();
		int ifReachEnd();
		unsigned int getOffset() const{
			return tk_offset;
		}
		unsigned int getTkLen() const{
			return tk_len;
		}
		const char *getSqlStr() const{
			return sqlstr;
		}
		int getTkType() const{
			return tk_type;
		}

	private:
		const char *sqlstr;
		unsigned int tk_offset;
		int tk_type;
		unsigned int tk_len;
};

#endif
