package flash.media
{
    import flash.events.EventDispatcher;

    intrinsic  public class SoundChannel extends EventDispatcher {

        public function SoundChannel() ;

        public function get position() : Number;

//        [native(support="api")]
//        public function get soundTransform() : SoundTransform;

        public function stop() : void;

        public function get leftPeak() : Number;

        public function get rightPeak() : Number;

    }
}
