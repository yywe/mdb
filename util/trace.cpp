#include "trace.h"


void Tracer::tracePrint(tracelevel level,const char *fmt,...){
  /* extract the information */
  char msg[TRACEBUF];
  memset(msg,0,TRACEBUF);

  time_t ti;
  time(&ti);
  char *tinfo=asctime(localtime(&ti));
  snprintf(msg,strlen(tinfo),tinfo);
  strcat(msg,"  ");

  std::string levelinfo;
  switch(level){
    case INFO:
	levelinfo="INFO";
	break;
    case WARNING:
	levelinfo="WARNING";
	break;
    case ERROR:
	levelinfo="ERROR";
	break;
  }
  strcat(msg,levelinfo.c_str());
  strcat(msg,"\t");

  va_list ap;
  va_start(ap,fmt);
  vsnprintf(msg+strlen(msg),TRACEBUF,fmt,ap);
  va_end(ap);

  strcat(msg,"\n");
  FILE *fout=NULL;
  fout=stdout;
  fputs(msg,fout);
  return ;
}
void Tracer::TraceInfo(tracelevel level,const char *fmt,...){
  /* extract the information */
  char msg[TRACEBUF];
  memset(msg,0,TRACEBUF);

  time_t ti;
  time(&ti);
  char *tinfo=asctime(localtime(&ti));
  snprintf(msg,strlen(tinfo),tinfo);
  strcat(msg,"  ");

  std::string levelinfo;
  switch(level){
    case INFO:
	levelinfo="INFO";
	break;
    case WARNING:
	levelinfo="WARNING";
	break;
    case ERROR:
	levelinfo="ERROR";
	break;
  }
  strcat(msg,levelinfo.c_str());
  strcat(msg,"\t");

  va_list ap;
  va_start(ap,fmt);
  vsnprintf(msg+strlen(msg),TRACEBUF,fmt,ap);
  va_end(ap);

  strcat(msg,"\n");
  FILE *fout=NULL;
  if(tracefile.length()==0){
    fout=stdout;
  }
  else{
    if((fout=fopen(tracefile.c_str(),"a+"))==NULL){
	fprintf(stderr,"open the trace file  %s failed",tracefile.c_str());
	return;
    }
  }
  fputs(msg,fout);

  if(fout!=NULL){
    fclose(fout);
  }
}
void Tracer::printTbls(std::map<std::string,Table *> tbls){
	std::map<std::string,Table *>::iterator iter;
	for(iter=tbls.begin();iter!=tbls.end();iter++){
		std::string tblname=iter->first;
		printf("table name:%s\n",tblname.c_str());
		
		Table *pt=iter->second;
		if(pt){
			int i;
			for(i=0;i<pt->nCol;i++){
				Column *pc=&pt->aCol[i];
				printf("column %s,type %s\n",pc->colname,pc->zType);
			}
		}
	}
}
