// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// -RUN: pn-translator --symbol %t.pn -o %t.sym
// -RUN: cat %t.sym | FileCheck -input-file=- %s 

package abc
{
	function fib( v:int): int           //CHECK: fib
	{                                   //CHECK: -v
		var ret:int = 1;                //CHECK: -ret
		if( v < 3 )	
			ret = 1;
		else 
			ret = fib( v - 1 ) + fib( v - 2 );
		return ret;
	}

	function main():int                 //CHECK: main
	{

        wprintf(" %d\n", fib(1)); 
	}
}
