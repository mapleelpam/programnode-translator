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


#ifndef __TW_MAPLE_AS_SYMBOL__SYMBOL_H__
#define __TW_MAPLE_AS_SYMBOL__SYMBOL_H__

#include <boost/assert.hpp>
#include <string>
#include <stdlib.h>
#include <global.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct Symbol;
typedef SHARED_PTR(Symbol) SymbolPtr;

struct Symbol
{
	enum Properties
	{
		T_NONE			= 0x0000,
		T_SCOPE			= 0x0001,
		T_VARIABLE		= 0x0002,
		T_PRIMITIVE_TYPE= 0x0004,
		T_PRARAMETER	= 0x0008,
	};

	enum Attributes
	{
		ATTR_NONE,
		ATTR_PUBLIC,
		ATTR_PRIVATE,
	};

	const std::string name() const {	return m_name;	}

	Symbol( std::string n,  uint p = T_NONE, Attributes attr = ATTR_NONE )
		: m_name( n )
		, m_properties( p )
		, m_attributes( attr )
	{
	}

	uint getSymbolProperties( ) const {	return m_properties;	}
	void setSymbolProperties( uint p ) {	m_properties = p;	};

	virtual std::string toString() = 0;
	virtual void bindType( SymbolPtr ){}

	Attributes getSymbolAttribtues( ) const {	return m_attributes;	}
	void setSymbolAttributes( Attributes p ) {	m_attributes = p;	};
	virtual std::string getFQN()
	{
			return name();
	}
protected:
	std::string		m_name;
	uint			m_properties;
	Attributes		m_attributes;
};

}}}}//tw/maple/as/symbol

#endif

