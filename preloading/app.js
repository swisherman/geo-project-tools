const main=require('./main')

let todo;
 go=  async  () => {
    todo = await main()
    //todo.print()
    console.log('banana');
}
go()
