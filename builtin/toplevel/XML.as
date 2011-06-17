//
// D:\test\lib\playerglobal.swc\XML
//
package
{
	public class XML extends Object
	{
		public static const length : *;

		/**
		 Determines whether XML comments are ignored 
	when XML objects parse the source XML data. By default, the comments are ignored 
	(true). To include XML comments, set this property to false. 
	The ignoreComments property is used only during the XML parsing, not during 
	the call to any method such as myXMLObject.child(~~).toXMLString(). 
	If the source XML includes comment nodes, they are kept or discarded during the XML parsing.
		 */
		[native(support="none")]
		public static function get ignoreComments () : Boolean;
		[native(support="none")]
		public static function set ignoreComments (newIgnore:Boolean) : void;

		/**
		 Determines whether XML 
	processing instructions are ignored when XML objects parse the source XML data. 
	By default, the processing instructions are ignored (true). To include XML 
	processing instructions, set this property to false. The 
	ignoreProcessingInstructions property is used only during the XML parsing, 
	not during the call to any method such as myXMLObject.child(~~).toXMLString().
	If the source XML includes processing instructions nodes, they are kept or discarded during 
	the XML parsing.
		 */
		[native(support="none")]
		public static function get ignoreProcessingInstructions () : Boolean;
		[native(support="none")]
		public static function set ignoreProcessingInstructions (newIgnore:Boolean) : void;

		/**
		 Determines whether white space characters
	at the beginning and end of text nodes are ignored during parsing. By default, 
	white space is ignored (true). If a text node is 100% white space and the 
	ignoreWhitespace property is set to true, then the node is not created.  
	To show white space in a text node, set the ignoreWhitespace property to 
	false.
		 */
		[native(support="none")]
		public static function get ignoreWhitespace () : Boolean;
		[native(support="none")]
		public static function set ignoreWhitespace (newIgnore:Boolean) : void;

		/**
		 Determines the amount of indentation applied by 
	the toString() and toXMLString() methods when 
	the XML.prettyPrinting property is set to true. 
	Indentation is applied with the space character, not the tab character.
	
	The default value is 2.
		 */
		[native(support="none")]
		public static function get prettyIndent () : int;
		[native(support="none")]
		public static function set prettyIndent (newIndent:int) : void;

		/**
		 Determines whether the toString() 
	and toXMLString() methods normalize white space characters between some tags. 
	The default value is true.
		 */
		[native(support="none")]
		public static function get prettyPrinting () : Boolean;
		[native(support="none")]
		public static function set prettyPrinting (newPretty:Boolean) : void;
		[native(support="none")]
		AS3 function addNamespace (ns:*) : XML;
		[native(support="none")]
		AS3 function appendChild (child:*) : XML;
		
		AS3 function attribute (arg:*) : XMLList;

		AS3 function attributes () : XMLList;

		AS3 function child (propertyName:*) : XMLList;
		[native(support="none")]
		AS3 function childIndex () : int;

		AS3 function children () : XMLList;

		AS3 function comments () : XMLList;
		[native(support="none")]
		AS3 function contains (value:*) : Boolean;
		[native(support="none")]
		AS3 function copy () : XML;
		[native(support="none")]
		AS3 static function defaultSettings () : Object;
		[native(support="none")]
		AS3 function descendants (name:* = "*") : XMLList;

		AS3 function elements (name:* = "*") : XMLList;

		AS3 function hasComplexContent () : Boolean;

		AS3 function hasOwnProperty (P:* = null) : Boolean;

		AS3 function hasSimpleContent () : Boolean;
		[native(support="none")]
		AS3 function inScopeNamespaces () : Array;
		[native(support="none")]
		AS3 function insertChildAfter (child1:*, child2:*) : *;
		[native(support="none")]
		AS3 function insertChildBefore (child1:*, child2:*) : *;

		AS3 function length () : int;
		[native(support="none")]
		AS3 function localName () : Object;

		AS3 function name () : Object;
		[native(support="none")]
		AS3 function namespace (prefix:* = null) : *;
		[native(support="none")]
		AS3 function namespaceDeclarations () : Array;
		
		AS3 function nodeKind () : String;
		[native(support="none")]
		AS3 function normalize () : XML;
		[native(support="none")]
		AS3 function notification () : Function;
		
		AS3 function parent () : *;
		[native(support="none")]
		AS3 function prependChild (value:*) : XML;
		[native(support="none")]
		AS3 function processingInstructions (name:* = "*") : XMLList;
		[native(support="none")]
		AS3 function propertyIsEnumerable (P:* = null) : Boolean;
		[native(support="none")]
		AS3 function removeNamespace (ns:*) : XML;
		[native(support="none")]
		AS3 function replace (propertyName:*, value:*) : XML;
		[native(support="none")]
		AS3 function setChildren (value:*) : XML;
		[native(support="none")]
		AS3 function setLocalName (name:*) : void;
		[native(support="none")]
		AS3 function setName (name:*) : void;
		[native(support="none")]
		AS3 function setNamespace (ns:*) : void;
		[native(support="none")]
		AS3 function setNotification (f:Function) : *;
		[native(support="none")]
		AS3 static function setSettings (o:Object = null) : void;
		[native(support="none")]
		AS3 static function settings () : Object;
		
		AS3 function text () : XMLList;

		AS3 function toString () : String;
		[native(support="none")]
		AS3 function toXMLString () : String;
		[native(support="none")]
		AS3 function valueOf () : XML;

		public function XML (value:* = null);
	}
}
