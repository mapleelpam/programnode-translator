//
// D:\test\lib\playerglobal.swc\Array
//
package
{
	public class Array extends Object
	{
		/**
		 Specifies case-insensitive sorting for the Array class sorting methods. You can use this constant
	 for the options parameter in the sort() or sortOn() method. 
	 The value of this constant is 1.
		 */
		public static const CASEINSENSITIVE : uint = 1;

		/**
		 Specifies descending sorting for the Array class sorting methods. 
 	 You can use this constant for the options parameter in the sort()
 	 or sortOn() method. 
 	 The value of this constant is 2.
		 */
		public static const DESCENDING : uint = 2;
		public static const length : int;

		/**
		 Specifies numeric (instead of character-string) sorting for the Array class sorting methods. 
     Including this constant in the options
 	 parameter causes the sort() and sortOn() methods 
 	 to sort numbers as numeric values, not as strings of numeric characters.  
     Without the NUMERIC constant, sorting treats each array element as a 
 	 character string and produces the results in Unicode order. 
 	 
     For example, given the array of values [2005, 7, 35], if the NUMERIC 
 	 constant is not included in the options parameter, the 
     sorted array is [2005, 35, 7], but if the NUMERIC constant is included, 
     the sorted array is [7, 35, 2005]. This constant applies only to numbers in the array; it does 
     not apply to strings that contain numeric data such as ["23", "5"].The value of this constant is 16.
		 */
		public static const NUMERIC : uint = 16;

		/**
		 Specifies that a sort returns an array that consists of array indices. You can use this constant
 	 for the options parameter in the sort() or sortOn() 
 	 method, so you have access to multiple views of the array elements while the original array is unmodified. 
 	 The value of this constant is 8.
		 */
		public static const RETURNINDEXEDARRAY : uint = 8;

		/**
		 Specifies the unique sorting requirement for the Array class sorting methods. 
     You can use this constant for the options parameter in the sort() or sortOn() 
	 method. The unique sorting option terminates the sort if any two elements
	 or fields being sorted have identical values. 
	 The value of this constant is 4.
		 */
		public static const UNIQUESORT : uint = 4;

		/**
		 A non-negative integer specifying the number of elements in the array. This property is automatically updated when new elements are added to the array. When you assign a value to an array element (for example, my_array[index] = value), if index is a number, and index+1 is greater than the length property, the length property is updated to index+1.
   	 Note: If you assign a value to the length property that is shorter than the existing length, the array will be truncated.
		 */
		public function get length () : uint;
		public function set length (newLength:uint) : void;

		public function Array (...rest);

		AS3 function concat (...rest) : Array;

		AS3 function every (callback:Function, thisObject:* = null) : Boolean;

		AS3 function filter (callback:Function, thisObject:* = null) : Array;

		AS3 function forEach (callback:Function, thisObject:* = null) : void;

		AS3 function indexOf (searchElement:*, fromIndex:* = 0) : int;

		AS3 function join (sep:* = null) : String;

		AS3 function lastIndexOf (searchElement:*, fromIndex:* = 2147483647) : int;

		AS3 function map (callback:Function, thisObject:* = null) : Array;

		AS3 function pop () : *;

		AS3 function push (...rest) : uint;

		AS3 function reverse () : Array;

		AS3 function shift () : *;

		AS3 function slice (A:* = 0, B:* = 4294967295) : Array;

		AS3 function some (callback:Function, thisObject:* = null) : Boolean;

		AS3 function sort (...rest) : *;

		AS3 function sortOn (names:*, options:* = 0, ...rest) : *;

		AS3 function splice (...rest) : *;

		AS3 function unshift (...rest) : uint;
	}
}
