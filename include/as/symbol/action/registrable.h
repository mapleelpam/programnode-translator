/* ***************************************************************
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 * ProgrameNode Translator
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
 *
 * https://github.com/mapleelpam/programnode-translator
 *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple
 * ***************************************************************/

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

	SymbolPtr registerFunctionParameter(std::string name, bool has_init);

private:
	Scope* _instance;
};

}}}}//tw/maple/as/symbol

#endif /* REGISTRABLE_H_ */
