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

#ifndef __BACKEDN_CPP_INTERPRET_STMT_FUNCTION_RETTYPE_H__
#define __BACKEDN_CPP_INTERPRET_STMT_FUNCTION_RETTYPE_H__

#include <as/ast/function_signature.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct FunctionSignature : public Interpreter
{
	static void interpret( AST::Node* exp, tw::maple::backend::cpp::Context* ctx )
	{
//		AST::FunctionDefinition* fdef = dynamic_cast<AST::FunctionDefinition*>( &(*exp) );
//		AST::NodePtr fname = fdef->FunctionName();
//		AST::NodePtr fbody = fdef->FunctionBody();
//		dispatchDo(fname, ctx);
//		ctx->ofs_stream << "() "<<std::endl << "{" << std::endl;
//			dispatchDo(fbody, ctx);
//
//		ctx->ofs_stream << std::endl << "}" << std::endl;


	}
};

};


} } } } 

#endif 
