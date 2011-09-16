package flash.events
{
    import flash.events.Event;
    import flash.display.InteractiveObject;

    intrinsic  public class MouseEvent extends Event
    {
      
        public static const CLICK:String = "click";
       
        public static const MOUSE_DOWN:String = "mouseDown";
        public static const MOUSE_MOVE:String = "mouseMove";
        

        public static const MOUSE_UP:String = "mouseUp";
      

        public function MouseEvent(param1:String, param2:Boolean = true, param3:Boolean = false, param4:Number = 0, param5:Number = 0, param6:InteractiveObject = null, param7:Boolean = false, param8:Boolean = false, param9:Boolean = false, param10:Boolean = false, param11:int = 0) ;

        public function clone() : Event ;

        public function toString() : String;

        public function get localX() : Number;

        public function get localY() : Number;

        [native(support="none")]
        public function get relatedObject() : InteractiveObject ;

        [native(support="none")]
        public function set relatedObject(param1:InteractiveObject) : void;

        public function get ctrlKey() : Boolean ;

        public function get altKey() : Boolean;

        public function get shiftKey() : Boolean ;

        public function get buttonDown() : Boolean ;

      
        public function get delta() : int ;

    
        public function get stageX() : Number;

        public function get stageY() : Number;

        [native(support="none")]
        public function updateAfterEvent() : void;

     
        [native(support="none")]
        public function get isRelatedObjectInaccessible() : Boolean ;
        
	[native(support="none")]
        public function set isRelatedObjectInaccessible(param1:Boolean) : void ;
    }
}
