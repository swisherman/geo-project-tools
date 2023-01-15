#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <string>

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


struct InterfaceStuffWrapper : public wrapper<MyStuff> {
    EMSCRIPTEN_WRAPPER(InterfaceStuffWrapper);
};

EMSCRIPTEN_BINDINGS(myinterface) {
    class_<MyStuff>("MyStuff")
    .constructor()
        .property("color", &MyStuff::GetColor,&MyStuff::SetColor)
         .allow_subclass<InterfaceStuffWrapper>("InterfaceStuffWrapper")
        ;
}