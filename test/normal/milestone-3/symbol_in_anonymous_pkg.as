// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
package
{
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
		[native(support="none")]
		public function valueOf () : Number;
*/
	}

}
package flash.geom
{
	import flash.geom.Matrix;
//	import flash.geom.Point;

	intrinsic public class Matrix extends Object
	{
//		public var a : Number;

		public var b : Number;

		public var c : Number;

		public var d : Number;

		public var tx : Number;

		public var ty : Number;

		public function clone () : Matrix;

		public function concat (m:Matrix) : Void;

/*
		public function createBox (scaleX:Number, scaleY:Number, rotation:Number = 0, tx:Number = 0, ty:Number = 0) : Void;

		public function createGradientBox (width:Number, height:Number, rotation:Number = 0, tx:Number = 0, ty:Number = 0) : Void;

		public function deltaTransformPoint (point:Point) : Point;

		public function identity () : Void;

		public function invert () : Void;

		public function Matrix (a:Number = 1, b:Number = 0, c:Number = 0, d:Number = 1, tx:Number = 0, ty:Number = 0);
*/

		public function rotate (angle:Number) : Void;

		public function scale (sx:Number, sy:Number) : Void;

		public function toString () : String;

//		public function transformPoint (point:Point) : Point;

		public function translate (dx:Number, dy:Number) : Void;
	}
}
package
{
	intrinsic public class String extends Object
	{
	}
}
package
{
	intrinsic public class Object
	{
	}
}
