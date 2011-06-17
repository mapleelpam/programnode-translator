//
// D:\test\lib\playerglobal.swc\flash\utils\Timer
//
package flash.utils
{
	import flash.events.EventDispatcher;

	/**
	 Dispatched whenever it has completed the number of requests set by Timer.repeatCount.
	 @eventType	flash.events.TimerEvent.TIMER_COMPLETE
	 */
	[Event(name="timerComplete", type="flash.events.TimerEvent")] 

	/**
	 Dispatched whenever a Timer object reaches an interval specified according to the Timer.delay property.
	 @eventType	flash.events.TimerEvent.TIMER
	 */
	[Event(name="timer", type="flash.events.TimerEvent")] 

	public class Timer extends EventDispatcher
	{
		/**
		 The total number of times the timer has fired since it started
	 at zero. If the timer has been reset, only the fires since
	 the reset are counted.
		 */
		[native(support="none")]
		public function get currentCount () : int;

		/**
		 The delay, in milliseconds, between timer
	 events. If you set the delay interval while
     the timer is running, the timer will restart
     at the same repeatCount iteration.
		 */
		[native(support="none")]
		public function get delay () : Number;
		[native(support="none")]
		public function set delay (value:Number) : void;

		/**
		 The total number of times the timer is set to run.
         If the repeat count is set to 0, the timer continues forever 
         or until the stop() method is invoked or the program stops.
         If the repeat count is nonzero, the timer runs the specified number of times. 
         If repeatCount is set to a total that is the same or less then currentCount
         the timer stops and will not fire again.
		 */
		[native(support="none")]
		public function get repeatCount () : int;
		[native(support="none")]
		public function set repeatCount (value:int) : void;

		/// The timer's current state; true if the timer is running, otherwise false.
		[native(support="none")]
		public function get running () : Boolean;

		public function reset () : void;

		public function start () : void;

		public function stop () : void;

		public function Timer (delay:Number, repeatCount:int = 0);
	}
}
