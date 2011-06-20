package flash.utils
{
	import flash.utils.ByteArray;

	intrinsic public class ByteArray extends Object implements IDataInput, IDataOutput
	{
		[native(support="none")]
		public function get bytesAvailable () : uint;

		[native(support="none")]
		public static function get defaultObjectEncoding () : uint;
		[native(support="none")]
		public static function set defaultObjectEncoding (version:uint) : void;

		[native(support="none")]
		public function get endian () : String;
		[native(support="none")]
		public function set endian (type:String) : void;

		[native(support="none")]
		public function get length () : uint;
		[native(support="none")]
		public function set length (value:uint) : void;

		[native(support="none")]
		public function get objectEncoding () : uint;
		[native(support="none")]
		public function set objectEncoding (version:uint) : void;

		[native(support="none")]
		public function get position () : uint;
		[native(support="none")]
		public function set position (offset:uint) : void;

		public function ByteArray ();

		public function clear () : void;

		public function compress () : void;

		public function deflate () : void;

		public function inflate () : void;

		public function readBoolean () : Boolean;

		public function readByte () : int;

		public function readBytes (bytes:ByteArray, offset:uint = 0, length:uint = 0) : void;

		public function readDouble () : Number;

		public function readFloat () : Number;

		public function readInt () : int;

		public function readMultiByte (length:uint, charSet:String) : String;
		[native(support="none")]
		public function readObject () : *;

		public function readShort () : int;

		public function readUnsignedByte () : uint;

		public function readUnsignedInt () : uint;

		public function readUnsignedShort () : uint;

		public function readUTF () : String;

		public function readUTFBytes (length:uint) : String;

		public function toString () : String;

		public function uncompress () : void;

		public function writeBoolean (value:Boolean) : void;

		public function writeByte (value:int) : void;

		public function writeBytes (bytes:ByteArray, offset:uint = 0, length:uint = 0) : void;

		public function writeDouble (value:Number) : void;

		public function writeFloat (value:Number) : void;

		public function writeInt (value:int) : void;

		public function writeMultiByte (value:String, charSet:String) : void;
		[native(support="none")]
		public function writeObject (object:*) : void;

		public function writeShort (value:int) : void;

		public function writeUnsignedInt (value:uint) : void;

		public function writeUTF (value:String) : void;

		public function writeUTFBytes (value:String) : void;
	}
}
