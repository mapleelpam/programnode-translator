// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc --symbol %t.pn -o %t.sym
// RUN: cat %t.sym | FileCheck -input-file=- %s 

package abc
{
    class TestClass                  //CHECK: class:TestClass
    {
        function fib( v:int): int           //CHECK: -function:fib
        {                                   //CHECK: --variable:v,param
            var ret:int = 1;                //CHECK: --variable:ret,local
            if( v < 3 )	
                ret = 1;
            else 
                ret = fib( v - 1 ) + fib( v - 2 );

            if( 1 )
            {                               //CHECK: --anonymous
                var local_var:int = 2;      //CHECK: ---variable:local_var,local
            }
            return ret;
        }
    }
    class TestClass2 extends TestClass                  //CHECK: class:TestClass2
    {
    }

	function main():int                 //CHECK: function:main
	{

        wprintf(" %d\n", fib(1)); 
	}
}
