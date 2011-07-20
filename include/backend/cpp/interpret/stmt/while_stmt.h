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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_WHILE_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_WHILE_STMT_H__

#include <as/ast/stmt/while_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct WhileStatement : public Interpreter, public TemplatePrinter
{

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::WhileStatementPtr WHILE = std::tr1::static_pointer_cast<AST::WhileStatement>(node);
		std::list<PatternPtr> patterns;

		patterns.push_back( PatternPtr( new Pattern("condition", dispatchExpound(WHILE->WhileCondition(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("body", dispatchExpound(WHILE->WhileBody(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("endl", ctx.endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx.indent()) ));

		return substitutePatterns( patterns );
	}

	WhileStatement()
		: TemplatePrinter("WhileStatement")
	{
		setTemplateString( "#(indent_tab)while(#(condition)){#(endl)"
				"#(body)"
				"#(indent_tab)};#(endl)" );
	}

};

};


} } } } 

#endif 
