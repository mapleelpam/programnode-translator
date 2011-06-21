package
{
	intrinsic public class Array extends Object
	{
		public static const CASEINSENSITIVE : uint = 1;

		public static const DESCENDING : uint = 2;
		public static const length : int;

		public static const NUMERIC : uint = 16;

		public static const RETURNINDEXEDARRAY : uint = 8;

		public static const UNIQUESORT : uint = 4;

		public function get length () : uint;
		public function set length (newLength:uint) : void;

		//public function Array (...rest);

		//public function concat (...rest) : Array;

/*
		public function every (callback:Function, thisObject:* = null) : Boolean;

		public function filter (callback:Function, thisObject:* = null) : Array;

		public function forEach (callback:Function, thisObject:* = null) : void;

		public function indexOf (searchElement:*, fromIndex:* = 0) : int;

		public function join (sep:* = null) : String;

		public function lastIndexOf (searchElement:*, fromIndex:* = 2147483647) : int;

		public function map (callback:Function, thisObject:* = null) : Array;

		public function pop () : *;
*/

		//public function push (...rest) : uint;

		public function reverse () : Array;

		public function shift () : *;

//		public function slice (A:* = 0, B:* = 4294967295) : Array;

//		public function some (callback:Function, thisObject:* = null) : Boolean;

		//public function sort (...rest) : *;

		//public function sortOn (names:*, options:* = 0, ...rest) : *;

		//public function splice (...rest) : *;

		//public function unshift (...rest) : uint;
	}
}
