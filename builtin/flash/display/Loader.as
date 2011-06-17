//
// D:\test\lib\playerglobal.swc\flash\display\Loader
//
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

	public class Loader extends DisplayObjectContainer
	{
		/**
		 Contains the root display object of the SWF file or image (JPG, PNG, or GIF) 
     file that was loaded by using the load() or loadBytes() methods.
		 */
		public function get content () : DisplayObject;

		/**
		 Returns a LoaderInfo object corresponding to the object being loaded. LoaderInfo objects 
     are shared between the Loader object and the loaded content object. The LoaderInfo object 
     supplies loading progress information and statistics about the loaded file. 
     
     Events related to the load are dispatched by the LoaderInfo object referenced by the 
     contentLoaderInfo property of the Loader object. The contentLoaderInfo 
     property is set to a valid LoaderInfo object, even before the content is loaded, so that you can add 
     event listeners to the object prior to the load.
		 */
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
