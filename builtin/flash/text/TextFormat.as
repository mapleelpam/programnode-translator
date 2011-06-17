//
// D:\test\lib\playerglobal.swc\flash\text\TextFormat
//
package flash.text
{
	public class TextFormat extends Object
	{
		/// Indicates the alignment of the paragraph. Valid values are TextFormatAlign constants.
		[native(support="none")]
		public function get align () : String;
		[native(support="none")]
		public function set align (value:String) : void;

		/**
		 Indicates the block indentation in pixels. Block indentation is applied to
	 an entire block of text; that is, to all lines of the text. In contrast, normal indentation 
	 (TextFormat.indent) affects only the first line of each paragraph. 
	 If this property is null, the TextFormat object does not specify block indentation
	 (block indentation is 0).
		 */
		[native(support="none")]
		public function get blockIndent () : Object;
		[native(support="none")]
		public function set blockIndent (value:Object) : void;

		/**
		 Specifies whether the text is boldface. The default value is null,
	 which means no boldface is used.
	 If the value is true, then
	 the text is boldface.
		 */
		[native(support="none")]
		public function get bold () : Object;
		[native(support="none")]
		public function set bold (value:Object) : void;

		/**
		 Indicates that the text is part of a bulleted list. In a bulleted
	 list, each paragraph of text is indented. To the left of the first line of each paragraph, a bullet
	 symbol is displayed. The default value is null, which means no bulleted list   
	 is used.
		 */
		[native(support="none")]
		public function get bullet () : Object;
		[native(support="none")]
		public function set bullet (value:Object) : void;

		/**
		 Indicates the color of the text. A number containing three 8-bit RGB components; for example,
	 0xFF0000 is red, and 0x00FF00 is green. The default value is null,
	 which means that Flash Player uses the color black (0x000000).
		 */
		public function get color () : Object;
		public function set color (value:Object) : void;

		[native(support="none")]
		public function get display () : String;
		[native(support="none")]
		public function set display (value:String) : void;

		/**
		 The name of the font for text in this text format, as a string. The default value is
	 null, which means that Flash Player uses Times New Roman font for the text.
		 */
		public function get font () : String;
		public function set font (value:String) : void;

		/**
		 Indicates the indentation from the left
	 margin to the first character in the paragraph. The default value is null, which
	 indicates that no indentation is used.
		 */
		[native(support="none")]
		public function get indent () : Object;
		[native(support="none")]
		public function set indent (value:Object) : void;

		/**
		 Indicates whether text in this text format is italicized. The default
	 value is null, which means no italics are used.
		 */
		[native(support="none")]
		public function get italic () : Object;
		[native(support="none")]
		public function set italic (value:Object) : void;

		/**
		 A Boolean value that indicates whether kerning is enabled (true) 
	 or disabled (false). Kerning adjusts the pixels between certain character pairs to improve readability, and 
	 should be used only when necessary, such as with headings in large fonts. Kerning is 
	 supported for embedded fonts only.
	 
	 Certain fonts such as Verdana and monospaced fonts, 
     such as Courier New,  do not support kerning.The default value is null, which means that kerning is not enabled.
		 */
		[native(support="none")]
		public function get kerning () : Object;
		[native(support="none")]
		public function set kerning (value:Object) : void;

		/**
		 An integer representing the amount of vertical space (called leading)
	 between lines. The default value is null, which indicates that the
	 amount of leading used is 0.
		 */
		[native(support="none")]
		public function get leading () : Object;
		[native(support="none")]
		public function set leading (value:Object) : void;

		/**
		 The left margin of the paragraph, in pixels. The default value is null, which
	 indicates that the left margin is 0 pixels.
		 */
		[native(support="none")]
		public function get leftMargin () : Object;
		[native(support="none")]
		public function set leftMargin (value:Object) : void;

		/**
		 A number representing the amount of space that is uniformly distributed between all characters.
	 The value specifies the number of pixels that are added to the advance after each character.
	 The default value is null, which means that 0 pixels of letter spacing is used.
     You can use decimal values such as 1.75.
		 */
		[native(support="none")]
		public function get letterSpacing () : Object;
		[native(support="none")]
		public function set letterSpacing (value:Object) : void;

		/**
		 The right margin of the paragraph, in pixels. The default value is null,
	 which indicates that the right margin is 0 pixels.
		 */
		[native(support="none")]
		public function get rightMargin () : Object;
		[native(support="none")]
		public function set rightMargin (value:Object) : void;

		/**
		 The size in pixels of text in this text format. The default value is null, which
	 means that a size of 12 is used.
		 */
		public function get size () : Object;
		public function set size (value:Object) : void;

		/**
		 Specifies custom tab stops as an array of non-negative integers. Each tab stop is
	 specified in pixels. If custom tab stops are not specified (null), the default tab
	 stop is 4 (average character width).
		 */
		[native(support="none")]
		public function get tabStops () : Array;
		[native(support="none")]
		public function set tabStops (value:Array) : void;

		/**
		 Indicates the target window where the hyperlink is displayed. If the target window is an
	 empty string, the text is displayed in the default target window _self. You can choose
	 a custom name or one of the following four names: _self specifies the current frame in
	 the current window, _blank specifies a new window, _parent specifies the
	 parent of the current frame, and _top specifies the top-level frame in the current
	 window. If the TextFormat.url property is an empty string or null, 
	 you can get or set this property, but the property will have no effect.
		 */
		[native(support="none")]
		public function get target () : String;
		[native(support="none")]
		public function set target (value:String) : void;

		/**
		 Indicates whether the text that uses this text format is underlined (true)
	 or not (false). This underlining is similar to that produced by the
	 <U> tag, but the latter is not true underlining, because it does not skip
	 descenders correctly. The default value is null, which indicates that underlining
	 is not used.
		 */
		[native(support="none")]
		public function get underline () : Object;
		[native(support="none")]
		public function set underline (value:Object) : void;

		/**
		 Indicates the target URL for the text in this text format. If the url
	 property is an empty string, the text does not have a hyperlink. The default value is null,
	 which indicates that the text does not have a hyperlink.
	 Note: The text with the assigned text format must be set with the htmlText
	 property for the hyperlink to work.
		 */
		[native(support="none")]
		public function get url () : String;
		[native(support="none")]
		public function set url (value:String) : void;

		public function TextFormat (font:String = null, size:Object = null, color:Object = null, bold:Object = null, italic:Object = null, underline:Object = null, url:String = null, target:String = null, align:String = null, leftMargin:Object = null, rightMargin:Object = null, indent:Object = null, leading:Object = null);
	}
}
