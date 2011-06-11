package
{
	[native(cls="Math", instance="Math", methods="auto")]
	public final class Math extends Object
	{
		static public function abs( val:double ) : double;
		static public function acos( val:double ) : double;
		static public function asin( val:double ) : double;
		static public function atan( val:double ) : double;
		static public function atan2( y:double, x:double ) : double;
		static public function ceil( val:double ) : double;
		static public function cos( val:double ) : double;
		static public function exp( val:double ) : double;
		static public function floor( val:double ) : double;
		static public function log( val:double ) : double;
		static public function max( amount:int, ... Arguments) : double;
		static public function min( amount:int, ... Arguments) : double;
		static public function pow( num1:double, num2:double ) : double;
		static public function random() : double;
		static public function round( val:double ) : int;
		static public function sin( val:double ) : double;
		static public function sqrt( val:double ) : double;
		static public function tan( val:double ) : double;

		public static const E:double;
		public static const LN10:double;
		public static const LN2:double;
		public static const LOG10E:double;
		public static const LOG2E:double;
		public static const PI:double;
		public static const SQRT1_2:double;
		public static const SQRT2:double;
		
	}
}
