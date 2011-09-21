package flash.filters
{
    intrinsic public class DropShadowFilter extends BitmapFilter {

        public function DropShadowFilter(param1:Number = 4, param2:Number = 45, param3:uint = 0, param4:Number = 1, param5:Number = 4, param6:Number = 4, param7:Number = 1, param8:int = 1, param9:Boolean = false, param10:Boolean = false, param11:Boolean = false);
        
        public function get distance() : Number;

        public function set distance(param1:Number) : void;

        public function get angle() : Number;

        public function set angle(param1:Number) : void;

        public function get color() : uint;

        public function set color(param1:uint) : void;

        public function get alpha() : Number;

        public function set alpha(param1:Number) : void;

        public function get blurX() : Number;

        public function set blurX(param1:Number) : void;

        public function get blurY() : Number;

        public function set blurY(param1:Number) : void;

        public function get hideObject() : Boolean;

        public function set hideObject(param1:Boolean) : void;

        public function get inner() : Boolean;

        public function set inner(param1:Boolean) : void;

        public function get knockout() : Boolean;

        public function set knockout(param1:Boolean) : void;

        public function get quality() : int;

        public function set quality(param1:int) : void;

        public function get strength() : Number;

        public function set strength(param1:Number) : void;

        public function clone() : BitmapFilter;
    }
}
