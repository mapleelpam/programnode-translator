package flash.events
{

    intrinsic  public class GestureEvent extends Event {
     
        public static const GESTURE_TWO_FINGER_TAP:String = "gestureTwoFingerTap";

        public function GestureEvent(param1:String, param2:Boolean = true, param3:Boolean = false, param4:String = null, param5:Number = 0, param6:Number = 0, param7:Boolean = false, param8:Boolean = false, param9:Boolean = false) 
        
	public function clone() : Event;

        public function toString() : String;

        public function get localX() : Number;

        public function get localY() : Number;

        public function get phase() : String ;

        public function get ctrlKey() : Boolean;

        public function get altKey() : Boolean ;

     
        public function get shiftKey() : Boolean;
      
        public function get stageX() : Number ;
        public function get stageY() : Number;

	[native(support="none")]
        public function updateAfterEvent() : void;

        private function getStageX() : Number;

        private function getStageY() : Number;

    }
}
