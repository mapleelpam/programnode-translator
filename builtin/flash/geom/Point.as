intrinsic class flash.geom.Point {

//	var x : Number;
//	var y : Number;
//	var length : Number;

	public function get x () : Number;
	public function set x (newX:Number) : void;
	
	public function get y () : Number;
	public function set y (newY:Number) : void;
	
	public function get length () : Number;
	public function set length (newLength:Number) : void;
	
	function Point( x : Number, y : Number );

	function normalize( length : Number ) : Void;
	function add( p : Point ) : Point;
	function subtract( p : Point ) : Point;
	function equals( p : Object ) : Boolean;
	function offset( dx : Number, dy : Number ) : Void;
	function clone() : Point;
	function toString() : String;


	static function distance( p1 : Point, p2 : Point ) : Number;
	static function interpolate( p1 : Point, p2 : Point, f : Number ) : Point;
	static function polar( dist : Number, angle : Number ) : Point;

}
