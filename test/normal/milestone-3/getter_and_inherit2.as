// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp -lruntime -D_LINUX
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
    public function another( test:int ) : int
    {
        return 0;
    }
}

class B extends A
{
    public function test( a:A ) : int
    {
//        a.me();
//        return me.number + 1;
    }
}

/*
function main():int
{
	var t1:B = new B();
	printf(" %d\n", t1.me.number ); // CHECK: 1
	
	printf(" %d\n", t1.me.number ); // CHECK: 2
	printf(" %d\n", t1.me.another()); // CHECK: 2
}

*/
