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

#ifndef __AS_AST_FUNCTION_NAME_H__
#define __AS_AST_FUNCTION_NAME_H__

#include <as/ast/abstract/statement.h>
#include "SyntaxTree_types.h"

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct FunctionName : public Statement
{
	FunctionName( std::string fname = "dummy "
			, tw::maple::generated::FunctionType::type func_type= tw::maple::generated::FunctionType::TF_NORMAL )
		: Statement(Node::NodeType::T_FUNCTION_NAME)
		, function_name( fname )
		, function_type( func_type )

	{
	}

    int stmtType() {
		return Node::NodeType::T_FUNCTION_NAME;
	}

    std::string toString()  {	return "node::function_name"; };

    std::string function_name;
    tw::maple::generated::FunctionType::type function_type;
};

typedef SHARED_PTR(FunctionName) FunctionNamePtr;


} } } }

#endif
