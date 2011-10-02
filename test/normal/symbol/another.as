// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc --symbol %t.pn -o %t.sym
// RUN: cat %t.sym | FileCheck -input-file=- %s 

class A		// CHECK: class:A FQN->::A
{
}

class B extends A   // CHECK: class:B FQN->::B
{                   // CHECK: class:B ParentFQN->::A
	public function B() : Void // CHECK: -function:B return:Void : FQN->::B::B
	{
	}
}

function main() : int
{
    var a:A = new A;	// CHECK: -variable:a,local type:::A
    var b:B = new B;
}
