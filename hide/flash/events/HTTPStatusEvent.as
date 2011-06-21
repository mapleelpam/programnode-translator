package flash.events
{
	import flash.events.Event;

	intrinsic public class HTTPStatusEvent extends Event
	{
		[native(support="none")]
		public static const HTTP_RESPONSE_STATUS : String = "httpResponseStatus";

		public static const HTTP_STATUS : String = "httpStatus";

		[native(support="none")]
		public function get responseHeaders () : Array;
		[native(support="none")]
		public function set responseHeaders (value:Array) : void;

		[native(support="none")]
		public function get responseURL () : String;
		[native(support="none")]
		public function set responseURL (value:String) : void;

		[native(support="none")]
		public function get status () : int;

		public function clone () : Event;

		public function HTTPStatusEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, status:int = 0);

		public function toString () : String;
	}
}
