//
// D:\test\lib\playerglobal.swc\flash\events\ErrorEvent
//
package flash.events
{
	import flash.events.Event;

	/// @eventType	flash.events.ErrorEvent.ERROR
	[Event(name="error", type="flash.events.ErrorEvent")] 

	public class ErrorEvent extends TextEvent
	{
		/**
		 Defines the value of the type property of an error event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe object experiencing a network operation failure.textText to be displayed as an error message.
		 */
		public static const ERROR : String = "error";

		/**
		 Contains the reference number associated with the specific error.
	For a custom ErrorEvent object, this number is the value from the id
	parameter supplied in the constructor.
		 */
		[native(support="none")]
		public function get errorID () : int;

		public function clone () : Event;

		public function ErrorEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, text:String = "", id:int = 0);

		public function toString () : String;
	}
}
