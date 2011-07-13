// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

function max( a:int, b:int ): int
{
	return (a>b) ? a : b;
}

function main():int
{

	printf(" %d\n", max(1, 2)); // CHECK: 2
	printf(" %d\n", max(100, 2)); // CHECK: 100
	printf(" %d\n", max(1123123, 2)); // CHECK: 1123123
}

