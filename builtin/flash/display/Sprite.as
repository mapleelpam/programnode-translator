//
// D:\test\lib\playerglobal.swc\flash\display\Sprite
//
package flash.display
{
	import flash.display.Graphics;
	import flash.geom.Rectangle;
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.media.SoundTransform;

	public class Sprite extends DisplayObjectContainer
	{
		/**
		 Specifies the button mode of this sprite. If true, this
     sprite behaves as a button, which means that it triggers the display
     of the hand cursor when the mouse passes over the sprite and can
     receive a click event if the enter or space keys are pressed
     when the sprite has focus. You can suppress the display of the hand cursor
     by setting the useHandCursor property to false,
     in which case the pointer is displayed.
     
     Although it is better to use the SimpleButton class to create buttons, 
     you can use the buttonMode property to give a sprite 
     some button-like functionality. To include a sprite in the tab order,
     set the tabEnabled property (inherited from the
     InteractiveObject class and false by default) to
     true. Additionally, consider whether you want
     the children of your sprite to be mouse enabled. Most buttons
     do not enable mouse interactivity for their child objects because
     it confuses the event flow. To disable mouse interactivity for all child
     objects, you must set the mouseChildren property (inherited
     from the DisplayObjectContainer class) to false.If you use the buttonMode property with the MovieClip class (which is a
     subclass of the Sprite class), your button might have some added
     functionality. If you include frames labeled _up, _over, and _down,
     Flash Player provides automatic state changes (functionality
     similar to that provided in previous versions of ActionScript for movie
     clips used as buttons). These automatic state changes are
     not available for sprites, which have no timeline, and thus no frames
     to label.
		 */
		[native(support="none")]
		public function get buttonMode () : Boolean;
		[native(support="none")]
		public function set buttonMode (value:Boolean) : void;

		/**
		 Specifies the display object over which the sprite is being dragged, or on
	 which the sprite was dropped.
		 */
		[native(support="none")]
		public function get dropTarget () : DisplayObject;

		/**
		 Specifies the Graphics object that belongs to this sprite where vector
     drawing commands can occur.
		 */
		[native(support="none")]
		public function get graphics () : Graphics;

		/**
		 Designates another sprite to serve as the hit area for a sprite. If the hitArea
	 property does not exist or the value is null or undefined, the
	 sprite itself is used as the hit area. The value of the hitArea property can
	 be a reference to a Sprite object.
	 
	 You can change the hitArea property at any time; the modified sprite immediately
	 uses the new hit area behavior. The sprite designated as the hit area does not need to be
	 visible; its graphical shape, although not visible, is still detected as the hit area.Note: You must set to false the mouseEnabled 
	 property of the sprite designated as the hit area. Otherwise, your sprite button might
	 not work because the sprite designated as the hit area receives the mouse events instead
	 of your sprite button.
		 */
		[native(support="none")]
		public function get hitArea () : Sprite;
		[native(support="none")]
		public function set hitArea (value:Sprite) : void;

		/// Controls sound within this sprite.
		[native(support="none")]
		public function get soundTransform () : SoundTransform;
		[native(support="none")]
		public function set soundTransform (sndTransform:SoundTransform) : void;

		/**
		 A Boolean value that indicates whether the pointing hand (hand cursor) appears when the mouse rolls 
	 over a sprite in which the buttonMode property is set to true. 
	 The default value of the useHandCursor property is true.
	 If useHandCursor is set to true, the pointing hand used for buttons
	 appears when the mouse rolls over a button sprite. If useHandCursor is
	 false, the arrow pointer is used instead.
	 
	 You can change the useHandCursor property at any time; the modified sprite
	 immediately takes on the new cursor appearance. Note: If your sprite has child sprites, you might want to 
     set the mouseChildren property to false. For example, if you want a hand 
     cursor to appear over a Flex <mx:Label> control, set the useHandCursor and 
     buttonMode properties to true, and the mouseChildren property 
     to false.
		 */
		[native(support="none")]
		public function get useHandCursor () : Boolean;
		[native(support="none")]
		public function set useHandCursor (value:Boolean) : void;

		public function Sprite ();
		
		[native(support="none")]
		public function startDrag (lockCenter:Boolean = false, bounds:Rectangle = null) : void;

		[native(support="none")]
		public function startTouchDrag (touchPointID:int, lockCenter:Boolean = false, bounds:Rectangle = null) : void;

		[native(support="none")]
		public function stopDrag () : void;

		[native(support="none")]
		public function stopTouchDrag (touchPointID:int) : void;
	}
}
