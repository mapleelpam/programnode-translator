
#include <global.h>

namespace tw { namespace maple {

std::string replace(
		const std::string &input
		, const std::string &SearchString
		, const std::string &ReplaceString
		)
{   
	std::string result = input;
	std::string::size_type p = 0;
	while((p = result.find(SearchString, p)) != std::string::npos)
	{   
		result.replace(p, SearchString.size(), ReplaceString);
		p++;
	}
	return result;
}

} /*maple*/ } /*tw*/


