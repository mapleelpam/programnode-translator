#ifndef _TW_MAPLE_BACKEND_CPP_RETURNVALUE_H_
#define _TW_MAPLE_BACKEND_CPP_RETURNVALUE_H_

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct ReturnValue
{
	tw::maple::as::symbol::SymbolPtr		token_symbol;
	tw::maple::as::symbol::Symbol*		token_symbol2;
	bool is_instance;
	std::string result;
	ReturnValue( const std::string& init )
		: result( init )
		, token_symbol(tw::maple::as::symbol::SymbolPtr())
		, token_symbol2( NULL )
		, is_instance(false)
	{	}
	ReturnValue( const char* init )
		: result( std::string(init) )
		, token_symbol(tw::maple::as::symbol::SymbolPtr())
		, token_symbol2( NULL )
		, is_instance(false)
	{	}
	ReturnValue( const ReturnValue& right )
		: result( right.result )
		, token_symbol( right.token_symbol )
		, token_symbol2( right.token_symbol2)
		, is_instance( right.is_instance )
	{
		std::cerr<<"------> path damn "<<(right.token_symbol!=NULL?right.token_symbol->name():"")<<std::endl;
	}
	ReturnValue()
		: result("")
		, token_symbol(tw::maple::as::symbol::SymbolPtr())
		, token_symbol2( NULL )
		, is_instance(false)
	{	}

	void operator=( const std::string& rhs )
	{	result = rhs;	}

	void operator=( ReturnValue& right )
	{
		result = right.result;
		token_symbol = right.token_symbol;
		is_instance = right.is_instance;
		std::cerr<<"------> path shit  "<< right.is_instance<<std::endl;
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
