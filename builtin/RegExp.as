package
{
	intrinsic public final class RegExp extends Object
	{
		/* constructor */
		public function RegExp( text:String = "" );
		
		public function search( subject:String ) : int;
		public function split( subject:String ) : Array;
		public function match( subject:String ) : Array;
	
		public function replace( subject:String, repl:String ) : String;
	}
}
