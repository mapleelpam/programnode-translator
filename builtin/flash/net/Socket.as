//
// D:\test\lib\playerglobal.swc\flash\net\Socket
//
package flash.net
{
	import flash.events.EventDispatcher;
	import private.IDataInput;
	import private.IDataOutput;
	import flash.utils.Timer;
	import flash.events.SecurityErrorEvent;
	import flash.events.TimerEvent;
	import flash.utils.ByteArray;

	/**
	 Dispatched if a call to Socket.connect() 
 attempts to connect either to a server outside the caller's security sandbox or to a port lower than 1024.
	 @eventType	flash.events.SecurityErrorEvent.SECURITY_ERROR
	 */
	[Event(name="securityError", type="flash.events.SecurityErrorEvent")] 

	/**
	 Dispatched when a socket has received data.
	 @eventType	flash.events.ProgressEvent.SOCKET_DATA
	 */
	[Event(name="socketData", type="flash.events.ProgressEvent")] 

	/**
	 Dispatched when an input/output error occurs that causes a send or load operation to fail.
	 @eventType	flash.events.IOErrorEvent.IO_ERROR
	 */
	[Event(name="ioError", type="flash.events.IOErrorEvent")] 

	/**
	 Dispatched when a network connection has been established.
	 @eventType	flash.events.Event.CONNECT
	 */
	[Event(name="connect", type="flash.events.Event")] 

	/**
	 Dispatched when the server closes the socket connection.
	 @eventType	flash.events.Event.CLOSE
	 */
	[Event(name="close", type="flash.events.Event")] 

	public class Socket extends EventDispatcher implements IDataInput, IDataOutput
	{
		/**
		 The number of bytes of data available for reading in the input buffer.
     
         Your code must access bytesAvailable to ensure
         that sufficient data is available before trying to read
         it with one of the read methods.
		 */
		public function get bytesAvailable () : uint;

		/**
		 Indicates whether this Socket object is currently connected. 
         A call to this property returns a value of true if the socket
         is currently connected, or false otherwise.
		 */
		public function get connected () : Boolean;

		/**
		 Indicates the byte order for the data; possible values are
         constants from the flash.utils.Endian class,
         Endian.BIG_ENDIAN or Endian.LITTLE_ENDIAN.
		 */
		public function get endian () : String;
		public function set endian (type:String) : void;

		/// Controls the version of AMF used when writing or reading an object.
		public function get objectEncoding () : uint;
		public function set objectEncoding (version:uint) : void;

		public function get timeout () : uint;
		/**
		 Indicates the number of milliseconds to wait for a connection.
     
         If the connection doesn't succeed within the specified time, the connection fails.
         The default value is 20,000 (twenty seconds).
		 */
		public function set timeout (value:uint) : void;

		public function close () : void;

		public function connect (host:String, port:int) : void;

		public function flush () : void;

		public function readBoolean () : Boolean;

		public function readByte () : int;

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

		public function Socket (host:String = null, port:int = 0);

		public function writeBoolean (value:Boolean) : void;

		public function writeByte (value:int) : void;

		public function writeBytes (bytes:ByteArray, offset:uint = 0, length:uint = 0) : void;

		public function writeDouble (value:Number) : void;

		public function writeFloat (value:Number) : void;

		public function writeInt (value:int) : void;

		public function writeMultiByte (value:String, charSet:String) : void;

		public function writeObject (object:*) : void;

		public function writeShort (value:int) : void;

		public function writeUnsignedInt (value:uint) : void;

		public function writeUTF (value:String) : void;

		public function writeUTFBytes (value:String) : void;
	}
}
