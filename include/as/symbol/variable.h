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
// Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple


#ifndef __TW_MAPLE_AS_SYMBOL_VARIABLE_H__
#define __TW_MAPLE_AS_SYMBOL_VARIABLE_H__

#include <as/symbol/symbol.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct Variable : public Symbol
{
	Variable( std::string n,  uint p = Symbol::T_NONE )
		: Symbol( n, p | Symbol::T_VARIABLE )
	{
	}


	virtual std::string toString()
	{
		std::string s_attr = "";
		if( m_properties & T_VARIABLE ) {
			if( m_properties & T_PRARAMETER )
				s_attr = "param";
			else
				s_attr = "local";
		}

		return "variable:"+name()+","+s_attr+" type:"+m_type_symbol->getFQN();
	}

	virtual void bindType( SymbolPtr type)
	{
			m_type_symbol = type;
	}
private:
	SymbolPtr	m_type_symbol;
};

typedef SHARED_PTR(Variable) VariablePtr;

}}}}//tw/maple/as/symbol

#endif

