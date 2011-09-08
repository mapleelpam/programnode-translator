// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %BUILTIN_PN %t.pn -o %t.cpp
package
{
	intrinsic public class Number extends Object
	{
		public function Number (value:* = 0);
	}
	public class Number2 extends Object
	{
		public function Number (value:* = 0);
	}
}
