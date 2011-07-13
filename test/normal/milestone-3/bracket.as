// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// R UN: g++ -o %t %t.cpp -lruntime -D_LINUX

class C
{
}


function main():int
{
	var names:C= new C(); 
	names[0] = 0;
}

