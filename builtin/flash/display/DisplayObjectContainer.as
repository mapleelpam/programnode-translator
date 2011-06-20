package flash.display
{
	import flash.display.DisplayObject;
	import flash.text.TextSnapshot;
	import flash.geom.Point;

	intrinsic public class DisplayObjectContainer extends InteractiveObject
	{
		[native(support="none")]
		public function get mouseChildren () : Boolean;
		[native(support="none")]
		public function set mouseChildren (enable:Boolean) : void;

		public function get numChildren () : int;

		[native(support="none")]
		public function get tabChildren () : Boolean;
		[native(support="none")]
		public function set tabChildren (enable:Boolean) : void;

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
