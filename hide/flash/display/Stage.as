package flash.display
{
	import flash.display.InteractiveObject;
	import flash.geom.Rectangle;
	import flash.display.DisplayObject;
	import flash.geom.Transform;
	import flash.accessibility.AccessibilityProperties;
	import flash.accessibility.AccessibilityImplementation;
	import flash.events.Event;
	import flash.text.TextSnapshot;
	import flash.ui.ContextMenu;

	intrinsic public class Stage extends DisplayObjectContainer
	{
		[native(support="none")]
		public function set accessibilityImplementation (value:AccessibilityImplementation) : void;

		[native(support="none")]
		public function set accessibilityProperties (value:AccessibilityProperties) : void;

		[native(support="none")]
		public function get align () : String;
		[native(support="none")]
		public function set align (value:String) : void;
		[native(support="api")]
		public function set alpha (value:Number) : void;
		[native(support="api")]
		public function set blendMode (value:String) : void;
		[native(support="none")]
		public function set cacheAsBitmap (value:Boolean) : void;

		[native(support="none")]
		public function get colorCorrection () : String;
		[native(support="none")]
		public function set colorCorrection (value:String) : void;

		[native(support="none")]
		public function get colorCorrectionSupport () : String;
		[native(support="none")]
		public function set contextMenu (value:ContextMenu) : void;

		[native(support="none")]
		public function get displayState () : String;
		[native(support="none")]
		public function set displayState (value:String) : void;
		
		public function set filters (value:Array) : void;

		[native(support="none")]
		public function get focus () : InteractiveObject;
		[native(support="none")]
		public function set focus (newFocus:InteractiveObject) : void;
		[native(support="none")]
		public function set focusRect (value:Object) : void;

		[native(support="none")]
		public function get frameRate () : Number;
		[native(support="none")]
		public function set frameRate (value:Number) : void;

		[native(support="none")]
		public function get fullScreenHeight () : uint;

		[native(support="none")]
		public function get fullScreenSourceRect () : Rectangle;
		[native(support="none")]
		public function set fullScreenSourceRect (value:Rectangle) : void;

		[native(support="none")]
		public function get fullScreenWidth () : uint;

		public function get height () : Number;
		public function set height (value:Number) : void;
		[native(support="none")]
		public function set mask (value:DisplayObject) : void;

		[native(support="none")]
		public function get mouseChildren () : Boolean;
		[native(support="none")]
		public function set mouseChildren (value:Boolean) : void;
		[native(support="none")]
		public function set mouseEnabled (value:Boolean) : void;

		public function set name (value:String) : void;

		public function get numChildren () : int;
		[native(support="none")]
		public function set opaqueBackground (value:Object) : void;

		[native(support="none")]
		public function get quality () : String;
		[native(support="none")]
		public function set quality (value:String) : void;

		public function set rotation (value:Number) : void;
		[native(support="none")]
		public function set rotationX (value:Number) : void;
		[native(support="none")]
		public function set rotationY (value:Number) : void;
		[native(support="none")]
		public function set rotationZ (value:Number) : void;
		[native(support="none")]
		public function set scale9Grid (value:Rectangle) : void;

		[native(support="none")]
		public function get scaleMode () : String;
		[native(support="none")]
		public function set scaleMode (value:String) : void;

		public function set scaleX (value:Number) : void;

		public function set scaleY (value:Number) : void;
		[native(support="none")]
		public function set scaleZ (value:Number) : void;
		[native(support="none")]
		public function set scrollRect (value:Rectangle) : void;

		[native(support="none")]
		public function get showDefaultContextMenu () : Boolean;
		[native(support="none")]
		public function set showDefaultContextMenu (value:Boolean) : void;

		/// Specifies whether or not objects display a glowing border when they have focus.
		[native(support="none")]
		public function get stageFocusRect () : Boolean;
		[native(support="none")]
		public function set stageFocusRect (on:Boolean) : void;

		public function get stageHeight () : int;
		public function set stageHeight (value:int) : void;

		public function get stageWidth () : int;
		public function set stageWidth (value:int) : void;

		[native(support="none")]
		public function get tabChildren () : Boolean;
		[native(support="none")]
		public function set tabChildren (value:Boolean) : void;
		[native(support="none")]
		public function set tabEnabled (value:Boolean) : void;
		[native(support="none")]
		public function set tabIndex (value:int) : void;

		[native(support="none")]
		public function get textSnapshot () : TextSnapshot;

		public function set transform (value:Transform) : void;

		public function set visible (value:Boolean) : void;

		public function get width () : Number;
		public function set width (value:Number) : void;

		[native(support="none")]
		public function get wmodeGPU () : Boolean;

		public function set x (value:Number) : void;

		public function set y (value:Number) : void;
		[native(support="none")]
		public function set z (value:Number) : void;

		public function addChild (child:DisplayObject) : DisplayObject;

		public function addChildAt (child:DisplayObject, index:int) : DisplayObject;

		public function addEventListener (type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false) : void;

		public function dispatchEvent (event:Event) : Boolean;

		public function hasEventListener (type:String) : Boolean;

		public function invalidate () : void;
		[native(support="none")]
		public function isFocusInaccessible () : Boolean;

		public function removeChildAt (index:int) : DisplayObject;

		public function setChildIndex (child:DisplayObject, index:int) : void;

		public function Stage ();

		public function swapChildrenAt (index1:int, index2:int) : void;
		[native(support="none")]
		public function willTrigger (type:String) : Boolean;
	}
}
