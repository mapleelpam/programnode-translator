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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_EXPRMEMBER_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_EXPRMEMBER_H_

#include <as/ast/expr/expr_member.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/scope.h>

#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

#define DEBUG {std::cerr<<__FILE__<<":"<<__LINE__<<std::endl;}
struct ExpressionMember : public Interpreter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx
			, tw::maple::as::symbol::ScopePtr class_symbol_table
			)
	{
		namespace ASY = tw::maple::as::symbol;

		std::string result;

		AST::ExpressionMemberPtr expr_mem = STATIC_CAST( AST::ExpressionMember, node);

		if( expr_mem->node_childs.size() == 1 )
		{
			DEBUG
			result += dispatchExpound(*(expr_mem->node_childs.begin()), symbol_table, ctx, class_symbol_table);
		}
		else if( expr_mem->node_childs.size() == 2 )
		{
			DEBUG
			std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = expr_mem->node_childs.begin();

			DEBUG
			ctx->token_class_type.reset();
			result += dispatchExpound(*nItr, symbol_table, ctx, class_symbol_table);
			nItr ++;

			DEBUG
			if(  (*nItr)->nodeType() == AST::Node::NodeType::T_CALL
				&& STATIC_CAST( AST::Call, *nItr)->isObjectConsturct() )
			{
				DEBUG
				return constructor_work_around(result,dispatchExpound(*nItr, symbol_table, ctx, class_symbol_table));
			}
			else if( ctx->token_class_type != NULL )
			{
				DEBUG
				ASY::ScopePtr s = DYNA_CAST( ASY::Scope, ctx->token_class_type);
				result += "->" + dispatchExpound(*nItr, symbol_table, ctx, s);
			}
			else
			{
				DEBUG
				if( symbol_table->isInstance( result, "::") ) /* is instance is not make sense. TBR */
				{
					DEBUG

					ASY::SymbolPtr instance = symbol_table->findSymbol( result );
					if( instance == NULL && class_symbol_table != NULL )
					{
						instance = class_symbol_table->findSymbol( result );
					}
					ASY::VariablePtr variable = DYNA_CAST( ASY::Variable, instance );


					if( variable /* && function_ptr && function_ptr->isGetter()*/ )
					{
						ASY::SymbolPtr instance_type = variable -> getTypeSymbol();
						ASY::ScopePtr  instance_class_type = DYNA_CAST( ASY::Scope, instance_type );
						result += "->"+ dispatchExpound(*nItr, symbol_table, ctx, instance_class_type) ;

						ctx->token_class_type = variable->getTypeSymbol();
					} 
					else
					{
						std::cerr << "@@ can't find symbol '" << result << "' in symboltable '" << symbol_table->name() << "'" << std::endl;
						if( class_symbol_table != NULL )
							std::cerr << "can't find symbol '" << result << "' in class symboltable '" << class_symbol_table->name() << "'" << std::endl;
						exit(1);
					}

				}
				else 
				{
					result += "::" + dispatchExpound(*nItr, symbol_table, ctx, class_symbol_table);
				}
			}
		}
		else
		{
			std::cerr << "there's some strange in member get expression"<<std::endl;
			std::cerr << "pls contact mapleelpam at gmail.com" << std::endl;
			exit(1);
		}

		return result;
	}
private:
	std::string constructor_work_around( std::string base, std::string callee )
	{
		return replace( callee, "new ", "new "+base+"::");
	}

};

};


} } } } 

#endif 
