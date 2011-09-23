// RUN: java -jar %ASC_JAR -x -z %t.pn  %s
// RUN: pnc %t.pn %BUILTIN_PN -o %t.cpp 
// RUN: pnc %t.pn %BUILTIN_PN -o %t.only.cpp	--declare
// RUN: pnc %t.pn %BUILTIN_PN -o %t.only.h		--define

package
{
	import flash.display.Loader;
	import flash.display.LoaderInfo;
	import flash.display.MovieClip;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.IOErrorEvent;
	import flash.events.ProgressEvent;
	import flash.events.TextEvent;
	import flash.filters.BlurFilter;
	import flash.filters.DropShadowFilter;
	import flash.filters.GlowFilter;
	import flash.geom.Matrix;
	import flash.net.URLRequest;
	import flash.text.TextField;

	public class ISeeYou extends Sprite
	{
		public function ISeeYou()
		{
			var loader:Loader=new Loader();
			loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onComplete);
			loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onIOError);
			loader.contentLoaderInfo.addEventListener(ProgressEvent.PROGRESS, onProgress);
			loader.load(new URLRequest("assets.swf"));
			text=new TextField();
			//text.type=TextFieldType.INPUT;
//			text.wordWrap=true;
			text.multiline=true;
			text.border=true;
			text.addEventListener(TextEvent.TEXT_INPUT, onInput);
			addChild(text);
			filterList=[new GlowFilter(), new DropShadowFilter(), new BlurFilter()];
		}

		private var mc:MovieClip;
		private var text:TextField;
		private var filterList:Array;
		private var currentCount:int;

		protected function onAdd(event:Event):void
		{
			trace("add to displaylist");
		}

		protected function onAddToStage(event:Event):void
		{
			trace("add to stage");

		}

		protected function onProgress(event:ProgressEvent):void
		{
			trace("load progress:" + event.bytesLoaded + "/" + event.bytesTotal);

		}

		protected function onIOError(event:IOErrorEvent):void
		{
			trace("load error");

		}

		protected function onComplete(event:Event):void
		{
			var loaderinfo:LoaderInfo=event.target as LoaderInfo;
			var girlClass:Class=loaderinfo.applicationDomain.getDefinition("friendTD.battle.char.girlstudent.Run") as Class;
			mc=new girlClass();
			mc.y=150;
			addChild(mc);
			mc.stop();
		}


		protected function onInput(event:TextEvent):void
		{
			if (event.text == "\n")
			{
				event.preventDefault();
				trace("enter");
				switch (text.text)
				{
					case "backword": //后退
						mc.prevFrame();
						break;
					case "forword": //前进
						mc.nextFrame();
						break;
					case "p": //播放
						mc.play();
						break;
					case "f": //滤镜开关
						if (mc.filters && mc.filters.length == 0)
						{
							mc.filters=[filterList[currentCount]];
							if (currentCount == 2)
								currentCount=0;
							else
								currentCount++;
						}
						else
							mc.filters=null;
						break;
					case "+": //ZoomIn
						mc.scaleX+=0.2;
						mc.scaleY+=0.2;
						break;
					case "-": //ZoomOut
						mc.scaleX-=0.2;
						mc.scaleY-=0.2;
						break;
					case "r": //Rotate
						mc.rotation+=10;
						break;
					case "t": //transform
						this.transform.matrix=new Matrix(0.8, 0, 0, 0.8, 100, 100);
						break;
				}
			}

		}
	}
}
