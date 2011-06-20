package flash.display
{
	import flash.net.URLRequest;
	import flash.system.LoaderContext;
	import flash.system.ApplicationDomain;
	import flash.system.SecurityDomain;
	import flash.utils.ByteArray;
	import flash.display.DisplayObject;
	import flash.display.LoaderInfo;
	import flash.events.UncaughtErrorEvents;

	intrinsic public class Loader extends DisplayObjectContainer
	{
		public function get content () : DisplayObject;

		public function get contentLoaderInfo () : LoaderInfo;
		
		[native(support="none")]
		public function get uncaughtErrorEvents () : UncaughtErrorEvents;
		
		public function addChild (child:DisplayObject) : DisplayObject;

		public function addChildAt (child:DisplayObject, index:int) : DisplayObject;

		public function close () : void;

		public function load (request:URLRequest, context:LoaderContext = null) : void;
		
		[native(support="api")]
		public function loadBytes (bytes:ByteArray, context:LoaderContext = null) : void;

		public function Loader ();

		public function removeChild (child:DisplayObject) : DisplayObject;

		public function removeChildAt (index:int) : DisplayObject;

		public function setChildIndex (child:DisplayObject, index:int) : void;

		public function unload () : void;

		[native(support="none")]
		public function unloadAndStop (gc:Boolean = true) : void;
	}
}
