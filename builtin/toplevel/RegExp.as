//
// D:\test\lib\playerglobal.swc\RegExp
//
package
{
	intrinsic public class RegExp extends Object
	{
		public static const length : int;

		/**
		 Specifies whether the dot character (.) in a regular expression pattern matches 
         new-line characters. Use the s flag when constructing 
         a regular expression to set dotall = true.
		 */
		[native(support="none")]
		public function get dotall () : Boolean;

		/**
		 Specifies whether to use extended mode for the regular expression. 
         When a RegExp object is in extended mode, white space characters in the constructor  
         string are ignored. This is done to allow more readable constructors.
         
         Use the x flag when constructing a regular expression to set 
         extended = true.
		 */
		[native(support="none")]
		public function get extended () : Boolean;

		/**
		 Specifies whether to use global matching for the regular expression. When 
         global == true, the lastIndex property is set after a match is 
         found. The next time a match is requested, the regular expression engine starts from 
         the lastIndex position in the string. Use the g flag when 
         constructing a regular expression  to set global to true.
		 */
		 [native(support="none")]
		public function get global () : Boolean;

		/**
		 Specifies whether the regular expression ignores case sensitivity. Use the 
         i flag when constructing a regular expression to set 
         ignoreCase = true.
		 */
		 [native(support="none")]
		public function get ignoreCase () : Boolean;

		/**
		 Specifies the index position in the string at which to start the next search. This property 
         affects the exec() and test() methods of the RegExp class. 
         However, the match(), replace(), and search() methods
         of the String class ignore the lastIndex property and start all searches from
         the beginning of the string.
         
         When the exec() or test() method finds a match and the g 
         (global) flag is set to true for the regular expression, the method
         automatically sets the lastIndex property to the index position of the character 
         after the last character in the matching substring of the last match. If the 
         g (global) flag is set to false, the method does not 
         set the lastIndexproperty.You can set the lastIndex property to adjust the starting position
         in the string for regular expression matching.
		 */
		 [native(support="none")]
		public function get lastIndex () : int;
		[native(support="none")]
		public function set lastIndex (i:int) : void;

		/**
		 Specifies whether the m (multiline) flag is set. If it is set,
         the caret (^) and dollar sign ($) in a regular expression 
         match before and after new lines. 
         Use the m flag when constructing a regular expression to set 
         multiline = true.
		 */
		 [native(support="none")]
		public function get multiline () : Boolean;

		/// Specifies the pattern portion of the regular expression.
		[native(support="none")]
		public function get source () : String;
		[native(support="none")]
		AS3 function exec (s:String = "") : *;

		public function RegExp (pattern:* = null, options:* = null);
		[native(support="none")]
		AS3 function test (s:String = "") : Boolean;

		public function RegExp( text:String = "" );
		
		public function search( subject:String ) : int;
		public function split( subject:String ) : Array;
		public function match( subject:String ) : Array;
	
		public function replace( subject:String, repl:String ) : String;
	}
}
