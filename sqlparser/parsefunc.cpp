#include "../mdbproto.h"
#include "../util/trace.h"
void mdbBeginParse(Parse  *pParse,int explainFlag){
    //Tracer::tracePrint(INFO,"parse query:\t %s\n",pParse->zSql);
	pParse->explain=explainFlag;
}
