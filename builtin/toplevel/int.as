package
{
    [native(cls="Int", instance="Int", methods="auto")]
	intrinsic public class int extends Object
	{
		public static const length : int;

		[native(support="none")]
		public static const MAX_VALUE : int = 2147483647;

		[native(support="none")]
		public static const MIN_VALUE : int = -2147483648;

/*
		public function int (value:* = 0);
		[native(support="none")]
		public function toExponential (p:* = 0) : String;
		[native(support="none")]
		public function toFixed (p:* = 0) : String;
		[native(support="none")]
		public function toPrecision (p:* = 0) : String;

		public function toString (radix:* = 10) : String;
*/
		[native(support="none")]
		public function valueOf () : int;
	}
}
