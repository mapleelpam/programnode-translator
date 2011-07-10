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


#ifndef __TW_MAPLE_AS_AST_INCREMENT_OPERATOR_H__
#define __TW_MAPLE_AS_AST_INCREMENT_OPERATOR_H__

#include <as/ast/abstract/expression.h>
#include "AstDumper.h"

namespace tw { namespace maple { namespace as { namespace ast {

struct IncrementOperator: public Expression
{
	IncrementOperator(
			const tw::maple::generated::IncrementType::type type
			, std::string ot ) :
		Expression(Node::NodeType::T_INCREMENT)
		, op_type(ot)
		, m_type(type)
	{
	}

    NodePtr child(){	return node_childs[0];	}

    std::string toString()  {	return "node::binary_operator"; };
    bool check(){	return node_childs.size() == 2;	};


    std::string op_type;
    tw::maple::generated::IncrementType::type m_type;
};

typedef std::tr1::shared_ptr<IncrementOperator> IncrementOperatorPtr;


} } } }

#endif
