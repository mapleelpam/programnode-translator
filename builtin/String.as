package
{
	[native(cls="XCString", instance="String", methods="auto")]
	intrinsic public final class String extends Object
	{
		public function charAt(i:Number=0):String

		public function charCodeAt( index:int ):int

		// concat
		// fromCharCode

		public function indexOf(s:String="undefined", i:Number=0):int
		public function lastIndexOf(s:String="undefined", i:Number=0x7FFFFFFF):int

		// match
		public function replace(pattern:String, repl:String):String
		
		public function get length():int

		public function equal( rhs:String ):Boolean

		
	}
}
