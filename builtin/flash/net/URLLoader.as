package flash.net
{
	import flash.events.EventDispatcher;
	import flash.net.URLStream;
	import flash.net.URLRequest;
	import flash.events.Event;
	import flash.events.ProgressEvent;

	intrinsic public class URLLoader extends EventDispatcher
	{
		public var bytesLoaded : uint;

		public var bytesTotal : uint;

//		public var data : *;

		public var dataFormat : String;

    		[mapper(caller="addEventListener(this,#(argc))")]
		public function addEventListener (type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false) : void;

		public function close () : void;

		public function load (request:URLRequest) : void;

		public function URLLoader (request:URLRequest = null);
	}
}
