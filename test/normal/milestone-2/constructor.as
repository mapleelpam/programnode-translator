// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


class A
{
}

class B extends A 
{
	public function B()
	{
	}
}

function main() : int
{
    var a:A = new A;
    var b:B = new B;
}
