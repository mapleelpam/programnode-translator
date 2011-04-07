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
// Copyright 2010 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __BACKEDN_CPP_INTERPRET_CALL_H
#define __BACKEDN_CPP_INTERPRET_CALL_H

#include <as/ast/expression.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

// Abstract
struct Call : public Interpreter
{   
	static void interpret( AST::Expression* exp, tw::maple::backend::cpp::Context* ctx )
	{
		std::cout << exp->node_childs.size() <<std::endl;
		std::tr1::shared_ptr<AST::Node> callee;
		std::tr1::shared_ptr<AST::Node> args;

		callee = exp->node_childs[ 0 ];
		args = exp->node_childs[ 1 ];


		dispatchDo(callee, ctx);
		ctx->ofs_stream << " ( ";
			dispatchDo(args, ctx);
		ctx->ofs_stream << " ) ";
//		for (std::vector<std::tr1::shared_ptr<AST::Node> >::iterator nItr =
//				exp->node_childs.begin(); nItr != exp->node_childs.end(); nItr++)
//		{
//			dispatchDo(*nItr, ctx);
//		}

	}
};


} } } } }

#endif 
