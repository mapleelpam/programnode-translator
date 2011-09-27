package a
{
	import flash.display.BitmapData;
	import flash.geom.Point;
	import flash.geom.Rectangle;

	public class Person
	{
		private static var json:Object;
		private static var step:int=2;

		public static function init(description:Object):void
		{
			json=description;
		}

		public function Person()
		{
		}

		public var position:Point;
		private var _mirror:Boolean;
		private var currentFrame:int=1;
		private var totalFrame:int=17;
		private var stepX:Number=-2;
		private var stepY:Number=-2;
		private var _currentRect:Rectangle;

		public function go():Rectangle
		{
			if (currentFrame > 17)
				currentFrame=1;
			var rect:Object=json.frames[currentFrame].frame;
			currentFrame++;
			position=position.add(new Point(stepX, stepY));
			_currentRect=new Rectangle(rect.x, rect.y, rect.w, rect.h);
			return _currentRect;
		}

		public function flip():void
		{
			_mirror=!_mirror;
			stepX=-stepX;
		}

		public function get mirror():Boolean
		{
			return _mirror;
		}

		public function turn():void
		{
			stepY=-stepY;
		}

		public function get currentRect():Rectangle
		{
			return _currentRect;
		}
	}
}
