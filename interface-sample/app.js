const myinterface = require('./interface')



let thisModule;
let myGoose;
let myTest;
const go = async () => {

    thisModule = await myinterface();

    myTest=thisModule.MyStuff.extend("MyStuff",{
        __construct: function() {
            this.__parent.__construct.call(this);
        },
        __destruct: function() {
            this.__parent.__destruct.call(this);
        },
    });
    var DerivedClass = thisModule.Interface.extend("Interface", {
        // __construct and __destruct are optional.  They are included
        // in this example for illustration purposes.
        // If you override __construct or __destruct, don't forget to
        // call the parent implementation!
        __construct: function() {
            this.__parent.__construct.call(this);
        },
        __destruct: function() {
            this.__parent.__destruct.call(this);
        },
        invoke: function() {
            // your code goes here
        },
    });
    
    var testInstance=new myTest();
    var instance = new DerivedClass;
    myGoose=new thisModule.Goose();
    instance.delete();
    Note

}


go()