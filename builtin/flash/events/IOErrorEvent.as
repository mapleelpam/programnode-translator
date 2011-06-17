//
// D:\test\lib\playerglobal.swc\flash\events\IOErrorEvent
//
package flash.events
{
	import flash.events.Event;

	/// @eventType	flash.events.IOErrorEvent.IO_ERROR
	[Event(name="ioError", type="flash.events.IOErrorEvent")] 

	public class IOErrorEvent extends ErrorEvent
	{
		[native(support="none")]
		public static const DISK_ERROR : String;

		/**
		 Defines the value of the type property of an ioError event object.
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.errorIDA reference number associated with the specific error (AIR only).targetThe network object experiencing the input/output error.textText to be displayed as an error message.
		 */
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
