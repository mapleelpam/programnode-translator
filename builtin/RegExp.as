package
{
	[native(cls="RegExp", instance="RegExp", methods="auto")]
	intrinsic public final class RegExp extends Object
	{
		/* constructor */
		public functin RegExp( const String text = "" );
		
		public function search( const String subject ) : int;
		public function split( const String subject ) : Array;
		public function match( const String subject ) : Array;
	
		public function replace( const String subject, const String repl ) : String;
	}
}
