package flash.geom
{
	import flash.geom.Point;

	intrinsic public class Point extends Object
	{
		public var x : Number;

		public var y : Number;

		public function get length () : Number;

		public function add (v:Point) : Point;

		public function clone () : Point;

		public static function distance (pt1:Point, pt2:Point) : Number;

		public function equals (toCompare:Point) : Boolean;

		public static function interpolate (pt1:Point, pt2:Point, f:Number) : Point;

		public function normalize (thickness:Number) : void;

		public function offset (dx:Number, dy:Number) : void;

		public function Point (x:Number = 0, y:Number = 0);

		public static function polar (len:Number, angle:Number) : Point;

		public function subtract (v:Point) : Point;

		public function toString () : String;
	}
}
