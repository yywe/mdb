#include "lexer.h"
#include "../mdbtype.h"
#include <map>
#include <string>

std::map<std::string,int> initKeyword(){
	std::map<std::string,int> m;
	m["CREATE"]=TK_CREATE;
	m["TABLE"]=TK_TABLE;
	m["DROP"]=TK_DROP;
	m["INSERT"]=TK_INSERT;
	m["INTO"]=TK_INTO;
	m["VALUES"]=TK_VALUES;
	return m;
}

/*std::map<int,std::string> mapTktoStr(){
	extern std::string cwd;

	std::map<int,std::string> pairs;

	std::string tkheader=cwd+"/sqlparser/parser.h";
	FILE *fp=fopen(tkheader.c_str(),"r");
	if(!fp){
		printf("can not open the file %s",tkheader.c_str());
		exit(0);
	}
	char buf[MAXLINESIZE]={0};
	while(fgets(buf,MAXLINESIZE,fp)!=NULL){
		std::string line=buf;
		size_t start=line.find("TK_",0);
		if(start!=std::string::npos){
			size_t i=start;
			while(*(line.c_str()+i)!=' ' && *(line.c_str()+i)!='\t') i++;
			std::string tokenstr=line.substr(start,i-1);
			int tkId=0;

			while(*(line.c_str()+i)==' ' && *(line.c_str()+i)=='\t') i++;
			if(i!=std::string::npos){
				size_t j=i;
				while(isdigit(*(line.c_str()+j))) j++;
				tkId=atoi(line.substr(i,j).c_str());
			}
			pairs.insert(std::pair<int,std::string>(tkId,tokenstr));
		}	
	}
	
	fclose(fp);
	return pairs;
}
*/

std::map<std::string,int> keywords=initKeyword();
//std::map<int,std::string> tkToStr=mapTktoStr();

int getKeyToken(std::map<std::string,int> m, const char *id,unsigned len){
	char *tmp=(char *)malloc(len+1);
	memset(tmp,0,len+1);
	strncpy(tmp,id,len);
	unsigned i;
	for(i=0;i<len;i++){
		tmp[i]=toupper(tmp[i]);
	}
	std::string target=tmp;
	if(m.find(target)!=m.end()){
		free(tmp);
		return m[target];
	}
	free(tmp);
	return TK_ID;
}
const char IdChar[]=
	{
	    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,  
	    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,  
	    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,  
	};

int isIdChar(int c){
	return ((c&0x80)!=0)||(c>0x1f&&(IdChar[c-0x20]));
}
	
/* get the next token ,return -1 illegal char ,0 success, 1 ,end of string */
int Lexer::getNextToken(){
	int i,c;
	tk_offset=tk_offset+tk_len;
	if(ifReachEnd()){
		return 1;
	}
	const char *substr=sqlstr+tk_offset;
	switch(*substr){
		case ' ':case '\t':case '\n':case '\f':case '\r':
		{
			for(i=1;isspace(substr[i]);i++){}
			tk_type=TK_SPACE;
			tk_len=i;
			return 0;
		}
		case '-':
		{
			if(*(substr+1)=='-'){
				for(i=2;(c=*(substr+i))!=0&&c!='\n';i++){}
				tk_type=TK_COMMENT;
				tk_len=i;
				return 0;
			}
			tk_type=TK_MINUS;
			tk_len=1;
			return 0;
		}
		case '(':
		{
			tk_type=TK_LP;
			tk_len=1;
			return 0;
		}
		case ')':
		{
			tk_type=TK_RP;
			tk_len=1;
			return 0;
		}
		case ';':
		{
			tk_type=TK_SEMI;
			tk_len=1;
			return 0;
		}
		case ',':
		{
			tk_type=TK_COMMA;
			tk_len=1;
			return 0;
		}
		case '`':
		case '\'':
		case '"':
		{
			int delim=*substr;
			for(i=1;(c=*(substr+i))!=0;i++){
				if(c==delim){
					break;
				}
			}
			if(c) i++;
			tk_type=TK_STRING;
			tk_len=i;
			return 0;

		}
		case '0': case '1': case '2': case '3': case '4': case '5': case '6':
		case '7': case '8': case '9':
		{
			tk_type=TK_INTEGER;
			for(i=1;isdigit(*(substr+i));i++){}
			tk_len=i;
			return 0;
		}
		default:
		{
			if(!isIdChar(*substr)){
				break;
			}
			for(i=1;isIdChar(*(substr+i));i++){}
			tk_type=getKeyToken(keywords,substr,i);
			tk_len=i;
			return 0;
		}

	}

	tk_type=TK_ILLEGAL;
	tk_len=1;

	return -1;
}

int Lexer::ifReachEnd(){

	return tk_offset>=strlen(sqlstr);
}

/*
int main(){
	Lexer lexer("create  table t1(id int,name varchar(12))");
//	Lexer lexer("create  table t1(id int,name int)");

	while(!lexer.ifReachEnd()){
		int d=lexer.getNextToken();
		if(d==1){
			printf("reach end!\n");
		}

		else{
			if(d==0){
				printf("correct string:");
			}
			else{
				printf("illegal char:");
			}
			char *tmp=(char *)malloc(lexer.getTkLen()+1);
			memcpy(tmp,lexer.getSqlStr()+lexer.getOffset(),lexer.getTkLen());
			printf("%s\n",tmp);
		}
	}
	return 0;
}
*/
