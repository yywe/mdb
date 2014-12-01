#include "handler.h"
#include "../util/augfunc.h"

int Handler::createTbl(Table *ptbl){
	char header[TABLEHEADER]={0};
	int magiclen=strlen(MAGICSTR);
	/*write magic string */
	memcpy(header,MAGICSTR,magiclen);
	/*write table name */
	writeVarchar(header+magiclen,ptbl->zName);
	/*write table definition */
	writeVarchar(header+magiclen+4+strlen(ptbl->zName),(char *)ptbl->creatsql);
	
	char datfile[MAXLINESIZE];
	memset(datfile,0,MAXLINESIZE);
	getcwd(datfile,MAXLINESIZE);
	strcat(datfile,"/");
	strcat(datfile,ptbl->zName);
	strcat(datfile,".dat");
	if(access(datfile,F_OK)==0){
		printf("the data table %s is already exists!\n",datfile);
		return -1;
	}
	else{
		FILE *fp=fopen(datfile,"w");
		if(fp==NULL){
			printf("open table %s failed\n",datfile);
		}
		fwrite(header,TABLEHEADER,1,fp);
		printf("create table %s succeed!\n",ptbl->zName);
		fclose(fp);
	}
	
	return 0;
}
