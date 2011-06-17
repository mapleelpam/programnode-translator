//
// D:\test\lib\playerglobal.swc\flash\net\URLStream
//
package flash.net
{
	import flash.events.EventDispatcher;
	import flash.net.URLRequest;
	import flash.utils.ByteArray;

	/**
	 Dispatched when data is received as the download operation progresses.
	 @eventType	flash.events.ProgressEvent.PROGRESS
	 */
	[Event(name="progress", type="flash.events.ProgressEvent")] 

	/**
	 Dispatched when a load operation starts.
	 @eventType	flash.events.Event.OPEN
	 */
	[Event(name="open", type="flash.events.Event")] 

	/**
	 Dispatched when an input/output error occurs that causes a load operation to fail.
	 @eventType	flash.events.IOErrorEvent.IO_ERROR
	 */
	[Event(name="ioError", type="flash.events.IOErrorEvent")] 

	/**
	 Dispatched if a call to the URLStream.load() method attempts to access data over HTTP 
 and Adobe AIR is able to detect and return the status code for the request.
	 @eventType	flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS
	 */
	[Event(name="httpResponseStatus", type="flash.events.HTTPStatusEvent")] 

	/**
	 Dispatched if a call to URLStream.load() 
 attempts to access data over HTTP, and Flash Player or  Adobe AIR
 is able to detect and return the status code for the request.
	 @eventType	flash.events.HTTPStatusEvent.HTTP_STATUS
	 */
	[Event(name="httpStatus", type="flash.events.HTTPStatusEvent")] 

	/**
	 Dispatched if a call to URLStream.load() 
 attempts to load data from a server outside the security sandbox.
	 @eventType	flash.events.SecurityErrorEvent.SECURITY_ERROR
	 */
	[Event(name="securityError", type="flash.events.SecurityErrorEvent")] 

	/**
	 Dispatched when data has loaded successfully.
	 @eventType	flash.events.Event.COMPLETE
	 */
	[Event(name="complete", type="flash.events.Event")] 

	public class URLStream extends EventDispatcher implements IDataInput
	{
		/**
		 Returns the number of bytes of data available for reading
     in the input buffer.
     Your code must call the bytesAvailable property to ensure
     that sufficient data is available before you try to read
     it with one of the read methods.
		 */
		public function get bytesAvailable () : uint;

		/**
		 Indicates whether this URLStream object is
     currently connected. A call to this property returns a value of true
     if the URLStream object is connected, or false otherwise.
		 */
		public function get connected () : Boolean;

		/**
		 Indicates the byte order for the data. Possible values are 
     Endian.BIG_ENDIAN or Endian.LITTLE_ENDIAN.
		 */
		[native(support="none")]
		public function get endian () : String;
		[native(support="none")]
		public function set endian (type:String) : void;

		/// Controls the version of Action Message Format (AMF) used when writing or reading an object.
		[native(support="none")]
		public function get objectEncoding () : uint;
		[native(support="none")]
		public function set objectEncoding (version:uint) : void;

		public function close () : void;

		public function load (request:URLRequest) : void;

		public function readBoolean () : Boolean;

		public function readByte () : int;
		[native(support="none")]
		public function readBytes (bytes:ByteArray, offset:uint = 0, length:uint = 0) : void;

		public function readDouble () : Number;

		public function readFloat () : Number;

		public function readInt () : int;

		public function readMultiByte (length:uint, charSet:String) : String;

		public function readObject () : *;

		public function readShort () : int;

		public function readUnsignedByte () : uint;

		public function readUnsignedInt () : uint;

		public function readUnsignedShort () : uint;

		public function readUTF () : String;

		public function readUTFBytes (length:uint) : String;

		public function URLStream ();
	}
}
