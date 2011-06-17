//
// D:\test\lib\playerglobal.swc\flash\events\ProgressEvent
//
package flash.events
{
	import flash.events.Event;

	/// @eventType	flash.events.ProgressEvent.PROGRESS
	[Event(name="progress", type="flash.events.ProgressEvent")] 

	/// @eventType	flash.events.ProgressEvent.SOCKET_DATA
	[Event(name="socketData", type="flash.events.ProgressEvent")] 

	public class ProgressEvent extends Event
	{
		/**
		 Defines the value of the type property of a progress event object.
	
	This event has the following properties:PropertyValuebubblesfalsebytesLoadedThe number of items or bytes loaded at the time the listener processes the event.bytesTotalThe total number of items or bytes that ultimately will  be loaded if the loading process succeeds.cancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe object reporting progress.
		 */
		public static const PROGRESS : String = "progress";

		/**
		 Defines the value of the type property of a socketData event object.
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event.bytesLoadedThe number of items or bytes loaded at the time the listener processes the event.bytesTotal0; this property is not used by socketData event objects.targetThe Socket object reporting progress.
		 */
		public static const SOCKET_DATA : String = "socketData";

		/// The number of items or bytes loaded when the listener processes the event.
		[native(support="none")]
		public function get bytesLoaded () : Number;
		[native(support="none")]
		public function set bytesLoaded (value:Number) : void;

		/**
		 The total number of items or bytes that will be loaded if the loading process succeeds. 
	If the progress event is dispatched/attached to a Socket object, the bytesTotal will always be 0 
	unless a value is specified in the bytesTotal parameter of the constructor. 
	The actual number of bytes sent back or forth is not set and is up to the application developer.
		 */
	[native(support="none")]
		public function get bytesTotal () : Number;
		[native(support="none")]
		public function set bytesTotal (value:Number) : void;

		public function clone () : Event;

		public function ProgressEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, bytesLoaded:Number = 0, bytesTotal:Number = 0);

		public function toString () : String;
	}
}
