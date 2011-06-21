package flash.geom
{
	import flash.geom.ColorTransform;

	intrinsic public class ColorTransform extends Object
	{
		public var alphaMultiplier : Number;

		public var alphaOffset : Number;

		public var blueMultiplier : Number;

		public var blueOffset : Number;

		public var greenMultiplier : Number;

		public var greenOffset : Number;

		public var redMultiplier : Number;

		public var redOffset : Number;

		public function get color () : uint;
		public function set color (newColor:uint) : void;

		public function ColorTransform (redMultiplier:Number = 1, greenMultiplier:Number = 1, blueMultiplier:Number = 1, alphaMultiplier:Number = 1, redOffset:Number = 0, greenOffset:Number = 0, blueOffset:Number = 0, alphaOffset:Number = 0);

		public function concat (second:ColorTransform) : void;

		public function toString () : String;
	}
}
