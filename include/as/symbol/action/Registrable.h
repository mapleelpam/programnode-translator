/*
 * Registrable.h
 *
 *  Created on: Apr 27, 2011
 *      Author: maple
 */

#ifndef REGISTRABLE_H_
#define REGISTRABLE_H_

#include <as/symbol/Symbol.h>


namespace tw { namespace maple { namespace as { namespace symbol {

template< typename T >
struct Registrable {

	Registrable( T* instance )
		: _instance( instance )
	{

	}
	static SHARED_PTR(T) rootScope()
		{
			SHARED_PTR(T) root( new T("root") );
			root->setProperties( T::T_PROGRAM_ROOT );
			return root;
		}

	SHARED_PTR(T) registerFunction(std::string name )
		{
			SHARED_PTR(T) s( new T( name ) );
			s -> setProperties( T::T_FUNCTIONE);
			_instance->_m_childs . push_back( s );
			return s;
		}
	SymbolPtr registerVariable(std::string name )
	{
		SymbolPtr symbol( new Symbol( name ) );
		symbol -> setSymbolProperties( T::T_VARIABLE);
		_instance->_m_childs . push_back( symbol );
		return symbol;
	}

private:
	T* _instance;
};

}}}}//tw/maple/as/symbol

#endif /* REGISTRABLE_H_ */
