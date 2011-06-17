//
// D:\test\lib\playerglobal.swc\int
//
package
{
	public class int extends Object
	{
		public static const length : int;

		/// The largest representable 32-bit signed integer, which is 2,147,483,647.
		[native(support="none")]
		public static const MAX_VALUE : int = 2147483647;

		/// The smallest representable 32-bit signed integer, which is -2,147,483,648.
		[native(support="none")]
		public static const MIN_VALUE : int = -2147483648;

		public function int (value:* = 0);
		[native(support="none")]
		AS3 function toExponential (p:* = 0) : String;
		[native(support="none")]
		AS3 function toFixed (p:* = 0) : String;
		[native(support="none")]
		AS3 function toPrecision (p:* = 0) : String;

		AS3 function toString (radix:* = 10) : String;
		[native(support="none")]
		AS3 function valueOf () : int;
	}
}
