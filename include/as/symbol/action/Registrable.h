/*
 * Registrable.h
 *
 *  Created on: Apr 27, 2011
 *      Author: maple
 */

#ifndef REGISTRABLE_H_
#define REGISTRABLE_H_

#include <as/symbol/Symbol.h>

namespace tw {
namespace maple {
namespace as {
namespace symbol {

template<typename T>
struct Registrable {

	Registrable(T* instance) :
		_instance(instance) {
	}

	static SHARED_PTR(T) rootScope() {
		SHARED_PTR(T) root(new T("root", T::T_PROGRAM_ROOT));
		return root;
	}

	SHARED_PTR(T) registerFunction(std::string name) {
		SHARED_PTR(T) s(new T(name, T::T_FUNCTION));
		_instance->addChild(s);
		return s;
	}
	SHARED_PTR(T) registerClass(std::string name) {
		SHARED_PTR(T) s(new T(name, T::T_CLASS));
		_instance->addChild(s);
		return s;
	}
	SHARED_PTR(T) registerAnonymousScope() {
		SHARED_PTR(T) s(new T("", T::T_ANONYMOUS));
		_instance->addChild(s);
		return s;
	}
	SymbolPtr registerVariable(std::string name) {
		SymbolPtr symbol(new Symbol(name));
		symbol -> setSymbolProperties( Symbol::T_VARIABLE );
		_instance->addChild(symbol);
		return symbol;
	}

	SymbolPtr registerFunctionParameter(std::string name) {
		SymbolPtr symbol(new Symbol(name));
		symbol -> setSymbolProperties( Symbol::T_VARIABLE | Symbol::T_PRARAMETER);
		_instance->addChild(symbol);
		return symbol;
	}

private:
	T* _instance;
};

}
}
}
}//tw/maple/as/symbol

#endif /* REGISTRABLE_H_ */
