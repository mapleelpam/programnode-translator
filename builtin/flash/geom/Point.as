//
// D:\test\lib\playerglobal.swc\flash\geom\Point
//
package flash.geom
{
	import flash.geom.Point;

	public class Point extends Object
	{
		/// The horizontal coordinate of the point. The default value is 0.
		public var x : Number;

		/// The vertical coordinate of the point. The default value is 0.
		public var y : Number;

		/// The length of the line segment from (0,0) to this point.
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
