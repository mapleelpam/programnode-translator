// RUN: java -jar %ASC_JAR -x -z %t.pn  %s
// RUN: pnc %t.pn %BUILTIN_PN -o %t.cpp 

package
{

	public class TestClass
	{
		public function foo()
		{
            trace( "hello" );
		} 
	}
}
