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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_ASSIGNMENT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_ASSIGNMENT_H__

#include <as/ast/assignment.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;


struct Assignment : public Interpreter
{   
	void interpret( AST::NodePtr node, tw::maple::backend::cpp::Context* ctx )
	{
		DEBUG_INTERPRET_ENTRY;


		AST::AssignmentPtr assignment = std::tr1::static_pointer_cast<
				AST::Assignment>(node);

//		ctx->ofs_stream << " " << var->varType() << " "<< var->varName() << " ";
		dispatchDo(assignment->LHS(), ctx); //
		ctx->ofs_stream << " = " ;
		dispatchDo(assignment->RHS(), ctx); //

		DEBUG_INTERPRET_LEAVE;
	}
};


} } } } }

#endif 