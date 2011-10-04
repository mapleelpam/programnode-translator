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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_THROW_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_THROW_STMT_H__

#include <as/ast/stmt/throw_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ThrowStatement : public Interpreter, public TemplatePrinter
{

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::ThrowStatementPtr THROW = std::tr1::static_pointer_cast<AST::ThrowStatement>(node);
		std::list<PatternPtr> patterns;

		std::string str_expression = dispatchExpound(THROW->expr(), symbol_table, ctx);

		patterns.push_back( PatternPtr( new Pattern("expression", str_expression ) ));
		COMPELETE_PATTERNS( patterns, ctx );

		return substitutePatterns( patterns );
	}

	ThrowStatement()
		: TemplatePrinter("ThrowStatement")
	{
		setTemplateString( 	"#(indent_tab)throw #(expression);#(endl)" );
	}

};

};


} } } } 

#endif 
