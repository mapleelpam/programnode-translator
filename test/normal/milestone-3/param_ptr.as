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
		public function c( param:c )
		{
		}
		public function c( )
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
	var instance_c : a.c;
	instance_c = new a.c();
	printf(" %d \n", instance_c.e ); // CHECK: 987
}

