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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_IS_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_IS_H__

#include <as/ast/is.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/template_printer.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct Is : public Interpreter, public TemplatePrinter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		AST::IsPtr bin = STATIC_CAST( AST::Is, node);

		std::string instance_name = dispatchExpound(bin->LHS(), ctx);
		std::string type_name = dispatchExpound(bin->RHS(), ctx);

		std::list<PatternPtr> patterns;
		patterns.push_back( PatternPtr( new Pattern("instance_name", instance_name ) ));
		patterns.push_back( PatternPtr( new Pattern("type_name", type_name) ));

		return substitutePatterns( patterns );
	}
	Is()
		: TemplatePrinter("Is")
	{
//		setTemplateString( "(%instance_name%)->is(\"%type_name%\" )" );
		setTemplateString( "false/*not support instanceof*/" );
	}
private:

};

};


} } } } 

#endif 
