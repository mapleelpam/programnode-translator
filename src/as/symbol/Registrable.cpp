/*
 * Symbol.cpp
 *
 *  Created on: Apr 21, 2011
 *      Author: maple
 */

/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// ProgrameNode Translator
// Copyright 2011 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple


#include <boost/assert.hpp>
#include <string>
#include <as/symbol/Symbol.h>
#include <as/symbol/Scope.h>
#include <as/symbol/action/Registrable.h>
#include <as/symbol/Function.h>

namespace tw { namespace maple {namespace as {namespace symbol {

FunctionPtr Registrable::registerFunction(std::string name) {
	FunctionPtr s(new Function(name, _instance));
	_instance->addChild(s);
	return s;
}
ScopePtr Registrable::registerPackage(std::string name) {
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
	ScopePtr s(new Scope(_instance));
	_instance->addChild(s);
	return s;
}

SymbolPtr Registrable::registerVariable(std::string name) {
		SymbolPtr symbol(new Variable(name));
		_instance->addChild(symbol);
		return symbol;
	}

SymbolPtr Registrable::registerFunctionParameter(std::string name) {
	SymbolPtr symbol(new Variable(name, Symbol::T_PRARAMETER));
//		symbol -> setSymbolProperties( Symbol::T_VARIABLE | Symbol::T_PRARAMETER);
	_instance->addChild(symbol);
	return symbol;
}
}}}}//tw/maple/as/symbol

