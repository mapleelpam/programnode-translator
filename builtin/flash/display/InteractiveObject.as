package flash.display
{
//	import flash.accessibility.AccessibilityImplementation;
	import flash.ui.ContextMenu;

	intrinsic public class InteractiveObject extends DisplayObject
	{
/*
		[native(support="none")]
		public function get accessibilityImplementation () : AccessibilityImplementation;
		[native(support="none")]
		public function set accessibilityImplementation (value:AccessibilityImplementation) : void;
*/

		[native(support="none")]
		public function get contextMenu () : ContextMenu;
		[native(support="none")]
		public function set contextMenu (cm:ContextMenu) : void;

		[native(support="none")]
		public function get doubleClickEnabled () : Boolean;
		[native(support="none")]
		public function set doubleClickEnabled (enabled:Boolean) : void;

		[native(support="none")]
		public function get focusRect () : Object;
		[native(support="none")]
		public function set focusRect (focusRect:Object) : void;

		[native(support="none")]
		public function get mouseEnabled () : Boolean;
		[native(support="none")]
		public function set mouseEnabled (enabled:Boolean) : void;

		[native(support="none")]
		public function get tabEnabled () : Boolean;
		[native(support="none")]
		public function set tabEnabled (enabled:Boolean) : void;

		[native(support="none")]
		public function get tabIndex () : int;
		[native(support="none")]
		public function set tabIndex (index:int) : void;

		public function InteractiveObject ();
	}
}
