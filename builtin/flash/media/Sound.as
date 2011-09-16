package flash.media
{
    import flash.events.EventDispatcher;
//    import flash.net.*;
    import flash.utils.ByteArray;
    import flash.net.URLRequest;

    public class Sound extends EventDispatcher
    {

//        public function Sound(param1:URLRequest = null, param2:SoundLoaderContext = null);

//        public function load(param1:URLRequest, param2:SoundLoaderContext = null) : void ;

        

        public function get url() : String;

        public function get isURLInaccessible() : Boolean;

//        public function play(param1:Number = 0, param2:int = 0, param3:SoundTransform = null) : SoundChannel;

        [native(support="api")]
        public function get length() : Number;

        [native(support="api")]
        public function get isBuffering() : Boolean;

        [native(support="api")]
        public function get bytesLoaded() : uint;
        
	[native(support="api")]
        public function get bytesTotal() : int;

//        [native(support="api")]
//        public function get id3() : ID3Info;

        public function close() : void;

        [native(support="none")]
        public function extract(param1:ByteArray, param2:Number, param3:Number = -1) : Number;

    }
}
