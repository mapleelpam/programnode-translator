import flash.geom.Point;

intrinsic class flash.geom.Rectangle {

//	var left : Number;
//	var top : Number;
//	var right : Number;
//	var bottom : Number;
//
//	// OR
//	var x : Number;
//	var y : Number;
//	var width : Number;
//	var height : Number;
//
//	// OR
//	var size : Point;
//	var bottomRight : Point;
//	var topLeft : Point;
	
	
	public function get left () : Number;
	public function set left (newLeft:Number) : void;
	
	public function get top () : Number;
	public function set top (newTop:Number) : void;
	
	public function get right () : Number;
	public function set right (newRight:Number) : void;
	
	public function get bottom () : Number;
	public function set bottom (newBottom:Number) : void;
	
	public function get x () : Number;
	public function set x (newX:Number) : void;

	public function get y () : Number;
	public function set y (newY:Number) : void;
	
	public function get width () : Number;
	public function set width (newWidth:Number) : void;
	
	public function get height () : Number;
	public function set height (newHeight:Number) : void;
	
	public function get size () : Point;
	public function set size (newSize:Point) : void;
	
	public function get bottomRight () : Point;
	public function set bottomRight (newBottomRight:Point) : void;
	
	public function get topLeft () : Point;
	public function set topLeft (newTopLeft:Point) : void;
	

	function Rectangle( x : Number, y : Number, w : Number, h : Number );

	function equals( r : Object ) : Boolean;
	function union( r : Rectangle ) : Rectangle;
	function intersects( r : Rectangle ) : Boolean;
	function intersection( r : Rectangle ) : Rectangle;
	function containsRectangle( r : Rectangle ) : Boolean;
	function containsPoint( p : Point ) : Boolean;
	function contains( x : Number, y : Number ) : Boolean;
	function offsetPoint( p : Point ) : Void;
	function offset( x : Number, y : Number ) : Void;

	function inflatePoint( p : Point ) : Void;
	function inflate( x : Number, y : Number ) : Void;
	function isEmpty() : Boolean;
	function setEmpty() : Void;
	function clone() : Rectangle;

	function toString() : String;


}