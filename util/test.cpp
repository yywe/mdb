#include "trace.h"
#include <string>

/** for test usage 
 * g++ test.cpp trace.cpp 
 *
 */

int main(int argc,char **argv){
    std::string tf="hello.txt";
    Tracer tc;
    tc.TraceInfo(ERROR,"this is from %s","stdout");

    Tracer tc2(tf);
    tc2.TraceInfo(INFO,"this is from %s","hello.txt");

    return 0;
}
