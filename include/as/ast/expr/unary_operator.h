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

#ifndef __TW_MAPLE_AS_AST_UNARY_OPERATOR_H__
#define __TW_MAPLE_AS_AST_UNARY_OPERATOR_H__

#include <tr1/memory>
#include <as/ast/abstract/expression.h>

namespace tw { namespace maple { namespace as { namespace ast {

struct UnaryOperator: public Expression
{
	UnaryOperator( std::string ot ) :
		Expression(Node::NodeType::T_UNARY_OPERATOR)
		, op_type(ot)
	{
	}

    int exprType()   {   return Node::NodeType::T_UNARY_OPERATOR;  }

    NodePtr subExpr(){	return node_childs[0];	}

    std::string toString()  {	return "node::unary_operator"; };
    bool check(){	return node_childs.size() == 1;	};


    std::string op_type;
};

typedef std::tr1::shared_ptr<UnaryOperator>    UnaryOperatorPtr;


} } } }

#endif
