package flash.events
{
	import flash.events.IEventDispatcher;
	import flash.events.Event;

	intrinsic public class EventDispatcher extends Object implements IEventDispatcher
	{
		public function addEventListener (type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false) : void;

		public function dispatchEvent (event:Event) : Boolean;

		public function EventDispatcher (target:IEventDispatcher = null);

		public function hasEventListener (type:String) : Boolean;

		public function removeEventListener (type:String, listener:Function, useCapture:Boolean = false) : void;

		[native(support="none")]
		public function toString () : String;

		[native(support="none")]
		public function willTrigger (type:String) : Boolean;
	}
}
