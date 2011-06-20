package flash.display
{
	import flash.events.EventDispatcher;
	import flash.display.IBitmapDrawable;
	import flash.display.DisplayObject;
	import flash.display.Stage;
	import flash.display.DisplayObjectContainer;
	import flash.geom.Rectangle;
	import flash.geom.Transform;
	import flash.geom.Point;
	import flash.display.LoaderInfo;
	import flash.accessibility.AccessibilityProperties;
	import flash.geom.Vector3D;
	import flash.display.Shader;

	intrinsic public class DisplayObject extends EventDispatcher implements IBitmapDrawable
	{
		[native(support="none")]
		public function get accessibilityProperties () : AccessibilityProperties;
		[native(support="none")]
		public function set accessibilityProperties (value:AccessibilityProperties) : void;

		[native(support="api")]
		public function get alpha () : Number;
		[native(support="api")]
		public function set alpha (value:Number) : void;

		[native(support="api")]
		public function get blendMode () : String;
		[native(support="api")]
		public function set blendMode (value:String) : void;

		[native(support="none")]
		public function set blendShader (value:Shader) : void;

		[native(support="none")]
		public function get cacheAsBitmap () : Boolean;
		[native(support="none")]
		public function set cacheAsBitmap (value:Boolean) : void;

		[native(support="api")]
		public function get filters () : Array;
		[native(support="api")]
		public function set filters (value:Array) : void;

		public function get height () : Number;
		public function set height (value:Number) : void;

		[native(support="none")]
		public function get loaderInfo () : LoaderInfo;

		[native(support="none")]
		public function get mask () : DisplayObject;
		[native(support="none")]
		public function set mask (value:DisplayObject) : void;

		[native(support="none")]
		public function get mouseX () : Number;

		[native(support="none")]
		public function get mouseY () : Number;

		public function get name () : String;
		public function set name (value:String) : void;

		[native(support="none")]
		public function get opaqueBackground () : Object;
		[native(support="none")]
		public function set opaqueBackground (value:Object) : void;

		public function get parent () : DisplayObjectContainer;

		public function get root () : DisplayObject;

		public function get rotation () : Number;
		public function set rotation (value:Number) : void;

		[native(support="none")]
		public function get rotationX () : Number;
		[native(support="none")]
		public function set rotationX (value:Number) : void;

		[native(support="none")]
		public function get rotationY () : Number;
		[native(support="none")]
		public function set rotationY (value:Number) : void;

		[native(support="none")]
		public function get rotationZ () : Number;
		[native(support="none")]
		public function set rotationZ (value:Number) : void;

		[native(support="none")]
		public function get scale9Grid () : Rectangle;
		[native(support="none")]
		public function set scale9Grid (innerRectangle:Rectangle) : void;

		public function get scaleX () : Number;
		public function set scaleX (value:Number) : void;

		public function get scaleY () : Number;
		public function set scaleY (value:Number) : void;

		[native(support="none")]
		public function get scaleZ () : Number;
		[native(support="none")]
		public function set scaleZ (value:Number) : void;

		[native(support="none")]
		public function get scrollRect () : Rectangle;
		[native(support="none")]
		public function set scrollRect (value:Rectangle) : void;

		public function get stage () : Stage;

		public function get transform () : Transform;
		public function set transform (value:Transform) : void;

		public function get visible () : Boolean;
		public function set visible (value:Boolean) : void;

		public function get width () : Number;
		public function set width (value:Number) : void;

		public function get x () : Number;
		public function set x (value:Number) : void;

		public function get y () : Number;
		public function set y (value:Number) : void;

		[native(support="none")]
		public function get z () : Number;
		[native(support="none")]
		public function set z (value:Number) : void;

		public function DisplayObject ();

		public function getBounds (targetCoordinateSpace:DisplayObject) : Rectangle;

		public function getRect (targetCoordinateSpace:DisplayObject) : Rectangle;

		public function globalToLocal (point:Point) : Point;

		[native(support="none")]
		public function globalToLocal3D (point:Point) : Vector3D;

		public function hitTestObject (obj:DisplayObject) : Boolean;

		public function hitTestPoint (x:Number, y:Number, shapeFlag:Boolean = false) : Boolean;

		[native(support="none")]
		public function local3DToGlobal (point3d:Vector3D) : Point;

		[native(support="none")]
		public function localToGlobal (point:Point) : Point;
	}
}
