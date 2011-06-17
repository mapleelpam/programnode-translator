//
// D:\test\lib\playerglobal.swc\flash\geom\Matrix
//
package flash.geom
{
	import flash.geom.Matrix;
	import flash.geom.Point;

	public class Matrix extends Object
	{
		/**
		 The value that affects the positioning of pixels
     along the x axis when scaling or rotating an image.
		 */
		public var a : Number;

		/**
		 The value that affects the positioning of pixels
     along the y axis when rotating or skewing an image.
		 */
		public var b : Number;

		/**
		 The value that affects the positioning of pixels
     along the x axis when rotating or skewing an image.
		 */
		public var c : Number;

		/**
		 The value that affects the positioning of pixels
     along the y axis when scaling or rotating an image.
		 */
		public var d : Number;

		/// The distance by which to translate each point along the x axis.
		public var tx : Number;

		/// The distance by which to translate each point along the y axis.
		public var ty : Number;

		public function clone () : Matrix;

		public function concat (m:Matrix) : void;

		public function createBox (scaleX:Number, scaleY:Number, rotation:Number = 0, tx:Number = 0, ty:Number = 0) : void;

		public function createGradientBox (width:Number, height:Number, rotation:Number = 0, tx:Number = 0, ty:Number = 0) : void;

		public function deltaTransformPoint (point:Point) : Point;

		public function identity () : void;

		public function invert () : void;

		public function Matrix (a:Number = 1, b:Number = 0, c:Number = 0, d:Number = 1, tx:Number = 0, ty:Number = 0);

		public function rotate (angle:Number) : void;

		public function scale (sx:Number, sy:Number) : void;

		public function toString () : String;

		public function transformPoint (point:Point) : Point;

		public function translate (dx:Number, dy:Number) : void;
	}
}
