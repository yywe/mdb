#ifndef _EXEC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifdef __cplusplus
}
#endif

#include <string>
#include "../mdbtype.h"
#include "../sqlparser/lexer.h"

using std::string;
class Executor{
	public:
		Executor(string str):querystr(str){
		}
		Executor(){
			querystr="";
		};
		void setParsertf(string filename){
			parsertf=filename;
		}
		string getParsertf() const{
			return parsertf;
		}
		void setQuery(string str){
			querystr=str;
		}
		string getQuery() const{
			return querystr;
		}

		void execute();
		int prepare();
		int runParser(const char *sqlstr);
		Parse *getParser(){
			return &mdbParser;
		}
	private:
		string querystr;
		string parsertf;
		Parse mdbParser;

};

#endif
