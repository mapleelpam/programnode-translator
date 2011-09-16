package flash.net
{
    import flash.events.EventDispatcher;
//    import flash.utils.*;
    import flash.utils.ByteArray;

    intrinsic public class Socket extends EventDispatcher implements IDataInput, IDataOutput
    {
        public function Socket(param1:String = null, param2:int = 0);

        public function connect(param1:String, param2:int) : void;

        public function get timeout() : uint ;

        public function readBytes(param1:ByteArray, param2:uint = 0, param3:uint = 0) : void;

        public function writeBytes(param1:ByteArray, param2:uint = 0, param3:uint = 0) : void;

        public function writeBoolean(param1:Boolean) : void;

        public function writeByte(param1:int) : void;

        public function writeShort(param1:int) : void;

        public function writeInt(param1:int) : void;

        public function writeUnsignedInt(param1:uint) : void;

        public function writeFloat(param1:Number) : void;

        public function writeDouble(param1:Number) : void;

        public function writeMultiByte(param1:String, param2:String) : void;

        public function writeUTF(param1:String) : void;

        public function writeUTFBytes(param1:String) : void;

        public function readBoolean() : Boolean;

        public function readByte() : int;

        public function readUnsignedByte() : uint;

        public function readShort() : int;

        public function readUnsignedShort() : uint;

        public function readInt() : int;

        public function readUnsignedInt() : uint;

        public function readFloat() : Number;

        public function readDouble() : Number;

        public function readMultiByte(param1:uint, param2:String) : String;

        public function readUTF() : String;

        public function readUTFBytes(param1:uint) : String;

        public function get bytesAvailable() : uint;

        public function get connected() : Boolean;

        public function close() : void ;

        public function flush() : void;
        
	[native(support="none")]
        public function writeObject(param1) : void;

        [native(support="none")]
        public function readObject();

        [native(support="none")]
        public function get objectEncoding() : uint;

        public function get endian() : String;

    }
}
