//
// D:\test\lib\playerglobal.swc\flash\display\DisplayObjectContainer
//
package flash.display
{
	import flash.display.DisplayObject;
	import flash.text.TextSnapshot;
	import flash.geom.Point;

	public class DisplayObjectContainer extends InteractiveObject
	{
		/**
		 Determines whether or not the children of the object are mouse enabled. 
	 If an object is mouse enabled, a user can interact with it by using a mouse. The default is true.
	 
	 This property is useful when you create a button with an instance of the Sprite class
	 (instead of using the SimpleButton class). When you use a Sprite instance to create a button,
	 you can choose to decorate the button by using the addChild() method to add additional
	 Sprite instances. This process can cause unexpected behavior with mouse events because
	 the Sprite instances you add as children can become the target object of a mouse event
	 when you expect the parent instance to be the target object. To ensure that the parent
	 instance serves as the target objects for mouse events, you can set the 
	 mouseChildren property of the parent instance to false. No event is dispatched by setting this property. You must use the
	 addEventListener() method to create interactive functionality.
		 */
		[native(support="none")]
		public function get mouseChildren () : Boolean;
		[native(support="none")]
		public function set mouseChildren (enable:Boolean) : void;

		/// Returns the number of children of this object.
		public function get numChildren () : int;

		/**
		 Determines whether the children of the object are tab enabled. Enables or disables tabbing for the 
     children of the object. The default is true.
		 */
		[native(support="none")]
		public function get tabChildren () : Boolean;
		[native(support="none")]
		public function set tabChildren (enable:Boolean) : void;

		/// Returns a TextSnapshot object for this DisplayObjectContainer instance.
		[native(support="none")]
		public function get textSnapshot () : TextSnapshot;

		public function addChild (child:DisplayObject) : DisplayObject;

		public function addChildAt (child:DisplayObject, index:int) : DisplayObject;

		[native(support="none")]
		public function areInaccessibleObjectsUnderPoint (point:Point) : Boolean;

		public function contains (child:DisplayObject) : Boolean;

		public function DisplayObjectContainer ();

		public function getChildAt (index:int) : DisplayObject;

		public function getChildByName (name:String) : DisplayObject;

		public function getChildIndex (child:DisplayObject) : int;

		public function getObjectsUnderPoint (point:Point) : Array;

		public function removeChild (child:DisplayObject) : DisplayObject;

		public function removeChildAt (index:int) : DisplayObject;

		public function setChildIndex (child:DisplayObject, index:int) : void;

		public function swapChildren (child1:DisplayObject, child2:DisplayObject) : void;

		public function swapChildrenAt (index1:int, index2:int) : void;
	}
}
