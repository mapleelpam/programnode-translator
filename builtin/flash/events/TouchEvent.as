package flash.events
{
    import flash.events.Event;
    import flash.display.InteractiveObject;

   intrinsic  public class TouchEvent extends Event {
       
        public static const TOUCH_BEGIN:String = "touchBegin";
        public static const TOUCH_END:String = "touchEnd";
        public static const TOUCH_MOVE:String = "touchMove";

        public function TouchEvent(param1:String, param2:Boolean = true, param3:Boolean = false, param4:int = 0, param5:Boolean = false, param6:Number = NaN, param7:Number = NaN, param8:Number = NaN, param9:Number = NaN, param10:Number = NaN, param11:InteractiveObject = null, param12:Boolean = false, param13:Boolean = false, param14:Boolean = false) ;

        public function clone() : Event;

        public function toString() : String;

        public function get localX() : Number;

        public function get localY() : Number;

        public function get touchPointID() : int;

        public function get isPrimaryTouchPoint() : Boolean ;
       
        public function get sizeX() : Number;
       
        public function get sizeY() : Number ;

        public function get pressure() : Number;

        [native(support="none")]
        public function get relatedObject() : InteractiveObject;

        public function get ctrlKey() : Boolean ;

        public function get altKey() : Boolean ;
       
        public function get shiftKey() : Boolean;
       
        public function get stageX() : Number;

        public function get stageY() : Number;

        public function updateAfterEvent() : void;

        private function getStageX() : Number;

        private function getStageY() : Number;
    }
}
