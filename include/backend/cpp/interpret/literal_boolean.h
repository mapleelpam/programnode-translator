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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_BOOL_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_BOOL_H__

#include <as/ast/expression.h>
#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/literal_boolean.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

// Abstract
struct LiteralBoolean : public Interpreter
{   
	void interpret( ::tw::maple::as::ast::NodePtr node, ::tw::maple::backend::cpp::Context* ctx )
	{
		std::tr1::shared_ptr<AST::LiteralBoolean> li = std::tr1::static_pointer_cast<AST::LiteralBoolean>(node);

		if( li->value == "true" )
			ctx->ofs_stream << "true";
		else if( li->value == "false" )
			ctx->ofs_stream << "false";
		else {
			std::cerr << " can't resolve literal boolean "<<li->value<<std::endl;
			exit(1);
		}
	}

};


} } } } }

#endif 

