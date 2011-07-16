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

#include <as/ast/expr/member_expression.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/scope.h>

#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

#define DEBUG {std::cerr<<__FILE__<<":"<<__LINE__<<std::endl;}
struct MemberExpression : public Interpreter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx
			, tw::maple::as::symbol::Scope* class_symbol_table
			)
	{
		namespace ASY = tw::maple::as::symbol;

		std::string result;

		AST::MemberExpressionPtr expr_mem = STATIC_CAST( AST::MemberExpression, node);

		if( expr_mem->base()->is( AST::Node::NodeType::T_EMPTY) )
		{
			result += dispatchExpound( expr_mem->selector(), symbol_table, ctx, class_symbol_table);
		}
		else
		{

			ctx->token_class_type.reset();
			//workaround -> jump function into class
			if( class_symbol_table == NULL && symbol_table )
				class_symbol_table = symbol_table->getParent();

			result += dispatchExpound( expr_mem->base(), symbol_table, ctx, class_symbol_table);

			if( ctx->token_class_type != NULL )
			{
				if(  expr_mem->selector()->is( AST::Node::NodeType::T_CALL )
					&& STATIC_CAST( AST::Call, expr_mem->selector())->isObjectConsturct() )
				{
					ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, ctx->token_class_type);
					return constructor_work_around(result, dispatchExpound(expr_mem->selector(), symbol_table, ctx, base_type.get()));
				}

				ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, ctx->token_class_type);
				result += dispatchExpound( expr_mem->selector(), symbol_table, ctx, base_type.get());
			}
			else
				result += dispatchExpound( expr_mem->selector(), symbol_table, ctx, class_symbol_table );
		}
#if 0
		else if( expr_mem->node_childs.size() == 2 )
		{
			DEBUG
			std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = expr_mem->node_childs.begin();

			DEBUG
			ctx->token_class_type.reset();
			//workaround
			if( class_symbol_table == NULL && symbol_table )
			{
				class_symbol_table = symbol_table->getParent();
			}
			result += dispatchExpound(*nItr, symbol_table, ctx, class_symbol_table);
			nItr ++;

			if( result == "a" )
			{
				std::cerr<<"st "<< symbol_table->toString()<<std::endl;
			}
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
				ASY::ScopePtr s	 = DYNA_CAST( ASY::Scope, ctx->token_class_type);
				result += "/*in token class type */"+dispatchExpound(*nItr, symbol_table, ctx, s.get());
			}
			else
			{
				DEBUG
				if( result != "" && symbol_table->isInstance( result, "::") ) /* is instance is not make sense. TBR */
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
						result += "->"+ dispatchExpound(*nItr, symbol_table, ctx, instance_class_type.get()) ;

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
					result +=  dispatchExpound(*nItr, symbol_table, ctx, class_symbol_table);
				}
			}
		}
		else
		{
			std::cerr << "there's some strange in member get expression"<<std::endl;
			std::cerr << "pls contact mapleelpam at gmail.com" << std::endl;
			exit(1);
		}
#endif

		return result;
	}
private:
	std::string constructor_work_around( std::string base, std::string callee )
	{
		if( base != "")
			return replace( callee, "new ", "new "+base+"::");
		return callee;
	}

};

};


} } } } 

#endif 
