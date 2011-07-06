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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_IDENTIFIER_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_IDENTIFIER_H__

#include <as/ast/token/identifier.h>
#include <backend/cpp/interpret/interpreter.h>
#include <global.h>
#include <as/symbol/function.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct Identifier : public Interpreter
{
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx
			, tw::maple::as::symbol::ScopePtr class_symbol_table
			)
	{
		namespace ASY = tw::maple::as::symbol;
		SHARED_PTR(AST::Identifier) li = std::tr1::static_pointer_cast<AST::Identifier>(node);

		if(li->qualifier != "")
		{
			std::string left = replace( li->qualifier, ".", "::");

			return left+"::"+li->value;
		}
		else
		{
//			ASY::SymbolPtr symbol = symbol_table->findSymbol( result );
			
			ASY::SymbolPtr instance = symbol_table->findSymbol( li->value, true );
			if( instance == NULL && class_symbol_table != NULL )
				instance = class_symbol_table->findSymbol( li->value, true );
			ASY::FunctionPtr function_ptr = DYNA_CAST( ASY::Function, instance );

			if( function_ptr != NULL && function_ptr->isGetter() )
				return "get_" +  li->value + "()";
			else
				return li->value;
		}
	}

};


} } } } }

#endif 

