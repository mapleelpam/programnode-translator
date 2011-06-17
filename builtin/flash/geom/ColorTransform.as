//
// D:\test\lib\playerglobal.swc\flash\geom\ColorTransform
//
package flash.geom
{
	import flash.geom.ColorTransform;

	public class ColorTransform extends Object
	{
		/**
		 A decimal value that is multiplied with the alpha transparency channel value.
	 
	 If you set the alpha transparency value of a display object directly by using the 
	 alpha property of the DisplayObject instance, it affects the value of the 
	 alphaMultiplier property of that display object's transform.colorTransform 
	 property.
		 */
		public var alphaMultiplier : Number;

		/**
		 A number from -255 to 255 that is added to the alpha transparency channel value after it has 
	 been multiplied by the alphaMultiplier value.
		 */
		public var alphaOffset : Number;

		/// A decimal value that is multiplied with the blue channel value.
		public var blueMultiplier : Number;

		/**
		 A number from -255 to 255 that is added to the blue channel value after it has 
	 been multiplied by the blueMultiplier value.
		 */
		public var blueOffset : Number;

		/// A decimal value that is multiplied with the green channel value.
		public var greenMultiplier : Number;

		/**
		 A number from -255 to 255 that is added to the green channel value after it has 
	 been multiplied by the greenMultiplier value.
		 */
		public var greenOffset : Number;

		/// A decimal value that is multiplied with the red channel value.
		public var redMultiplier : Number;

		/**
		 A number from -255 to 255 that is added to the red channel value after it has been 
	 multiplied by the redMultiplier value.
		 */
		public var redOffset : Number;

		/**
		 The RGB color value for a ColorTransform object.
	 
	 When you set this property, it changes the three color offset values (redOffset, 
	 greenOffset, and blueOffset)
	 accordingly, and it sets the three color multiplier values (redMultiplier, 
	 greenMultiplier, and blueMultiplier) to 0. 
	 The alpha transparency multiplier and offset values do not change.When you pass a value for this property, use the format 0xRRGGBB.  
	 RR, GG, and BB each consist 
	 of two hexadecimal digits that specify the offset of each color component. The 0x 
	 tells the ActionScript compiler that the number is a hexadecimal value.
		 */
		public function get color () : uint;
		public function set color (newColor:uint) : void;

		public function ColorTransform (redMultiplier:Number = 1, greenMultiplier:Number = 1, blueMultiplier:Number = 1, alphaMultiplier:Number = 1, redOffset:Number = 0, greenOffset:Number = 0, blueOffset:Number = 0, alphaOffset:Number = 0);

		public function concat (second:ColorTransform) : void;

		public function toString () : String;
	}
}
