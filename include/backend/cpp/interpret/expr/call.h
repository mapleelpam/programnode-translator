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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_CALL_H
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_CALL_H

#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/abstract/expression.h>
#include <as/ast/expr/call.h>

namespace AST = ::tw::maple::as::ast;

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

// Abstract
struct Call : public Interpreter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
//			/* , tw::maple::as::symbol::Scope* class_symbol_table */
			)
	{

		namespace ASY = tw::maple::as::symbol;


		ReturnValue result;
		AST::CallPtr call = STATIC_CAST( AST::Call, node);

		if (call->isObjectConsturct()) {
			result +=  " new ";
			std::string type_name = get_full_functionname( call->callee );
			ASY::SymbolPtr p_type = call->getCalleeType();
			if( p_type != NULL && p_type->getFQN_and_mappedName() != "" )
			{
				result.token_symbol = p_type;
				result.is_instance = true; // TODO:
				result += p_type->getFQN_and_mappedName();
			}
			else
			{
				result += type_name;
			}
		}
		else
		{
			if( call->mode == "dot" )
			{
				std::string right = get_full_functionname( call->callee );
				if( ctx.expression_symbol != NULL )
				{

					ASY::Scope* left_scope = NULL;
					if( ctx.expression_symbol->is(ASY::Symbol::T_VARIABLE ))
					{
						ASY::Variable* var_symbol = (ASY::Variable*) ctx.expression_symbol;
						left_scope = (ASY::Scope*)(var_symbol -> getTypeSymbol().get());
					}
					else
					{
						left_scope = (ASY::Scope*)(ctx.expression_symbol);
					}

					std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
					if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE) )
					{  // TODO: guess this child_string is ??? primitive? or non-deletable
						std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
						result += ("->"+right);
					}
					else if(ctx.expression_symbol->is( ASY::Symbol::T_SCOPE) )
					{ // should be a type
						std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
						result += ( "::"+right);
					}

					ASY::SymbolPtr callee_symbol = ASY::Findable::findCallee(left_scope,right);
					std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
					ASY::FunctionPtr callee_func_symbol = DYNA_CAST(ASY::Function, callee_symbol);
					std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
					result.token_symbol = callee_func_symbol->ReturnType();
					std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
				}
				else
				{
					std::cerr << " call(dot) expression error, should pass left symbol" << std::endl;
					exit(1);
				}

			}
			else
				result += get_full_functionname( call->callee );
		}
		result +=  "( ";
		if (call->getArgs())
		{
			tw::maple::backend::cpp::Context ctx2 = ctx;
			result += dispatchExpound( call->getArgs(), symbol_table, ctx2/*, class_symbol_table*/);
		}
		result += " )";

//		std::cerr << " in call interpreter  = (end)" << std::endl;

		return result;
	}

private:
		const std::string get_full_functionname( const std::vector<std::string> fn )
		{
			std::string ans = fn[0];
			for( int idx = 1 ; idx < fn.size() ; idx ++ )
			{
				ans += "::"+fn[idx];
			}
			return ans;
		}
};


} } } } }

#endif 
