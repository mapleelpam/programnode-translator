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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_BOOL_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_BOOL_H__

#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/token/literal_boolean.h>
#include <as/symbol/action/findable.h>
#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct LiteralBoolean : public Interpreter
{   

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		namespace AST = ::tw::maple::as::ast;
		using ::tw::maple::as::symbol::Findable;

		AST::LiteralBooleanPtr li = std::tr1::static_pointer_cast<AST::LiteralBoolean>(node);
		ReturnValue result;

		if( li->value == "true" )
			result = "true";
		else if( li->value == "false" )
			result = "false";

		result.token_symbol = Findable::findType( symbol_table, "Boolean" );

		return result;
	}

};


} } } } }

#endif 

