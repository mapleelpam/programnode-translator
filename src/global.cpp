
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

std::vector<std::string> tokenize(const std::string& str, const std::string& delimiters, bool allowEmptyTokenString)
{
	std::vector<std::string> tokens;
	std::string::size_type delimPos = 0, tokenPos = 0, pos = 0;

	if (str.length() < 1)
		return tokens;

	while (true)
	{
		delimPos = str.find_first_of(delimiters, pos);
		tokenPos = str.find_first_not_of(delimiters, pos);

		if (std::string::npos != delimPos)
		{
			if (std::string::npos != tokenPos)
			{
				if (tokenPos < delimPos)
				{
					tokens.push_back(str.substr(pos, delimPos - pos));
				}
				else
				{
					if (allowEmptyTokenString)	tokens.push_back("");
				}
			}
			else
			{
				if (allowEmptyTokenString) tokens.push_back("");
			}
			pos = delimPos + 1;
		}
		else
		{
			if (std::string::npos != tokenPos)
			{
				tokens.push_back(str.substr(pos));
			}
			else
			{
				if (allowEmptyTokenString) tokens.push_back("");
			}
			break;
		}
	}
	return tokens;
}

} /*maple*/ } /*tw*/


