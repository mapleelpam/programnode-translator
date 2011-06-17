//
// D:\test\lib\playerglobal.swc\flash\net\URLLoader
//
package flash.net
{
	import flash.events.EventDispatcher;
	import flash.net.URLStream;
	import flash.net.URLRequest;
	import flash.events.Event;
	import flash.events.ProgressEvent;

	/**
	 Dispatched if a call to the load() method attempts to access data over HTTP, 
 and Adobe AIR is able to detect and return the status code for the request.
	 @eventType	flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS
	 */
	[Event(name="httpResponseStatus", type="flash.events.HTTPStatusEvent")] 

	/**
	 Dispatched if a call to URLLoader.load() 
 attempts to access data over HTTP.
	 @eventType	flash.events.HTTPStatusEvent.HTTP_STATUS
	 */
	[Event(name="httpStatus", type="flash.events.HTTPStatusEvent")] 

	/**
	 Dispatched if a call to URLLoader.load() 
 attempts to load data from a server outside the security sandbox.
	 @eventType	flash.events.SecurityErrorEvent.SECURITY_ERROR
	 */
	[Event(name="securityError", type="flash.events.SecurityErrorEvent")] 

	/**
	 Dispatched if a call to URLLoader.load()
 results in a fatal error that terminates the download.
	 @eventType	flash.events.IOErrorEvent.IO_ERROR
	 */
	[Event(name="ioError", type="flash.events.IOErrorEvent")] 

	/**
	 Dispatched when data is received as the download operation progresses.
	 @eventType	flash.events.ProgressEvent.PROGRESS
	 */
	[Event(name="progress", type="flash.events.ProgressEvent")] 

	/**
	 Dispatched after all the received data is decoded and 
 placed in the data property of the URLLoader object.
	 @eventType	flash.events.Event.COMPLETE
	 */
	[Event(name="complete", type="flash.events.Event")] 

	/**
	 Dispatched when the download operation commences following
 a call to the URLLoader.load() method.
	 @eventType	flash.events.Event.OPEN
	 */
	[Event(name="open", type="flash.events.Event")] 

	public class URLLoader extends EventDispatcher
	{
		/**
		 Indicates the number of bytes that have been loaded thus far
	 during the load operation.
		 */
		public var bytesLoaded : uint;

		/**
		 Indicates the total number of bytes in the downloaded data.
	 This property contains 0 while the load operation is in progress
	 and is populated when the operation is complete. 
	 Also, a missing Content-Length header will result in bytesTotal being indeterminate.
		 */
		public var bytesTotal : uint;

		/**
		 The data received from the load operation. This property
	 is populated only when the load operation is complete.
	 The format of the data depends on the setting of the
	 dataFormat property:
	 
	 If the dataFormat property is URLLoaderDataFormat.TEXT,
	 the received data is a string containing the text of the loaded file.If the dataFormat property is URLLoaderDataFormat.BINARY,
	 the received data is a ByteArray object containing the raw binary data.If the dataFormat property is URLLoaderDataFormat.VARIABLES,
	 the received data is a URLVariables object containing the URL-encoded variables.
		 */
		public var data : *;

		/**
		 Controls whether the downloaded data is received as
	 text (URLLoaderDataFormat.TEXT), raw binary data
	 (URLLoaderDataFormat.BINARY), or URL-encoded variables
	 (URLLoaderDataFormat.VARIABLES).
	 
	 If the value of the dataFormat property is URLLoaderDataFormat.TEXT,
	 the received data is a string containing the text of the loaded file.If the value of the dataFormat property is URLLoaderDataFormat.BINARY,
	 the received data is a ByteArray object containing the raw binary data.If the value of the dataFormat property is URLLoaderDataFormat.VARIABLES,
	 the received data is a URLVariables object containing the URL-encoded variables.
		 */
		public var dataFormat : String;

		public function addEventListener (type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false) : void;

		public function close () : void;

		public function load (request:URLRequest) : void;

		public function URLLoader (request:URLRequest = null);
	}
}
