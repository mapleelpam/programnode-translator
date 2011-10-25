package a
{
	import com.adobe.serialization.json.JSON;
	import flash.display.Bitmap;
	import flash.display.BitmapData;
	import flash.display.Loader;
	import flash.display.Sprite;
	import flash.display.StageScaleMode;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.filters.GlowFilter;
	import flash.geom.Point;
	import flash.geom.Rectangle;
	import flash.media.Sound;
	import flash.media.SoundChannel;
	import flash.net.URLLoader;
	import flash.net.URLRequest;
	import flash.text.TextField;

	public class GoNiblerGo extends Sprite
	{
		public function GoNiblerGo()
		{
			canvas=new BitmapData(stage.stageWidth, stage.stageHeight, false);
			container=new Bitmap(canvas);
			addChild(container);
			mainRect=new Rectangle(0, 0, stage.stageWidth, stage.stageHeight);

			var urlloader:URLLoader=new URLLoader();
			urlloader.addEventListener(Event.COMPLETE, onComplete);
			urlloader.load(new URLRequest("sprites.json"));

			var picloader:Loader=new Loader();
//			picloader.contentLoaderInfo.addEventListener(Event.COMPLETE, onPicComplete);
			picloader.load(new URLRequest("sprites.png"));
			person=new Person();
			stage.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
			stage.addEventListener(MouseEvent.MOUSE_UP, onMoueUp);
			stage.addEventListener(MouseEvent.CLICK, onClick);
		}

		private var isMouseDown:Boolean=false;
		private var sheet:BitmapData;
		private var sound:Sound;
		private var canvas:BitmapData;
		private var container:Bitmap;
		private var mainRect:Rectangle;
		private var dataReady:Boolean;
		private var picReady:Boolean;
		private var person:Person;
		private var hitperson:Boolean;
		private var lastPoint:Point;
		private var isplay:Boolean=false;
		private var control:SoundChannel;

		protected function onClick(event:MouseEvent):void
		{
//			event.stageX  event.stageY
			if (picReady && dataReady && !hasEventListener(Event.ENTER_FRAME))
			{
				person.position=new Point(event.stageX, event.stageY);
				addEventListener(Event.ENTER_FRAME, loop);
			}
		}

		protected function onMoueUp(event:MouseEvent):void
		{
			isMouseDown=false;
		}

		protected function onMouseDown(event:MouseEvent):void
		{
			isMouseDown=true;
		}

		protected function onPicComplete(event:Event):void
		{
			sheet=event.target.content.bitmapData;
			picReady=true;
//			if (dataReady)
//				addEventListener(Event.ENTER_FRAME, loop);
		}

		protected function onComplete(event:Event):void
		{
			dataReady=true;
			Person.init(JSON.decode(event.target.data));
//			if (picReady)
//				addEventListener(Event.ENTER_FRAME, loop);
		}

		protected function loop(event:Event):void
		{
			if (!hitperson || !isMouseDown)
			{
				person.go();
				if (isplay)
				{
					control.stop();
					isplay=false;
				}
			}
			else
			{
				person.position=new Point(mouseX, mouseY).subtract(lastPoint).add(person.position);
				if (!sound)
				{
					sound=new Sound();
					sound.load(new URLRequest("rw153.mp3"));
				}
				if (!isplay)
				{
					control=sound.play(0, 9999);
					isplay=true;
				}

			}
			var pp:BitmapData=new BitmapData(person.currentRect.width, person.currentRect.height, true, 0x00000000);
			pp.copyPixels(sheet, person.currentRect, new Point);
			hitperson=hitTest(pp, person.position, new Point(mouseX, mouseY));
			if (hitperson)
			{
				pp.applyFilter(pp, pp.rect, new Point, new GlowFilter());
			}
			canvas.lock();
			canvas.fillRect(mainRect, 0xFFFFFF);
			var rect:Rectangle=new Rectangle(0, 0, stage.stageWidth, stage.stageHeight);
			canvas.copyPixels(pp, pp.rect, person.position);
			canvas.unlock();
			lastPoint=new Point(mouseX, mouseY);
			if (!mainRect.intersects(new Rectangle(person.position.x, person.position.y, pp.width, pp.height)))
			{
				removeEventListener(Event.ENTER_FRAME, loop);
			}
		}

		private function hitTest(bitmapdata:BitmapData, position:Point, testPoint:Point):Boolean
		{
			if (!new Rectangle(position.x, position.y, bitmapdata.width, bitmapdata.height).containsPoint(testPoint))
				return false;
			else
			{
				return bitmapdata.hitTest(position, 0, testPoint);
			}
		}
	}
}
