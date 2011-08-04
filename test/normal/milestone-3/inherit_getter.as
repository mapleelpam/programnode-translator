// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp 
// : %t | FileCheck -input-file=- %s 


class B
{
    public function get position() : int
    {
        return 1;
    }
}

class A extends B
{
}

function main():int
{
	var t1:A = new A();
	printf(" %d\n", t1.position ); // CHECK: 1
	
}

