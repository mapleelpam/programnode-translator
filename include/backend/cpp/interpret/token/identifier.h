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
			std::vector<ASY::SymbolPtr> candidates = symbol_table->findSymbol_down2( li->value );
			if( candidates.size() == 0 && class_symbol_table != NULL )
				candidates = class_symbol_table->findSymbol_down2( li->value );

			if( candidates.size() > 0 )
			{
				if( ctx->inter_type==Context::RHS )
				{
					for( int idx = 0, E = candidates.size() ; idx < E ; idx ++ )
					{
						ASY::SymbolPtr instance_symbol = candidates[idx];
						ASY::FunctionPtr function_ptr = DYNA_CAST( ASY::Function, instance_symbol );
						if( function_ptr != NULL && function_ptr->isGetter() )
							return "get_" +  li->value + "()";
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
				/* TODO: exit 1 */
//				exit(1);
				return li->value;
			}

		}
	}

};


} } } } }

#endif 

