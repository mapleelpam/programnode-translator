

#include <service/ConfigService.h>

namespace tw { namespace maple { namespace service {



ConfigRequest::ConfigRequest()
{
	SVC_CONFIG->registerElement(this);
}


} /*service*/ } /*maple*/ } /*tw*/
