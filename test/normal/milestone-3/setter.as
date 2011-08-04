// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


class TestObject
{
	public function get number() : int
	{
		return save;
	}

	public function set number( i:int ) : Void
	{
		save = i;
	}
	
//	private:
		var save:int;
}

function main():int
{
	var t1:TestObject = new TestObject();
	t1.number = 1;
	printf(" %d\n", t1.number ); // CHECK: 1
	t1.number = 2;
	printf(" %d\n", t1.number ); // CHECK: 2
	
}

