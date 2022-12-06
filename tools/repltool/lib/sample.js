const { constructor } = require("testdouble");

class Sample {
   
    constructor() {
      
    }
 

    print() {
        console.log('I am a sample')
    }
}

module.exports={
    Sample
}