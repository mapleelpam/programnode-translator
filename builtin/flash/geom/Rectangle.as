//
// D:\test\lib\playerglobal.swc\flash\geom\Rectangle
//
package flash.geom
{
	import flash.geom.Point;
	import flash.geom.Rectangle;

	public class Rectangle extends Object
	{
		/**
		 The height of the rectangle, in pixels. Changing the height value of a Rectangle
	object has no effect on the x, y, and
	width properties.
		 */
		public var height : Number;

		/**
		 The width of the rectangle, in pixels. Changing the width value of a Rectangle object
	has no effect on the x, y, and height 
	properties.
		 */
		public var width : Number;

		/**
		 The x coordinate of the top-left corner of the rectangle. Changing
	the value of the x property of a Rectangle object has no effect on the 
	y, 
	width, and height properties. 
	
	The value of the x property is equal to the value of the 
	left property.
		 */
		public var x : Number;

		/**
		 The y coordinate of the top-left corner of the rectangle. Changing
	the value of the y property of a Rectangle object has no effect on the  
	x, width, and height properties.
	
	The value of the y property is equal to the value of 
	the top property.
		 */
		public var y : Number;

		/**
		 The sum of the y and 
	height properties.
		 */
		public function get bottom () : Number;
		public function set bottom (value:Number) : void;

		/**
		 The location of the Rectangle object's bottom-right corner, determined by the values of the right and 
	bottom properties.
		 */
		public function get bottomRight () : Point;
		public function set bottomRight (value:Point) : void;

		/**
		 The x coordinate of the top-left corner of the rectangle. Changing
	the left property of a Rectangle object has no effect on the y 
	and height properties. However it does affect the width 
	property, whereas changing the x value does not affect the 
	width property.
	
	The value of the left property is equal to the value of the 
	x property.
		 */
		public function get left () : Number;
		public function set left (value:Number) : void;

		/**
		 The sum of the x and 
	width properties.
		 */
		public function get right () : Number;
		public function set right (value:Number) : void;

		/**
		 The size of the Rectangle object, expressed as a Point object with the values 
	of the width and height properties.
		 */
		public function get size () : Point;
		public function set size (value:Point) : void;

		/**
		 The y coordinate of the top-left corner of the rectangle. Changing
	the top property of a Rectangle object has no effect on the x 
	and width properties. However it does affect the height 
	property, whereas changing the y value does not affect the 
	height property.
	
	The value of the top property is equal to the value of the y property.
		 */
		public function get top () : Number;
		public function set top (value:Number) : void;

		/**
		 The location of the Rectangle object's top-left corner, determined by the x and 
	y coordinates of the point.
		 */
		public function get topLeft () : Point;
		public function set topLeft (value:Point) : void;

		public function clone () : Rectangle;

		public function contains (x:Number, y:Number) : Boolean;

		public function containsPoint (point:Point) : Boolean;

		public function containsRect (rect:Rectangle) : Boolean;

		public function equals (toCompare:Rectangle) : Boolean;

		public function inflate (dx:Number, dy:Number) : void;

		public function inflatePoint (point:Point) : void;

		public function intersection (toIntersect:Rectangle) : Rectangle;

		public function intersects (toIntersect:Rectangle) : Boolean;

		public function isEmpty () : Boolean;

		public function offset (dx:Number, dy:Number) : void;

		public function offsetPoint (point:Point) : void;

		public function Rectangle (x:Number = 0, y:Number = 0, width:Number = 0, height:Number = 0);

		public function setEmpty () : void;

		public function toString () : String;

		public function union (toUnion:Rectangle) : Rectangle;
	}
}
