package flash.text
{
	intrinsic public class TextFormat extends Object
	{
		[native(support="none")]
		public function get align () : String;
		[native(support="none")]
		public function set align (value:String) : void;

		[native(support="none")]
		public function get blockIndent () : Object;
		[native(support="none")]
		public function set blockIndent (value:Object) : void;

		[native(support="none")]
		public function get bold () : Object;
		[native(support="none")]
		public function set bold (value:Object) : void;

		[native(support="none")]
		public function get bullet () : Object;
		[native(support="none")]
		public function set bullet (value:Object) : void;

		public function get color () : Object;
		public function set color (value:Object) : void;

		[native(support="none")]
		public function get display () : String;
		[native(support="none")]
		public function set display (value:String) : void;

		public function get font () : String;
		public function set font (value:String) : void;

		[native(support="none")]
		public function get indent () : Object;
		[native(support="none")]
		public function set indent (value:Object) : void;

		[native(support="none")]
		public function get italic () : Object;
		[native(support="none")]
		public function set italic (value:Object) : void;

		[native(support="none")]
		public function get kerning () : Object;
		[native(support="none")]
		public function set kerning (value:Object) : void;

		[native(support="none")]
		public function get leading () : Object;
		[native(support="none")]
		public function set leading (value:Object) : void;

		[native(support="none")]
		public function get leftMargin () : Object;
		[native(support="none")]
		public function set leftMargin (value:Object) : void;

		[native(support="none")]
		public function get letterSpacing () : Object;
		[native(support="none")]
		public function set letterSpacing (value:Object) : void;

		[native(support="none")]
		public function get rightMargin () : Object;
		[native(support="none")]
		public function set rightMargin (value:Object) : void;

		public function get size () : Object;
		public function set size (value:Object) : void;

		[native(support="none")]
		public function get tabStops () : Array;
		[native(support="none")]
		public function set tabStops (value:Array) : void;

		[native(support="none")]
		public function get target () : String;
		[native(support="none")]
		public function set target (value:String) : void;

		[native(support="none")]
		public function get underline () : Object;
		[native(support="none")]
		public function set underline (value:Object) : void;

		[native(support="none")]
		public function get url () : String;
		[native(support="none")]
		public function set url (value:String) : void;

		public function TextFormat (font:String = null, size:Object = null, color:Object = null, bold:Object = null, italic:Object = null, underline:Object = null, url:String = null, target:String = null, align:String = null, leftMargin:Object = null, rightMargin:Object = null, indent:Object = null, leading:Object = null);
	}
}
