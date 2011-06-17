//
// D:\test\lib\playerglobal.swc\Date
//
package
{
	public class Date extends Object
	{
		public static const length : int;

		public function get date () : Number;
		public function set date (value:Number) : void;

		public function get dateUTC () : Number;
		public function set dateUTC (value:Number) : void;

		public function get day () : Number;

		public function get dayUTC () : Number;

		public function get fullYear () : Number;
		public function set fullYear (value:Number) : void;

		public function get fullYearUTC () : Number;
		public function set fullYearUTC (value:Number) : void;

		public function get hours () : Number;
		public function set hours (value:Number) : void;

		public function get hoursUTC () : Number;
		public function set hoursUTC (value:Number) : void;

		public function get milliseconds () : Number;
		public function set milliseconds (value:Number) : void;

		public function get millisecondsUTC () : Number;
		public function set millisecondsUTC (value:Number) : void;

		public function get minutes () : Number;
		public function set minutes (value:Number) : void;

		public function get minutesUTC () : Number;
		public function set minutesUTC (value:Number) : void;

		public function get month () : Number;
		public function set month (value:Number) : void;

		public function get monthUTC () : Number;
		public function set monthUTC (value:Number) : void;

		public function get seconds () : Number;
		public function set seconds (value:Number) : void;

		public function get secondsUTC () : Number;
		public function set secondsUTC (value:Number) : void;

		public function get time () : Number;
		public function set time (value:Number) : void;

		public function get timezoneOffset () : Number;

		public function Date (year:* = null, month:* = null, date:* = null, hours:* = null, minutes:* = null, seconds:* = null, ms:* = null);

		AS3 function getDate () : Number;

		AS3 function getDay () : Number;

		AS3 function getFullYear () : Number;

		AS3 function getHours () : Number;

		AS3 function getMilliseconds () : Number;

		AS3 function getMinutes () : Number;

		AS3 function getMonth () : Number;

		AS3 function getSeconds () : Number;

		AS3 function getTime () : Number;

		AS3 function getTimezoneOffset () : Number;

		AS3 function getUTCDate () : Number;

		AS3 function getUTCDay () : Number;

		AS3 function getUTCFullYear () : Number;

		AS3 function getUTCHours () : Number;

		AS3 function getUTCMilliseconds () : Number;

		AS3 function getUTCMinutes () : Number;

		AS3 function getUTCMonth () : Number;

		AS3 function getUTCSeconds () : Number;

		public static function parse (s:*) : Number;

		AS3 function setDate (date:* = null) : Number;

		AS3 function setFullYear (year:* = null, month:* = null, date:* = null) : Number;

		AS3 function setHours (hour:* = null, min:* = null, sec:* = null, ms:* = null) : Number;

		AS3 function setMilliseconds (ms:* = null) : Number;

		AS3 function setMinutes (min:* = null, sec:* = null, ms:* = null) : Number;

		AS3 function setMonth (month:* = null, date:* = null) : Number;

		AS3 function setSeconds (sec:* = null, ms:* = null) : Number;

		AS3 function setTime (t:* = null) : Number;

		AS3 function setUTCDate (date:* = null) : Number;

		AS3 function setUTCFullYear (year:* = null, month:* = null, date:* = null) : Number;

		AS3 function setUTCHours (hour:* = null, min:* = null, sec:* = null, ms:* = null) : Number;

		AS3 function setUTCMilliseconds (ms:* = null) : Number;

		AS3 function setUTCMinutes (min:* = null, sec:* = null, ms:* = null) : Number;

		AS3 function setUTCMonth (month:* = null, date:* = null) : Number;

		AS3 function setUTCSeconds (sec:* = null, ms:* = null) : Number;

		AS3 function toDateString () : String;

		AS3 function toLocaleDateString () : String;

		AS3 function toLocaleString () : String;

		AS3 function toLocaleTimeString () : String;

		AS3 function toString () : String;

		AS3 function toTimeString () : String;

		AS3 function toUTCString () : String;

		public static function UTC (year:*, month:*, date:* = 1, hours:* = 0, minutes:* = 0, seconds:* = 0, ms:* = 0, ...rest) : Number;

		AS3 function valueOf () : Number;
	}
}
