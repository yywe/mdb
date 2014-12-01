#include "augfunc.h"
#include <assert.h>
#include <string.h>
void writeInt32(char *buf,unsigned int v){
	assert(buf!=NULL);
	unsigned char ac[4];
	ac[0]=(v>>24)&0xff;
	ac[1]=(v>>16)&0xff;
	ac[2]=(v>>8)&0xff;
	ac[3]=v & 0xff;
	memcpy(buf,ac,4);
	return ;
}
void writeVarchar(char *buf,char *str){
	unsigned int len=strlen(str);
	writeInt32(buf,len);
	memcpy(buf+4,str,len);
	return ;
}
