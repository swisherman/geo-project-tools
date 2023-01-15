#include <emscripten.h>

#include <emscripten/bind.h>
#include <stdio.h>
#include <iostream> 
using namespace std;
using namespace emscripten;
#include <emscripten/val.h>
EM_JS(void, myprint, (), {
  print();
});

EM_JS(void,boom,(),{});

extern "C"
{
    void JsIterate()
    {
        size_t counter = 1000000;
       
          time_t result = time(NULL);
   
        if (result != (time_t)(-1))
        {
std::cout << "The current time is " <<ctime(&result) << std::endl;
        std::cout.flush();
         
        }
           // printf("The current time is %s(%jd seconds since the Epoch)\n",
           //        asctime(gmtime(&result)), (intmax_t)result);
            while (counter > 0)
        {
           // myprint();
            counter--;
        }
        result = time(NULL);
        if (result != (time_t)(-1))
            {
std::cout << "The current time is " <<ctime(&result) << std::endl; std::cout.flush();
        
        }
    }
}
// int main()
// {
  
//     val obj = val::module_property("wasmModule");
//     if (obj.as<bool>())
//     {
//         std::cout << obj.typeOf().as<std::string>();
//       obj.call<val>("jump",0);
//     }
//     else
//     {
//         printf("Unable to get wasmModule\n");
//     }

//     return 0;
// }

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("jsPrint", &JsIterate);
}