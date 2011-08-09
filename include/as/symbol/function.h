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

#ifndef __TW_MAPLE_AS_SYMBOL_SCOPE_FUNCTION_H__
#define __TW_MAPLE_AS_SYMBOL_SCOPE_FUNCTION_H__

#include <as/symbol/scope.h>
#include "SyntaxTree_types.h"

namespace tw { namespace maple { namespace as { namespace symbol {

struct Function : public Scope
{
	Function( std::string n, Scope *parent = NULL )
		: Scope( n, Scope::T_FUNCTION, parent )
		, m_is_constructor( false )
		, m_ever_used_like_variable( false )
		, m_function_type( tw::maple::generated::FunctionType::TF_NORMAL )
	{
	}

	void setIsConstructor( bool b )
	{
		m_is_constructor = b;
	}
	bool isConstructor( ) const
	{
		return m_is_constructor;
	}

	virtual const std::string toString() const
	{
		std::string post;
		if( isGetter() )
			post = "GET";
		if( isSetter() )
			post = "SET";
		return "function:"+name() + " return:"+m_return_type_symbol->getFQN()+" :"+post;
	}

	virtual void bindType( SymbolPtr sType )
	{
		m_return_type_symbol = sType;
	}
	void bindReturnType( SymbolPtr type)
	{
		m_return_type_symbol = type;
		m_types.push_back( type );
	}
	void addParameterType( SymbolPtr param_type )
	{
		m_types.push_back( param_type );
	}


	SymbolPtr ReturnType()
	{
		return m_return_type_symbol;
	}

	void setFunctionType( tw::maple::generated::FunctionType::type t)
	{
		m_function_type = t;

	}
	const bool isSetter() const
	{
		return m_function_type == tw::maple::generated::FunctionType::TF_SETTER;
	}
	const bool isGetter() const
	{
		return m_function_type == tw::maple::generated::FunctionType::TF_GETTER;
	}

	bool isMemberFunction()
	{
		return getParent() ? (getParent()->getScopeType() == Scope::T_CLASS ? true : false ) : false;
	}

	bool getEverUsedLikeVariable()
	{
		return m_ever_used_like_variable;
	}
	void setEverUsedLikeVariable(  bool b )
	{
		m_ever_used_like_variable = b;
	}

public:
	std::vector<SymbolPtr> m_types;

private:
	SymbolPtr	m_return_type_symbol;
	bool		m_is_constructor;
	tw::maple::generated::FunctionType::type m_function_type;
	bool		m_ever_used_like_variable;

public:
    std::vector<SymbolPtr> m_parameter_types;

};

typedef SHARED_PTR(Function) FunctionPtr;

}}}}//tw/maple/as/symbol

#endif

