// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %BUILTIN_PN %t.pn -o %t.cpp
// R U N: g++ -o %t %t.cpp 
// R U N: %t | FileCheck -input-file=- %s 

package a
{
	function b() : int
	{
		return 456;
	}
	class c 
	{
		static public function d() : int
		{
			return 789;
		}

		[mapto(name="foo_bar_e")]
		static public var e:int = 987;

		private var testList:Array = ["aaa","bbb","ccc"];
	}
}

function main() : int
{
	a.b();
	a.c.d();
	printf(" %d \n", a.b() ); // CHECK: 456
	printf(" %d \n", a.c.d() ); // CHECK: 789

	printf(" %d \n", a.c.e ); // CHECK: 987
}

