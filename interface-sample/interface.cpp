#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <string>

using namespace emscripten;

struct Interface {
    virtual void invoke(const std::string& str) = 0;
};

struct InterfaceWrapper : public wrapper<Interface> {
    EMSCRIPTEN_WRAPPER(InterfaceWrapper);
    void invoke(const std::string& str) {
        return call<void>("invoke", str);
    }
};

EMSCRIPTEN_BINDINGS(interface) {
    class_<Interface>("Interface")
        .function("invoke", &Interface::invoke, pure_virtual())
        .allow_subclass<InterfaceWrapper>("InterfaceWrapper")
        ;
}


class Goose {
public:
std::string frog;

std::string  Get() const
{
    return frog;
}

void Set(std::string x)
{
    frog=x;
}
};

EMSCRIPTEN_BINDINGS(goosey) {
        class_<Goose>("Goose")
            .constructor()
            .property("goose", &Goose::Get,&Goose::Set)
    ;
}