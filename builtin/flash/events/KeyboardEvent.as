package flash.events
{

   intrinsic  public class KeyboardEvent extends Event {
      
        public static const KEY_DOWN:String = "keyDown";
        
	public static const KEY_UP:String = "keyUp";

        public function KeyboardEvent(param1:String, param2:Boolean = true, param3:Boolean = false, param4:uint = 0, param5:uint = 0, param6:uint = 0, param7:Boolean = false, param8:Boolean = false, param9:Boolean = false) ;
        
	public function clone() : Event;

        override public function toString() : String ;

        public function get charCode() : uint;

        public function get keyCode() : uint ;
        
        public function get keyLocation() : uint ;

        public function get ctrlKey() : Boolean;

        public function get altKey() : Boolean;

        public function get shiftKey() : Boolean;

        [native(support="none")]
        public function updateAfterEvent() : void;

    }
}
