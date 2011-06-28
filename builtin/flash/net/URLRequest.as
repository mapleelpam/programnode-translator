package flash.net
{
	intrinsic public class URLRequest extends Object
	{
		public function get contentType () : String;
		public function set contentType (value:String) : void;

		public function get data () : Object;
		public function set data (value:Object) : void;
		[native(support="none")]
		public function get digest () : String;
		
		[native(support="none")]
		public function set digest (value:String) : void;

		public function get method () : String;
		public function set method (value:String) : void;

		public function get requestHeaders () : Array;
		public function set requestHeaders (value:Array) : void;

		public function get url () : String;
		public function set url (value:String) : void;

		public function URLRequest (url:String = null);
	}
}
