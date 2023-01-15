#include <emscripten/bind.h>
#include <string>

using namespace emscripten;


struct Interface {
    std::string goose;
    Interface() {
        goose="type of bird with long neck";
    };
    static std::string getStringFromInstance(const Interface & instance) {
    return instance.goose;
  }
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
           .class_function("getStringFromInstance", &Interface::getStringFromInstance)
        ;
}