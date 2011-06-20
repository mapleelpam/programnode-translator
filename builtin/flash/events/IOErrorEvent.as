package flash.events
{
	import flash.events.Event;

	intrinsic public class IOErrorEvent extends ErrorEvent
	{
		[native(support="none")]
		public static const DISK_ERROR : String;

		public static const IO_ERROR : String = "ioError";
		[native(support="none")]
		public static const NETWORK_ERROR : String;
		[native(support="none")]
		public static const VERIFY_ERROR : String;

		public function clone () : Event;

		public function IOErrorEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, text:String = "", id:int = 0);

		public function toString () : String;
	}
}
