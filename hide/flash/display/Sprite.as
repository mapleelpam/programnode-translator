package flash.display
{
	import flash.display.Graphics;
	import flash.geom.Rectangle;
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.media.SoundTransform;

	intrinsic public class Sprite extends DisplayObjectContainer
	{
		[native(support="none")]
		public function get buttonMode () : Boolean;
		[native(support="none")]
		public function set buttonMode (value:Boolean) : void;

		[native(support="none")]
		public function get dropTarget () : DisplayObject;

		[native(support="none")]
		public function get graphics () : Graphics;

		[native(support="none")]
		public function get hitArea () : Sprite;
		[native(support="none")]
		public function set hitArea (value:Sprite) : void;

		[native(support="none")]
		public function get soundTransform () : SoundTransform;
		[native(support="none")]
		public function set soundTransform (sndTransform:SoundTransform) : void;

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
