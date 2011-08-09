/* ******************************************************************\
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com       *
 *                                                                   *
 * Licensed under the Apache License, Version 2.0 (the "License");   *
 * you may not use this file except in compliance with the License.  *
 * You may obtain a copy of the License at                           *
 *                                                                   *
 *   http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                   *
 * Unless required by applicable law or agreed to in writing,        *
 * software distributed under the License is distributed on an       *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY            *
 * KIND, either express or implied. See the License for the          *
 * specific language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 * https://github.com/mapleelpam/programnode-translator              *
 *                                                                   *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple           *
 \*******************************************************************/


#ifndef __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH3_BINDING_IDENTIFIER_H__
#define __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH3_BINDING_IDENTIFIER_H__

#include <as/ast/token/identifier.h>
#include <as/symbol/scope.h>
#include <as/symbol/action/findable.h>
#include <service/pass/construct_symboltable/pass.h>


namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ { namespace ph3 {


struct Phase3_Identifier
	: public Pass<tw::maple::as::ast::Identifier, tw::maple::service::pass::cs::constructor_stage::PH3_BINDING>
{

	static void pass(
			tw::maple::as::ast::IdentifierPtr ast_identifier
	//		, tw::maple::as::symbol::SymbolPtr var_symbol
			, tw::maple::as::symbol::ScopePtr symboltable
			, Phase2ContextPtr context
			)
	{
		using tw::maple::as::symbol::Findable;
		namespace ASY = tw::maple::as::symbol;

		ASY::FunctionPtr func_symbol = Findable::findFunction( symboltable, ast_identifier->value );		
		if( func_symbol )
			func_symbol -> setEverUsedLikeVariable( true );
	}
};

} } } } } }

#endif 
