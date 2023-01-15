var DerivedClass = Module.Interface.extend("Interface", {
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

var instance = new DerivedClass;