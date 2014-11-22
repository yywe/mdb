#include "config.h"
#include "trace.h"
#include "../mdbtype.h"
map<string,string> Config::loadConf() throw(exception){
    try{
	 FILE *fp=fopen(filename.c_str(),"r");
	 if(!fp) throw exception();
	 char line[MAXLINESIZE]={0};
	 while(fgets(line,MAXLINESIZE,fp)!=NULL){
	    size_t offset=0;
	    if(line[0]=='#'||line[0]=='\n') continue;
	    else{
		while(line[offset]==' '||line[offset]=='\t') offset++;
		size_t start=offset;
		while(line[offset]!=' '&&line[offset]!='='&&line[offset]!='\t') offset++;
		size_t end=offset;
		string attr(line+start,end-start);
		while(line[offset]==' '||line[offset]=='\t') offset++;
		if(line[offset]!='=') throw exception();
		offset++;
		while(line[offset]==' '||line[offset]=='\t') offset++;
		start=offset;
		while(line[offset]!=' '&&line[offset]!='='&&line[offset]!='\t'&&line[offset]!='\n') offset++;
		end=offset;
		string value(line+start,end-start);
		if(value.empty()) throw exception();
		confinfo.insert(std::pair<string,string>(attr,value));
	    }
	    
	 }
	 loadStatus=1;
	 fclose(fp);
    }catch(const exception &e){
	loadStatus=-1;
	Tracer::tracePrint(ERROR,"Load Configuration file failed\n");
    }
    return confinfo;
}

string Config::getConfValue(string key){
    if(loadStatus!=1){
      return string();
    }
    map<string,string>::iterator iter;           
    iter=confinfo.find(key);
    if(iter!=confinfo.end()){
       return iter->second;
    }
    return string();
}

/**test
 * g++ config.cpp trace.cpp
 *
#include <iostream>
int main(){

    Config conf("/home/whisly/mdb/conf.ini");
    if(conf.getLoadStatus()==1){
	map<string ,string> m=conf.getConfInfo();
	map<string,string>::iterator iter;

	for(iter=m.begin();iter!=m.end();iter++){
	    std::cout<<iter->first<<":";
	    std::cout<<iter->second<<std::endl;
	}

    }
    string b=conf.getConfValue("hello");
    printf("hello:%s\n",b.c_str());
    b=conf.getConfValue("listenport");
    printf("listenport:%s\n",b.c_str());
    
    return 0;
}
*/
