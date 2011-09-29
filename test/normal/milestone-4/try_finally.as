// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: pnc %t.pn -o %t.h --predef
// RUN: g++  -o %t %t.cpp 
// RUN: %t | FileCheck -input-file=- %s 

function main () : int
{

	try {
		printf("try 1\n");		// CHECK: try 1
		throw 1;
		printf("try 2\n");
	}
	catch (errObject:int) {
		printf("catch\n");		// CHECK: catch
	}
	finally {
		printf("finally\n"); 
	}


	try {
		printf("try 3\n");			// CHECK: try 3
	}
	catch (errObject:int) {
		printf("catch 3\n");	
	}
	finally {
		printf("finally 3\n");		
	}
}
