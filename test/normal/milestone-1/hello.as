// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

function main( ) : int
{
	printf(" hello world"); // CHECK: hello world
	printf(" hello mars"); // CHECK: hello mars
}
