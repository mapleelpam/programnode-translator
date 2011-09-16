// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc --symbol %t.pn -o %t.sym
// RUN: cat %t.sym | FileCheck -input-file=- %s 

class A		// CHECK: class:A FQN->::A
{
	public function test()
// CHECK: -function:test return:Void : FQN->::A::test
// CHECK: -function:test return:Void : instance name->
// CHECK: -function:test return:Void : not_constructor not_intrinsic will used like variable caller:'' Void
	{
		test2( test );	
	}
	public function test2( i:int)
	{
	}
}

function main() : int
{
}
