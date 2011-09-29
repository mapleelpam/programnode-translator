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

#ifndef __TW_MAPLE_AS_AST_INVOKE_H__
#define __TW_MAPLE_AS_AST_INVOKE_H__

#include <as/ast/abstract/expression.h>
#include <as/symbol/symbol.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Invoke : public Expression
{
	Invoke( const std::vector<std::string> c, std::string m, bool is_new = false )
	 : Expression(Node::NodeType::T_INVOKE)
 	 , callee(c)
	 , mode(m)
	{	}

    std::string toString()  {	return "node::invoke"; };

    const std::vector<std::string> callee;
    NodePtr getArgs(){	return (node_childs.size() > 0 )? node_childs[0] : NodePtr();	}

	virtual void bindType( tw::maple::as::symbol::SymbolPtr type)
	{
			m_type_symbol = type;
	}
	virtual tw::maple::as::symbol::SymbolPtr getInvokeeeType()
	{
		return m_type_symbol;
	}

	std::string mode;
private:

	tw::maple::as::symbol::SymbolPtr	m_type_symbol;
};

typedef SHARED_PTR(Invoke) InvokePtr;


} } } }


#endif
