package flash.display
{
	import flash.display.BitmapData;
	import flash.geom.Rectangle;
	import flash.geom.Point;
	import flash.filters.BitmapFilter;
	import flash.geom.ColorTransform;
	import flash.display.IBitmapDrawable;
	import flash.geom.Matrix;
	import flash.utils.ByteArray;

	intrinsic public class BitmapData extends Object implements IBitmapDrawable
	{
		public function get height () : int;

		public function get rect () : Rectangle;

		public function get transparent () : Boolean;

		public function get width () : int;
		
		[native(support="api")]
		public function applyFilter (sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, filter:BitmapFilter) : void;

		public function BitmapData (width:int, height:int, transparent:Boolean = true, fillColor:uint = 4294967295);

		public function clone () : BitmapData;
		
		public function colorTransform (rect:Rectangle, colorTransform:ColorTransform) : void;

		public function compare (otherBitmapData:BitmapData) : Object;

		public function copyChannel (sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, sourceChannel:uint, destChannel:uint) : void;

		public function copyPixels (sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, alphaBitmapData:BitmapData = null, alphaPoint:Point = null, mergeAlpha:Boolean = false) : void;

		public function dispose () : void;

		public function draw (source:IBitmapDrawable, matrix:Matrix = null, colorTransform:ColorTransform = null, blendMode:String = null, clipRect:Rectangle = null, smoothing:Boolean = false) : void;

		public function fillRect (rect:Rectangle, color:uint) : void;

		public function floodFill (x:int, y:int, color:uint) : void;

		[native(support="api")]
		public function generateFilterRect (sourceRect:Rectangle, filter:BitmapFilter) : Rectangle;

		public function getColorBoundsRect (mask:uint, color:uint, findColor:Boolean = true) : Rectangle;

		public function getPixel (x:int, y:int) : uint;

		public function getPixel32 (x:int, y:int) : uint;

		[native(support="api")]
		public function getPixels (rect:Rectangle) : ByteArray;

/*
		public function getVector (rect:Rectangle) : Vector.<uint>;

		[native(support="api")]
		public function histogram (hRect:Rectangle = null) : Vector.<Vector.<Number>>;
*/

		public function hitTest (firstPoint:Point, firstAlphaThreshold:uint, secondObject:Object, secondBitmapDataPoint:Point = null, secondAlphaThreshold:uint = 1) : Boolean;

		[native(support="api")]
		public function lock () : void;

		public function merge (sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, redMultiplier:uint, greenMultiplier:uint, blueMultiplier:uint, alphaMultiplier:uint) : void;

		public function noise (randomSeed:int, low:uint = 0, high:uint = 255, channelOptions:uint = 7, grayScale:Boolean = false) : void;

		[native(support="api")]
		public function paletteMap (sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, redArray:Array = null, greenArray:Array = null, blueArray:Array = null, alphaArray:Array = null) : void;

		[native(support="api")]
		public function perlinNoise (baseX:Number, baseY:Number, numOctaves:uint, randomSeed:int, stitch:Boolean, fractalNoise:Boolean, channelOptions:uint = 7, grayScale:Boolean = false, offsets:Array = null) : void;

		[native(support="api")]
		public function pixelDissolve (sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, randomSeed:int = 0, numPixels:int = 0, fillColor:uint = 0) : int;

		[native(support="api")]
		public function scroll (x:int, y:int) : void;

		public function setPixel (x:int, y:int, color:uint) : void;

		public function setPixel32 (x:int, y:int, color:uint) : void;

		[native(support="api")]
		public function setPixels (rect:Rectangle, inputByteArray:ByteArray) : void;

//		public function setVector (rect:Rectangle, inputVector:Vector.<uint>) : void;

		public function threshold (sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, operation:String, threshold:uint, color:uint = 0, mask:uint = 4294967295, copySource:Boolean = false) : uint;

		[native(support="api")]
		public function unlock (changeRect:Rectangle = null) : void;
	}
}
