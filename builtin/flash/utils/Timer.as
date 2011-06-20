package flash.utils
{
	import flash.events.EventDispatcher;

	intrinsic public class Timer extends EventDispatcher
	{
		[native(support="none")]
		public function get currentCount () : int;

		[native(support="none")]
		public function get delay () : Number;
		[native(support="none")]
		public function set delay (value:Number) : void;

		[native(support="none")]
		public function get repeatCount () : int;
		[native(support="none")]
		public function set repeatCount (value:int) : void;

		[native(support="none")]
		public function get running () : Boolean;

		public function reset () : void;

		public function start () : void;

		public function stop () : void;

		public function Timer (delay:Number, repeatCount:int = 0);
	}
}
