package flash.net
{
	import flash.events.EventDispatcher;
	import flash.net.URLRequest;
	import flash.utils.ByteArray;

	intrinsic public class URLStream extends EventDispatcher implements IDataInput
	{
		public function get bytesAvailable () : uint;

		public function get connected () : Boolean;

		[native(support="none")]
		public function get endian () : String;
		[native(support="none")]
		public function set endian (type:String) : void;

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
