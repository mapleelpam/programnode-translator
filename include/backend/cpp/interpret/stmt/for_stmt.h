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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FOR_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FOR_STMT_H__

#include <as/ast/stmt/for_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ForStatement : public Interpreter, public TemplatePrinter
{

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::ForStatementPtr FOR = std::tr1::static_pointer_cast<AST::ForStatement>(node);
		std::list<PatternPtr> patterns;

		ctx.tree_depth ++;
		std::string str_for_body = dispatchExpound(FOR->ForBody(), symbol_table, ctx);
		ctx.tree_depth --;

		patterns.push_back( PatternPtr( new Pattern("for_condition", dispatchExpound(FOR->ForCondition(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("for_init", dispatchExpound(FOR->ForInit(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("for_step", dispatchExpound(FOR->ForStep(), symbol_table, ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("for_body",  str_for_body ) ));
		patterns.push_back( PatternPtr( new Pattern("endl", ctx.endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx.indent()) ));

		return substitutePatterns( patterns );
	}

	ForStatement()
		: TemplatePrinter("ForStatement")
	{
		setTemplateString( "#(indent_tab)for( "
				"#(for_init) ; #(for_condition) ; #(for_step) )"
				"#(endl)#(indent_tab){#(endl)"
				"#(for_body)"
				"#(indent_tab)}#(endl)" );
	}

};

};


} } } } 

#endif 
