import flash.geom.Point;

intrinsic class flash.geom.Matrix {

	// 3x2 affine 2D matrix
//	public var a : Number;
//	public var b : Number;
//	public var c : Number;
//	public var d : Number;
//	public var tx : Number;
//	public var ty : Number;
	
	
	
	
	public function get a () : Number;
	public function set a (newA:Number) : void;
	
	public function get b () : Number;
	public function set b (newB:Number) : void;
	
	public function get c () : Number;
	public function set c (newC:Number) : void;
	
	public function get d () : Number;
	public function set d (newD:Number) : void;
	
	public function get tx () : Number;
	public function set tx (newTx:Number) : void;
	
	public function get ty () : Number;
	public function set ty (newTy:Number) : void;
	
	public function Matrix(a : Number, b : Number, c : Number, d : Number, tx : Number, ty : Number);

	public function transformPoint( p : Point ) : Point;
	public function deltaTransformPoint( p : Point ) : Point;

	public function toString() : String;
	public function scale( sx : Number, sy : Number ) : Void;
	public function translate( tx : Number, ty : Number ) : Void;
	public function rotate( r : Number ) : Void;
	public function identity() : Void;
	public function invert() : Void;
	public function concat( m : Matrix ) : Void;
	public function clone() : Matrix;

	public function createGradientBox( width : Number, height : Number, rot : Number, tx : Number, ty : Number ) : Void;
	public function createBox( scalex : Number, scaley : Number, rot : Number, tx : Number, ty : Number ) : Void;

}
