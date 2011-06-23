// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp -lruntime -D_LINUX
// : %t | FileCheck -input-file=- %s 


class TestObject
{
	public function get number() : int
	{
		/* always reutrn 1 */
		return 1;
	}
}

function main():int
{
	var t1:TestObject = new TestObject();
	printf(" %d\n", t1.number ); // CHECK: 1
	
    var test_getter_var : int = t1.number;
}

