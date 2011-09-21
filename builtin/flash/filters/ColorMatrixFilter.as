package flash.filters
{
    intrinsic public class ColorMatrixFilter extends BitmapFilter {

        public function ColorMatrixFilter(param1:Array = null);
		
        public function get matrix() : Array;

        public function set matrix(param1:Array) : void;

        public function clone() : BitmapFilter;
    }
}
