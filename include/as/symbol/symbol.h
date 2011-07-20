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

#ifndef __TW_MAPLE_AS_SYMBOL__SYMBOL_H__
#define __TW_MAPLE_AS_SYMBOL__SYMBOL_H__

#include <global.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct Symbol;
typedef SHARED_PTR(Symbol) SymbolPtr;

struct Symbol
{
	enum Properties
	{
		T_NONE			= 0x0000,
		T_SCOPE			= 0x0002, // function/class/package
		T_VARIABLE		= 0x0004,
		T_PRIMITIVE_TYPE= 0x0008,
		T_PARAMETER	= 0x0010,
	};

	enum Attributes
	{
		ATTR_NONE,
		ATTR_PUBLIC,
		ATTR_PRIVATE,
	};

	const std::string name() const {	return m_name;	}
	virtual const std::string mappedName() const {	return m_mapped_name;	}
	void	setMappedName( std::string n ){ m_mapped_name = n;	}

	Symbol( std::string n,  uint p = T_NONE, Attributes attr = ATTR_NONE )
		: m_name( n )
		, m_properties( p )
		, m_attributes( attr )
		, m_is_static( false )
	{
	}

	uint getSymbolProperties( ) const {	return m_properties;	}
	void setSymbolProperties( uint p ) {	m_properties = p;	};

	virtual const std::string toString() const = 0;
	virtual void bindType( SymbolPtr ){}

	Attributes getSymbolAttribtues( ) const {	return m_attributes;	}
	void setSymbolAttributes( Attributes p ) {	m_attributes = p;	};

	void setIsStatic( bool b ){	m_is_static = b;	}
	bool isStatic()	{	return m_is_static;	}

	virtual const std::string getFQN( ) const
	{
		return name();
	}
	virtual const std::string getFQN_and_mappedName() const
	{
		return mappedName();
	}
	virtual bool isConstructor( ) const
	{
		return false;
	}
	virtual bool isPrimitiveType( ) const
	{
		return false;
	}

	bool is( Properties prop )
	{
		return ( m_properties & prop ) != 0;

	}
	virtual bool preferStack() const {	return false;	} // prefer heap
	virtual std::string instanceName() const {	return mappedName();	}
	virtual const std::string getFQN_and_m_instanceName() const
	{
		return instanceName();
	}
protected:
	std::string		m_name;
	std::string		m_mapped_name;
	uint			m_properties;
	Attributes		m_attributes;
	bool			m_is_static;
};

}}}}//tw/maple/as/symbol

#endif

