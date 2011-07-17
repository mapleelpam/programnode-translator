#ifndef _TW_MAPLE_BACKEND_CPP_RETURNVALUE_H_
#define _TW_MAPLE_BACKEND_CPP_RETURNVALUE_H_

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct ReturnValue
{
	std::string result;
	ReturnValue( const std::string& init )
		: result( init )
	{	}
	ReturnValue( const char* init )
		: result( std::string(init) )
	{	}
	ReturnValue()
		: result("")
	{	}
	void operator=( const std::string& rhs )
	{	result = rhs;	}

//	std::string operator=( Value& right )
//	{
//		return right.result;
//	}
	operator std::string()
	{
		return result;
	}
	std::string operator+( const std::string& right )
	{	return result + right;	}

	std::string operator+( const ReturnValue& right )
	{	return result + right.result;	}

	const ReturnValue operator+(const ReturnValue &other) const {
		return ReturnValue(*this) += other;
	}

	std::string operator+=( const ReturnValue& right )
	{	return result += right.result;	}
};

} } } } }
#endif
