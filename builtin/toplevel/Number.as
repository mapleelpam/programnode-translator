//
// D:\test\lib\playerglobal.swc\Number
//
package
{
	public class Number extends Object
	{
		public static const length : int;

		/**
		 The largest representable number (double-precision IEEE-754). This number is 
  approximately 1.79e+308.
		 */
		[native(support="none")]
		public static const MAX_VALUE : Number;

		/**
		 The smallest representable non-negative, non-zero, number (double-precision IEEE-754). This number is 
  approximately 5e-324. The smallest representable number overall is actually -Number.MAX_VALUE.
		 */
		[native(support="none")]
		public static const MIN_VALUE : Number;

		/// The IEEE-754 value representing Not a Number (NaN).
		[native(support="none")]
		public static const NaN : Number;

		/**
		 Specifies the IEEE-754 value representing negative infinity. The value of this property 
  is the same as that of the constant -Infinity.
  
  Negative infinity is a special numeric value that is returned when a mathematical 
  operation or function returns a negative value larger than can be 
  represented.
		 */
		[native(support="none")]
		public static const NEGATIVE_INFINITY : Number;

		/**
		 Specifies the IEEE-754 value representing positive infinity. The value of this property 
  is the same as that of the constant Infinity.
  
  Positive infinity is a special numeric value that is returned when a mathematical 
  operation or function returns a value larger than can be represented.
		 */
		[native(support="none")]
		public static const POSITIVE_INFINITY : Number;

		public function Number (value:* = 0);
		[native(support="none")]
		AS3 function toExponential (p:* = 0) : String;
		[native(support="none")]
		AS3 function toFixed (p:* = 0) : String;
		[native(support="none")]
		AS3 function toPrecision (p:* = 0) : String;

		AS3 function toString (radix:* = 10) : String;
		[native(support="none")]
		AS3 function valueOf () : Number;
	}
}
