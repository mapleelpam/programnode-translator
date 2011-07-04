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


#ifndef __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_BINDING_IMPORT_H__
#define __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_BINDING_IMPORT_H__

#include <service/pass/construct_symboltable/pass.h>
#include <service/pass/construct_symboltable/context.h>
#include <as/ast/variable_declare.h>
#include <as/symbol/scope.h>

namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ { namespace ph2 {

struct Phase2_ImportStatement
	: public Pass<tw::maple::as::ast::ImportStatementPtr, tw::maple::service::pass::cs::constructor_stage::PH2_BINDING>
{

		static void pass(
				tw::maple::as::ast::ImportStatementPtr ast_import
				, tw::maple::as::symbol::ScopePtr symboltable
				, Phase2ContextPtr context
				)
		{
			{
				tw::maple::as::symbol::ScopePtr pkg_scope = symboltable;

				if( ast_import->package_names[0] == "__AS3__")
					return;

				for( int idx = 0 ; idx < ast_import->package_names.size() - 1 ; idx ++ )
				{
					tw::maple::as::symbol::SymbolPtr temp_pkg = pkg_scope->findSymbol( ast_import->package_names[idx] );
					if( temp_pkg && temp_pkg ->getSymbolProperties() == tw::maple::as::symbol::Symbol::T_SCOPE )
					{
						pkg_scope = STATIC_CAST( tw::maple::as::symbol::Scope , temp_pkg );
					} else {
						std::cerr<<" can't find scope - "<< ast_import->package_names[idx] << " '"<< ast_import->toString() << "'"<<std::endl;
						exit(1);
					}
				}
				tw::maple::as::symbol::SymbolPtr p_type = pkg_scope->findType( ast_import->package_names[ast_import->package_names.size() - 1]  );
				if( p_type == NULL )
				{
					std::cerr << "import can't find type - '"<< ast_import->package_names[ast_import->package_names.size() - 1] <<"'"<<std::endl;
//					exit(1);

				}
				else
				{
					tw::maple::as::symbol::ScopePtr p_class_scope  = STATIC_CAST( tw::maple::as::symbol::Scope, p_type  );
					if( p_class_scope == NULL )
						std::cerr << "import can't find type - '"<< ast_import->package_names[ast_import->package_names.size() - 1] <<"'"<<std::endl;

					std::cerr << "symboltable ph2 try to import " << p_class_scope->getFQN() <<std::endl;
					context -> add_import( p_class_scope );
				}
			}
		}
};

} } } } } }

#endif 
