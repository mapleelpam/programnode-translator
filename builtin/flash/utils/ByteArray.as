//
// D:\test\lib\playerglobal.swc\flash\utils\ByteArray
//
package flash.utils
{
	import flash.utils.ByteArray;

	public class ByteArray extends Object implements IDataInput, IDataOutput
	{
		/**
		 The number of bytes of data available for reading
         from the current position in the byte array to the
         end of the array.

         Use the bytesAvailable property in conjunction 
         with the read methods each time you access a ByteArray object 
         to ensure that you are reading valid data.
		 */
		[native(support="none")]
		public function get bytesAvailable () : uint;

		/**
		 Denotes the default object encoding for the ByteArray class to use for a new ByteArray instance.
         When you create a new ByteArray instance, the encoding on that instance starts
         with the value of defaultObjectEncoding.
         The defaultObjectEncoding property is initialized to ObjectEncoding.AMF3.


         When an object is written to or read from binary data, the objectEncoding value
         is used to determine whether the ActionScript 3.0, ActionScript2.0, or ActionScript 1.0 format should be used. The value is a
         constant from the ObjectEncoding class.
		 */
		[native(support="none")]
		public static function get defaultObjectEncoding () : uint;
		[native(support="none")]
		public static function set defaultObjectEncoding (version:uint) : void;

		/**
		 Changes or reads the byte order for the data; either Endian.BIG_ENDIAN or 
         Endian.LITTLE_ENDIAN.
		 */
		[native(support="none")]
		public function get endian () : String;
		[native(support="none")]
		public function set endian (type:String) : void;

		/**
		 The length of the ByteArray object, in bytes.
	 
         If the length is set to a value that is larger than the current length, 
         the the right side  of the byte array is filled with zeros.If the length is set to a value that is smaller than the
         current length, the byte array is truncated.
		 */
		[native(support="none")]
		public function get length () : uint;
		[native(support="none")]
		public function set length (value:uint) : void;

		/**
		 Used to determine whether the ActionScript 3.0, ActionScript 2.0, or ActionScript 1.0 format should be 
         used when writing to, or reading from, a ByteArray instance. The value is a
         constant from the ObjectEncoding class.
		 */
		[native(support="none")]
		public function get objectEncoding () : uint;
		[native(support="none")]
		public function set objectEncoding (version:uint) : void;

		/**
		 Moves, or returns the current position, in bytes, of the file
         pointer into the ByteArray object. This is the
         point at which the next call to a read
         method starts reading or a write
         method starts writing.
		 */
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
