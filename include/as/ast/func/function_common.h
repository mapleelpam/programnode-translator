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

#ifndef __AS_AST_FUNCTION_COMMON_H__
#define __AS_AST_FUNCTION_COMMON_H__

#include <as/ast/abstract/statement.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct FunctionCommon: public Statement
{
	FunctionCommon() :
		Statement(Node::NodeType::T_FUNCTION_COMMON) {
	}

    int stmtType()   {   return Node::NodeType::T_FUNCTION_COMMON;  }

    NodePtr FunctionSignature(){
//    	std::cout << "   <<<<<<<<<<<,, function common child size   " << node_childs.size()<<std::endl;
    	return node_childs[0];
    }
    NodePtr FunctionBody(){	return node_childs[1];	}

    std::string toString()  {	return "node::function_common"; };
    bool check(){	return node_childs.size() == 2;	};
};

typedef SHARED_PTR(FunctionCommon) FunctionCommonPtr;


} } } }

#endif
