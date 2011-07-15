// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
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
		public function c()
		{
		}

		public function d() : int
		{
			return 789;
		}

		public var e:int = 987;
	}
}

function main() : int
{
	printf(" %d \n", (new a.c).d() ); // CHECK: 987
}

