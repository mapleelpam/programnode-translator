package
{
	intrinsic public class Date extends Object
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

//		public function Date (year:* = null, month:* = null, date:* = null, hours:* = null, minutes:* = null, seconds:* = null, ms:* = null);

		public function getDate () : Number;

		public function getDay () : Number;

		public function getFullYear () : Number;

		public function getHours () : Number;

		public function getMilliseconds () : Number;

		public function getMinutes () : Number;

		public function getMonth () : Number;

		public function getSeconds () : Number;

		public function getTime () : Number;

		public function getTimezoneOffset () : Number;

		public function getUTCDate () : Number;

		public function getUTCDay () : Number;

		public function getUTCFullYear () : Number;

		public function getUTCHours () : Number;

		public function getUTCMilliseconds () : Number;

		public function getUTCMinutes () : Number;

		public function getUTCMonth () : Number;

		public function getUTCSeconds () : Number;

		public static function parse (s:*) : Number;

		public function setDate (date:* = null) : Number;

		public function setFullYear (year:* = null, month:* = null, date:* = null) : Number;

		public function setHours (hour:* = null, min:* = null, sec:* = null, ms:* = null) : Number;

		public function setMilliseconds (ms:* = null) : Number;

		public function setMinutes (min:* = null, sec:* = null, ms:* = null) : Number;

		public function setMonth (month:* = null, date:* = null) : Number;

		public function setSeconds (sec:* = null, ms:* = null) : Number;

		public function setTime (t:* = null) : Number;

		public function setUTCDate (date:* = null) : Number;

		public function setUTCFullYear (year:* = null, month:* = null, date:* = null) : Number;

		public function setUTCHours (hour:* = null, min:* = null, sec:* = null, ms:* = null) : Number;

		public function setUTCMilliseconds (ms:* = null) : Number;

		public function setUTCMinutes (min:* = null, sec:* = null, ms:* = null) : Number;

		public function setUTCMonth (month:* = null, date:* = null) : Number;

		public function setUTCSeconds (sec:* = null, ms:* = null) : Number;

		public function toDateString () : String;

		public function toLocaleDateString () : String;

		public function toLocaleString () : String;

		public function toLocaleTimeString () : String;

		public function toString () : String;

		public function toTimeString () : String;

		public function toUTCString () : String;

		//public static function UTC (year:*, month:*, date:* = 1, hours:* = 0, minutes:* = 0, seconds:* = 0, ms:* = 0, ...rest) : Number;

		public function valueOf () : Number;
	}
}
