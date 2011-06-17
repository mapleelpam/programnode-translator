//
// D:\test\lib\playerglobal.swc\flash\text\TextField
//
package flash.text
{
	import flash.display.InteractiveObject;
	import flash.text.TextFormat;
	import flash.text.StyleSheet;
	import flash.geom.Rectangle;
	import flash.text.TextLineMetrics;
	import flash.display.DisplayObject;

	/**
	 Flash Player dispatches the textInput event when a user enters one or more 
     characters of text.
	 @eventType	flash.events.TextEvent.TEXT_INPUT
	 */
	[Event(name="textInput", type="flash.events.TextEvent")] 

	/**
	 Dispatched by a TextField object after the user scrolls.
	 @eventType	flash.events.Event.SCROLL
	 */
	[Event(name="scroll", type="flash.events.Event")] 

	/**
	 Dispatched when a user clicks a hyperlink in an 
     HTML-enabled text field, where the URL begins with "event:".
	 @eventType	flash.events.TextEvent.LINK
	 */
	[Event(name="link", type="flash.events.TextEvent")] 

	/**
	 Dispatched after a control value is modified, unlike 
     the textInput event, which is dispatched before the value is modified.
	 @eventType	flash.events.Event.CHANGE
	 */
	[Event(name="change", type="flash.events.Event")] 

	public class TextField extends InteractiveObject
	{
		/**
		 When set to true and the text field is not in focus, Flash Player highlights the 
         selection in the text field in gray. When set to false and the text field is not in
         focus, Flash Player does not highlight the selection in the text field.
		 */
		[native(support="none")]
		public function get alwaysShowSelection () : Boolean;
		[native(support="none")]
		public function set alwaysShowSelection (value:Boolean) : void;

		/**
		 The type of anti-aliasing used for this text field. Use flash.text.AntiAliasType
         constants for this property. You can control this setting only if the font is
         embedded (with the embedFonts property set to true). 
         The default setting is flash.text.AntiAliasType.NORMAL.

         To set values for this property, use the following string values:String valueDescriptionflash.text.AntiAliasType.NORMALApplies the regular text anti-aliasing. This value matches the type of anti-aliasing that
         Flash Player 7 and earlier versions used.flash.text.AntiAliasType.ADVANCEDApplies advanced anti-aliasing, which makes text more legible. (This feature became
         available in Flash Player 8.) Advanced anti-aliasing allows for high-quality rendering
         of font faces at small sizes. It is best used with applications
         with a lot of small text. Advanced anti-aliasing is not recommended for
         fonts that are larger than 48 points.
		 */
		[native(support="none")]
		public function get antiAliasType () : String;
		[native(support="none")]
		public function set antiAliasType (antiAliasType:String) : void;

		/**
		 Controls automatic sizing and alignment of text fields.
         Acceptable values for the TextFieldAutoSize constants: TextFieldAutoSize.NONE (the default),
         TextFieldAutoSize.LEFT, TextFieldAutoSize.RIGHT, and TextFieldAutoSize.CENTER.

         If autoSize is set to TextFieldAutoSize.NONE (the default) no resizing occurs.If autoSize is set to TextFieldAutoSize.LEFT, the text is
         treated as left-justified text, meaning that the left margin of the text field remains fixed and any
         resizing of a single line of the text field is on the right margin. If the text includes a line break
         (for example, "\n" or "\r"), the bottom is also resized to fit the next
         line of text. If wordWrap is also set to true, only the bottom
         of the text field is resized and the right side remains fixed.If autoSize is set to TextFieldAutoSize.RIGHT, the text is treated as
         right-justified text, meaning that the right margin of the text field remains fixed and any resizing
         of a single line of the text field is on the left margin. If the text includes a line break
         (for example, "\n" or "\r"), the bottom is also resized to fit the next
         line of text. If wordWrap is also set to true, only the bottom
         of the text field is resized and the left side remains fixed.If autoSize is set to TextFieldAutoSize.CENTER, the text is treated as
         center-justified text, meaning that any resizing of a single line of the text field is equally distributed
         to both the right and left margins. If the text includes a line break (for example, "\n" or 
         "\r"), the bottom is also resized to fit the next line of text. If wordWrap is also
         set to true, only the bottom of the text field is resized and the left and
         right sides remain fixed.
		 */
		[native(support="none")]
		public function get autoSize () : String;
		[native(support="none")]
		public function set autoSize (value:String) : void;

		/**
		 Specifies whether the text field has a background fill. If true, the text field has a
	 background fill. If false, the text field has no background fill.
	 Use the backgroundColor property to set the background color of a text field.
		 */
		[native(support="none")]
		public function get background () : Boolean;
		[native(support="none")]
		public function set background (value:Boolean) : void;

		/**
		 The color of the text field background. The default value is 0xFFFFFF (white). 
	 This property can be retrieved or set, even if there currently is no background, but the 
	 color is visible only if the text field has the background property set to 
	 true.
		 */
		[native(support="none")]
		public function get backgroundColor () : uint;
		[native(support="none")]
		public function set backgroundColor (value:uint) : void;

		/**
		 Specifies whether the text field has a border. If true, the text field has a border.
	 If false, the text field has no border. Use the borderColor property 
	 to set the border color.
		 */
		[native(support="none")]
		public function get border () : Boolean;
		[native(support="none")]
		public function set border (value:Boolean) : void;

		/**
		 The color of the text field border. The default value is 0x000000 (black). 
	 This property can be retrieved or set, even if there currently is no border, but the 
	 color is visible only if the text field has the border property set to 
	 true.
		 */
		[native(support="none")]
		public function get borderColor () : uint;
		[native(support="none")]
		public function set borderColor (value:uint) : void;

		/**
		 An integer (1-based index) that indicates the bottommost line that is currently visible in
	 the specified text field. Think of the text field as a window onto a block of text.
	 The scrollV property is the 1-based index of the topmost visible line
	 in the window.
	 
	 All the text between the lines indicated by scrollV and bottomScrollV
	 is currently visible in the text field.
		 */
		[native(support="none")]
		public function get bottomScrollV () : int;

		/**
		 The index of the insertion point (caret) position. If no insertion point is displayed,
     the value is the position the insertion point would be if you restored focus to the field (typically where the 
     insertion point last was, or 0 if the field has not had focus).
	 
	 Selection span indexes are zero-based (for example, the first position is 0,
	 the second position is 1, and so on).
		 */
		[native(support="none")]
		public function get caretIndex () : int;

		/**
		 A Boolean value that specifies whether extra white space (spaces, line breaks, and so on)
	 in a text field with HTML text is removed. The default value is false.
	 The condenseWhite property only affects text set with
	 the htmlText property, not the text property. If you set 
	 text with the text property, condenseWhite is ignored.
	 
	 If condenseWhite is set to true, use standard HTML commands such as
	 <BR> and <P> to place line breaks in the text field.Set the condenseWhite property before setting the htmlText property.
		 */
		[native(support="none")]
		public function get condenseWhite () : Boolean;
		[native(support="none")]
		public function set condenseWhite (value:Boolean) : void;

		/**
		 Specifies the format applied to newly inserted text, such as text entered by a user or text inserted with the 
	 replaceSelectedText() method.
	 
	 Note: When selecting characters to be replaced with setSelection() and
	 replaceSelectedText(), the defaultTextFormat will be applied only if the 
	 text has been selected up to and including the last character. Here is an example:
	 var my_txt:TextField new TextField();
	 my_txt.text = "Flash Macintosh version";
	 var my_fmt:TextFormat = new TextFormat();
	 my_fmt.color = 0xFF0000;
	 my_txt.defaultTextFormat = my_fmt;
	 my_txt.setSelection(6,15); // partial text selected - defaultTextFormat not applied
	 my_txt.setSelection(6,23); // text selected to end - defaultTextFormat applied
	 my_txt.replaceSelectedText("Windows version");
	 When you access the defaultTextFormat property, the returned TextFormat object has all
	 of its properties defined. No property is null.Note: You can't set this property if a style sheet is applied to the text field.
		 */
		public function get defaultTextFormat () : TextFormat;
		public function set defaultTextFormat (format:TextFormat) : void;

		/**
		 Specifies whether the text field is a password text field. If the value of this property is true,
	 the text field is treated as a password text field and hides the input characters using asterisks instead of the
	 actual characters. If false, the text field is not treated as a password text field. When password mode
	 is enabled, the Cut and Copy commands and their corresponding keyboard shortcuts will
	 not function.  This security mechanism prevents an unscrupulous user from using the shortcuts to discover
	 a password on an unattended computer.
		 */
		[native(support="none")]
		public function get displayAsPassword () : Boolean;
		[native(support="none")]
		public function set displayAsPassword (value:Boolean) : void;

		/**
		 Specifies whether to render by using embedded font outlines. 
	 If false, Flash Player renders the text field by using
	 device fonts.
	 
	 If you set the embedFonts property to true for a text field, 
	 you must specify a font for that text by using the font property of 
	 a TextFormat object applied to the text field.
	 If the specified font is not embedded in the SWF file, the text is not displayed.
		 */
		[native(support="none")]
		public function get embedFonts () : Boolean;
		[native(support="none")]
		public function set embedFonts (value:Boolean) : void;

		/**
		 The type of grid fitting used for this text field. This property applies only if the
	 flash.text.AntiAliasType property of the text field is set to flash.text.AntiAliasType.ADVANCED.
	 
	 The type of grid fitting used determines whether Flash Player forces strong horizontal and 
	 vertical lines to fit to a pixel or subpixel grid, or not at all.For the flash.text.GridFitType property, you can use the following string values:String valueDescriptionflash.text.GridFitType.NONESpecifies no grid fitting. Horizontal and vertical lines in the glyphs are not
	         forced to the pixel grid. This setting is recommended for animation or
	         for large font sizes.flash.text.GridFitType.PIXELSpecifies that strong horizontal and vertical lines are fit to the
	         pixel grid. This setting works only for left-aligned text fields.
	         To use this setting, the flash.dispaly.AntiAliasType property of the text field
	 	   must be set to flash.text.AntiAliasType.ADVANCED.
	 	   This setting generally provides the best legibility for
	         left-aligned text.flash.text.GridFitType.SUBPIXELSpecifies that strong horizontal and vertical lines are fit to the subpixel grid on
	         an LCD monitor. To use this setting, the
	         flash.text.AntiAliasType property of the text field must be set to
	         flash.text.AntiAliasType.ADVANCED. The flash.text.GridFitType.SUBPIXEL setting is often good
	 	   for right-aligned or centered
	         dynamic text, and it is sometimes a useful trade-off for animation versus text quality.
		 */
		[native(support="none")]
		public function get gridFitType () : String;
		[native(support="none")]
		public function set gridFitType (gridFitType:String) : void;

		/**
		 Contains the HTML representation of the text field contents. 
	 
	 Flash Player supports the following HTML tags:
	 Tag
	 
	 Description
	 
	 Anchor tag
	 
	 The <a> tag creates a hypertext link and supports the following attributes:
	 target: Specifies the name of the target window where you load the page. 
	 Options include _self, _blank, _parent, and 
	 _top. The _self option specifies the current frame in the current window, 
	 _blank specifies a new window, _parent specifies the parent of the 
	 current frame, and _top specifies the top-level frame in the current window. 
	 href: Specifies a URL or an ActionScript link event.The URL can 
	 be either absolute or relative to the location of the SWF file that 
	 is loading the page. An example of an absolute reference to a URL is 
	 http://www.adobe.com; an example of a relative reference is 
	 /index.html. Absolute URLs must be prefixed with 
	 http://; otherwise, Flash Player or AIR treats them as relative URLs. 
	 
	 You can use the link event to cause the link to execute an ActionScript 
	 function in a SWF file instead of opening a URL. To specify a link event, use 
	 the event scheme instead of the http scheme in your href attribute. An example 
	 is href="event:myText" instead of href="http://myURL"; when the 
	 user clicks a hypertext link that contains the event scheme, the text field dispatches a 
	 link TextEvent with its text property set to "myText". You can then create an ActionScript 
	 function that executes whenever the link TextEvent is dispatched. 
	 
	 You can also define a:link, a:hover, and a:active 
	 styles for anchor tags by using style sheets.
	 
	 Bold tag
	 
	 The <b> tag renders text as bold. A bold typeface must be available for the font used.
	 
	 Break tag
	 
	 The <br> tag creates a line break in the text field. Set the text field to 
	 be a multiline text field to use this tag.
	 
	 Font tag
	 
	 The <font> tag specifies a font or list of fonts to display the text.The font tag 
	 supports the following attributes:
	 color: Only hexadecimal color (#FFFFFF) values are supported. 
	 face: Specifies the name of the font to use. As shown in the following example, 
	 you can specify a list of comma-delimited font names, in which case Flash Player selects the first available 
	 font. If the specified font is not installed on the local computer system or isn't embedded in the SWF file, 
	 Flash Player selects a substitute font. 
	 size: Specifies the size of the font. You can use absolute pixel sizes, such as 16 or 18, 
	 or relative point sizes, such as +2 or -4. 
	 
	 Image tag
	 
	 The <img> tag lets you embed external image files (JPEG, GIF, PNG), SWF files, and 
	 movie clips inside text fields. Text automatically flows around images you embed in text fields. You 
	 must set the text field to be multiline to wrap text around an image. 
	 
	  The <img> tag supports the following attributes: src: Specifies the URL to an image or SWF file, or the linkage identifier for a movie clip 
	 symbol in the library. This attribute is required; all other attributes are optional. External files (JPEG, GIF, PNG, 
	 and SWF files) do not show until they are downloaded completely. 
	 width: The width of the image, SWF file, or movie clip being inserted, in pixels. 
	 height: The height of the image, SWF file, or movie clip being inserted, in pixels. 
	 align: Specifies the horizontal alignment of the embedded image within the text field. 
     Valid values are left and right. The default value is left. 
	 hspace: Specifies the amount of horizontal space that surrounds the image where 
	 no text appears. The default value is 8. 
	 vspace: Specifies the amount of vertical space that surrounds the image where no 
	 text appears. The default value is 8.  
	 id: Specifies the name for the movie clip instance (created by Flash Player) that contains 
	 the embedded image file, SWF file, or movie clip. This approach is used to control the embedded content with 
	 ActionScript. 
	 checkPolicyFile: Specifies that Flash Player checks for a URL policy file
	 on the server associated with the image domain. If a policy file exists, SWF files in the domains
	 listed in the file can access the data of the loaded image, for example, by calling the 
	 BitmapData.draw() method with this image as the source parameter. For more information,
	 see the "Flash Player Security" chapter in Programming ActionScript 3.0.
	 Flash displays media embedded in a text field at full size. To specify the dimensions of the media 
	 you are embedding, use the <img> tag height and width 
	 attributes. In general, an image embedded in a text field appears on the line following the 
	 <img> tag. However, when the <img> tag 
	 is the first character in the text field, the image appears on the first line of the text field. For AIR content in the application security sandbox, AIR ignores img tags in 
	 HTML content in ActionScript TextField objects. This is to prevent possible phishing attacks,
	 Italic tag
	 
	 The <i> tag displays the tagged text in italics. An italic typeface must be available 
	 for the font used.
	 
	 List item tag
	 
	 The <li> tag places a bullet in front of the text that it encloses. 
	 Note: Because Flash Player and AIR do not recognize ordered and unordered list tags (<ol> 
	 and <ul>, they do not modify how your list is rendered. All lists are unordered and all 
	 list items use bullets.
	 
	 Paragraph tag
	 
	 The <p> tag creates a new paragraph. The text field must be set to be a multiline 
	 text field to use this tag. 
	 
	 The <p> tag supports the following attributes:
	 
	 align: Specifies alignment of text within the paragraph; valid values are left, right, justify, and center. 
	 
	 class: Specifies a CSS style class defined by a flash.text.StyleSheet object. 
	 
	 Span tag
	 
	 
	 The <span> tag is available only for use with CSS text styles. It supports the 
	 following attribute:
	 
	 
	 class: Specifies a CSS style class defined by a flash.text.StyleSheet object. 
	 
	 Text format tag
	 The <textformat> tag lets you use a subset of paragraph formatting 
	 properties of the TextFormat class within text fields, including line leading, indentation, 
	 margins, and tab stops. You can combine <textformat> tags with the 
	 built-in HTML tags. The <textformat> tag has the following attributes: blockindent: Specifies the block indentation in points; corresponds to 
	 TextFormat.blockIndent. 
	 indent: Specifies the indentation from the left margin to the first character 
	 in the paragraph; corresponds to TextFormat.indent. Both positive and negative 
	 numbers are acceptable. 
	 leading: Specifies the amount of leading (vertical space) between lines; 
	 corresponds to TextFormat.leading. Both positive and negative numbers are acceptable. 
	 leftmargin: Specifies the left margin of the paragraph, in points; corresponds 
	 to TextFormat.leftMargin. 
	 rightmargin: Specifies the right margin of the paragraph, in points; corresponds 
	 to TextFormat.rightMargin. 
	 tabstops: Specifies custom tab stops as an array of non-negative integers; 
	 corresponds to TextFormat.tabStops. 
	 
	 Underline tag
	 
	 The <u> tag underlines the tagged text.
	 Flash Player and AIR support the following HTML entities:
	 Entity
	 
	 Description
	 
	 
	 &amp;lt;	
	 
	 
	 
	 < (less than)
	 
	 
	 
	 &amp;gt;	
	 
	 
	 
	 > (greater than)
	 
	 
	 
	 &amp;amp;	
	 
	 
	 
	 & (ampersand)
	 
	 
	 &amp;quot;	
	 
	 
	 
	 " (double quotes)
	 
	 
	 
	 &amp;apos;	
	 
	 
	 
	 ' (apostrophe, single quote)
	 
	 Flash Player and AIR also support explicit character codes, such as 
	  &#38; (ASCII ampersand) and &#x20AC; (Unicode € symbol).
		 */
		[native(support="none")]
		public function get htmlText () : String;
		[native(support="none")]
		public function set htmlText (value:String) : void;

		/**
		 The number of characters in a text field. A character such as tab (\t) counts as one
	 character.
		 */
		[native(support="none")]
		public function get length () : int;

		/**
		 The maximum number of characters that the text field can contain, as entered by a user.
	 A script can insert more text than maxChars allows; the maxChars property
	 indicates only how much text a user can enter. If the value of this property is 0,
	 a user can enter an unlimited amount of text.
		 */
		[native(support="none")]
		public function get maxChars () : int;
		[native(support="none")]
		public function set maxChars (value:int) : void;

		/// The maximum value of scrollH.
		[native(support="none")]
		public function get maxScrollH () : int;

		/// The maximum value of scrollV.
		[native(support="none")]
		public function get maxScrollV () : int;

		/**
		 A Boolean value that indicates whether Flash Player automatically scrolls multiline
	 text fields when the user clicks a text field and rolls the mouse wheel.
	 By default, this value is true. This property is useful if you want to prevent
	 mouse wheel scrolling of text fields, or implement your own text field scrolling.
		 */
		[native(support="none")]
		public function get mouseWheelEnabled () : Boolean;
		[native(support="none")]
		public function set mouseWheelEnabled (value:Boolean) : void;

		/**
		 Indicates whether field is a multiline text field. If the value is true,
	 the text field is multiline; if the value is false, the text field is a single-line
	 text field. In a field of type TextFieldType.INPUT, the multiline value
	 determines whether the Enter key creates a new line (a value of false,
	 and the Enter key is ignored).
	 If you paste text into a TextField with a multiline value of false,
	 newlines are stripped out of the text.
		 */
		[native(support="none")]
		public function get multiline () : Boolean;
		[native(support="none")]
		public function set multiline (value:Boolean) : void;

		/**
		 Defines the number of text lines in a multiline text field. 
	 If wordWrap property is set to true,
	 the number of lines increases when text wraps.
		 */
		[native(support="none")]
		public function get numLines () : int;

		/**
		 Indicates the set of characters that a user can enter into the text field. If the value of the
	 restrict property is null, you can enter any character. If the value of
	 the restrict property is an empty string, you cannot enter any character. If the value
	 of the restrict property is a string of characters, you can enter only characters in
	 the string into the text field. The string is scanned from left to right. You can specify a range by
	 using the hyphen (-) character. Only user interaction is restricted; a script can put any text into the 
	 text field. This property does not synchronize with the Embed font options
	 in the Property inspector.If the string begins with a caret (^) character, all characters are initially accepted and 
	 succeeding characters in the string are excluded from the set of accepted characters. If the string does 
	 not begin with a caret (^) character, no characters are initially accepted and succeeding characters in the 
	 string are included in the set of accepted characters.The following example allows only uppercase characters, spaces, and numbers to be entered into
	 a text field:
	 my_txt.restrict = "A-Z 0-9";
	 The following example includes all characters, but excludes lowercase letters:
	 my_txt.restrict = "^a-z";
	 You can use a backslash to enter a ^ or - verbatim. The accepted backslash sequences are \-, \^ or \\.
	 The backslash must be an actual character in the string, so when specified in ActionScript, a double backslash
	 must be used. For example, the following code includes only the dash (-) and caret (^):
	 my_txt.restrict = "\\-\\^";
	 The ^ can be used anywhere in the string to toggle between including characters and excluding characters.
	 The following code includes only uppercase letters, but excludes the uppercase letter Q:
	 my_txt.restrict = "A-Z^Q";
	 You can use the \u escape sequence to construct restrict strings.
	 The following code includes only the characters from ASCII 32 (space) to ASCII 126 (tilde).
     my_txt.restrict = "\u0020-\u007E";
		 */
		[native(support="none")]
		public function get restrict () : String;
		[native(support="none")]
		public function set restrict (value:String) : void;

		/**
		 The current horizontal scrolling position. If the scrollH property is 0, the text
	 is not horizontally scrolled. This property value is an integer that represents the horizontal
	 position in pixels.
	 
	 
	 The units of horizontal scrolling are pixels, whereas the units of vertical scrolling are lines.
	 Horizontal scrolling is measured in pixels because most fonts you typically use are proportionally
	 spaced; that is, the characters can have different widths. Flash Player performs vertical scrolling by
	 line because users usually want to see a complete line of text rather than a
	 partial line. Even if a line uses multiple fonts, the height of the line adjusts to fit
	 the largest font in use.Note: The scrollH property is zero-based, not 1-based like 
	 the scrollV vertical scrolling property.
		 */
		[native(support="none")]
		public function get scrollH () : int;
		[native(support="none")]
		public function set scrollH (value:int) : void;

		/**
		 The vertical position of text in a text field. The scrollV property is useful for
	 directing users to a specific paragraph in a long passage, or creating scrolling text fields.
	 
	 The units of vertical scrolling are lines, whereas the units of horizontal scrolling are pixels.
	 If the first line displayed is the first line in the text field, scrollV is set to 1 (not 0).
	 Horizontal scrolling is measured in pixels because most fonts are proportionally
	 spaced; that is, the characters can have different widths. Flash performs vertical scrolling by line
	 because users usually want to see a complete line of text rather than a partial line.
	 Even if there are multiple fonts on a line, the height of the line adjusts to fit the largest font in
	 use.
		 */
		[native(support="none")]
		public function get scrollV () : int;
		[native(support="none")]
		public function set scrollV (value:int) : void;

		/**
		 A Boolean value that indicates whether the text field is selectable. The value true
	 indicates that the text is selectable. The selectable property controls whether
	 a text field is selectable, not whether a text field is editable. A dynamic text field can
	 be selectable even if it is not editable. If a dynamic text field is not selectable, the user
	 cannot select its text.
	 
	 If selectable is set to false, the text in the text field does not
	 respond to selection commands from the mouse or keyboard, and the text cannot be copied with the
	 Copy command. If selectable is set to true, the text in the text field
	 can be selected with the mouse or keyboard, and the text can be copied with the Copy command. 
	 You can select text this way even if the text field is a dynamic text field instead of an input text field.
		 */
		[native(support="none")]
		public function get selectable () : Boolean;
		[native(support="none")]
		public function set selectable (value:Boolean) : void;
		[native(support="none")]
		public function get selectedText () : String;

		/**
		 The zero-based character index value of the first character in the current selection.
	 For example, the first character is 0, the second character is 1, and so on. If no
	 text is selected, this property is the value of caretIndex.
		 */
		[native(support="none")]
		public function get selectionBeginIndex () : int;

		/**
		 The zero-based character index value of the last character in the current selection.
     For example, the first character is 0, the second character is 1, and so on. If no
     text is selected, this property is the value of caretIndex.
		 */
		[native(support="none")]
		public function get selectionEndIndex () : int;

		/**
		 The sharpness of the glyph edges in this text field. This property applies
	 only if the flash.text.AntiAliasType property of the text field is set to
	 flash.text.AntiAliasType.ADVANCED. The range for
	 sharpness is a number from -400 to 400. If you attempt to set
	 sharpness to a value outside that range, Flash sets the property to
	 the nearest value in the range (either -400 or 400).
		 */
		[native(support="none")]
		public function get sharpness () : Number;
		[native(support="none")]
		public function set sharpness (value:Number) : void;

		/**
		 Attaches a style sheet to the text field. For information on creating style sheets, see the StyleSheet class
	 and Programming ActionScript 3.0.
	 
	 You can change the style sheet associated with a text field at any time. If you change
	 the style sheet in use, the text field is redrawn with the new style sheet. 
	 You can set the style sheet to null or undefined 
     to remove the style sheet. If the style sheet in use is removed, the text field is redrawn without a style sheet. Note: If the style sheet is removed, the contents of both TextField.text and 
     TextField.htmlText change to incorporate the formatting previously applied by the style sheet. To preserve
     the original TextField.htmlText contents without the formatting, save the value in a variable before
     removing the style sheet.
		 */
		[native(support="none")]
		public function get styleSheet () : StyleSheet;
		[native(support="none")]
		public function set styleSheet (value:StyleSheet) : void;

		/**
		 A string that is the current text in the text field. Lines are separated by the carriage
	 return character ('\r', ASCII 13). This property contains unformatted text in the text
	 field, without HTML tags.
	 
	 To get the text in HTML form, use the htmlText property.
		 */
		public function get text () : String;
		public function set text (value:String) : void;

		/**
		 The color of the text in a text field, in hexadecimal format.
	 The hexadecimal color system uses six digits to represent
	 color values. Each digit has 16 possible values or characters. The characters range from
	 0-9 and then A-F. For example, black is 0x000000; white is
	 0xFFFFFF.
		 */
		public function get textColor () : uint;
		public function set textColor (value:uint) : void;

		/// The height of the text in pixels.
		[native(support="none")]
		public function get textHeight () : Number;

		/// The width of the text in pixels.
		[native(support="none")]
		public function get textWidth () : Number;

		/**
		 The thickness of the glyph edges in this text field. This property applies only
	 when flash.text.AntiAliasType is set to flash.text.AntiAliasType.ADVANCED.
	 
	 The range for thickness is a number from -200 to 200. If you attempt to
	 set thickness to a value outside that range, the property is set to the
	 nearest value in the range (either -200 or 200).
		 */
		[native(support="none")]
		public function get thickness () : Number;
		[native(support="none")]
		public function set thickness (value:Number) : void;

		/**
		 The type of the text field.
	 Either one of the following TextFieldType constants: TextFieldType.DYNAMIC,
	 which specifies a dynamic text field, which a user cannot edit, or TextFieldType.INPUT,
	 which specifies an input text field, which a user can edit.
		 */
		[native(support="none")]
		public function get type () : String;
		[native(support="none")]
		public function set type (value:String) : void;
		[native(support="none")]
		public function get useRichTextClipboard () : Boolean;
		/**
		 Specifies whether to copy and paste the text formatting along with the text. When set to true,
     Flash Player copies and pastes formatting (such as alignment, bold, and italics) when you copy and paste between text fields. Both the origin and destination text fields for the copy and paste procedure must have
	 useRichTextClipboard set to true. The default value
	 is false.
		 */
		[native(support="none")]
		public function set useRichTextClipboard (value:Boolean) : void;

		/**
		 A Boolean value that indicates whether the text field has word wrap. If the value of
	 wordWrap is true, the text field has word wrap;
	 if the value is false, the text field does not have word wrap. The default
	 value is false.
		 */
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