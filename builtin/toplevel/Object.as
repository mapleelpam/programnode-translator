package
{
    [root_object]
	intrinsic public class Object 
	{
//		public static const length : int;
		[native(support="none")]
		protected static function _dontEnumPrototype (proto:Object) : void;

		[native(support="none")]
		protected static function _setPropertyIsEnumerable (o:*, V:String, enumerable:Boolean) : void;

		public function hasOwnProperty (V:* = null) : Boolean;
		[native(support="none")]
		public static function init () : *;
		[native(support="none")]
		public function isPrototypeOf (V:* = null) : Boolean;

		public function Object ();

		[native(support="none")]
		public function propertyIsEnumerable (V:* = null) : Boolean;

        public function toString() : String;
	}
}
