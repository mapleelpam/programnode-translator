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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_TRY_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_TRY_STMT_H__

#include <as/ast/stmt/try_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct TryStatement : public Interpreter, public TemplatePrinter
{

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::TryStatementPtr TRY = std::tr1::static_pointer_cast<AST::TryStatement>(node);
		std::list<PatternPtr> patterns;

		ctx.tree_depth ++;
		std::string str_try_block = dispatchExpound(TRY->tryBlock(), symbol_table, ctx);
		ctx.tree_depth --;
		std::string str_catch_block = dispatchExpound(TRY->catchList(), symbol_table, ctx);
		std::string str_finally_block = dispatchExpound(TRY->finallyBlock(), symbol_table, ctx);

		patterns.push_back( PatternPtr( new Pattern("try_block", str_try_block ) ));
		patterns.push_back( PatternPtr( new Pattern("catch_list", str_catch_block )));
		patterns.push_back( PatternPtr( new Pattern("finally_block", str_finally_block ) ));

		COMPELETE_PATTERNS( patterns, ctx );

		return substitutePatterns( patterns );
	}

	TryStatement()
		: TemplatePrinter("TryStatement")
	{
		setTemplateString( 	"#(indent_tab)try{#(endl)"
							"#(try_block)"
							"#(indent_tab)}#(endl)"
							"#(catch_list)"
							"#(finally_block)"
		);
	}

};

};


} } } } 

#endif 
