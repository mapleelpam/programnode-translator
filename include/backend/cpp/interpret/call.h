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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_CALL_H
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_CALL_H

#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/expression.h>
#include <as/ast/call.h>

namespace AST = ::tw::maple::as::ast;

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

// Abstract
struct Call : public Interpreter
{   
	virtual void interpret( ::tw::maple::as::ast::NodePtr node,	::tw::maple::backend::cpp::Context* ctx)
	{
		DEBUG_INTERPRET_ENTRY;

		std::tr1::shared_ptr<AST::Call> call = std::tr1::static_pointer_cast<AST::Call>(node);

		std::tr1::shared_ptr<AST::Node> callee  = call->getCallee();
		std::tr1::shared_ptr<AST::Node> args = call->getArgs();

		dispatchDo(callee, ctx);
		ctx->ofs_stream << "( ";
			dispatchDo(args, ctx);
		ctx->ofs_stream << " )";

		DEBUG_INTERPRET_LEAVE;
	}
};


} } } } }

#endif 
