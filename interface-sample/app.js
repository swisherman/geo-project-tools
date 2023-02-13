const myinterface = require('./interface')



let thisModule;
let myGoose;
let myTest;
let myColor;
let bananaStuffType;
let bananaStuffing;
const go = async () => {

    thisModule = await myinterface();


    thisModule.youSaid('beautiful');

    bananaStuffType = thisModule.BananaFluff.extend("BananaFluff",{
    __construct: function() {
        this.__parent.__construct.call(this);
    },
    __destruct: function() {
        this.__parent.__destruct.call(this);
    },
});

bananaStuffing=new bananaStuffType();


    // myColor= thisModule.MyColor.extend("MyColor",{
    //     __construct: function() {
    //         this.__parent.__construct.call(this);
    //     },
    //     __destruct: function() {
    //         this.__parent.__destruct.call(this);
    //     },
    // });


    // myTest=thisModule.MyStuff.extend("MyStuff",{
    //     __construct: function() {
    //         this.__parent.__construct.call(this);
    //     },
    //     __destruct: function() {
    //         this.__parent.__destruct.call(this);
    //     },
    // });
    // var DerivedClass = thisModule.Interface.extend("Interface", {
    //       __construct: function() {
    //         this.__parent.__construct.call(this);
    //     },
    //     __destruct: function() {
    //         this.__parent.__destruct.call(this);
    //     },
    //     invoke: function() {
    //         // your code goes here
    //     },
    // });
    
    // var testInstance=new myTest();
    // var instance = new DerivedClass;
    // myGoose=new thisModule.Goose();
    // instance.delete();
    // Note
bananaStuffing.delete();
}


go()