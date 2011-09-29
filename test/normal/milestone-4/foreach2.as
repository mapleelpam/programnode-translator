// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn %BUILTIN_PN -o %t.cpp 

package foo
{
	import flash.utils.Dictionary
	class Bar
	{
		function fib( v:int): int
		{
			var groupMap:Dictionary = new Dictionary();
			for each (var item:Object in groupMap)
			{
				for each (var item2:Object in groupMap)
				{
					trace(item);
				}
			}
		}
	}
}
