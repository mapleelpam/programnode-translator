package
{
    [native(cls="Number", instance="NativeNumber", methods="auto")]
	intrinsic public class Number extends Object
	{
		public static const length : int;

		[native(support="none")]
		public static const MAX_VALUE : Number;

		[native(support="none")]
		public static const MIN_VALUE : Number;

		[native(support="none")]
		public static const NaN : Number;

		[native(support="none")]
		public static const NEGATIVE_INFINITY : Number;

		[native(support="none")]
		public static const POSITIVE_INFINITY : Number;

/*
		public function Number (value:* = 0);
		[native(support="none")]
		public function toExponential (p:* = 0) : String;
		[native(support="none")]
		public function toFixed (p:* = 0) : String;
		[native(support="none")]
		public function toPrecision (p:* = 0) : String;

		public function toString (radix:* = 10) : String;
*/
		[native(support="none")]
		public function valueOf () : Number;
	}
}
