#ifndef _TW_MAPLE_BACKEND_CPP_RETURNVALUE_H_
#define _TW_MAPLE_BACKEND_CPP_RETURNVALUE_H_

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct ReturnValue
{
	tw::maple::as::symbol::SymbolPtr		token_symbol;
	std::string result;
	ReturnValue( const std::string& init )
		: result( init )
		, token_symbol(tw::maple::as::symbol::SymbolPtr())
	{	}
	ReturnValue( const char* init )
		: result( std::string(init) )
		, token_symbol(tw::maple::as::symbol::SymbolPtr())
	{	}
	ReturnValue( const ReturnValue& right )
		: result( right.result )
		, token_symbol( right.token_symbol )
	{
		std::cerr<<"------> path damn "<<(right.token_symbol!=NULL?right.token_symbol->name():"")<<std::endl;
	}
	ReturnValue()
		: result("")
		, token_symbol(tw::maple::as::symbol::SymbolPtr())
	{	}
	void operator=( const std::string& rhs )
	{	result = rhs;	}

	void operator=( ReturnValue& right )
	{
		result = right.result;
		token_symbol = right.token_symbol;
		std::cerr<<"------> path shit"<<std::endl;
	}
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
