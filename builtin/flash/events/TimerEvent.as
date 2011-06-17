//
// D:\test\lib\playerglobal.swc\flash\events\TimerEvent
//
package flash.events
{
	import flash.events.Event;

	/// @eventType	flash.events.TimerEvent.TIMER
	[Event(name="timer", type="flash.events.TimerEvent")] 

	/// @eventType	flash.events.TimerEvent.TIMER_COMPLETE
	[Event(name="timerComplete", type="flash.events.TimerEvent")] 

	public class TimerEvent extends Event
	{
		/**
		 Defines the value of the type property of a timer event object.
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe Timer object that has reached its interval.
		 */
		public static const TIMER : String = "timer";

		/**
		 Defines the value of the type property of a timerComplete event object.
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe Timer object that has completed its requests.
		 */
		public static const TIMER_COMPLETE : String = "timerComplete";

		public function clone () : Event;

		public function TimerEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false);

		public function toString () : String;
		[native(support="none")]
		public function updateAfterEvent () : void;
	}
}
