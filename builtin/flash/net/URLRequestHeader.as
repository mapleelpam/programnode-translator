package flash.net
{
	intrinsic public class URLRequestHeader extends Object
	{
//		public var name : String;
//
//		public var value : String;
		
		public function get name () : String;
		public function set name (value:String) : void;
		
		public function get value () : String;
		public function set value (value:String) : void;


		public function URLRequestHeader (name:String = "", value:String = "");
	}
}
