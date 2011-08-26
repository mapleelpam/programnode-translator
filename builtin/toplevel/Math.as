package
{
	intrinsic public class Math extends Object
	{
		public static const E : Number = 2.71828182845905;

		public static const LN10 : Number = 2.302585092994046;

		public static const LN2 : Number = 0.6931471805599453;

		public static const LOG10E : Number = 0.4342944819032518;

		public static const LOG2E : Number = 1.442695040888963387;

		public static const PI : Number = 3.141592653589793;

		public static const SQRT1_2 : Number = 0.7071067811865476;

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

    		[mapper(caller="max(#(argn),#(argc))")]
		public static function max (val1:Number = -Infinity, val2:Number = -Infinity, ...rest) : Number;

    		[mapper(caller="min(#(argn),#(argc))")]
		public static function min (val1:Number = Infinity, val2:Number = Infinity, ...rest) : Number;

		public static function pow (base:Number, pow:Number) : Number;

		public static function random () : Number;

		public static function round (val:Number) : Number;

		public static function sin (angleRadians:Number) : Number;

		public static function sqrt (val:Number) : Number;

		public static function tan (angleRadians:Number) : Number;
	}
}
