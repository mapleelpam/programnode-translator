package
{
	intrinsic public class XMLList extends Object
	{
		public static const length : *;
		[native(support="none")]
		public function addNamespace (ns:*) : XML;
		[native(support="none")]
		public function appendChild (child:*) : XML;

		public function attribute (arg:*) : XMLList;

		public function attributes () : XMLList;

		public function child (propertyName:*) : XMLList;
		[native(support="none")]
		public function childIndex () : int;

		public function children () : XMLList;

		public function comments () : XMLList;
		[native(support="none")]
		public function contains (value:*) : Boolean;
		[native(support="none")]
		public function copy () : XMLList;
		[native(support="none")]
		public function descendants (name:* = "*") : XMLList;

		public function elements (name:* = "*") : XMLList;

		public function hasComplexContent () : Boolean;

		public function hasOwnProperty (P:* = null) : Boolean;

		public function hasSimpleContent () : Boolean;
		[native(support="none")]
		public function inScopeNamespaces () : Array;
		[native(support="none")]
		public function insertChildAfter (child1:*, child2:*) : *;
		[native(support="none")]
		public function insertChildBefore (child1:*, child2:*) : *;

		public function length () : int;
		[native(support="none")]
		public function localName () : Object;
		[native(support="none")]
		public function name () : Object;
		[native(support="none")]
		public function namespace (prefix:* = null) : *;
		[native(support="none")]
		public function namespaceDeclarations () : Array;
		[native(support="none")]
		public function nodeKind () : String;
		[native(support="none")]
		public function normalize () : XMLList;

		public function parent () : *;
		[native(support="none")]
		public function prependChild (value:*) : XML;
		[native(support="none")]
		public function processingInstructions (name:* = "*") : XMLList;
		[native(support="none")]
		public function propertyIsEnumerable (P:* = null) : Boolean;
		[native(support="none")]
		public function removeNamespace (ns:*) : XML;
		[native(support="none")]
		public function replace (propertyName:*, value:*) : XML;
		[native(support="none")]
		public function setChildren (value:*) : XML;
		[native(support="none")]
		public function setLocalName (name:*) : void;
		[native(support="none")]
		public function setName (name:*) : void;
		[native(support="none")]
		public function setNamespace (ns:*) : void;

		public function text () : XMLList;

		public function toString () : String;
		[native(support="none")]
		public function toXMLString () : String;
		[native(support="none")]
		public function valueOf () : XMLList;

		public function XMLList (value:* = null);
	}
}
