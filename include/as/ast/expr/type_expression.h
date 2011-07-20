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

#ifndef __TW_MAPLE_AS_AST_TYPE_REXPRESSION_H__
#define __TW_MAPLE_AS_AST_TYPE_REXPRESSION_H__

#include <as/ast/abstract/expression.h>
#include <global.h>
#include "SyntaxTree_types.h"


namespace tw { namespace maple { namespace as { namespace ast {

struct TypeExpression : public Expression
{
	TypeExpression( )
		: Expression(Node::NodeType::T_TYPE_EXPRESSION)
	{
	}
	std::string toString()  {	return "node::type_expression"; };

	 NodePtr child(){	return node_childs[0];	}

};

typedef SHARED_PTR(TypeExpression) TypeExpressionPtr;

} } } }

#endif