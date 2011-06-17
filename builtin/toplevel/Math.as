//
// D:\test\lib\playerglobal.swc\Math
//
package
{
	public class Math extends Object
	{
		/**
		 A mathematical constant for the base of natural logarithms, expressed as e.
  The approximate value of eis 2.71828182845905.
		 */
		public static const E : Number = 2.71828182845905;

		/**
		 A mathematical constant for the natural logarithm of 10, expressed as loge10,
  with an approximate value of 2.302585092994046.
		 */
		public static const LN10 : Number = 2.302585092994046;

		/**
		 A mathematical constant for the natural logarithm of 2, expressed as loge2,
  with an approximate value of 0.6931471805599453.
		 */
		public static const LN2 : Number = 0.6931471805599453;

		/**
		 A mathematical constant for the base-10 logarithm of the constant e (Math.E),
  expressed as log10e, with an approximate value of 0.4342944819032518. 
  The Math.log() method computes the natural logarithm of a number. Multiply the 
  result of Math.log() by Math.LOG10E to obtain the base-10 logarithm.
		 */
		public static const LOG10E : Number = 0.4342944819032518;

		/**
		 A mathematical constant for the base-2 logarithm of the constant e, expressed 
  as log2e, with an approximate value of 1.442695040888963387.
  
  The Math.log method computes the natural logarithm of a number. Multiply the 
  result of Math.log() by Math.LOG2E to obtain the base-2 logarithm.
		 */
		public static const LOG2E : Number = 1.442695040888963387;

		/**
		 A mathematical constant for the ratio of the circumference of a circle to its diameter,
  expressed as pi, with a value of 3.141592653589793.
		 */
		public static const PI : Number = 3.141592653589793;

		/**
		 A mathematical constant for the square root of one-half, with an approximate  
  value of 0.7071067811865476.
		 */
		public static const SQRT1_2 : Number = 0.7071067811865476;

		/**
		 A mathematical constant for the square root of 2, with an approximate 
  value of 1.4142135623730951.
		 */
		public static const SQRT2 : Number = 1.4142135623730951;

		public static function abs (val:Number) : Number;

		public static function acos (val:Number) : Number;

		public static function asin (val:Number) : Number;

		public static function atan (val:Number) : Number;

		public static function atan2 (y:Number, x:Number) : Number;

		public static function ceil (val:Number) : Number;

		public static function cos (angleRadians:Number) : Number;

		public static function exp (val:Number) : Number;

		public static function floor (val:Number) : Number;

		public static function log (val:Number) : Number;

		public function Math ();

		public static function max (val1:Number = -Infinity, val2:Number = -Infinity, ...rest) : Number;

		public static function min (val1:Number = Infinity, val2:Number = Infinity, ...rest) : Number;

		public static function pow (base:Number, pow:Number) : Number;

		public static function random () : Number;

		public static function round (val:Number) : Number;

		public static function sin (angleRadians:Number) : Number;

		public static function sqrt (val:Number) : Number;

		public static function tan (angleRadians:Number) : Number;
	}
}
