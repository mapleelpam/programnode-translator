package
{
	intrinsic public class RegExp extends Object
	{
		public static const length : int;

		[native(support="none")]
		public function get dotall () : Boolean;

		[native(support="none")]
		public function get extended () : Boolean;

		 [native(support="none")]
		public function get global () : Boolean;

		 [native(support="none")]
		public function get ignoreCase () : Boolean;

		 [native(support="none")]
		public function get lastIndex () : int;
		[native(support="none")]
		public function set lastIndex (i:int) : void;

		 [native(support="none")]
		public function get multiline () : Boolean;

		public function get source () : String;

//		[native(support="none")]
//		public function exec (s:String = "") : *;

//		public function RegExp (pattern:* = null, options:* = null);

		[native(support="none")]
		public function test (s:String = "") : Boolean;
	}
}
