import os
from   os import popen, path
import shlex
import sys

def main() -> int:
   
    """Echo the input arguments to standard output"""
    arguments =  sys.argv
    if len(arguments) < 2:
        return 0
    modname=arguments[1]
    blue=popen('npm init --yes')
    result=blue.read()
    print(result)
    blue.close()
    blue=popen('npm i testdouble mocha')
    blue.close()
    y=0
    insert= """const td = require('testdouble')
    const %1 = require('%1.js')  >> lib\%1-spec.js 
    describe( 'generic test',() %arrow% { 
        describe('#test1', () %arrow% { 
            it('boobytrap', () %arrow% { 
                }) 
        }) 
    }) """

    if  not path.isdir("lib"):
        os.mkdir('lib')
    raw=open("raw.js","r");
    contents=raw.read();
    contents=contents.replace("%1",modname);
    specfile=open("lib\\"+modname+"-spec.js", "w");
    specfile.write(contents);
    specfile.close();

    mymodule=open( "".join(["lib\\",modname,".js"]),"w");
    mymodule.write("module.exports={}")
    mymodule.close()

    return 0


if __name__ == '__main__':
    sys.exit(main())  # next section explains the use of sys.exit




