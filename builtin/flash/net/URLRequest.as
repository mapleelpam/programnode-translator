//
// D:\test\lib\playerglobal.swc\flash\net\URLRequest
//
package flash.net
{
	public class URLRequest extends Object
	{
		/**
		 The MIME content type of the content in the the data property.
     
     The default value is application/x-www-form-urlencoded.Note:The FileReference.upload(),
     FileReference.download(), and HTMLLoader.load() methods do not
     support the URLRequest.contentType property.When sending a POST request, the values of the contentType 
     and data properties must correspond properly. The value of the contentType 
     property instructs servers on how to interpret the value of the data property. If the value of the data property is a URLVariables object, the value of 
     contentType must be application/x-www-form-urlencoded.  If the value of the data property is any other type, the value of contentType 
     should indicate the type of the POST data that will be sent (which is the binary or string data 
     contained in the value of the data property). For FileReference.upload(), 
     the Content-Type of the request is set automatically to multipart/form-data, 
     and the value of the contentType property is ignored. In Flash Player 10 and later, if you use a multipart Content-Type (for example "multipart/form-data") 
     that contains an upload (indicated by a "filename" parameter in a "content-disposition" header within the POST body),
	 the POST operation is subject to the security rules applied to uploads:The POST operation must be performed in response to a user-initiated action, such as a mouse click or key press.If the POST operation is cross-domain (the POST target is not on the same server as the SWF file 
	 that is sending the POST request),
	 the target server must provide a URL policy file that permits cross-domain access.Also, for any multipart Content-Type, the syntax must be valid (according to the RFC2046 standards).
     If the syntax appears to be invalid, the POST operation is subject to the security rules applied to uploads.
		 */
		public function get contentType () : String;
		public function set contentType (value:String) : void;

		/**
		 An object containing data to be transmitted with the URL request. 
     
     This property is used in conjunction with the method property.
     When the value of method is GET,
     the value of data is appended to the value of URLRequest.url, 
     using HTTP query-string syntax. When the method value is POST 
     (or any value other than GET), the value 
     of data is transmitted in the body of the HTTP request.The URLRequest API offers binary POST support and support for URL-encoded variables,
     as well as support for strings. The data object can be a ByteArray, URLVariables, 
     or String object.The way in which the data is used depends on the type of object used:If the object is a ByteArray object, the binary
     data of the ByteArray object is used as POST data. For GET, data of ByteArray type
     is not supported. Also, data of ByteArray type is not supported for
     FileReference.upload() and FileReference.download().If the object is a URLVariables object and the method is POST,
     the variables are encoded using x-www-form-urlencoded format
     and the resulting string is used as POST data. An exception is a call to 
     FileReference.upload(), in which the variables are sent as separate fields in
     a multipart/form-data post.If the object is a URLVariables object and the method is GET,
     the URLVariables object defines variables to be sent with the URLRequest object.Otherwise, the object is converted to a string, and the string
     is used as the POST or GET data.This data is not sent until a method, such as navigateToURL() 
     or FileReference.upload(), uses the URLRequest object.Note: The value of contentType must correspond to the type of data 
     in the data property. See the note in the description of the 
     contentType property.
		 */
		public function get data () : Object;
		public function set data (value:Object) : void;
		[native(support="none")]
		public function get digest () : String;
		/**
		 A string that uniquely identifies the signed Adobe platform component to be stored 
     to (or retrieved from) the Flash Player cache.  An Adobe 
     platform component is a signed file (a SWZ file) that contains SWF content that is cached  
     persistently on a user's machine. All SWZ files are signed by Adobe. A digest 
     corresponds to a single cached file; if you change the file in any way, its digest
     will change in an unpredictable way. By using a digest, you can verify the cached file across
     multiple domains. Two files with the same digest are the same file, and two files with different
     digests are not the same file. A file cannot (practically) be created to "spoof" a digest and 
     pretend to be another digest. This property applies to
     SWF content only; it does not apply to JavaScript code running in AIR.The digest is based on an SHA-256 message digest algorithm 
     (64 characters long in hexadecimal format).For example, the Flex SDK includes a SWZ for the Flex framework (and it
     provides the digest string for that SWZ file). You can post this SWZ on your web server and load it 
     in your SWF file (using the load() method of a URLLoader object). If the end user's 
     machine already has the matching SWZ file cached, the application uses the cached SWZ file. 
     (A SWZ file matches if its digest matches the one you provide.) Otherwise, the 
     application downloads the SWZ file from the URL you specify. Only set the digest parameter in a URLRequest object
     used in a call to the URLLoader.load() method to load a SWZ file. If the digest
     property of a a URLRequest object is set when it is used in other methods, the application throws an
     IOError exception.
		 */
		[native(support="none")]
		public function set digest (value:String) : void;

		/**
		 Controls the HTTP form submission method. 
     
     For SWF content running in Flash Player 
     (in the browser), this property is limited to GET or 
     POST operations, and valid values are URLRequestMethod.GET 
     or URLRequestMethod.POST.For content running in Adobe AIR, you You can use any string value
     if the content is in the application security sandbox. Otherwise,
     as with content running in Flash Player, 
     you are restricted to using GET or POST operations, and valid values are 
     URLRequestMethod.GET or URLRequestMethod.POST.For content running in Adobe AIR, when When 
     using the navigateToURL() function, the runtime treats a URLRequest that uses the POST
     method (one that has its method property set to URLRequestMethod.POST)
     as using the GET method.Note: 
     If running in Flash Player and the referenced form has no body, 
     Flash Player automatically uses a GET operation, even if the method is set to 
     URLRequestMethod.POST. For this reason, it is recommended to always include 
     a "dummy" body to ensure that the correct method is used.
		 */
		public function get method () : String;
		public function set method (value:String) : void;

		/**
		 The array of HTTP request headers to be appended to the
     HTTP request. The array is composed of URLRequestHeader objects.
     Each object in the array must be a URLRequestHeader object that 
     contains a name string and a value string, as follows: 
     
     var rhArray:Array = new Array(new URLRequestHeader("Content-Type", "text/html"));
     Flash Player and the AIR runtime imposeThe AIR runtime imposes certain restrictions on request headers; 
     for more information, see the URLRequestHeader class description.Not all methods that accept URLRequest parameters support the requestHeaders property,
     consult the documentation for the method you are calling. For example, the FileReference.upload()
     and FileReference.download() methods do not
     support the URLRequest.requestHeaders property.Due to browser limitations, custom HTTP request headers are only supported for POST requests,
     not for GET requests.
		 */
		public function get requestHeaders () : Array;
		public function set requestHeaders (value:Array) : void;

		/**
		 The URL to be requested. 
     
     Be sure to encode any characters that are either described as unsafe in the Uniform Resource Locator 
     specification (see http://www.faqs.org/rfcs/rfc1738.html) or that are reserved in the 
     URL scheme of the URLRequest object (when not used for their reserved purpose). For example, 
     use "%25" for the percent (%) symbol and "%23" for the number sign (#), as in 
     "http://www.example.com/orderForm.cfm?item=%23B-3&discount=50%25".By default, the URL must be in the same domain as the calling file,
      unless the content is running in the Adobe AIR application 
      security sandbox. If you need to load data from a different domain,
      put a URL policy file on the server that is hosting the data. For more information,
      see the description of the URLRequest class.For content running in Adobe AIR, filesFiles in the application security sandobx
     — files installed with the AIR application — can access URLs using any of the 
     following URL schemes:http and httpsfileapp-storageappNote: IPv6 (Internet Protocol version 6) is supported in
     AIR and in Flash Player 9.0.115.0 and later. 
     
     IPv6 is a version of Internet Protocol that supports 
     128-bit addresses (an improvement on the earlier IPv4 protocol that supports 32-bit 
     addresses). You might need to activate IPv6 on your networking interfaces. For more 
     information, see the Help for the operating system hosting the data.
     If IPv6 is supported on the hosting system, you can specify numeric IPv6 literal addresses
     in URLs enclosed in brackets ([]), as in the following. 
     rtmp://[2001:db8:ccc3:ffff:0:444d:555e:666f]:1935/test
		 */
		public function get url () : String;
		public function set url (value:String) : void;

		public function URLRequest (url:String = null);
	}
}
