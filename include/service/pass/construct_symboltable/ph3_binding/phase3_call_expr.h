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


#ifndef __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_CALL_EXPR_H__
#define __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_CALL_EXPR_H__

#include <service/pass/construct_symboltable/pass.h>
#include <service/pass/construct_symboltable/context.h>
#include <as/ast/expr/call.h>
#include <as/symbol/scope.h>
#include <as/symbol/action/findable.h>


namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ { namespace ph3 {

struct Phase3_CallExpression
	: public Pass<tw::maple::as::ast::CallPtr, tw::maple::service::pass::cs::constructor_stage::PH3_BINDING>
{

		static void pass(
				tw::maple::as::ast::CallPtr CALL
				, tw::maple::as::symbol::ScopePtr symboltable
				, Phase2ContextPtr context
				)
		{
			using tw::maple::as::symbol::Findable;
			namespace ASY = tw::maple::as::symbol;

			if( symboltable == NULL )
			{
				std::cerr << "error in phase2 "<< CALL->toString() <<std::endl;
				exit(1);
			}

			ASY::SymbolPtr p_type = context->find_symbol( CALL->callee[CALL->callee.size()-1] );

			if(p_type != NULL ) // found the symbol in import list
			{
				CALL->bindType( p_type );
				return;
			}
			tw::maple::as::symbol::ScopePtr symbol_pkg = symboltable;

			std::cerr << " find " << CALL->callee[0] << "symboltable = "<<symboltable->getFQN() << std::endl;

			for( int idx = 0 ; idx < CALL->callee.size() - 1 ; idx ++ )
			{
				tw::maple::as::symbol::SymbolPtr temp_pkg = symbol_pkg->findSymbol( CALL->callee[idx] );
				if( temp_pkg && temp_pkg ->getSymbolProperties() == tw::maple::as::symbol::Symbol::T_SCOPE )
				{
					std::cerr << " find " << CALL->callee[idx] << std::endl;
					symbol_pkg = STATIC_CAST( tw::maple::as::symbol::Scope , temp_pkg );
				} else {
					std::cerr<<" can't find scope - "<< CALL->callee[CALL->callee.size()-1] << " '"<< CALL->toString() << "'"<<std::endl;
				}
			}
			if( CALL->isObjectConsturct()){
				p_type = Findable::findClassType_downward(symbol_pkg.get(), CALL->callee[CALL->callee.size()- 1]);
//				if( p_type == NULL)
//				{
//					std::vector<ASY::SymbolPtr> cans = Findable::findRHS_Candidates(symbol_pkg.get(), CALL->callee[CALL->callee.size()- 1]);
//					p_type = *(cans.begin());
//				}

				if( p_type == NULL)
				{
					std::vector<ASY::SymbolPtr> rhs = Findable::findRHS_Candidates( symbol_pkg.get(), CALL->callee[CALL->callee.size()- 1] );
					if( rhs.size() == 0 )
					{
						std::cerr <<" can't resolve constructor "<< CALL->callee[CALL->callee.size()- 1] << std::endl;
						//TBF
//						exit(1);

					}
				}
			}
			else
			{
				p_type = Findable::findFunction_downward(symbol_pkg.get(), CALL->callee[CALL->callee.size()- 1]);
			}

			if( p_type ) {
				std::cerr<<" callee bind type "<< p_type->getFQN() <<std::endl;
				CALL->bindType( p_type );
			} else {
				/* BUG fix this, a.b() can't find  */
				std::cerr<<" callee name '"<<"" <<"': can't find type - '"<< CALL->toString() <<"'"<<"  '"<<CALL->callee[CALL->callee.size()-1]<<"'"<<std::endl;
//				if( CALL->callee[CALL->callee.size()-1] != "printf")
//					exit(1);
			}
		}
};

} } } } } }

#endif 
