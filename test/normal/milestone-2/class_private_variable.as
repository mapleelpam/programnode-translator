// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp 
// RUN: %t | FileCheck -input-file=- %s 

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
			e = 987;
		}

		public function d() : int
		{
			return 789;
		}
	
		public function getE() : int
		{
			return e;
		}

		private var e:int = 987;
	}
}

function main() : int
{
	var instance_c : a.c;
	instance_c = new a.c();
	printf(" %d \n", instance_c.getE() ); // CHECK: 987
}

