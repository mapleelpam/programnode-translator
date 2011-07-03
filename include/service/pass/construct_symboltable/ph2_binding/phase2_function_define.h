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


#ifndef __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_BINDING_FUNCTION_H__
#define __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_BINDING_FUNCTION_H__

#include <service/pass/construct_symboltable/pass.h>
#include <as/ast/func/function_definition.h>
#include <as/symbol/scope.h>

namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ { namespace ph2 {

struct Phase2_FunctionDefine
	: public Pass<tw::maple::as::ast::FunctionDefinitionPtr, tw::maple::service::pass::cs::constructor_stage::PH2_BINDING>
{

		static void pass(
				tw::maple::as::ast::FunctionDefinitionPtr 	ast_func
				, tw::maple::as::symbol::FunctionPtr 			func_symbol
				, tw::maple::as::symbol::ScopePtr			symboltable
				, Phase2ContextPtr context
				)
		{
			tw::maple::as::symbol::SymbolPtr p_type;

			tw::maple::as::ast::FunctionCommonPtr fcommon  = STATIC_CAST( tw::maple::as::ast::FunctionCommon, ast_func->FunctionCommon() );
			BOOST_ASSERT( fcommon != NULL );
			tw::maple::as::ast::FunctionSignaturePtr fsig  = STATIC_CAST( tw::maple::as::ast::FunctionSignature, fcommon->FunctionSignature() );

			p_type = context->find_symbol( fsig->ReturnType );

			if( p_type != NULL )
			{
				func_symbol->bindReturnType( p_type );
				return;
			}

			p_type = symboltable->findType( fsig->ReturnType );

			if( p_type == NULL )
			{
				std::cerr << "symboltable ph2: Function Defnition can't find symbol (function return type) '" << fsig->ReturnType << "'"<<std::endl;
				exit(1);
			}
			BOOST_ASSERT( p_type != NULL && "can't find symbol" );
			BOOST_ASSERT( p_type );
			func_symbol->bindReturnType( p_type );
		}
};

} } } } } }

#endif 
