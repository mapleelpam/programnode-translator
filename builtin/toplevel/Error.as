﻿package 
{

    [no_reflection]
    //intrinsic public class Error extends Object 
    intrinsic public class Error 
    {
        public var message:String;
        public var name:String;
    
    
        [native(support="none")]
        public function getStackTrace() : String;

        [native(support="none")]
        public function get errorID() : int ;

        public function toString():String;
    }
}
