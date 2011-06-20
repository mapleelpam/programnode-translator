package flash.events
{
	import flash.events.Event;

	intrinsic public class ProgressEvent extends Event
	{
		public static const PROGRESS : String = "progress";

		public static const SOCKET_DATA : String = "socketData";

		[native(support="none")]
		public function get bytesLoaded () : Number;
		[native(support="none")]
		public function set bytesLoaded (value:Number) : void;

		[native(support="none")]
		public function get bytesTotal () : Number;
		[native(support="none")]
		public function set bytesTotal (value:Number) : void;

		public function clone () : Event;

		public function ProgressEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, bytesLoaded:Number = 0, bytesTotal:Number = 0);

		public function toString () : String;
	}
}
