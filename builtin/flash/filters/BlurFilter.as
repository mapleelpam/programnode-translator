package flash.filters
{
    intrinsic public class BlurFilter extends BitmapFilter {

        public function BlurFilter(param1:Number = 4, param2:Number = 4, param3:int = 1);
		
        public function get blurX() : Number;

        public function set blurX(param1:Number) : void;

        public function get blurY() : Number;

        public function set blurY(param1:Number) : void;

        public function get quality() : int;

        public function set quality(param1:int) : void;

        public function clone() : BitmapFilter;
    }
}
