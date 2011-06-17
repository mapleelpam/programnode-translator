
intrinsic class flash.net.URLRequest {

	public var contentType: String;
	public var data: Object;
	public var method: String;
	public var requestHeaders: Arrary;
	public var url: String;

	public function get_contentType() : String;

	public function get_method() : String;
	public function get_url() : String;
	public function get_requestHeaders() : Array;
	public function get_data() : Object;
	
	public function set_contentType( String rhs ) : void;

	public function set_method( String rhs ) : void;
	public function set_url( String rhs ) : void;
	public function set_requestHeaders( Array ths ) : void;
	public function set_data( Object rhs ) : void;

	public function URLRequest( String _url );
}
