//
// D:\test\lib\playerglobal.swc\XMLList
//
package
{
	public class XMLList extends Object
	{
		public static const length : *;
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
		AS3 function copy () : XMLList;
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
		[native(support="none")]
		AS3 function name () : Object;
		[native(support="none")]
		AS3 function namespace (prefix:* = null) : *;
		[native(support="none")]
		AS3 function namespaceDeclarations () : Array;
		[native(support="none")]
		AS3 function nodeKind () : String;
		[native(support="none")]
		AS3 function normalize () : XMLList;

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

		AS3 function text () : XMLList;

		AS3 function toString () : String;
		[native(support="none")]
		AS3 function toXMLString () : String;
		[native(support="none")]
		AS3 function valueOf () : XMLList;

		public function XMLList (value:* = null);
	}
}
