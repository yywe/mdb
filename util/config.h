#ifndef _CONFIG_H_
#define _CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#ifdef __cplusplus
}
#endif

#include <string>
#include <exception>
#include <map>
using std::string;
using std::map;
using std::exception;

class Config{

    public:
	Config(string fn):filename(fn),loadStatus(0){
	    loadConf();
	}
	Config(){
	    filename="";
	    loadStatus=0;
	}
	string getConfFile() const {
	    return filename;
	}
	void setConfFile(string fn) {
	    filename=fn;
	}
	map<string,string> loadConf() throw(exception);
	int getLoadStatus() const{
	    return loadStatus;
	}
	map<string,string> getConfInfo() const {
	    return confinfo;
	}
	string getConfValue(string key);
	
    private:
	string filename;
	/*load status :0 init, -1 load failed, 1 load success */
	int loadStatus;
	map<string,string> confinfo;
};

#endif
