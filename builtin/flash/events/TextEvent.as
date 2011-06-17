//
// D:\test\lib\playerglobal.swc\flash\events\TextEvent
//
package flash.events
{
	import flash.events.Event;
	import flash.events.TextEvent;

	/// @eventType	flash.events.TextEvent.LINK
	[Event(name="link", type="flash.events.TextEvent")] 

	/// @eventType	flash.events.TextEvent.TEXT_INPUT
	[Event(name="textInput", type="flash.events.TextEvent")] 

	public class TextEvent extends Event
	{
		/**
		 Defines the value of the type property of a link event object.
	 
	 This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	 object with an event listener.targetThe text field containing the hyperlink that has been clicked. 
  	 The target is not always the object in the display list 
	 that registered the event listener. Use the currentTarget 
	 property to access the object in the display list that is currently processing the event.textThe remainder of the URL after "event:"
		 */
		[native(support="none")]
		public static const LINK : String = "link";

		/**
		 Defines the value of the type property of a textInput event object.
     Note: This event is not dispatched for the Delete or Backspace keys.This event has the following properties:PropertyValuebubblestruecancelabletrue; call the preventDefault() method 
	 to cancel default behavior.currentTargetThe object that is actively processing the Event 
	 object with an event listener.targetThe text field into which characters are being entered. 
	 The target is not always the object in the display list 
	 that registered the event listener. Use the currentTarget 
	 property to access the object in the display list that is currently processing the event.textThe character or sequence of characters entered by the user.
		 */
		[native(support="none")]
		public static const TEXT_INPUT : String = "textInput";

		/**
		 For a textInput event, the character or sequence of characters 
	 entered by the user. For a link event, the text 
	 of the event attribute of the href attribute of the 
	 <a> tag.
		 */
		[native(support="none")]
		public function get text () : String;
		[native(support="none")]
		public function set text (value:String) : void;

		public function clone () : Event;

		public function TextEvent (type:String, bubbles:Boolean = false, cancelable:Boolean = false, text:String = "");

		public function toString () : String;
	}
}
