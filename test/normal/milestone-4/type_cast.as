// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// RUN: cat %t.cpp | FileCheck -input-file=- %s 

function callee( a:uint ) : int
{
	return a;
}

function main () : int
{
	var input : int;

	input = 0;
	callee( input ); // CHECK: (unsigned int)input 
}
