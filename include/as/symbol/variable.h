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

#ifndef __TW_MAPLE_AS_SYMBOL_VARIABLE_H__
#define __TW_MAPLE_AS_SYMBOL_VARIABLE_H__

#include <as/symbol/symbol.h>
//#include <as/symbol/scope.h>
#include <as/ast/node.h>

namespace tw { namespace maple { namespace as { namespace symbol {
struct Scope;
struct Variable : public Symbol
{
	Variable( std::string n, Scope *parent,  uint p = Symbol::T_NONE )
		: Symbol( n, p | Symbol::T_VARIABLE )
		, m_parent( parent )
	{
	}


	virtual const std::string toString() const
	{
		std::string s_attr = "";
		if( m_properties & T_VARIABLE ) {
			if( m_properties & T_PARAMETER )
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
	virtual const std::string getFQN() const
	{
		if (m_parent)
			return m_parent->getFQN() + "::" + name();
		else
			return name();
	}
	virtual const std::string getFQN_noprefix( ) const
	{
		if (m_parent)
			return m_parent->getFQN_noprefix() + "::" + ( mappedName() == "" ? name() : mappedName() );
		else
			return name();
	}
	virtual const std::string getMapedFQN_noprefix( ) const
	{
		std::string n =  (mappedName() == "") ? name() : mappedName();
		if (m_parent)
			return m_parent->getFQN_noprefix() + "::" + n;
		else
			return n;
	}
	SymbolPtr getTypeSymbol()
	{
		return m_type_symbol;
	}
	bool isClassMember()
	{
		if(m_parent)
		{
			if( m_parent->getScopeType() == Scope::T_CLASS )
				return true;
		}
		return false;
	}

private:
	SymbolPtr	m_type_symbol;
	Scope*		m_parent;

public:
	void setInitializeNode( tw::maple::as::ast::NodePtr node )
	{
		m_initialize_node = node;
	}
	tw::maple::as::ast::NodePtr getInitializeNode()
	{
		return m_initialize_node;
	}
private:
	tw::maple::as::ast::NodePtr 	m_initialize_node;
};

typedef SHARED_PTR(Variable) VariablePtr;

}}}}//tw/maple/as/symbol

#endif

