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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_DEFINITION_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_DEFINITION_H__

#include <as/ast/function_definition.h>
#include <as/ast/function_signature.h>
#include <as/ast/function_rettype.h>
#include <as/ast/function_common.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct FunctionDefinition : public Interpreter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		std::string result;

		std::tr1::shared_ptr < AST::FunctionDefinition > fdef = std::tr1::static_pointer_cast<AST::FunctionDefinition>(node);
		std::tr1::shared_ptr < AST::FunctionCommon > fcommon= std::tr1::static_pointer_cast<AST::FunctionCommon>( fdef -> FunctionCommon());
		// Function Return Type
		std::tr1::shared_ptr < AST::FunctionSignature > fsig
				= std::tr1::static_pointer_cast<AST::FunctionSignature>( fcommon -> FunctionSignature());

        std::string str_func_name  = dispatchExpound(fdef->FunctionName(), ctx);
        std::string str_func_body  = dispatchExpound(fcommon->FunctionBody(), ctx);
        std::string str_func_type  = dispatchExpound(fsig->FunctionReturnType(), ctx);


		result += "\n" + ctx->indent();
		result += str_func_type;
		result += " ";

		result += str_func_name;
		result +=  "(";

		if (fsig->node_childs.size() > 1)
			result += dispatchExpound(fsig->FunctionParameter(), ctx); // parameters

		result +=  ")\n" + ctx->indent() + "{\n";

		result += str_func_body;

		result += "\n" + ctx->indent() + "}// (";
		result += str_func_name;

		result += ") function_end\n";

		return result;
	}
};

};


} } } } 

#endif 
