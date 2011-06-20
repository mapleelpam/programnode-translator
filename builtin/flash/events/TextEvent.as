package flash.events
{
	import flash.events.Event;
	import flash.events.TextEvent;

	intrinsic public class TextEvent extends Event
	{
		[native(support="none")]
		public static const LINK : String = "link";

		[native(support="none")]
		public static const TEXT_INPUT : String = "textInput";

		[native(support="none")]
		public function get text () : String;
		[native(support="none")]
		public function set text (value:String) : void;

		public function clone () : Event;

		public function TextEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, text:String = "");

		public function toString () : String;
	}
}
