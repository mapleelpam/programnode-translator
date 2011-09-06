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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CATCH_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CATCH_STMT_H__

#include <as/ast/stmt/catch_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct CatchStatement : public Interpreter, public TemplatePrinter
{

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::CatchStatementPtr CATCH = std::tr1::static_pointer_cast<AST::CatchStatement>(node);
		std::list<PatternPtr> patterns;

		std::string str_parameter = dispatchExpound(CATCH->parameter(), symbol_table, ctx);
		ctx.tree_depth ++;
		std::string str_statement = dispatchExpound(CATCH->statement(), symbol_table, ctx);
		ctx.tree_depth --;

		if( str_parameter == "" )
			return "";

		patterns.push_back( PatternPtr( new Pattern("parameter", str_parameter ) ));
		patterns.push_back( PatternPtr( new Pattern("statement", str_statement ) ));

		COMPELET_PATTERNS( patterns, ctx );

		return substitutePatterns( patterns );
	}

	CatchStatement()
		: TemplatePrinter("CatchStatement")
	{
		setTemplateString( 	"#(indent_tab)catch(#(parameter)){#(endl)"
							"#(statement)"
							"#(indent_tab)}#(endl)"
		);
	}

};

};


} } } } 

#endif 
