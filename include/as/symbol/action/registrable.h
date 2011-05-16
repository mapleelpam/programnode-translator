/*
 * Registrable.h
 *
 *  Created on: Apr 27, 2011
 *      Author: maple
 */

#ifndef REGISTRABLE_H_
#define REGISTRABLE_H_

#include <as/symbol/symbol.h>
//#include <as/symbol/variable.h>
namespace tw {namespace maple {namespace as {namespace symbol {

struct Function;
typedef SHARED_PTR(Function) FunctionPtr;

struct Scope;
typedef SHARED_PTR(Scope) ScopePtr;

struct Variable;
typedef SHARED_PTR(Variable) VariablePtr;

struct Registrable {

	Registrable(Scope* instance) :
		_instance(instance) {
	}

	FunctionPtr registerFunction(std::string name);
	ScopePtr registerPackage( std::vector<std::string> names );
	ScopePtr registerPackage( std::string names );
	ScopePtr registerClass(std::string name);
	ScopePtr registerAnonymousScope();

	VariablePtr registerVariable(std::string name);

	SymbolPtr registerFunctionParameter(std::string name);

private:
	Scope* _instance;
};

}}}}//tw/maple/as/symbol

#endif /* REGISTRABLE_H_ */
