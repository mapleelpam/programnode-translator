// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 

class A
{
    public var a:int;
}

class B 
{
    public var oa:A;
}

function main() : int
{
	var b:B;

    b . oa . a = 1;
}
