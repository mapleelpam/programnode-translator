// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

function fib( v:int): int
{
	var ret:int;
    switch( v )
    {
        case 0:
        case 1:
        case 2:
    		ret = 1;
        break;
        default:
		ret = fib( v - 1 ) + fib( v - 2 );
        break;
    }
	return ret;
}

function main():int
{

	printf(" %d\n", fib(1)); // CHECK: 1
	printf(" %d\n", fib(10)); // CHECK: 55
}

