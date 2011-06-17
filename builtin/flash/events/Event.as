//
// D:\test\lib\playerglobal.swc\flash\events\Event
//
package flash.events
{
	import flash.events.Event;

	/// @eventType	flash.events.Event.ACTIVATE
	[Event(name="activate", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.ADDED
	[Event(name="added", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.ADDED_TO_STAGE
	[Event(name="addedToStage", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.CANCEL
	[Event(name="cancel", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.CHANGE
	[Event(name="change", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.CLEAR
	[Event(name="copy", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.CLOSE
	[Event(name="close", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.CLOSING
	[Event(name="closing", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.COMPLETE
	[Event(name="complete", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.CONNECT
	[Event(name="connect", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.COPY
	[Event(name="copy", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.CUT
	[Event(name="cut", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.DEACTIVATE
	[Event(name="deactivate", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.DISPLAYING
	[Event(name="displaying", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.ENTER_FRAME
	[Event(name="enterFrame", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.EXITING
	[Event(name="exiting", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.EXIT_FRAME
	[Event(name="exitFrame", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.FRAME_CONSTRUCTED
	[Event(name="frameConstructed", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.FULLSCREEN
	[Event(name="fullScreen", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.HTML_BOUNDS_CHANGE
	[Event(name="htmlBoundsChange", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.HTML_DOM_INITIALIZE
	[Event(name="htmlDOMInitialize", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.HTML_RENDER
	[Event(name="htmlRender", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.ID3
	[Event(name="id3", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.INIT
	[Event(name="init", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.LOCATION_CHANGE
	[Event(name="locationChange", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.MOUSE_LEAVE
	[Event(name="mouseLeave", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.NETWORK_CHANGE
	[Event(name="networkChange", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.OPEN
	[Event(name="open", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.PASTE
	[Event(name="paste", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.REMOVED
	[Event(name="removed", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.REMOVED_FROM_STAGE
	[Event(name="removedFromStage", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.RENDER
	[Event(name="render", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.RESIZE
	[Event(name="resize", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.SCROLL
	[Event(name="scroll", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.SELECT
	[Event(name="select", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.SELECT_ALL
	[Event(name="selectAll", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.SOUND_COMPLETE
	[Event(name="soundComplete", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.TAB_CHILDREN_CHANGE
	[Event(name="tabChildrenChange", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.TAB_ENABLED_CHANGE
	[Event(name="tabEnabledChange", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.TAB_INDEX_CHANGE
	[Event(name="tabIndexChange", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.UNLOAD
	[Event(name="unload", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.USER_IDLE
	[Event(name="userIdle", type="flash.events.Event")] 

	/// @eventType	flash.events.Event.USER_PRESENT
	[Event(name="userIdle", type="flash.events.Event")] 

	public class Event extends Object
	{
		/**
		 The ACTIVATE constant defines the value of the type property of an activate event object. 
	Note: This event has neither a "capture phase" nor a "bubble phase",
	which means that event listeners must be added directly to any potential targets, 
	whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny DisplayObject instance with a listener registered for the activate event.
		 */
		public static const ACTIVATE : String = "activate";

		/**
		 The Event.ADDED constant defines the value of the type property of 
	an added event object. 
	
	The added event applies to the ActionScript 3.0 display list
	and is not relevant to JavaScript code.This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe DisplayObject instance being added to the display list.
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const ADDED : String = "added";

		/**
		 The Event.ADDED_TO_STAGE constant defines the value of the type 
	property of an addedToStage event object. 
	
	The addedToStage event applies to the ActionScript 3.0 display list
	and is not relevant to JavaScript code.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe DisplayObject instance being added to the on stage display list,
	either directly or through the addition of a sub tree in which the DisplayObject instance is contained.
	If the DisplayObject instance is being directly added, the added event occurs before this event.
		 */
		public static const ADDED_TO_STAGE : String = "addedToStage";

		/**
		 The Event.CANCEL constant defines the value of the type property of a cancel event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetA reference to the object on which the operation is canceled.
		 */
		public static const CANCEL : String = "cancel";

		/**
		 The Event.CHANGE constant defines the value of the type property of a change event object. 
	
	This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe object that has had its value modified. 
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const CHANGE : String = "change";

		/**
		 The Event.CLEAR constant efines the value of the type property 
	of a clear event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny InteractiveObject instance with a listener registered for the clear event.Note: TextField objects do not dispatch clear, copy, cut, paste,
	or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
	You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands 
	(or their keyboard equivalents) does not generate clear, copy, cut, paste, 
	or selectAll events. However, other classes that extend the InteractiveObject class, including components built 
	using the Flash Text Engine (FTE), can dispatch these events.
		 */
		public static const CLEAR : String = "clear";

		/**
		 The Event.CLOSE constant defines the value of the type property of a close event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe object whose connection has been closed.
		 */
		public static const CLOSE : String = "close";

		/**
		 The Event.COMPLETE constant defines the value of the type property of a complete event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe network object that has completed loading.
		 */
		public static const COMPLETE : String = "complete";

		/**
		 The Event.CONNECT constant defines the value of the type property of a connect event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe Socket or XMLSocket object that has established a network connection.
		 */
		public static const CONNECT : String = "connect";

		/**
		 Defines the value of the type property of a copy event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny InteractiveObject instance with a listener registered for the copy event.Note: TextField objects do not dispatch clear, copy, cut, paste,
	or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
	You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands 
	(or their keyboard equivalents) does not generate clear, copy, cut, paste, 
	or selectAll events. However, other classes that extend the InteractiveObject class, including components built 
	using the Flash Text Engine (FTE), can dispatch these events.
		 */
		public static const COPY : String = "copy";

		/**
		 Defines the value of the type property of a cut event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny InteractiveObject instance with a listener registered for the cut event.Note: TextField objects do not dispatch clear, copy, cut, paste,
	or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
	You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands 
	(or their keyboard equivalents) does not generate clear, copy, cut, paste, 
	or selectAll events. However, other classes that extend the InteractiveObject class, including components built 
	using the Flash Text Engine (FTE), can dispatch these events.
		 */
		public static const CUT : String = "cut";

		/**
		 The Event.DEACTIVATE constant defines the value of the type property of a deactivate event object. 
	Note: This event has neither a "capture phase" nor a "bubble phase",
	which means that event listeners must be added directly to any potential targets, 
	whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny DisplayObject instance with a listener registered for the deactivate event.
		 */
		public static const DEACTIVATE : String = "deactivate";

		/**
		 The Event.ENTER_FRAME constant defines the value of the type property of an enterFrame event object. 
	Note: This event has neither a "capture phase" nor a "bubble phase",
	which means that event listeners must be added directly to any potential targets, 
	whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny DisplayObject instance with a listener registered for the enterFrame event.
		 */
		public static const ENTER_FRAME : String = "enterFrame";

		/**
		 The Event.EXIT_FRAME constant defines the value of the type property of an exitFrame event object. 
	Note: This event has neither a "capture phase" nor a "bubble phase",
	which means that event listeners must be added directly to any potential targets, 
	whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny DisplayObject instance with a listener registered for the enterFrame event.
		 */
		public static const EXIT_FRAME : String = "exitFrame";

		/**
		 The Event.FRAME_CONSTRUCTED constant defines the value of the type property of an frameConstructed event object. 
	
	Note: This event has neither a "capture phase" nor a "bubble phase",
	which means that event listeners must be added directly to any potential targets, 
	whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny DisplayObject instance with a listener registered for the frameConstructed event.
		 */
		public static const FRAME_CONSTRUCTED : String = "frameConstructed";

		/**
		 The Event.FULL_SCREEN constant defines the value of the type property of a fullScreen event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe Stage object.
		 */
		public static const FULLSCREEN : String = "fullScreen";

		/**
		 The Event.ID3 constant defines the value of the type property of an id3 event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe Sound object loading the MP3 for which ID3 data is now available. 
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const ID3 : String = "id3";

		/**
		 The Event.INIT constant defines the value of the type property of an init event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe LoaderInfo object associated with the SWF file being loaded.
		 */
		public static const INIT : String = "init";

		/**
		 The Event.MOUSE_LEAVE constant defines the value of the type property of a mouseLeave event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe Stage object. 
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const MOUSE_LEAVE : String = "mouseLeave";

		/**
		 The Event.OPEN constant defines the value of the type property of an open event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe network object that has opened a connection.
		 */
		public static const OPEN : String = "open";

		/**
		 The Event.PASTE constant defines the value of the type property of a paste event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny InteractiveObject instance with a listener registered for the paste event.Note: TextField objects do not dispatch clear, copy, cut, paste,
	or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
	You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands 
	(or their keyboard equivalents) does not generate clear, copy, cut, paste, 
	or selectAll events. However, other classes that extend the InteractiveObject class, including components built 
	using the Flash Text Engine (FTE), can dispatch these events.
		 */
		public static const PASTE : String = "paste";

		/**
		 The Event.REMOVED constant defines the value of the type property of
	a removed event object. 
	
	The removed event applies to the ActionScript 3.0 display list
	and is not relevant to JavaScript code.This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe DisplayObject instance to be removed from the display list. 
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const REMOVED : String = "removed";

		/**
		 The Event.REMOVED_FROM_STAGE constant defines the value of the type 
	property of a removedFromStage event object. 
	
	The removedFromStage event applies to the ActionScript 3.0 display list
	and is not relevant to JavaScript code.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe DisplayObject instance being removed from the on stage display list,
	either directly or through the removal of a sub tree in which the DisplayObject instance is contained.
	If the DisplayObject instance is being directly removed, the removed event occurs before this event.
		 */
		public static const REMOVED_FROM_STAGE : String = "removedFromStage";

		/**
		 The Event.RENDER constant defines the value of the type property of a render event object. 
	Note: This event has neither a "capture phase" nor a "bubble phase",
	which means that event listeners must be added directly to any potential targets, 
	whether the target is on the display list or not.This event has the following properties:PropertyValuebubblesfalsecancelablefalse; the default behavior cannot be canceled.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny DisplayObject instance with a listener registered for the render event.
		 */
		public static const RENDER : String = "render";

		/**
		 The Event.RESIZE constant defines the value of the type property of a resize event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe Stage object.
		 */
		public static const RESIZE : String = "resize";

		/**
		 The Event.SCROLL constant defines the value of the type property of a scroll event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe TextField object that has been scrolled. 
	The target property is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const SCROLL : String = "scroll";

		/**
		 The Event.SELECT constant defines the value of the type property of a select event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe object on which an item has been selected.
		 */
		public static const SELECT : String = "select";

		/**
		 The Event.SELECT_ALL constant defines the value of the type property of a selectAll event object. 
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetAny InteractiveObject instance with a listener registered for the selectAll event.Note: TextField objects do not dispatch clear, copy, cut, paste,
	or selectAll events. TextField objects always include Cut, Copy, Paste, Clear, and Select All commands in the context menu.
	You cannot remove these commands from the context menu for TextField objects. For TextField objects, selecting these commands 
	(or their keyboard equivalents) does not generate clear, copy, cut, paste, 
	or selectAll events. However, other classes that extend the InteractiveObject class, including components built 
	using the Flash Text Engine (FTE), can dispatch these events.
		 */
		public static const SELECT_ALL : String = "selectAll";

		/**
		 The Event.SOUND_COMPLETE constant defines the value of the type property of a soundComplete event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe SoundChannel object in which a sound has finished playing.
		 */
		public static const SOUND_COMPLETE : String = "soundComplete";

		/**
		 The Event.TAB_CHILDREN_CHANGE constant defines the value of the type property of a tabChildrenChange event object. 
	This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe object whose tabChildren flag has changed. 
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const TAB_CHILDREN_CHANGE : String = "tabChildrenChange";

		/**
		 The Event.TAB_ENABLED_CHANGE constant defines the value of the type 
	property of a tabEnabledChange event object. 
	
	The tabEnabledChange event applies to the ActionScript 3.0 display list
	and is not relevant to JavaScript code.This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe InteractiveObject whose tabEnabled flag has changed. 
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const TAB_ENABLED_CHANGE : String = "tabEnabledChange";

		/**
		 The Event.TAB_INDEX_CHANGE constant defines the value of the 
	type property of a tabIndexChange event object. 
	
	The tabIndexChange event applies to the ActionScript 3.0 display list
	and is not relevant to JavaScript code.This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe object whose tabIndex has changed. 
	The target is not always the object in the display list 
	that registered the event listener. Use the currentTarget 
	property to access the object in the display list that is currently processing the event.
		 */
		public static const TAB_INDEX_CHANGE : String = "tabIndexChange";

		/**
		 The Event.UNLOAD constant defines the value of the type property of an unload event object. 
	
	This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
	object with an event listener.targetThe LoaderInfo object associated with the SWF file being unloaded or replaced.
		 */
		public static const UNLOAD : String = "unload";

		/**
		 Indicates whether an event is a bubbling event. If the event can bubble, 
	this value is true; otherwise it is false.
	
	Event bubbling is defined for display objects in SWF content,
	which uses the ActionScript 3.0 display object model. The bubbles property
	is only relavent in ActionScript 3.0 code.When an event occurs, it moves through the three phases of the event flow: the capture 
	phase, which flows from the top of the display list hierarchy to the node just before the 
	target node; the target phase, which comprises the target node; and the bubbling phase, 
	which flows from the node subsequent to the target node back up the display list hierarchy.Some events, such as the activate and unload events, do not 
	have a bubbling phase. The bubbles property has a value of 
	false for events that do not have a bubbling phase.
		 */
		public function get bubbles () : Boolean;

		/**
		 Indicates whether the behavior associated with the event can be prevented. 
	If the behavior can be canceled, this value is true; otherwise it is false.
		 */
		public function get cancelable () : Boolean;

		/// The object that is actively processing the Event object with an event listener. For example, if a user clicks an OK button, the current target could be the node containing that button or one of its ancestors that has registered an event listener for that event.
		public function get currentTarget () : Object;

		/**
		 The current phase in the event flow. This property can contain the following numeric values:
	 The capture phase (EventPhase.CAPTURING_PHASE). The target phase (EventPhase.AT_TARGET). The bubbling phase (EventPhase.BUBBLING_PHASE).The event flow is defined for display objects in SWF content, which use
	the ActionScript 3.0 display object model. The eventPhase property
	is only relavent in ActionScript 3.0 code.
		 */
		public function get eventPhase () : uint;

		/// The event target. This property contains the target node. For example, if a user clicks an OK button, the target node is the display list node containing that button.
		public function get target () : Object;

		/// The type of event. The type is case-sensitive.
		public function get type () : String;

		public function clone () : Event;

		public function Event (type:String, bubbles:Boolean = false, cancelable:Boolean = false);
		[native(support="none")]
		public function formatToString (className:String, ...rest) : String;
		[native(support="none")]
		public function isDefaultPrevented () : Boolean;
		[native(support="none")]
		public function preventDefault () : void;

		public function stopImmediatePropagation () : void;

		public function stopPropagation () : void;

		public function toString () : String;
	}
}
