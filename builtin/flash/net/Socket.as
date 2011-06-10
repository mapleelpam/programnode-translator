
intrinsic class flash.net.Socket{

	public function Socket( String host = null, Int port = "" ) : void;	
	public function close() : void;
    public function connect( String host, int port) : void;//XCStringPtr:host,int port
	public function connect() : void;
	public function flush() : void;
	public function readBoolean() : Boolean;
	public function readByte() : int;
	public function readBytes( ByteArray, UInt offest=0, UInt length=0) : void;
	public function readDouble() : Number;
	public function readFloat() : Number;
	public function readInt() : int;
	public function readMultiByte( UInt length, String charSet ) : String;
	public function readShort() : int;
	public function readUnsignedByte() : UInt;
	public function readUnsignedInt() : UInt
    public function readUnsignedShort() : UInt;
    public function readUTF() : String;

    public function readData() : void;

	public readUTFBytes( UInt length ) : String;

	public function writeXCBoolean( Boolean value) : void;
	public function writeByte(Int value) : void;
	public function writeBytes(ByteArray bytes, UInt offset=NULL, UInt length=NULL) : void;
	public function writeDouble(Number value) : void;
	public function writeFloat(Number value) : void;
	public function writeInt(Int value) : void;
	public function writeMultiByte(String value, String charSet) : void;
	public function writeShort(IntPtr value) : void;
	public function writeUnsignedInt(UintPtr value) : void;
	public function writeUTF(XCStringPtr value) : void;
	public function writeUTFBytes(XCStringPtr value) : void;

    public function Is3ByteUTF8Sequence(const T:value) : Boolean
}
