//
// D:\test\lib\playerglobal.swc\flash\net\URLRequestMethod
//
package flash.net
{
	public class URLRequestMethod extends Object
	{
		/// Specifies that the URLRequest object is a DELETE.
		[native(support="none")]
		public static const DELETE : String = "DELETE";

		/// Specifies that the URLRequest object is a GET.
		public static const GET : String = "GET";

		/// Specifies that the URLRequest object is a HEAD.
		[native(support="none")]
		public static const HEAD : String = "HEAD";

		/// Specifies that the URLRequest object is a OPTIONS.
		[native(support="none")]
		public static const OPTIONS : String = "OPTIONS";

		/**
		 Specifies that the URLRequest object is a POST.
	 
	 Note:For content running in Adobe AIR, when When  using the navigateToURL() function, the runtime 
	 treats a URLRequest that uses the POST method (one that has its method property set to 
	 URLRequestMethod.POST) as using the GET method.
		 */
		public static const POST : String = "POST";

		/// Specifies that the URLRequest object is a PUT.
		[native(support="none")]
		public static const PUT : String = "PUT";

		public function URLRequestMethod ();
	}
}
