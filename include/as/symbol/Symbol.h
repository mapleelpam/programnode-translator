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


#ifndef __TW_MAPLE_AS_SYMBOL_SYMBOL_H__
#define __TW_MAPLE_AS_SYMBOL_SYMBOL_H__

#include <boost/assert.hpp>
#include <string>

//namespace zs = zillians::zscript;
namespace tw { namespace maple { namespace as { namespace symbol {

class Symbol;
class Scope;
struct Registrable
{
public:
	Scope* addFunction( std::string Name );
	Scope* addPakage( std::string Name );
	Symbol* addVariable( std::string Name );

	Registrable( Scope* me ) : _me(me) {}
private:
	const Scope* _me;
};

struct Symbol
{
	enum Properties
	{
		T_SCOPE,
		T_VARIABLE,
		T_PRIMITIVE,
	};

	std::string name() {	return _m_name;	}

	Symbol( std::string n )
		: _m_name( n )
	{

	}

private:
	std::string _m_name;
};


};//Symbol

}}}//tw/maple/as/symbol

#endif

