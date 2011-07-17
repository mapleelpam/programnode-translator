package
{
    [native(cls="XCString", instance="String", methods="auto")]
	intrinsic public class String extends Object
	{
//		public static const length : int;

		public function get length () : int;

		public function charAt (i:Number = 0) : String;

		public function charCodeAt (i:Number = 0) : Number;

		//public function concat (...rest) : String;

		//public static function fromCharCode (...rest) : String;

		public function indexOf (s:String = undefined, i:Number = 0) : int;

		public function lastIndexOf (s:String = undefined, i:Number = 2147483647) : int;
		[native(support="none")]
		public function localeCompare (other:String = null) : int;

//		public function match (p:* = null) : Array;

//		public function replace (p:* = null, repl:* = null) : String;

//		public function search (p:* = null) : int;

		public function slice (start:Number = 0, end:Number = 2147483647) : String;

//		public function split (delim:* = null, limit:* = 4294967295) : Array;

//		public function String (value:* = "");

		public function substr (start:Number = 0, len:Number = 2147483647) : String;

		public function substring (start:Number = 0, end:Number = 2147483647) : String;

		public function toLocaleLowerCase () : String;

		public function toLocaleUpperCase () : String;

		public function toLowerCase () : String;

		public function toString () : String;

		public function toUpperCase () : String;
		[native(support="none")]
		public function valueOf () : String;
	}
}
