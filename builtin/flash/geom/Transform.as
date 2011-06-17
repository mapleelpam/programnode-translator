//
// D:\test\lib\playerglobal.swc\flash\geom\Transform
//
package flash.geom
{
	import flash.geom.Matrix;
	import flash.geom.ColorTransform;
	import flash.geom.Rectangle;
	import flash.display.DisplayObject;
	import flash.geom.Matrix3D;
	import flash.geom.PerspectiveProjection;

	public class Transform extends Object
	{
		/**
		 A ColorTransform object containing values that universally adjust the colors in 
     the display object.
		 */
		[native(support="none")]
		public function get colorTransform () : ColorTransform;
		[native(support="none")]
		public function set colorTransform (value:ColorTransform) : void;

		/**
		 A ColorTransform object representing the combined color transformations applied to the display object 
     and all of its parent objects, back to the root level.
     If different color transformations have been applied at different levels, all of those transformations are 
     concatenated into one ColorTransform object 
     for this property.
		 */
		[native(support="none")]
		public function get concatenatedColorTransform () : ColorTransform;

		/**
		 A Matrix object representing the combined transformation matrixes of the 
     display object and all of its parent objects, back to the root level.
     If different transformation matrixes have been applied at different levels, 
     all of those matrixes are concatenated into one matrix 
     for this property. Also, for resizeable SWF content running in the browser, 
     this property factors in the difference between stage coordinates and window 
     coordinates due to window resizing. Thus, the property converts local coordinates 
     to window coordinates, which may not be the same coordinate space as that of 
     the Stage.
		 */
		public function get concatenatedMatrix () : Matrix;

		/**
		 A Matrix object containing values that alter the scaling, rotation, 
     and translation of the display object.
     
     If the matrix property is set to a value (not null), the
     matrix3D property is null. And if the matrix3D property
     is set to a value (not null), the matrix property is null.
		 */
		public function get matrix () : Matrix;
		public function set matrix (value:Matrix) : void;

		/**
		 Provides access to the Matrix3D object of a three-dimensional display object.
     The Matrix3D object represents a transformation matrix that determines the 
     display object's position and orientation. A Matrix3D object can also
     perform perspective projection.
     
     If the matrix property is set to a value (not null), the
     matrix3D property is null. And if the matrix3D property
     is set to a value (not null), the matrix property is null.
		 */
		[native(support="none")]
		public function get matrix3D () : Matrix3D;
		[native(support="none")]
		public function set matrix3D (m:Matrix3D) : void;

		/**
		 Provides access to the PerspectiveProjection object of a three-dimensional display 
     object. The PerspectiveProjection object can be used to modify the perspective 
     transformation of the stage or to assign a perspective transformation to all the 
     three-dimensional children of a display object.
     
     Based on the field of view and aspect ratio (dimensions) of the stage, a 
     default PerspectiveProjection object is assigned to the root object.
		 */
		[native(support="none")]
		public function get perspectiveProjection () : PerspectiveProjection;
		[native(support="none")]
		public function set perspectiveProjection (pm:PerspectiveProjection) : void;

		/// A Rectangle object that defines the bounding rectangle of the display object on the stage.
		[native(support="none")]
		public function get pixelBounds () : Rectangle;
		[native(support="none")]
		public function getRelativeMatrix3D (relativeTo:DisplayObject) : Matrix3D;

		public function Transform (displayObject:DisplayObject);
	}
}
