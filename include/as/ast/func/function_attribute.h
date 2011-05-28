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

#ifndef __AS_AST_FUNCTION_ATTR_H__
#define __AS_AST_FUNCTION_ATTR_H__

#include <as/ast/abstract/statement.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct FunctionAttribute : public Statement
{
	FunctionAttribute( std::vector<std::string> values )
		: Statement(Node::NodeType::T_COMP_FUNCTION_ATTRIBUTE)
		, attrs( values )
	{

	}
    int stmtType() {
		return Node::NodeType::T_FUNCTION_NAME;
	}

    std::string toString()  {	return "node::function_attribute"; };

    std::vector<std::string>	attrs;
};

typedef SHARED_PTR(FunctionAttribute) FunctionAttributePtr;


} } } }

#endif
