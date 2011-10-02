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
#include <as/symbol/action/findable.h>

namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ { namespace ph3 {

struct Phase3_FunctionDefine
	: public Pass<tw::maple::as::ast::FunctionDefinitionPtr, tw::maple::service::pass::cs::constructor_stage::PH3_BINDING>
{

		static void pass(
				tw::maple::as::ast::FunctionDefinitionPtr 	ast_func
				, tw::maple::as::symbol::FunctionPtr 		func_symbol
				, tw::maple::as::symbol::ScopePtr			symboltable
				, Phase2ContextPtr context
				)
		{
			namespace ASY = tw::maple::as::symbol;
			using tw::maple::as::symbol::Findable;
			ASY::SymbolPtr p_type;

			tw::maple::as::ast::FunctionCommonPtr fcommon  = STATIC_CAST( tw::maple::as::ast::FunctionCommon, ast_func->FunctionCommon() );
			BOOST_ASSERT( fcommon != NULL );
			tw::maple::as::ast::FunctionSignaturePtr fsig  = STATIC_CAST( tw::maple::as::ast::FunctionSignature, fcommon->FunctionSignature() );

			p_type = context->find_symbol( fsig->ReturnType );

			if( p_type != NULL )
			{
				func_symbol->bindReturnType( p_type );
				return;
			}
//			p_type = symboltable->findType( fsig->ReturnType );

//			p_type = tw::maple::as::symbol::Findable::findClassType_downward(symboltable.get(), fsig->ReturnType );
			p_type = tw::maple::as::symbol::Findable::findType(symboltable.get(), fsig->ReturnType );


			if( p_type == NULL && ! func_symbol->isConstructor())
			{
				std::cerr << "symboltable ph3: Function Defnition can't find symbol (function return type) '" << fsig->ReturnType << "'" << " " << func_symbol->name()<<std::endl;
				exit(1);
			}
//			BOOST_ASSERT( p_type != NULL && "can't find symbol" );
//			BOOST_ASSERT( p_type );
			func_symbol->bindReturnType( p_type );

			// process meta data
			{ // add parameter in prefix annotation
				std::string pname, ptype;
				bool found;
				ast_func->getPrefixParameterName( pname, ptype, found);
				if( found )
				{
					ASY::SymbolPtr sym_param = func_symbol->registerFunctionParameter( pname, false );

					tw::maple::as::symbol::ScopePtr var_type_scope = symboltable;
					std::vector<std::string> type_tokens = tokenize( ptype, ".", false);
					for( int idx = 0 ; idx < type_tokens.size() - 1 ; idx ++ )
					{
						tw::maple::as::symbol::SymbolPtr temp_pkg = var_type_scope->findSymbol( type_tokens[idx] );
						if( temp_pkg && temp_pkg ->getSymbolProperties() == tw::maple::as::symbol::Symbol::T_SCOPE )
						{
							var_type_scope = STATIC_CAST( tw::maple::as::symbol::Scope , temp_pkg );
						} else {
							std::cerr <<" can't find scope - "<< type_tokens[idx] << " '"<< sym_param->toString() << "'"<<std::endl;
						}
					}
		//			p_type = var_type_scope->findType( ast_var->VariableType[ast_var->VariableType.size() - 1]  );

					ASY::SymbolPtr type_param =
							Findable::findClassType_downward(var_type_scope.get(), type_tokens[type_tokens.size()- 1]);
					sym_param ->bindType( type_param );
				}
			}
		}
};

} } } } } }

#endif 
