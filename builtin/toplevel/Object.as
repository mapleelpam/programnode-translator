//
// D:\test\lib\playerglobal.swc\Object
//
package
{
	public class Object extends *
	{
		public static const length : int;
		[native(support="none")]
		protected static function _dontEnumPrototype (proto:Object) : void;
		[native(support="none")]
		protected static function _setPropertyIsEnumerable (o:*, V:String, enumerable:Boolean) : void;

		AS3 function hasOwnProperty (V:* = null) : Boolean;
		[native(support="none")]
		public static function init () : *;
		[native(support="none")]
		AS3 function isPrototypeOf (V:* = null) : Boolean;

		public function Object ();
		[native(support="none")]
		AS3 function propertyIsEnumerable (V:* = null) : Boolean;
	}
}
