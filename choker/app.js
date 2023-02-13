const main = require('./main.js')



const start=async function () {
    const runner= await main()
   let x=4;
   const y=8;


   function getExceptionMessage(exception) {
    return typeof exception === 'number'
      ? runner.getExceptionMessage(exception)
      : exception;
  }


   try{
    runner.add(x,y);
    x=9;
    runner.add(x,y); 
    } catch(e) {

        const b=getExceptionMessage(e);
        console.error(b);
    }
   
}





start()