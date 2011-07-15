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

#include <global.h>

#include <as/ast/token/identifier.h>
#include <backend/cpp/interpret/interpreter.h>
#include <as/symbol/function.h>
#include <as/symbol/variable.h>
#include <as/symbol/action/findable.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

#define DEBUG {std::cerr<<__FILE__<<":"<<__LINE__<<std::endl;}

struct Identifier : public Interpreter
{
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx
			, tw::maple::as::symbol::Scope* class_symbol_table
			)
	{
		namespace ASY = tw::maple::as::symbol;
		SHARED_PTR(AST::Identifier) li = std::tr1::static_pointer_cast<AST::Identifier>(node);

		if(li->qualifier != "")
		{
			tw::maple::as::symbol::ScopePtr pkg_scope = symbol_table;

			std::string left = replace( li->qualifier, ".", "::");

			// only here we need to find package !!!
			std::vector<std::string> tokens = tokenize( li->qualifier, ".", false);
			for( std::vector<std::string>::iterator I = tokens.begin(), E = tokens.end()
					; I != E ; I ++ )
			{
				tw::maple::as::symbol::SymbolPtr temp_pkg = pkg_scope->findSymbol(
						*I);
				if (temp_pkg && temp_pkg ->getSymbolProperties()
						== tw::maple::as::symbol::Symbol::T_SCOPE) {
					pkg_scope
							= STATIC_CAST( tw::maple::as::symbol::Scope , temp_pkg );
				} else {
					std::cerr << " can't find scope - "
							<< *I << " '"
							<< node->toString() << "'" << std::endl;
					exit(1);
				}
			}
			ASY::SymbolPtr symbol_ptr = pkg_scope->findSymbol( li->value );
			if( symbol_ptr )
			{
				ctx-> token_class_type = symbol_ptr;
				return left+"::"+li->value + _DS("/* find symbol */");
			}
			else
				return left+"::"+li->value + _DS("/* can't find symbol */");
		}
		else
		{
			{ // just class...!!
				if( ASY::ScopePtr classtype_ptr = ASY::Findable::findClassType(symbol_table.get(),li->value))
				{
					ctx-> token_class_type = classtype_ptr;
					return classtype_ptr->name();
				}
			}



			bool should_use_fqn = false;
			std::cerr << __FILE__<<":"<<__LINE__<<" li->value " << li->value <<std::endl;
			std::vector<ASY::SymbolPtr> candidates = symbol_table->findSymbol_down2( li->value );
			std::cerr << __FILE__<<":"<<__LINE__<<" li->value " << li->value << " size "<<candidates.size()<<std::endl;
			if( candidates.size() == 0  )
			{
				ASY::SymbolPtr s = ctx->scope_ctx.find_symbol( li->value );
				if( s ){
					candidates.push_back( s );
					should_use_fqn = true;
				}
			}
			if( candidates.size() == 0 && class_symbol_table != NULL )
			{
				std::cerr << " li->value " << li->value<<std::endl;
				candidates = class_symbol_table->findSymbol_down2( li->value );
			}

			DEBUG
			if( candidates.size() > 0 )
			{
				if( ctx->inter_type==Context::RHS )
				{
					DEBUG
					for( int idx = 0, E = candidates.size() ; idx < E ; idx ++ )
					{
						DEBUG
						std::cerr << " name "<< candidates[idx]->name() <<":"<<candidates[idx]->toString()<< std::endl;
						ASY::SymbolPtr instance_symbol = candidates[idx];
						ASY::FunctionPtr function_ptr = DYNA_CAST( ASY::Function, instance_symbol );
						if( function_ptr )
						{
							std::cerr << " type " << function_ptr->getFunctionType()<<std::endl;
						}
						std::cerr<<instance_symbol->getFQN() << " 123 "<<instance_symbol->getSymbolProperties()<<std::endl;
						if( function_ptr && function_ptr->isGetter() )
						{
							DEBUG
							ctx-> token_class_type = function_ptr->ReturnType();
							return "get_" +  li->value + "()";
						}
						if( ASY::VariablePtr var_ptr = DYNA_CAST( ASY::Variable, instance_symbol ) )
						{
							ctx-> token_class_type = var_ptr->getTypeSymbol();
							return li->value;
						}
					}
					if( should_use_fqn )
					{
						for( int idx = 0, E = candidates.size() ; idx < E ; idx ++ )
						{
							ASY::SymbolPtr instance_symbol = candidates[idx];
							ctx-> token_class_type = instance_symbol;
							return instance_symbol->getFQN();
						}
					}
				}
				else if( ctx->inter_type==Context::LHS )
				{
					for( int idx = 0, E = candidates.size() ; idx < E ; idx ++ )
					{
						ASY::SymbolPtr instance_symbol = candidates[idx];
						ASY::FunctionPtr function_ptr = DYNA_CAST( ASY::Function, instance_symbol );
						if( function_ptr != NULL && function_ptr->isSetter() )
						{
							ctx-> lfs_is_setter = true;
							return "set_" +  li->value;
						}
					}
				}

				return li->value;
			}
			else
			{
				return li->value;
			}

		}
	}

};


} } } } }

#endif 

