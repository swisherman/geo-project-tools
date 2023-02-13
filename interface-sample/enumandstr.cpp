#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <string>
#include <sstream>

using namespace emscripten;

class MyStuff {
    public:
    MyStuff()
    {}

    std::string _color;
    void SetColor(std::string color){
        _color=color;
    }
    std::string GetColor() const
    {
        return _color;
    }
};


class MyColor {
    public:

    std::string _color;
    void SetColor(std::string color){
        _color=color;
    }
    std::string GetColor() const
    {
        return _color;
    }
};

struct InterfaceStuffWrapper : public wrapper<MyStuff> {
    EMSCRIPTEN_WRAPPER(InterfaceStuffWrapper);
};
struct InterfaceColorWrapper : public wrapper<MyColor> {
    EMSCRIPTEN_WRAPPER(InterfaceColorWrapper);
};

EMSCRIPTEN_BINDINGS(myinterface) {
    class_<MyStuff>("MyStuff")
    .constructor()
        .property("color", &MyStuff::GetColor,&MyStuff::SetColor)
         .allow_subclass<InterfaceStuffWrapper>("InterfaceStuffWrapper")
        ;

class_<MyColor>("MyColor")
        .property("color", &MyColor::GetColor,&MyColor::SetColor)
         .allow_subclass<InterfaceColorWrapper>("InterfaceColorWrapper")
        ;

}

extern "C" {
    std::string YouSaid(std::string quoted) 
    {
        std::stringstream input;
        input << "You said" << quoted << std::endl;
        return input.str();
    }
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("youSaid", &YouSaid);
}


std::string getExceptionMessage(intptr_t exceptionPtr) {
  return std::string(reinterpret_cast<std::exception *>(exceptionPtr)->what());
}




struct PersonRecord {
    std::string name;
    int age;
};

// Array fields are treated as if they were std::array<type,size>
struct ArrayInStruct {
    int field[2];
};

PersonRecord findPersonAtLocation()
{
 PersonRecord record;
return record;
}
PersonRecord findPersonAtLocation();



EMSCRIPTEN_BINDINGS(my_value_example) {
    value_object<PersonRecord>("PersonRecord")
        .field("name", &PersonRecord::name)
        .field("age", &PersonRecord::age)
        ;
    function("findPersonAtLocation", &findPersonAtLocation);
}