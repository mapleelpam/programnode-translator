// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp 
// : %t | FileCheck -input-file=- %s 


class A
{
	public function get number() : int
	{
		/* always reutrn 1 */
		return 1;
	}
	public function get me() : A
	{
		/* always reutrn 1 */
		return this;
	}
}

class B extends A
{
}

function main():int
{
	var t1:B = new B();
	printf(" %d\n", t1.me.number ); // CHECK: 1
	
}

