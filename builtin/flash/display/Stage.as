//
// D:\test\lib\playerglobal.swc\flash\display\Stage
//
package flash.display
{
	import flash.display.InteractiveObject;
	import flash.geom.Rectangle;
	import flash.display.DisplayObject;
	import flash.geom.Transform;
	import flash.accessibility.AccessibilityProperties;
	import flash.accessibility.AccessibilityImplementation;
	import flash.events.Event;
	import flash.text.TextSnapshot;
	import flash.ui.ContextMenu;

	/**
	 Dispatched when the Stage object enters, or leaves, full-screen mode.
	 @eventType	flash.events.FullScreenEvent.FULL_SCREEN
	 */
	[Event(name="fullScreen", type="flash.events.FullScreenEvent")] 

	/**
	 Dispatched when the scaleMode property of the Stage object is set to 
 StageScaleMode.NO_SCALE and the SWF file is resized.
	 @eventType	flash.events.Event.RESIZE
	 */
	[Event(name="resize", type="flash.events.Event")] 

	/**
	 Dispatched by the Stage object when the mouse pointer moves out of the  
 stage area.
	 @eventType	flash.events.Event.MOUSE_LEAVE
	 */
	[Event(name="mouseLeave", type="flash.events.Event")] 

	public class Stage extends DisplayObjectContainer
	{
		[native(support="none")]
		public function set accessibilityImplementation (value:AccessibilityImplementation) : void;

		[native(support="none")]
		public function set accessibilityProperties (value:AccessibilityProperties) : void;

		/**
		 A value from the StageAlign class that specifies the alignment of the stage in
	 Flash Player or the browser. The following are valid values:
	 
	 ValueVertical AlignmentHorizontalStageAlign.TOPTopCenterStageAlign.BOTTOMBottomCenterStageAlign.LEFTCenterLeftStageAlign.RIGHTCenterRightStageAlign.TOP_LEFTTopLeftStageAlign.TOP_RIGHTTopRightStageAlign.BOTTOM_LEFTBottomLeftStageAlign.BOTTOM_RIGHTBottomRightThe align property is only available to an object that is in the same security sandbox 
	 as the Stage owner (the main SWF file).
	  To avoid this, the Stage owner can grant permission to the domain of the 
	 calling object by calling the Security.allowDomain() method or the Security.alowInsecureDomain() method.
	 For more information, see the "Security" chapter in Programming ActionScript 3.0.
		 */
		[native(support="none")]
		public function get align () : String;
		[native(support="none")]
		public function set align (value:String) : void;
		[native(support="api")]
		public function set alpha (value:Number) : void;
		[native(support="api")]
		public function set blendMode (value:String) : void;
		[native(support="none")]
		public function set cacheAsBitmap (value:Boolean) : void;

		/**
		 Controls Flash Player color correction for displays.
     Color correction works only if the main monitor is assigned a valid ICC color profile, which specifies 
     the device's particular color attributes.
     By default, Flash Player tries to match the color correction of its host (usually a browser).
     
     Use the Stage.colorCorrectionSupport property
     to determine if color correction is available on the current system and the default state. 
.    If color correction is available, all colors on the stage are assumed to be in 
     the sRGB color space, which is the most standard color space. Source profiles of input devices are not considered during color correction. 
     No input color correction is applied; only the stage output is mapped to the main 
     monitor's ICC color profile.In general, the benefits to activating color management include predictable and consistent color, better conversion, 
     accurate proofing and more efficient cross-media output. Be aware, though, that color management does not provide 
     perfect conversions due to devices having a different gamut from each other or original images. 
     Nor does color management eliminate the need for custom or edited profiles. 
     Color profiles are dependent on browsers, operating systems (OS), OS extensions, output devices, and application support.Applying color correction degrades Flash Player performance. 
     Flash Player's color correction is a document style color correction because
     all SWF movies are considered documents with implicit sRGB profiles. 
     Use the Stage.colorCorrectionSupport property to tell Flash Player 
     to correct colors as best as it can when displaying the SWF (document) to the display color space.
     Flash Player only compensates for differences between monitors, not for differences between input devices (camera/scanner/etc.).
     The three possible values are strings with corresponding constants in the flash.display.ColorCorrection class:"default": Use the same color correction as the host system."on": Always perform color correction."off": Never perform color correction.
		 */
		[native(support="none")]
		public function get colorCorrection () : String;
		[native(support="none")]
		public function set colorCorrection (value:String) : void;

		/**
		 Specifies whether Flash Player is running on an operating system that supports 
      color correction and whether the color profile of the main (primary) 
      monitor can be read and understood by Flash Player. This property also returns the default state
      of color correction on the host system (usually the browser).
      Currently the return values can be:
 	  The three possible values are strings with corresponding constants in the flash.display.ColorCorrectionSupport class:"unsupported": Color correction is not available."defaultOn": Always performs color correction."defaultOff": Never performs color correction.
		 */
		[native(support="none")]
		public function get colorCorrectionSupport () : String;
		[native(support="none")]
		public function set contextMenu (value:ContextMenu) : void;

		/**
		 A value from the StageDisplayState class that specifies which display state to use. The following
	 are valid values: 
	 
	 StageDisplayState.FULL_SCREEN Sets AIR application or Flash Player to expand the 
	 stage over the user's entire screen, with keyboard input disabled.StageDisplayState.FULL_SCREEN_INTERACTIVE Sets the AIR application to expand the 
	 stage over the user's entire screen, with keyboard input allowed. 
	 (Not available for content running in Flash Player.)StageDisplayState.NORMAL Sets the player back to the standard stage display mode.The scaling behavior of the movie in full-screen mode is determined by the scaleMode 
     setting (set using the Stage.scaleMode property or the SWF file's embed 
     tag settings in the HTML file). If the scaleMode property is set to noScale 
     while the application transitions to full-screen mode, the Stage width and height 
     properties are updated, and the Stage the resize event.The following restrictions apply to SWF files that play within an HTML page (not those using the stand-alone 
	 Flash Player or not running in the AIR runtime):To enable full-screen mode, add the allowFullScreen parameter to the object 
	 and embed tags in the HTML page that includes the SWF file, with allowFullScreen set 
	 to "true", as shown in the following example:
	 
	 <param name="allowFullScreen" value="true" />
	        ...
	 <embed src="example.swf" allowFullScreen="true" ... >An HTML page may also use a script to generate SWF-embedding tags. You need to alter the script 
	 so that it inserts the proper allowFullScreen settings. HTML pages generated by Flash and  
	 Flex Builder use the AC_FL_RunContent() function to embed references to SWF files, and you 
	 need to add the allowFullScreen parameter settings, as in the following:AC_FL_RunContent( ... "allowFullScreen", "true", ... )Full-screen mode is initiated in response to a mouse click or key press by the user; the movie cannot change 
     Stage.displayState without user input. Flash Player restricts keyboard input  in full-screen mode. 
     Acceptable keys include keyboard shortcuts that terminate full-screen mode and non-printing keys such as arrows, space, Shift,
     and Tab keys. Keyboard shortcuts that terminate full-screen mode are: Escape (Windows, Linux, and Mac), Control+W (Windows), 
     Command+W (Mac), and Alt+F4.
     A Flash Player dialog box appears over the movie when users enter full-screen mode to inform the users they are in 
     full-screen mode and that they can press the Escape key to end full-screen mode.Starting with Flash Player 9.0.115.0, full-screen works the same in windowless mode as it does in window mode. 
     If you set the Window Mode (wmode in the HTML) to Opaque Windowless (opaque) 
     or Transparent Windowless (transparent), full-screen can be initiated, 
	 but the full-screen window will always be opaque.These restrictions are not present for SWF content running in the 
	 stand-alone Flash Player or in AIR. AIR supports an interactive full-screen mode which allows keyboard input.For AIR content running in full-screen mode, the system screen saver
	 and power saving options are disabled while video content is playing and until until either the video stops 
	 or full-screen mode is exited.On Linux, setting displayState to StageDisplayState.FULL_SCREEN or
	 StageDisplayState.FULL_SCREEN_INTERACTIVE is an asynchronous operation.
		 */
		[native(support="none")]
		public function get displayState () : String;
		[native(support="none")]
		public function set displayState (value:String) : void;
		
		public function set filters (value:Array) : void;

		/**
		 The interactive object with keyboard focus; or null if focus is not set 
	 or if the focused object belongs to a security sandbox to which the calling object does not 
	 have access.
		 */
		[native(support="none")]
		public function get focus () : InteractiveObject;
		[native(support="none")]
		public function set focus (newFocus:InteractiveObject) : void;
		[native(support="none")]
		public function set focusRect (value:Object) : void;

		/**
		 Gets and sets the frame rate of the stage. The frame rate is defined as frames per second. 
	 By default the rate is set to the frame rate of the first SWF file loaded. Valid range for the frame rate 
	 is from 0.01 to 1000 frames per second. 
	 
	 Note: An application might not be able to follow
	 high frame rate settings, either because the target platform is not fast enough or the player is
	 synchronized to the vertical blank timing of the display device (usually 60 Hz on LCD devices).
	 In some cases, a target platform might also choose to lower the maximum frame rate if it 
	 anticipates high CPU usage.For content running in Adobe AIR, setting the frameRate property of one Stage
	 object changes the frame rate for all Stage objects (used by different NativeWindow objects).
		 */
		[native(support="none")]
		public function get frameRate () : Number;
		[native(support="none")]
		public function set frameRate (value:Number) : void;

		/**
		 Returns the height of the monitor that will be used when going to full screen size, if that state 
  is entered immediately. If the user has multiple monitors, the monitor that's used is the 
  monitor that most of the stage is on at the time.
  
  Note: If the user has the opportunity to move the browser from one 
  monitor to another between retrieving the value and going to full screen
  size, the value could be incorrect. If you retrieve the value in an event handler that
  sets Stage.displayState to StageDisplayState.FULL_SCREEN, the value will be
  correct.This is the pixel height of the monitor and is the same as the 
  stage height would be if Stage.align is set to StageAlign.TOP_LEFT
  and Stage.scaleMode is set to StageScaleMode.NO_SCALE.
		 */
		[native(support="none")]
		public function get fullScreenHeight () : uint;

		/**
		 Sets Flash Player to scale a specific region of the stage to full-screen mode. 
  If available, Flash Player scales in hardware, which uses the graphics and video card on a user's computer,
  and generally displays content more quickly than software scaling.
  
  When this property is set to a valid rectangle and the displayState property is set to full-screen mode, 
  Flash Player scales the specified area. The actual Stage size in pixels within ActionScript does not change.
  Flash Player enforces a minimum limit for the size of the rectangle to accommodate the standard "Press Esc to exit full-screen mode" message.
  This limit is usually around 260 by 30 pixels but can vary on platform and Flash Player version.This property can only be set when Flash Player is not in full-screen mode. 
  To use this property correctly, set this property first, then set the displayState property to full-screen mode, as shown in the code examples.To enable scaling, set the fullScreenSourceRect property to a rectangle object:  
  // valid, will enable hardware scaling
  stage.fullScreenSourceRect = new Rectangle(0,0,320,240); 
  To disable scaling, set the fullScreenSourceRect=null in ActionScript 3.0, and undefined in ActionScript 2.0.
  stage.fullScreenSourceRect = null;
  The end user also can select within Flash Player Display Settings to turn off hardware scaling, which is enabled by default. 
  For more information, see www.adobe.com/go/display_settings.
		 */
		[native(support="none")]
		public function get fullScreenSourceRect () : Rectangle;
		[native(support="none")]
		public function set fullScreenSourceRect (value:Rectangle) : void;

		/**
		 Returns the width of the monitor that will be used when going to full screen size, if that state 
  is entered immediately. If the user has multiple monitors, the monitor that's used is the
  monitor that most of the stage is on at the time. 
  
  Note: If the user has the opportunity to move the browser from one 
  monitor to another between retrieving the value and going to full screen
  size, the value could be incorrect. If you retrieve the value in an event handler that
  sets Stage.displayState to StageDisplayState.FULL_SCREEN, the value will be
  correct.This is the pixel width of the monitor and is the same as the stage width would be if 
  Stage.align is set to StageAlign.TOP_LEFT and 
  Stage.scaleMode is set to StageScaleMode.NO_SCALE.
		 */
		[native(support="none")]
		public function get fullScreenWidth () : uint;

		/**
		 Indicates the height of the display object, in pixels. The height is calculated based on the bounds of the content of the display object.
     When you set the height property, the scaleY property is adjusted accordingly, as shown in the 
     following code:
     
     
    var rect:Shape = new Shape();
    rect.graphics.beginFill(0xFF0000);
    rect.graphics.drawRect(0, 0, 100, 100);
    trace(rect.scaleY) // 1;
    rect.height = 200;
    trace(rect.scaleY) // 2;Except for TextField and Video objects, a display object with no content (such as an empty sprite) has a height 
    of 0, even if you try to set height to a different value.
		 */
		public function get height () : Number;
		public function set height (value:Number) : void;
		[native(support="none")]
		public function set mask (value:DisplayObject) : void;

		/**
		 Determines whether or not the children of the object are mouse enabled. 
	 If an object is mouse enabled, a user can interact with it by using a mouse. The default is true.
	 
	 This property is useful when you create a button with an instance of the Sprite class
	 (instead of using the SimpleButton class). When you use a Sprite instance to create a button,
	 you can choose to decorate the button by using the addChild() method to add additional
	 Sprite instances. This process can cause unexpected behavior with mouse events because
	 the Sprite instances you add as children can become the target object of a mouse event
	 when you expect the parent instance to be the target object. To ensure that the parent
	 instance serves as the target objects for mouse events, you can set the 
	 mouseChildren property of the parent instance to false. No event is dispatched by setting this property. You must use the
	 addEventListener() method to create interactive functionality.
		 */
		[native(support="none")]
		public function get mouseChildren () : Boolean;
		[native(support="none")]
		public function set mouseChildren (value:Boolean) : void;
		[native(support="none")]
		public function set mouseEnabled (value:Boolean) : void;

		public function set name (value:String) : void;

		/// Returns the number of children of this object.
		public function get numChildren () : int;
		[native(support="none")]
		public function set opaqueBackground (value:Object) : void;

		/**
		 A value from the StageQuality class that specifies which rendering quality is used.
	 The following are valid values:
	 
	 StageQuality.LOW—Low rendering quality. Graphics are not
	 anti-aliased, and bitmaps are not smoothed, but runtimes still use mip-mapping. This setting is not supported in Adobe AIR.StageQuality.MEDIUM—Medium rendering quality. Graphics are
	 anti-aliased using a 2 x 2 pixel grid, bitmap smoothing is dependent on the Bitmap.smoothing setting.
	 Runtimes use mip-mapping. This setting is suitable for movies that do not contain text.
	 This setting is not supported in Adobe AIR.StageQuality.HIGH—High rendering quality. Graphics are anti-aliased
	 using a 4 x 4 pixel grid, and bitmap smoothing is dependent on the Bitmap.smoothing setting.
	 Runtimes use mip-mapping. This is the default rendering quality setting that Flash Player uses.StageQuality.BEST—Very high rendering quality. Graphics are
	 anti-aliased using a 4 x 4 pixel grid. If Bitmap.smoothing is true the runtime uses a high quality 
	 downscale algorithm that produces fewer artifacts (however, using StageQuality.BEST with Bitmap.smoothing set to true
	 slows performance significantly and is not a recommended setting).Higher quality settings produce better rendering of scaled bitmaps. However, higher 
	 quality settings are computationally more expensive. In particular, when rendering scaled video, 
	 using higher quality settings can reduce the frame rate.
	 For content running in Adobe AIR, quality can be set to StageQuality.BEST
	 or StageQuality.HIGH (and the default value is StageQuality.HIGH).
	 Attempting to set it to another value has no effect (and the property remains unchanged).
	 For content running in Adobe AIR, setting the quality property of one Stage
	 object changes the rendering quality for all Stage objects (used by different NativeWindow objects).
	 Note: The operating system draws the device fonts, 
	 which are therefore unaffected by the quality property.
		 */
		[native(support="none")]
		public function get quality () : String;
		[native(support="none")]
		public function set quality (value:String) : void;

		public function set rotation (value:Number) : void;
		[native(support="none")]
		public function set rotationX (value:Number) : void;
		[native(support="none")]
		public function set rotationY (value:Number) : void;
		[native(support="none")]
		public function set rotationZ (value:Number) : void;
		[native(support="none")]
		public function set scale9Grid (value:Rectangle) : void;

		/**
		 A value from the StageScaleMode class that specifies which scale mode to use.
	 The following are valid values:
	 
     StageScaleMode.EXACT_FIT—The entire application is visible
     in the specified area without trying to preserve the original aspect ratio. Distortion can occur, and the application may appear stretched or compressed.
     StageScaleMode.SHOW_ALL—The entire application is visible 
     in the specified area without distortion while maintaining the original aspect ratio of the application. 
     Borders can appear on two sides of the application.   
     StageScaleMode.NO_BORDER—The entire application fills the specified area, 
	 without distortion but possibly with some cropping, while maintaining the original aspect ratio 
	 of the application.
	 StageScaleMode.NO_SCALE—The entire application is fixed, so that 
	 it remains unchanged even as the size of the player window changes. Cropping might 
	 occur if the player window is smaller than the content.
		 */
		[native(support="none")]
		public function get scaleMode () : String;
		[native(support="none")]
		public function set scaleMode (value:String) : void;

		public function set scaleX (value:Number) : void;

		public function set scaleY (value:Number) : void;
		[native(support="none")]
		public function set scaleZ (value:Number) : void;
		[native(support="none")]
		public function set scrollRect (value:Rectangle) : void;

		/**
		 Specifies whether to show or hide the default items in the Flash Player 
     context menu.
     
     If the showDefaultContextMenu property is set to true (the 
	 default), all context menu items appear. If the showDefaultContextMenu property 
	 is set to false, only the Settings and About Adobe Flash Player menu items appear.
		 */
		[native(support="none")]
		public function get showDefaultContextMenu () : Boolean;
		[native(support="none")]
		public function set showDefaultContextMenu (value:Boolean) : void;

		/// Specifies whether or not objects display a glowing border when they have focus.
		[native(support="none")]
		public function get stageFocusRect () : Boolean;
		[native(support="none")]
		public function set stageFocusRect (on:Boolean) : void;

		/**
		 The current height, in pixels, of the Stage.
     
     If the value of the Stage.scaleMode property is set to StageScaleMode.NO_SCALE
	 when the user resizes the window, the Stage content maintains its size while the 
     stageHeight property changes to reflect the new height size of the screen area occupied by 
     the SWF file. (In the other scale modes, the stageHeight property always reflects the original 
     height of the SWF file.) You can add an event listener for the resize event and then use the 
     stageHeight property of the Stage class to determine the actual pixel dimension of the resized 
     Flash Player window. The event listener allows you to control how 
	 the screen content adjusts when the user resizes the window.Note: In an HTML page hosting the SWF file, both the object and embed tags' height attributes must be set to a percentage (such as 100%), not pixels. If the 
     settings are generated by JavaScript code, the height parameter of the AC_FL_RunContent()
      method must be set to a percentage, too. This percentage is applied to the stageHeight
     value.
		 */
		public function get stageHeight () : int;
		public function set stageHeight (value:int) : void;

		/**
		 Specifies the current width, in pixels, of the Stage.
     
     
     If the value of the Stage.scaleMode property is set to StageScaleMode.NO_SCALE
	 when the user resizes the window, the Stage content maintains its defined size while the stageWidth 
	 property changes to reflect the new width size of the screen area occupied by the SWF file. (In the other scale
     modes, the stageWidth property always reflects the original width of the SWF file.) You can add an event 
	 listener for the resize event and then use the stageWidth property of the Stage class to
	 determine the actual pixel dimension of the resized Flash Player window. The event listener allows you to control how 
	 the screen content adjusts when the user resizes the window.Note: In an HTML page hosting the SWF file, both the object and embed tags' width attributes must be set to a percentage (such as 100%), not pixels. If the 
     settings are generated by JavaScript code, the width parameter of the AC_FL_RunContent()
      method must be set to a percentage, too. This percentage is applied to the stageWidth
     value.
		 */
		public function get stageWidth () : int;
		public function set stageWidth (value:int) : void;

		/**
		 Determines whether the children of the object are tab enabled. Enables or disables tabbing for the 
     children of the object. The default is true.
		 */
		[native(support="none")]
		public function get tabChildren () : Boolean;
		[native(support="none")]
		public function set tabChildren (value:Boolean) : void;
		[native(support="none")]
		public function set tabEnabled (value:Boolean) : void;
		[native(support="none")]
		public function set tabIndex (value:int) : void;

		/// Returns a TextSnapshot object for this DisplayObjectContainer instance.
		[native(support="none")]
		public function get textSnapshot () : TextSnapshot;

		public function set transform (value:Transform) : void;

		public function set visible (value:Boolean) : void;

		/**
		 Indicates the width of the display object, in pixels. The width is calculated based on the bounds of the content of the display object.
     When you set the width property, the scaleX property is adjusted accordingly, as shown in the 
     following code:
     
     
    var rect:Shape = new Shape();
    rect.graphics.beginFill(0xFF0000);
    rect.graphics.drawRect(0, 0, 100, 100);
    trace(rect.scaleX) // 1;
    rect.width = 200;
    trace(rect.scaleX) // 2;Except for TextField and Video objects, a display object with no content (such as an empty sprite) has a width 
    of 0, even if you try to set width to a different value.
		 */
		public function get width () : Number;
		public function set width (value:Number) : void;

		/**
		 Indicates whether GPU compositing is available and in use. The wmodeGPU value is trueonly
	 when all three of the following conditions exist:
	 GPU compositing has been requested.GPU compositing is available.GPU compositing is in use.Specifically, the wmodeGPU property indicates one of the following:GPU compositing has not been requested or is unavailable. In this case, the wmodeGPU property value is false.GPU compositing has been requested (if applicable and available), but the environment is operating in "fallback mode" 
	 (not optimal rendering) due to limitations of the content. In this case, the wmodeGPU property value is true.GPU compositing has been requested (if applicable and available), and the environment is operating in the best mode. In this case, the 
	 wmodeGPU property value is also true.In other words, the wmodeGPU property identifies the capability and state of the rendering environment. For runtimes 
	 that do not support GPU compositing, such as AIR 1.5.2, the value is always false, because (as stated above) the value is 
	 true only when GPU compositing has been requested, is available, and is in use.The wmodeGPU property is useful to determine, at runtime, whether or not GPU compositing is in use. The value of 
	 wmodeGPU indicates if your content is going to be scaled by hardware, or not, so you can present graphics at the correct size.
	 You can also determine if you're rendering in a fast path or not, so that you can adjust your content complexity accordingly.For Flash Player in a browser, GPU compositing can be requested by the value of gpu for the wmode HTML 
	 parameter in the page hosting the SWF file. For other configurations, GPU compositing can be requested in the header of a SWF file 
	 (set using SWF authoring tools).However, the wmodeGPU property does not identify the current rendering performance. Even if GPU compositing is "in use" the rendering 
	 process might not be operating in the best mode. To adjust your content for optimal rendering, use a Flash runtime debugger version, 
	 and set the DisplayGPUBlendsetting in your mm.cfg file.Note: This property is always false when referenced
	 from ActionScript that runs before the runtime performs its first rendering
	 pass.  For example, if you examine wmodeGPU from a script in Frame 1 of
	 Adobe Flash Professional, and your SWF file is the first SWF file loaded in a new
	 instance of the runtime, then the wmodeGPU value is false.
	 To get an accurate value, wait until at least one rendering pass
	 has occurred. If you write an event listener for the
	 exitFrame event of any DisplayObject, the wmodeGPU value at
	 is the correct value.
		 */
		[native(support="none")]
		public function get wmodeGPU () : Boolean;

		public function set x (value:Number) : void;

		public function set y (value:Number) : void;
		[native(support="none")]
		public function set z (value:Number) : void;

		public function addChild (child:DisplayObject) : DisplayObject;

		public function addChildAt (child:DisplayObject, index:int) : DisplayObject;

		public function addEventListener (type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false) : void;

		public function dispatchEvent (event:Event) : Boolean;

		public function hasEventListener (type:String) : Boolean;

		public function invalidate () : void;
		[native(support="none")]
		public function isFocusInaccessible () : Boolean;

		public function removeChildAt (index:int) : DisplayObject;

		public function setChildIndex (child:DisplayObject, index:int) : void;

		public function Stage ();

		public function swapChildrenAt (index1:int, index2:int) : void;
		[native(support="none")]
		public function willTrigger (type:String) : Boolean;
	}
}
