package flash.geom
{
	import flash.geom.ColorTransform;

	intrinsic public class ColorTransform extends Object
	{
//		public var alphaMultiplier : Number;
//
//		public var alphaOffset : Number;
//
//		public var blueMultiplier : Number;
//
//		public var blueOffset : Number;
//
//		public var greenMultiplier : Number;
//
//		public var greenOffset : Number;
//
//		public var redMultiplier : Number;
//
//		public var redOffset : Number;
		
		public function get alphaMultiplier () : Number;
		public function set alphaMultiplier (newAlphaMultiplier:Number) : void;
		
		public function get alphaOffset () : Number;
		public function set alphaOffset (newAlphaOffset:Number) : void;
		
		public function get blueMultiplier () : Number;
		public function set blueMultiplier (newBlueMultiplier:Number) : void;
		
		public function get blueOffset () : Number;
		public function set blueOffset (newBlueOffset:Number) : void;
		
		public function get greenMultiplier () : Number;
		public function set greenMultiplier (newGreenMultiplier:Number) : void;
		
		public function get greenOffset () : Number;
		public function set greenOffset (newGreenOffsetr:Number) : void;
		
		public function get redMultiplier () : Number;
		public function set redMultiplier (newRedMultiplier:Number) : void;
		
		public function get redOffset () : Number;
		public function set redOffset (newRedOffset:Number) : void;
	
		public function get color () : uint;
		public function set color (newColor:uint) : void;

		public function ColorTransform (redMultiplier:Number = 1, greenMultiplier:Number = 1, blueMultiplier:Number = 1, alphaMultiplier:Number = 1, redOffset:Number = 0, greenOffset:Number = 0, blueOffset:Number = 0, alphaOffset:Number = 0);

		public function concat (second:ColorTransform) : void;

		public function toString () : String;
	}
}
