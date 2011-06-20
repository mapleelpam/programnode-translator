package
{
	intrinsic public class Boolean extends Object
	{
		public static const length : int;

		public function Boolean (value:* = null);

		public function toString () : String;
		
		[native(support="none")]
		public function valueOf () : Boolean;
	}
}
