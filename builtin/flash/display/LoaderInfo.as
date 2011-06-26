package flash.display
{
	import flash.events.EventDispatcher;
	import flash.display.LoaderInfo;
	import flash.system.ApplicationDomain;
	import flash.events.Event;
	import flash.display.Loader;
	import flash.display.DisplayObject;
	import flash.utils.ByteArray;
	import flash.events.UncaughtErrorEvents;

	intrinsic public class LoaderInfo extends EventDispatcher
	{
		[native(support="none")]
		public function get actionScriptVersion () : uint;

		[native(support="none")]
		public function get applicationDomain () : ApplicationDomain;

		public function get bytes () : ByteArray;

		public function get bytesLoaded () : uint;

		public function get bytesTotal () : uint;

		[native(support="none")]
		public function get childAllowsParent () : Boolean;

		public function get content () : DisplayObject;

		public function get contentType () : String;

		[native(support="none")]
		public function get frameRate () : Number;

		public function get height () : int;

		[native(support="none")]
		public function get isURLInaccessible () : Boolean;

		public function get loader () : Loader;

		[native(support="none")]
		public function get loaderURL () : String;

		[native(support="none")]
		public function get parameters () : Object;

		[native(support="none")]
		public function get parentAllowsChild () : Boolean;

		[native(support="none")]
		public function get sameDomain () : Boolean;

		[native(support="none")]
		public function get sharedEvents () : EventDispatcher;

		[native(support="none")]
		public function get swfVersion () : uint;

		[native(support="none")]
		public function get uncaughtErrorEvents () : UncaughtErrorEvents;

		public function get url () : String;

		public function get width () : int;

		public function dispatchEvent (event:Event) : Boolean;

		[native(support="none")]
		public static function getLoaderInfoByDefinition (object:Object) : LoaderInfo;

		public function LoaderInfo ();
	}
}
