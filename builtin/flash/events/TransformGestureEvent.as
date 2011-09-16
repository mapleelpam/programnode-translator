package flash.events
{

   intrinsic  public class TransformGestureEvent extends GestureEvent 
    {
      
        public static const GESTURE_ZOOM:String = "gestureZoom";
        public static const GESTURE_PAN:String = "gesturePan";
        public static const GESTURE_ROTATE:String = "gestureRotate";
        public static const GESTURE_SWIPE:String = "gestureSwipe";

        public function TransformGestureEvent(param1:String, param2:Boolean = true, param3:Boolean = false, param4:String = null, param5:Number = 0, param6:Number = 0, param7:Number = 1, param8:Number = 1, param9:Number = 0, param10:Number = 0, param11:Number = 0, param12:Boolean = false, param13:Boolean = false, param14:Boolean = false) ;

        public function clone() : Event;
        
        public function toString() : String ;

        public function get scaleX() : Number;

        public function get scaleY() : Number ;
        
        public function get rotation() : Number;

        public function get offsetX() : Number ;

        public function get offsetY() : Number;
    }
}
