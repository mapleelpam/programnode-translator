package flash.display
{
    intrinsic public class MovieClip extends Sprite {

        public function MovieClip();
		
        public function get currentFrame() : int;

        public function get framesLoaded() : int;

        public function get totalFrames() : int;

		[native(support="none")]
        public function get trackAsMenu() : Boolean;
		
		[native(support="none")]
        public function set trackAsMenu(param1:Boolean) : void;

        public function play() : void;

        public function stop() : void;

        public function nextFrame() : void;

        public function prevFrame() : void;

        public function gotoAndPlay(param1:Object, param2:String = null) : void;

        public function gotoAndStop(param1:Object, param2:String = null) : void;

		[native(support="none")]
        public function addFrameScript(... args) : void;

		[native(support="none")]
        public function get scenes() : Array;

/*
		[native(support="none")]
        public function get currentScene() : Scene;
*/

        public function get currentLabel() : String;

        public function get currentFrameLabel() : String;

		[native(support="none")]
        public function get currentLabels() : Array;
		
		[native(support="none")]
        public function prevScene() : void;

		[native(support="none")]
        public function nextScene() : void;

		[native(support="none")]
        public function get enabled() : Boolean;

		[native(support="none")]
        public function set enabled(param1:Boolean) : void;

    }
}
