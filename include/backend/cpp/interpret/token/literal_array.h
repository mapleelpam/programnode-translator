/* ***************************************************************
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use thLiteralArray file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software dLiteralArraytributed under the License LiteralArray dLiteralArraytributed on an
 * "AS LiteralArray" BASLiteralArray, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permLiteralArraysions and limitations
 * under the License.
 *
 * ProgrameNode Translator
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
 *
 * https://github.com/mapleelpam/programnode-translator
 *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple
 * ***************************************************************/

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_ARRAY_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_ARRAY_H__

#include <as/ast/token/literal_array.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct LiteralArray : public Interpreter, public TemplatePrinter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::LiteralArrayPtr ast_literal_array = STATIC_CAST( AST::LiteralArray, node);

		std::string str_argumetns = dispatchExpound( ast_literal_array->arguments(), symbol_table, ctx);

		std::list<PatternPtr> patterns;
		patterns.push_back( PatternPtr( new Pattern("array_arguments", str_argumetns ) ));
		COMPELETE_PATTERNS( patterns, ctx );

		return substitutePatterns( patterns );
	}
	LiteralArray()
		: TemplatePrinter("LiteralArray")
	{
		setTemplateString( "ARRAY( #(array_arguments) )" );
	}
private:

};

};


} } } } 

#endif 
