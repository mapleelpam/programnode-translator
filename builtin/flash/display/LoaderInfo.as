//
// D:\test\lib\playerglobal.swc\flash\display\LoaderInfo
//
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

	/**
	 Dispatched when a network request is made over HTTP and an HTTP status code can be detected.
	 @eventType	flash.events.HTTPStatusEvent.HTTP_STATUS
	 */
	[Event(name="httpStatus", type="flash.events.HTTPStatusEvent")] 

	/**
	 Dispatched by a LoaderInfo object whenever a loaded object is removed by using the unload() 
 method of the Loader object, or when a second load is performed by the same Loader object and the
 original content is removed prior to the load beginning.
	 @eventType	flash.events.Event.UNLOAD
	 */
	[Event(name="unload", type="flash.events.Event")] 

	/**
	 Dispatched when data is received as the download operation progresses.
	 @eventType	flash.events.ProgressEvent.PROGRESS
	 */
	[Event(name="progress", type="flash.events.ProgressEvent")] 

	/**
	 Dispatched when a load operation starts.
	 @eventType	flash.events.Event.OPEN
	 */
	[Event(name="open", type="flash.events.Event")] 

	/**
	 Dispatched when an input or output error occurs that causes a load operation to fail.
	 @eventType	flash.events.IOErrorEvent.IO_ERROR
	 */
	[Event(name="ioError", type="flash.events.IOErrorEvent")] 

	/**
	 Dispatched when the properties and methods of a loaded SWF file are 
 accessible and ready for use.
	 @eventType	flash.events.Event.INIT
	 */
	[Event(name="init", type="flash.events.Event")] 

	/**
	 Dispatched when data has loaded successfully.
	 @eventType	flash.events.Event.COMPLETE
	 */
	[Event(name="complete", type="flash.events.Event")] 

	public class LoaderInfo extends EventDispatcher
	{
		/**
		 The ActionScript version of the loaded SWF file.
	 
	 The language version is specified by using the enumerations in the
	 ActionScriptVersion class, such as ActionScriptVersion.ACTIONSCRIPT2
	 and ActionScriptVersion.ACTIONSCRIPT3.
	 
	 Note: This property always has a value of either ActionScriptVersion.ACTIONSCRIPT2 or 
	 ActionScriptVersion.ACTIONSCRIPT3.  ActionScript 1.0 and 2.0 are
	 both reported as ActionScriptVersion.ACTIONSCRIPT2 (version 2.0).  This property
	 only distinguishes ActionScript 1.0 and 2.0 from ActionScript 3.0.
		 */
		[native(support="none")]
		public function get actionScriptVersion () : uint;

		/**
		 When an external SWF file is loaded, all ActionScript 3.0 definitions contained in the loaded 
	 class are stored in the applicationDomain property.
	 
	 All code in a SWF file is defined to exist in an application domain. The current application 
	 domain is where your main application runs. The system domain contains all application domains,
	 including the current domain and all classes used by Flash Player or Adobe AIR.All application domains, except the system domain, have an associated parent domain. 
	 The parent domain of your main application's applicationDomain is the system domain. 
	 Loaded classes are defined only when their parent doesn't already define them. 
	 You cannot override a loaded class definition with a newer definition.For usage examples of application domains, see the "Client System Environment" chapter
 	 in Programming ActionScript 3.0.
		 */
		[native(support="none")]
		public function get applicationDomain () : ApplicationDomain;

		/// The bytes associated with a LoaderInfo object.
		public function get bytes () : ByteArray;

		/**
		 The number of bytes that are loaded for the media. When this number equals
	 the value of bytesTotal, all of the bytes are loaded.
		 */
		public function get bytesLoaded () : uint;

		/**
		 The number of compressed bytes in the entire media file.
	 
	 Before the first progress event is dispatched by
	 this LoaderInfo object's corresponding Loader object, bytesTotal is 0.
	 After the first progress event from the Loader object, bytesTotal
	 reflects the actual number of bytes to be downloaded.
		 */
		public function get bytesTotal () : uint;

		/**
		 Expresses the trust relationship from content (child) to the Loader (parent). 
	 If the child has allowed the parent access, true; otherwise, 
	 false. This property is set to true if the child object 
	 has called the allowDomain() method to grant permission to the parent domain 
	 or if a URL policy is loaded at the child domain that grants permission
	 to the parent domain. If child and parent are in 
	 the same domain, this property is set to true.
	 
	 For more information, see the "Flash Player Security" chapter
 	 in Programming ActionScript 3.0.
		 */
		[native(support="none")]
		public function get childAllowsParent () : Boolean;

		/// The loaded object associated with this LoaderInfo object.
		public function get content () : DisplayObject;

		/**
		 The MIME type of the loaded file. The value is null if not enough of the file has loaded 
	 in order to determine the type. The following list gives the possible values:
	 
	 "application/x-shockwave-flash""image/jpeg""image/gif""image/png"
		 */
		public function get contentType () : String;

		/**
		 The nominal frame rate, in frames per second, of the loaded SWF file. This
	 number is often an integer, but need not be.
	 
	 This value may differ from the actual frame rate in use.  
	 Flash Player or Adobe AIR only uses a single frame rate for all loaded SWF files at
	 any one time, and this frame rate is determined by the nominal
	 frame rate of the main SWF file. Also, the main frame rate may not be able to be achieved, depending on hardware, sound synchronization,
	 and other factors.
		 */
		[native(support="none")]
		public function get frameRate () : Number;

		/**
		 The nominal height of the loaded file. This value might differ from the actual
	 height at which the content is displayed, since the loaded content or its parent
	 display objects might be scaled.
		 */
		public function get height () : int;

		[native(support="none")]
		public function get isURLInaccessible () : Boolean;

		/**
		 The Loader object associated with this LoaderInfo object. If this LoaderInfo object
	 is the loaderInfo property of the instance of the main class of the SWF file, no  
	 Loader object is associated.
		 */
		public function get loader () : Loader;

		/**
		 The URL of the SWF file that initiated the loading of the media
	 described by this LoaderInfo object.  For the instance of the main class of the SWF file, this
	 URL is the same as the SWF file's own URL.
		 */
		[native(support="none")]
		public function get loaderURL () : String;

		/**
		 An object that contains name-value pairs that represent the parameters provided
	 to the loaded SWF file.
	 
	 You can use a for-in loop to extract all the names and values
	 from the parameters object.The two sources of parameters are: the query string in the
	 URL of the main SWF file, and the value of the FlashVars HTML parameter (this affects
	 only the main SWF file).The parameters property replaces the ActionScript 1.0 and 2.0 technique of
	 providing SWF file parameters as properties of the main timeline.The value of the parameters property is null for Loader objects
	 that contain SWF files that use ActionScript 1.0 or 2.0. It is only
	 non-null for Loader objects that contain SWF files that use ActionScript 3.0.
		 */
		[native(support="none")]
		public function get parameters () : Object;

		/**
		 Expresses the trust relationship from Loader (parent) to the content (child). 
	 If the parent has allowed the child access, true; otherwise, 
	 false. This property is set to true if the parent object 
	 called the allowDomain() method to grant permission to the child domain 
	 or if a URL policy file is loaded at the parent domain granting permission
	 to the child domain. If child and parent are in 
	 the same domain, this property is set to true.
	 
	 For more information, see the "Flash Player Security" chapter
 	 in Programming ActionScript 3.0.
		 */
		[native(support="none")]
		public function get parentAllowsChild () : Boolean;

		/**
		 Expresses the domain relationship between the loader and the content: true if they have 
	 the same origin domain; false otherwise.
		 */
		[native(support="none")]
		public function get sameDomain () : Boolean;

		/**
		 An EventDispatcher instance that can be used to exchange events across security boundaries.
	 Even when the Loader object and the loaded content originate from security domains that do not trust
	 one another, both can access sharedEvents and send and receive events via this object.
		 */
		[native(support="none")]
		public function get sharedEvents () : EventDispatcher;

		/**
		 The file format version of the loaded SWF file.
	 
	 The file format is specified using the enumerations in the
	 SWFVersion class, such as SWFVersion.FLASH7 and SWFVersion.FLASH9.
		 */
		[native(support="none")]
		public function get swfVersion () : uint;

		[native(support="none")]
		public function get uncaughtErrorEvents () : UncaughtErrorEvents;

		/**
		 The URL of the media being loaded.
	 
	 Before the first progress event is dispatched by this LoaderInfo 
	 object's corresponding Loader object, the value of the url property
	 might reflect only the initial URL specified in the call to the load() 
	 method  of the Loader object.  After the first progress event, the 
	 url property reflects the media's final URL, after any redirects and relative 
	 URLs are resolved.
		 */
		public function get url () : String;

		/**
		 The nominal width of the loaded content. This value might differ from the actual
	 width at which the content is displayed, since the loaded content or its parent
	 display objects might be scaled.
		 */
		public function get width () : int;

		public function dispatchEvent (event:Event) : Boolean;

		[native(support="none")]
		public static function getLoaderInfoByDefinition (object:Object) : LoaderInfo;

		public function LoaderInfo ();
	}
}
