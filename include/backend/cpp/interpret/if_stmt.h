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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_IF_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_IF_STMT_H__

#include <as/ast/if_stmt.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct IfStatement : public Interpreter
{   

	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		std::string result = "";

		AST::IfStatementPtr IF = std::tr1::static_pointer_cast<AST::IfStatement>(node);

		result += ctx->indent() + "if( ";
		result += dispatchExpound(IF->ifCondition(), ctx);
		result += "){\n";
		result += dispatchExpound(IF->ifThen(), ctx);

		result += ctx->indent()+"}";
		if( IF->ifElse() ) {
			result += ctx->indent() + " else\n" + ctx->indent()+ "{ \n";
			result += dispatchExpound(IF->ifElse(), ctx);
			result +=  ctx->indent() + "}";
		}

		return result;
	}
};

};


} } } } 

#endif 
