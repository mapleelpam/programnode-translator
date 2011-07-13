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

#ifndef __TW_MAPLE_AS_AST_CONDITION_EXPRESSION_H_
#define __TW_MAPLE_AS_AST_CONDITION_EXPRESSION_H_

#include <as/ast/abstract/expression.h>
#include <as/symbol/symbol.h>

namespace tw { namespace maple { namespace as { namespace ast {

struct ConditionExpression : public Expression
{
	ConditionExpression()
	 : Expression(Node::NodeType::T_CONDITION_EXPRESSION)
	{	}

    std::string toString()  {	return "node::condition_expression"; };



    NodePtr Condition(){	return node_childs[0];	}
    NodePtr ExpressionThen(){	return node_childs[1];	}
    NodePtr ExpressionElse(){	return node_childs[2];	}
};

typedef SHARED_PTR(ConditionExpression) ConditionExpressionPtr;


} } } }


#endif
