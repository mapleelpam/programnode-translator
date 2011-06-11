package
{
	[native(cls="FrameDrive", instance="FrameDrive", methods="auto")]
	public final class FrameDrive extends Object
	{
		public static function GetTicks() : int; /* should be uint64 */
		public function SetFrameRate( var framerate : int ) : void;
		public function GetFrameRate( ) : int;
	
		public function StartDrive( ) : void;
		
		
		//void addUserProc(const std::string & type, UserFun fun);
		public function removeUserProc( var String & type) : void;

	}
}
