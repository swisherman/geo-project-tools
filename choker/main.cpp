#include <emscripten/bind.h>
//#include <stdexcept>



class MyException: public std::exception
{
    char theException[255];

public:
    MyException(const char * msg) : std::exception()
    {
        strcpy(theException, msg);
    }
    void setWhat(const char * msg){
        memset(&theException, 0, sizeof(theException));
        if(strlen(msg) < sizeof(theException))
        {
            
        strncpy(theException, msg,strlen(msg));
        }
        else
        {
             strncpy(theException, msg,sizeof(theException)-1);
        }
    }
    const char *what()
    {
        return theException;
    }

};


::MyException myException("marbles are not free");


std::string
getExceptionMessage(intptr_t exceptionPtr)
{
    
    return std::string(reinterpret_cast<::MyException *>(exceptionPtr)->what());
}


using namespace emscripten;

extern "C" 
{

float add(float x, float y)
{ 
    if(x>6) {
        char buf[]="We got an error";
        ::myException.setWhat(buf);
        throw ::myException;
    }
    return x+y;
}

}

EMSCRIPTEN_BINDINGS(Bindings){
    function("add",&add);
    function("getExceptionMessage", &getExceptionMessage);

}

