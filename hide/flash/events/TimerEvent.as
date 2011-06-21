package flash.events
{
	import flash.events.Event;

	intrinsic public class TimerEvent extends Event
	{
		public static const TIMER : String = "timer";

		public static const TIMER_COMPLETE : String = "timerComplete";

		public function clone () : Event;

		public function TimerEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false);

		public function toString () : String;
		[native(support="none")]
		public function updateAfterEvent () : void;
	}
}
