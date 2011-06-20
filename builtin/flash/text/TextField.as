package flash.text
{
	import flash.display.InteractiveObject;
	import flash.text.TextFormat;
	import flash.text.StyleSheet;
	import flash.geom.Rectangle;
	import flash.text.TextLineMetrics;
	import flash.display.DisplayObject;

	intrinsic public class TextField extends InteractiveObject
	{
		[native(support="none")]
		public function get alwaysShowSelection () : Boolean;
		[native(support="none")]
		public function set alwaysShowSelection (value:Boolean) : void;

		[native(support="none")]
		public function get antiAliasType () : String;
		[native(support="none")]
		public function set antiAliasType (antiAliasType:String) : void;

		[native(support="none")]
		public function get autoSize () : String;
		[native(support="none")]
		public function set autoSize (value:String) : void;

		[native(support="none")]
		public function get background () : Boolean;
		[native(support="none")]
		public function set background (value:Boolean) : void;

		[native(support="none")]
		public function get backgroundColor () : uint;
		[native(support="none")]
		public function set backgroundColor (value:uint) : void;

		[native(support="none")]
		public function get border () : Boolean;
		[native(support="none")]
		public function set border (value:Boolean) : void;

		[native(support="none")]
		public function get borderColor () : uint;
		[native(support="none")]
		public function set borderColor (value:uint) : void;

		[native(support="none")]
		public function get bottomScrollV () : int;

		[native(support="none")]
		public function get caretIndex () : int;

		[native(support="none")]
		public function get condenseWhite () : Boolean;
		[native(support="none")]
		public function set condenseWhite (value:Boolean) : void;

		public function get defaultTextFormat () : TextFormat;
		public function set defaultTextFormat (format:TextFormat) : void;

		[native(support="none")]
		public function get displayAsPassword () : Boolean;
		[native(support="none")]
		public function set displayAsPassword (value:Boolean) : void;

		[native(support="none")]
		public function get embedFonts () : Boolean;
		[native(support="none")]
		public function set embedFonts (value:Boolean) : void;

		[native(support="none")]
		public function get gridFitType () : String;
		[native(support="none")]
		public function set gridFitType (gridFitType:String) : void;

		[native(support="none")]
		public function get htmlText () : String;
		[native(support="none")]
		public function set htmlText (value:String) : void;

		[native(support="none")]
		public function get length () : int;

		[native(support="none")]
		public function get maxChars () : int;
		[native(support="none")]
		public function set maxChars (value:int) : void;

		[native(support="none")]
		public function get maxScrollH () : int;

		[native(support="none")]
		public function get maxScrollV () : int;

		[native(support="none")]
		public function get mouseWheelEnabled () : Boolean;
		[native(support="none")]
		public function set mouseWheelEnabled (value:Boolean) : void;

		[native(support="none")]
		public function get multiline () : Boolean;
		[native(support="none")]
		public function set multiline (value:Boolean) : void;

		[native(support="none")]
		public function get numLines () : int;

		[native(support="none")]
		public function get restrict () : String;
		[native(support="none")]
		public function set restrict (value:String) : void;

		[native(support="none")]
		public function get scrollH () : int;
		[native(support="none")]
		public function set scrollH (value:int) : void;

		[native(support="none")]
		public function get scrollV () : int;
		[native(support="none")]
		public function set scrollV (value:int) : void;

		[native(support="none")]
		public function get selectable () : Boolean;
		[native(support="none")]
		public function set selectable (value:Boolean) : void;
		[native(support="none")]
		public function get selectedText () : String;

		[native(support="none")]
		public function get selectionBeginIndex () : int;

		[native(support="none")]
		public function get selectionEndIndex () : int;

		[native(support="none")]
		public function get sharpness () : Number;
		[native(support="none")]
		public function set sharpness (value:Number) : void;

		[native(support="none")]
		public function get styleSheet () : StyleSheet;
		[native(support="none")]
		public function set styleSheet (value:StyleSheet) : void;

		public function get text () : String;
		public function set text (value:String) : void;

		public function get textColor () : uint;
		public function set textColor (value:uint) : void;

		[native(support="none")]
		public function get textHeight () : Number;

		[native(support="none")]
		public function get textWidth () : Number;

		[native(support="none")]
		public function get thickness () : Number;
		[native(support="none")]
		public function set thickness (value:Number) : void;

		[native(support="none")]
		public function get type () : String;
		[native(support="none")]
		public function set type (value:String) : void;
		[native(support="none")]
		public function get useRichTextClipboard () : Boolean;
	
		[native(support="none")]
		public function set useRichTextClipboard (value:Boolean) : void;

		[native(support="none")]
		public function get wordWrap () : Boolean;
		[native(support="none")]
		public function set wordWrap (value:Boolean) : void;
		[native(support="none")]
		public function appendText (newText:String) : void;
		[native(support="none")]
		function copyRichText () : String;
		[native(support="none")]
		public function getCharBoundaries (charIndex:int) : Rectangle;
		[native(support="none")]
		public function getCharIndexAtPoint (x:Number, y:Number) : int;
		[native(support="none")]
		public function getFirstCharInParagraph (charIndex:int) : int;
		[native(support="none")]
		public function getImageReference (id:String) : DisplayObject;
		[native(support="none")]
		public function getLineIndexAtPoint (x:Number, y:Number) : int;
		[native(support="none")]
		public function getLineIndexOfChar (charIndex:int) : int;
		[native(support="none")]
		public function getLineLength (lineIndex:int) : int;
		[native(support="none")]
		public function getLineMetrics (lineIndex:int) : TextLineMetrics;
		[native(support="none")]
		public function getLineOffset (lineIndex:int) : int;
		[native(support="none")]
		public function getLineText (lineIndex:int) : String;
		[native(support="none")]
		public function getParagraphLength (charIndex:int) : int;
		[native(support="none")]
		public function getRawText () : String;
		[native(support="none")]
		public function getTextFormat (beginIndex:int = -1, endIndex:int = -1) : TextFormat;
		[native(support="none")]
		public function getTextRuns (beginIndex:int = 0, endIndex:int = 2147483647) : Array;
		[native(support="none")]
		public function getXMLText (beginIndex:int = 0, endIndex:int = 2147483647) : String;
		[native(support="none")]
		public function insertXMLText (beginIndex:int, endIndex:int, richText:String, pasting:Boolean = false) : void;
		[native(support="none")]
		public static function isFontCompatible (fontName:String, fontStyle:String) : Boolean;
		[native(support="none")]
		function pasteRichText (richText:String) : Boolean;
		[native(support="none")]
		public function replaceSelectedText (value:String) : void;
		[native(support="none")]
		public function replaceText (beginIndex:int, endIndex:int, newText:String) : void;
		[native(support="none")]
		public function setSelection (beginIndex:int, endIndex:int) : void;
		[native(support="none")]
		public function setTextFormat (format:TextFormat, beginIndex:int = -1, endIndex:int = -1) : void;

		public function TextField ();
	}
}
