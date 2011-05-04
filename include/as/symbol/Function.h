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


#ifndef __TW_MAPLE_AS_SYMBOL_SCOPE_FUNCTION_H__
#define __TW_MAPLE_AS_SYMBOL_SCOPE_FUNCTION_H__

#include <as/symbol/Scope.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct Function : public Scope
{
	Function( std::string n, Scope *parent = NULL  )
		: Scope( n, Scope::T_FUNCTION, parent )
	{
	}


	virtual std::string toString()
	{
		return "function:"+name();
	}

	virtual void bindReturnType( SymbolPtr type)
	{
		m_return_type_symbol = type;
	}
private:
	SymbolPtr	m_return_type_symbol;
};

typedef SHARED_PTR(Function) FunctionPtr;

}}}}//tw/maple/as/symbol

#endif

