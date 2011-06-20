package flash.geom
{
	import flash.geom.Matrix;
	import flash.geom.ColorTransform;
	import flash.geom.Rectangle;
	import flash.display.DisplayObject;
	import flash.geom.Matrix3D;
	import flash.geom.PerspectiveProjection;

	intrinsic public class Transform extends Object
	{
		[native(support="none")]
		public function get colorTransform () : ColorTransform;
		[native(support="none")]
		public function set colorTransform (value:ColorTransform) : void;

		[native(support="none")]
		public function get concatenatedColorTransform () : ColorTransform;

		public function get concatenatedMatrix () : Matrix;

		public function get matrix () : Matrix;
		public function set matrix (value:Matrix) : void;

		[native(support="none")]
		public function get matrix3D () : Matrix3D;
		[native(support="none")]
		public function set matrix3D (m:Matrix3D) : void;

		[native(support="none")]
		public function get perspectiveProjection () : PerspectiveProjection;
		[native(support="none")]
		public function set perspectiveProjection (pm:PerspectiveProjection) : void;

		[native(support="none")]
		public function get pixelBounds () : Rectangle;
		[native(support="none")]
		public function getRelativeMatrix3D (relativeTo:DisplayObject) : Matrix3D;

		public function Transform (displayObject:DisplayObject);
	}
}
