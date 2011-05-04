/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// ProgrameNode Translator
// Copyright 2011 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple


#ifndef __AS_AST_FUNCTION_SIGNATURE_H__
#define __AS_AST_FUNCTION_SIGNATURE_H__

#include <tr1/memory>
#include <as/ast/statement.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct FunctionSignature : public Statement
{
	FunctionSignature( const std::string& return_type)
		: Statement(Node::NodeType::T_FUNCTION_SIGNATURE)
		, ReturnType( return_type )
	{
	}


//    NodePtr FunctionReturnType(){	return node_childs[0];	}
    NodePtr FunctionParameter(){
    	return node_childs.size() ? node_childs[0] : NodePtr();
    }

    std::string toString()  {	return "node::function_signature - "+ReturnType; };

    bool check()	{	return node_childs.size() == 1; 	}

    const std::string ReturnType;
};

typedef SHARED_PTR(FunctionSignature) FunctionSignaturePtr;

} } } }

#endif
