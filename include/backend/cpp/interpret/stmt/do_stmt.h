/* ***************************************************************
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 * ProgrameNode Translator
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
 *
 * https://github.com/mapleelpam/programnode-translator
 *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple
 * ***************************************************************/

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_DO_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_DO_STMT_H__

#include <as/ast/stmt/do_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct DoStatement : public Interpreter, public TemplatePrinter
{

	virtual Value expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx
			, tw::maple::as::symbol::Scope* class_symbol_table
			)
	{
		AST::DoStatementPtr DO = std::tr1::static_pointer_cast<AST::DoStatement>(node);
		std::list<PatternPtr> patterns;

		patterns.push_back( PatternPtr( new Pattern("condition", dispatchExpound(DO->DoCondition(), symbol_table, ctx, class_symbol_table).result ) ));
		patterns.push_back( PatternPtr( new Pattern("body", dispatchExpound(DO->DoBody(), symbol_table, ctx, class_symbol_table).result ) ));
		patterns.push_back( PatternPtr( new Pattern("endl", ctx->endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx->indent()) ));

		return substitutePatterns( patterns );
	}

	DoStatement()
		: TemplatePrinter("DoStatement")
	{
		setTemplateString( "#(indent_tab)do{#(endl)"
				"#(body)"
				"#(indent_tab)}while(#(condition));#(endl)" );
	}

};

};


} } } } 

#endif 
