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


#ifndef __TW_MAPLE_AS_SYMBOL_REGISTRABLE_H__
#define __TW_MAPLE_AS_SYMBOL_REGISTRABLE_H__

#include <boost/assert.hpp>
#include <string>
#include <list>
#include <as/symbol/Symbol.h>

namespace tw { namespace maple { namespace as { namespace symbol {

class Scope;
struct Registrable
{
friend class Scope;
public:
	Scope* addFunction( std::string Name );
	Scope* addPakage( std::string Name );
	Symbol* addVariable( std::string Name );

	Registrable() : _me(NULL) {}
private:
	void setInstance( Scope* me ) { _me = me; }
	const Scope* _me;

	std::list<SymbolPtr>	_m_childs;
};

}}}}//tw/maple/as/symbol

#endif

