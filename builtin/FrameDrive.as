package
{
	public final class FrameDrive extends Object
	{
		public static function GetTicks() : int; /* should be uint64 */
		public function SetFrameRate(  framerate : int ) : void;
		public function GetFrameRate( ) : int;
	
		public function StartDrive( ) : void;
		
		
		//void addUserProc( type:String, UserFun fun);
		public function removeUserProc(  type:String ) : void;

	}
}
