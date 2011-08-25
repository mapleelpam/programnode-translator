 /*******************************************************************\
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com       *
 *                                                                   *
 * Licensed under the Apache License, Version 2.0 (the "License");   *
 * you may not use this file except in compliance with the License.  *
 * You may obtain a copy of the License at                           *
 *                                                                   *
 *   http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                   *
 * Unless required by applicable law or agreed to in writing,        *
 * software distributed under the License is distributed on an       *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY            *
 * KIND, either express or implied. See the License for the          *
 * specific language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 *     https://github.com/mapleelpam/programnode-translator          *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#include <global.h>
#include <as/symbol/symbol.h>
#include <as/symbol/scope.h>
#include <as/symbol/variable.h>
#include <as/symbol/parameter.h>
#include <as/symbol/action/registrable.h>
#include <as/symbol/function.h>

namespace tw { namespace maple {namespace as {namespace symbol {

FunctionPtr Registrable::registerFunction(std::string name) {
	FunctionPtr s(new Function(name, _instance));
	_instance->addChild(s);
	return s;
}
ScopePtr Registrable::registerPackage(std::string name) {
	std::vector<SymbolPtr> childs;
	_instance->getChilds( childs );

	for( std::vector<SymbolPtr>::iterator itr = childs.begin(), E = childs.end()
			; itr != E ; itr ++ )
	{
		if( (*itr)->getSymbolProperties() == Symbol::T_SCOPE && (*itr)->name() == name ) // is anonymous scope
		{
			ScopePtr anonymouse = DYNA_CAST( Scope, *itr);
			return anonymouse;
		}
	}

	ScopePtr s(new Scope(name, Scope::T_PACKAGE, _instance));
	_instance->addChild(s);
	return s;
}
ScopePtr Registrable::registerPackage( std::vector<std::string> names ) {

	ScopePtr s0 = registerPackage( names[0] );

	ScopePtr cur = s0;
	for( int idx = 1 ; idx < names.size() ; idx ++) {
		ScopePtr next = cur->registerPackage( names[idx] );
		cur = next;
	}
	return cur;
}

ScopePtr Registrable::registerClass(std::string name) {
	ScopePtr s(new Scope(name, Scope::T_CLASS, _instance));
	_instance->addChild(s);
	return s;
}
ScopePtr Registrable::registerAnonymousScope() {
	std::vector<SymbolPtr> childs;
	_instance->getChilds( childs );
	for( std::vector<SymbolPtr>::iterator itr = childs.begin(), E = childs.end()
			; itr != E ; itr ++ )
	{
		if( (*itr)->getSymbolProperties() == Symbol::T_SCOPE && (*itr)->name() == "" ) // is anonymous scope
		{
			ScopePtr anonymouse = DYNA_CAST( Scope, *itr);
			return anonymouse;
		}
	}
	// else
	ScopePtr s(new Scope(_instance));
	_instance->addChild(s);
	return s;
}

VariablePtr Registrable::registerVariable(std::string name) {
	VariablePtr symbol(new Variable(name, _instance));
		_instance->addChild(symbol);
		return symbol;
	}

SymbolPtr Registrable::registerFunctionParameter(std::string name) {
	SymbolPtr symbol(new Parameter(name, _instance, Symbol::T_PARAMETER));
//		symbol -> setSymbolProperties( Symbol::T_VARIABLE | Symbol::T_PRARAMETER);
	_instance->addChild(symbol);
	return symbol;
}
}}}}//tw/maple/as/symbol

