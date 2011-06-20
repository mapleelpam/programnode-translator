package flash.events
{
	import flash.events.Event;

	intrinsic public class ErrorEvent extends TextEvent
	{
		public static const ERROR : String = "error";

		[native(support="none")]
		public function get errorID () : int;

		public function clone () : Event;

		public function ErrorEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, text:String = "", id:int = 0);

		public function toString () : String;
	}
}
