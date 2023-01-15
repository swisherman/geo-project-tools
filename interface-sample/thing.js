
let print=() => {
console.log("hello world from Thing")
}
class WasmModule {
    constructor(){}
    jump()  {
        console.log('I am jumping')
    }
}

Module['print']=print;
Module['wasmModule']=new WasmModule();
Module['wm']=WasmModule;