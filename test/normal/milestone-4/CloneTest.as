// RUN: java -jar %ASC_JAR -x -z %t.pn  %s
// RUN: pnc %t.pn %BUILTIN_PN -o %t.cpp 

package
{
	import flash.display.DisplayObject;
	import flash.display.Loader;
	import flash.display.LoaderInfo;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.net.URLRequest;
	import flash.system.ApplicationDomain;
	import flash.system.LoaderContext;
	import flash.utils.getDefinitionByName;

	public class CloneTest extends Sprite
	{
		public function CloneTest()
		{
			var loader:Loader=new Loader();
			loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onComplete);
			var context:LoaderContext=new LoaderContext(false, ApplicationDomain.currentDomain);
			loader.load(new URLRequest("rect.swf"),context);
		}

		protected function onComplete(event:Event):void
		{
			var info:LoaderInfo = event.target as LoaderInfo;
			info.removeEventListener(Event.COMPLETE, onComplete);
			var rectDef:Class = getDefinitionByName("rect") as Class;
			var obj: DisplayObject = new rectDef() as DisplayObject;
			addChild(obj);

		}
	}
}
