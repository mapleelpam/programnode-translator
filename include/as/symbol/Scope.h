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


#ifndef __TW_MAPLE_AS_SYMBOL_SCOPE_H__
#define __TW_MAPLE_AS_SYMBOL_SCOPE_H__

#include "global.h"
#include <boost/assert.hpp>
#include <as/symbol/Symbol.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct Scope;
typedef SHARED_PTR(Scope) ScopePtr;

struct Scope : public Symbol
{
	enum Properties
	{
		T_NONE			= 0x0000,
		T_PACKAGE 		= 0x0001,
		T_FUNCTIONE		= 0x0002,
		T_CLASS			= 0x0004,

		T_PROGRAM_ROOT	= 0x0008,
	};

	Scope( std::string n )
		: Symbol( n )
		, _m_prop( T_NONE )
	{
	}
	void setProperties( Properties p ) {	_m_prop = p;	};
	Properties getProperties( ) {	return _m_prop;	}

	static ScopePtr rootScope()
	{
		ScopePtr root( new Scope("root") );
		root->setProperties( T_PROGRAM_ROOT );
		return root;
	}

	ScopePtr registerFunction(std::string name )
	{
		ScopePtr s( new Scope( name ) );
		s -> setProperties( Scope::T_FUNCTIONE);
		_m_childs . push_back( s );
		return s;
	}
	SymbolPtr registerVariable(std::string name )
	{
		SymbolPtr symbol( new Symbol( name ) );
		symbol -> setSymbolProperties( Symbol::T_VARIABLE);
		_m_childs . push_back( symbol );
		return symbol;
	}
private:
	Properties _m_prop;
	std::list<SymbolPtr>	_m_childs;

friend ScopePtr registerFunction(std::string);

};


//ScopePtr registerPakage(std::string name)
//{
//	ScopePtr s( new Scope( name ) );
//	s -> setProperties( Scope::T_PACKAGE);
//	_m_childs . push_back( s );
//	return s;
//}
//SymbolPtr registerVariable(std::string name)
//{
//	ScopePtr s( new Scope( name ) );
//	s -> setProperties( Scope::T_CLASS );
//	_m_childs . push_back( s );
//	return s;
//}
}}}}//tw/maple/as/symbol

#endif


