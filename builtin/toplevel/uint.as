//
// D:\test\lib\playerglobal.swc\uint
//
package
{
	public class uint extends Object
	{
		public static const length : int;

		/// The largest representable 32-bit unsigned integer, which is 4,294,967,295.
		[native(support="none")]
		public static const MAX_VALUE : uint = 4294967295;

		/// The smallest representable unsigned integer, which is 0.
		[native(support="none")]
		public static const MIN_VALUE : uint = 0;
		[native(support="none")]
		AS3 function toExponential (p:* = 0) : String;
		[native(support="none")]
		AS3 function toFixed (p:* = 0) : String;
		[native(support="none")]
		AS3 function toPrecision (p:* = 0) : String;

		AS3 function toString (radix:* = 10) : String;

		public function uint (value:* = 0);
		[native(support="none")]
		AS3 function valueOf () : uint;
	}
}
