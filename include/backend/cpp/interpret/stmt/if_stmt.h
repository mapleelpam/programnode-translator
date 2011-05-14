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
// Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_IF_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_IF_STMT_H__

#include <as/ast/stmt/if_stmt.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/template_printer.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct IfStatement : public Interpreter, public TemplatePrinter
{

	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx)
	{
		AST::IfStatementPtr IF = std::tr1::static_pointer_cast<AST::IfStatement>(node);
		std::list<PatternPtr> patterns;

		patterns.push_back( PatternPtr( new Pattern("if_condition", dispatchExpound(IF->ifCondition(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("then_stmt", dispatchExpound(IF->ifThen(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("else_stmt", dispatchExpound(IF->ifElse(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("endl", ctx->endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx->indent()) ));

		return substitutePatterns( patterns );
	}

	IfStatement()
		: TemplatePrinter("IfStatement")
	{
		setTemplateString( "#(indent_tab)if(#(if_condition)){#(endl)"
							"#(then_stmt)#(indent_tab)}else{#(endl)"
							"#(else_stmt)#(indent_tab)}#(endl)" );
	}

};

};


} } } } 

#endif 
