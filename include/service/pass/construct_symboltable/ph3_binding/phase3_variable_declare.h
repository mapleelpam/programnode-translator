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


#ifndef __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH3_BINDING_VARIABLE_H__
#define __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH3_BINDING_VARIABLE_H__

#include <service/pass/construct_symboltable/pass.h>
#include <as/ast/variable_declare.h>
#include <as/symbol/scope.h>
#include <as/symbol/action/findable.h>

namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ { namespace ph3 {

struct Phase3_VariableDeclare
	: public Pass<tw::maple::as::ast::VariableDeclarePtr, tw::maple::service::pass::cs::constructor_stage::PH2_BINDING>
{

		static void pass(
				tw::maple::as::ast::VariableDeclarePtr ast_var
				, tw::maple::as::symbol::SymbolPtr var_symbol
				, tw::maple::as::symbol::ScopePtr symboltable
				, Phase2ContextPtr context
				)
		{

			using tw::maple::as::symbol::Findable;
//            if( 0 )
//			{
//				std::cerr << " variable name = "<<var->VariableName<<std::endl;
//				std::cerr << " variable type size = "<<var->VariableType.size()<<std::endl;
//			}


			if( symboltable == NULL )
			{
				std::cerr << "error in phase3 "<< ast_var->toString() <<std::endl;
				exit(1);
			}

			std::string variable_str = ast_var->VariableType[ast_var->VariableType.size() - 1];
			tw::maple::as::symbol::SymbolPtr p_type = context->find_symbol( variable_str );

			if(p_type != NULL ) // found the symbol in import list
			{
				var_symbol->bindType( p_type );
				return;
			}
			tw::maple::as::symbol::ScopePtr var_type_scope = symboltable;

			for( int idx = 0 ; idx < ast_var->VariableType.size() - 1 ; idx ++ )
			{
				tw::maple::as::symbol::SymbolPtr temp_pkg = var_type_scope->findSymbol( ast_var->VariableType[idx] );
				if( temp_pkg && temp_pkg ->getSymbolProperties() == tw::maple::as::symbol::Symbol::T_SCOPE )
				{
					var_type_scope = STATIC_CAST( tw::maple::as::symbol::Scope , temp_pkg );
				} else {
//					std::cerr<<var->VariableName <<" can't find scope - "<< var->VariableType[idx] << " '"<< var->toString() << "'"<<std::endl;
				}
			}
			p_type = var_type_scope->findType( ast_var->VariableType[ast_var->VariableType.size() - 1]  );

//			if( p_type == NULL )
//			{
//				p_type = context->find_symbol( ast_var->VariableType[ast_var->VariableType.size() - 1] );
//			}
			if( p_type == NULL )
			{
				p_type = Findable::findClassType( symboltable, ast_var->VariableType[ast_var->VariableType.size() - 1]);
			}

			if( p_type ) {
				var_symbol->bindType( p_type );
			} else {
				std::cerr<<" variable name '"<<ast_var->VariableName <<"': can't find type - '"<< ast_var->toString() <<"'"<<"  '"<<ast_var->VariableType[ast_var->VariableType.size() - 1]<<"'"<<std::endl;
				exit(1);
			}
		}
};

} } } } } }

#endif 
