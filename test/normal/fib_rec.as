// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

	function fib( v:int): int
	{
		var ret:int;
		if( v < 3 )	
			ret = 1;
		else 
			ret = fib( v - 1 ) + fib( v - 2 );
		return ret;
	}

	function main():int
	{

        printf(" %d\n", fib(1)); // CHECK: 1
	}

