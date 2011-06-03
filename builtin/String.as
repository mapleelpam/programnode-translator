package
{
	[native(cls="XCString", instance="String", methods="auto")]
	public final class String extends Object
	{
		public static const length:int = 1
		

		public function charAt(i:Number=0):String

		public function charCodeAt( index:int ):int

		// concat
		// fromCharCode

		public function indexOf(s:String="undefined", i:Number=0):int
		public function lastIndexOf(s:String="undefined", i:Number=0x7FFFFFFF):int

		// match
		public function replace(pattern:String, repl:String):String
		
		public function get_length():int

		public function equal( rhs:String ):Boolean

		
	}
}
