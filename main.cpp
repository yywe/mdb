/* this is the entry file of the source, enjoy!*/
/* @author whisly */

#include <iostream>
#include <string>
#include "util/trace.h"
#include "executor/exec.h"
#include "mdbtype.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#ifdef __cplusplus
}
#endif
/* global variables */
std::string versioninfo="Mdb version 0.1, enjoy!";
std::string conf_name="conf.ini";
std::string dbname="data";
std::string cwd="";
std::string prompt="mdb#";

/*get the current working directory */
std::string mdbGetCwd(){
	long size;
	char *buf;
	char *ptr;

	size=pathconf(".",_PC_PATH_MAX);
	if((buf=(char *)malloc((size_t)size))!=NULL){
		ptr=getcwd(buf,(size_t)size);
		std::string cwd(ptr);
		free(buf);
		return cwd;
	}
	else{
		Tracer::tracePrint(ERROR,"alloc memory failed\n");
		return "";
	}
}
void printUsage(){
	printf("usage:mdb -d <dirname> -f <conf_file> \n"\
							"\tmdb -v\n\tmdb -h\n");
}
int main(int argc,char **argv){

	int c;
	extern char *optarg;
	extern int optopt;

	char *cmd=NULL;

	while((c=getopt(argc,argv,":f:d:vhe:"))!=-1){
		switch(c){
			case 'v':
				printf("%s\n",versioninfo.c_str());
				exit(0);
			case 'h':
				printUsage();
				exit(0);
			case 'f':
				conf_name=optarg;
				break;
			case 'e':
				cmd=optarg;
				break;
			case 'd':
				dbname=optarg;
				break;
			case ':':
				Tracer::tracePrint(ERROR,"-%c without argname\n",optopt);
				exit(0);
			case '?':
			    Tracer::tracePrint(ERROR,"Invalid option %c\n",optopt);
				exit(0);
		}
	}
	cwd=mdbGetCwd();
	if(cwd.empty()){
		printf("get current working directory failed!\n");
		exit(0);
	}
	if(*(dbname.c_str())!='/'){
		dbname=cwd+"/"+dbname;
	}
	if((!conf_name.empty())&&*(conf_name.c_str())!='/'){
		conf_name=cwd+"/"+conf_name;
	}
	Tracer::tracePrint(INFO,"configuration file name :%s",conf_name.c_str());
	Tracer::tracePrint(INFO,"database directory :%s",dbname.c_str());
	if(access(conf_name.c_str(),F_OK|R_OK)!=0){
		Tracer::tracePrint(ERROR,"can not access configuration file:%s",conf_name.c_str());
		exit(0);
	}
	/*the data directory not exists ,create it! */
    if(access(dbname.c_str(),F_OK)!=0){
		if(mkdir(dbname.c_str(),0700)!=0){
			Tracer::tracePrint(ERROR,"can not create data directory:%s,error %s",
					dbname.c_str(),strerror(errno));
			exit(0);
		}
	}
	else{
		if(access(dbname.c_str(),R_OK|W_OK)!=0){
			Tracer::tracePrint(ERROR,"do not have previllege to the directory:%s",dbname.c_str());
			exit(0);
		}
	}
	Tracer::tracePrint(INFO,"change to data directory : %s",dbname.c_str());
	/**  Be carefull, because here I choose to chdir to the data directory
	 *	 so from now on the relative path is not the mdb
	 * */
	if(chdir(dbname.c_str())!=0){
			Tracer::tracePrint(ERROR,"change to  directory:%s,failed %s",
					dbname.c_str(),strerror(errno));
			exit(0);
	}

	char inputline[MAXLINESIZE]={0};

	printf("%s\n",versioninfo.c_str());
	
	if(cmd!=NULL){
			Executor ex;
			ex.setQuery(cmd);
			ex.setParsertf(cwd+"/parsetrace.txt");
			ex.prepare();
			return 0;
	}

	int quitflag=0;
	while(quitflag!=1){	
		printf("%s",prompt.c_str());
		memset(inputline,0,MAXLINESIZE);
		fgets(inputline,MAXLINESIZE,stdin);
		if(strlen(inputline)>4095){
			printf("the input is too long!\n");
			quitflag=1;
		}
		if(strncmp(inputline,"quit",4)==0){
			quitflag=1;
		}
		/*cut off the '\n' symbol */
		int len=strlen(inputline);
		if(inputline[len-1]=='\n'){
			inputline[len-1]=0;
		}
		if(quitflag!=1){
			printf("%s\n",inputline);
			Executor ex;
			ex.setQuery(inputline);
			ex.setParsertf(cwd+"/parsetrace.txt");
			ex.prepare();
		}
	

	}
	return 0;
}
