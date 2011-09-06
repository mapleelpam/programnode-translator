// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// : cat %t.cpp | FileCheck -input-file=- %s 

function main () : int
{

	try {
		printf("try");
	}
/*
	catch (errObject:Error) {
		printf("catch");
	}
*/
	finally {
		printf("finally"); 
	}
}
