package flash.ui
{
//    import __AS3__.vec.*;

    intrinsic public class Multitouch extends Object 
    {

        public function Multitouch();

        public static function get inputMode() : String;

        public static function set inputMode(param1:String) : void;

        public static function get supportsTouchEvents() : Boolean;

        public static function get supportsGestureEvents() : Boolean;

//        public static function get supportedGestures() : Vector.<String>;

        public static function get maxTouchPoints() : int;

    }
}
