package flash.events
{

   intrinsic  public class PressAndTapGestureEvent extends GestureEvent {
        public static const GESTURE_PRESS_AND_TAP:String = "gesturePressAndTap";

        public function PressAndTapGestureEvent(param1:String, param2:Boolean = true, param3:Boolean = false, param4:String = null, param5:Number = 0, param6:Number = 0, param7:Number = 0, param8:Number = 0, param9:Boolean = false, param10:Boolean = false, param11:Boolean = false) ;

        public function clone() : Event ;

        public function toString() : String;

        public function get tapLocalX() : Number;

        public function get tapLocalY() : Number;


        public function get tapStageX() : Number;

        public function get tapStageY() : Number;

        private function getTapStageX() : Number;

        private function getTapStageY() : Number;

    }
}
