// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

function fib( v:int): int
{
	var a:int = 1;
	var b:int = 1;
	var idx:int = 1;
	for( idx = 1 ; idx < v ; idx ++ )
	{
		var c:int = a+b;
		a = b;
		b = c;
	}		

	return a;
}

function main():int
{

	printf(" %d\n", fib(1)); // CHECK: 1
	printf(" %d\n", fib(10)); // CHECK: 55
}

