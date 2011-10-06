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

#include <as/ast/expr/call.h>
#include <as/ast/expr/member_expression.h>
#include <as/ast/expr/get_expression.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/scope.h>

#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

#define DEBUG {std::cerr<<__FILE__<<":"<<__LINE__<<std::endl;}
struct MemberExpression : public Interpreter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		namespace ASY = ::tw::maple::as::symbol;
		namespace AST = ::tw::maple::as::ast;

		ReturnValue result;

		AST::MemberExpressionPtr expr_mem = STATIC_CAST( AST::MemberExpression, node);

		//std::cerr << __FILE__<<":"<<__LINE__ << std::endl;
		if( expr_mem->base()->is( AST::Node::NodeType::T_EMPTY) )
		{
			//std::cerr << __FILE__<<":"<<__LINE__ << std::endl;
			return dispatchExpound( expr_mem->selector(), symbol_table, ctx);
		}
		else if( expr_mem->base()->is( AST::Node::NodeType::T_LOAD_REG) )
		{
			/* TODO: checkout variable name (itc) from ctx */
			return "itc->next()";
		}
		else if( expr_mem->base()->is( AST::Node::NodeType::T_SUPER_EXPRESSION) )
		{
			//std::cerr << __FILE__<<":"<<__LINE__ << std::endl;
			ReturnValue super = dispatchExpound( expr_mem->base(), symbol_table, ctx);
			ASY::Scope* inherit_type = (ASY::Scope*)( super.token_symbol2 );

			tw::maple::backend::cpp::Context ctx2 = ctx;
			ctx2.expression_symbol = super.token_symbol2;
			ReturnValue selector_value = dispatchExpound(expr_mem->selector(), symbol_table, ctx2/*, inherit_type*/);
			selector_value = super.token_symbol2->getFQN()+selector_value.result;

			//std::cerr << __FILE__<<":"<<__LINE__ << std::endl;
			return selector_value;
		}
		else
		{

			ReturnValue base = dispatchExpound( expr_mem->base(), symbol_table, ctx/*crazy?*/);
			result = base;
			//debug only
//			{
//				std::stringstream ss;
//				ss << base.result << " (type = "<<base.expression_type  <<" ) ";
//				base.result = ss.str();
//			}
//			if( result.result != "")
//				result.result = "("+result.result+")";

			if( base.token_symbol != NULL )
			{
				//std::cerr << __FILE__<<":"<<__LINE__ << std::endl;

				std::string str_before_base, str_after_base;

				//std::cerr <<__FILE__<<" @@ base "<<base.token_symbol->getFQN() <<" '"<<base.expression_type<<"'"<< std::endl;
				tw::maple::backend::cpp::Context ctx2 = ctx;
				ctx2.left_is_pointer = (base.expression_type == ReturnValue::HEAP );
				//std::cerr <<__FILE__<<" is instance "<< base.expression_type << std::endl;
				ctx2.expression_symbol = base.token_symbol.get();
				if(  expr_mem->selector()->is( AST::Node::NodeType::T_CALL ) // should never be here
					&& STATIC_CAST( AST::Call, expr_mem->selector())->isObjectConsturct() )
				{
					ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, base.token_symbol);
					ReturnValue result = dispatchExpound(expr_mem->selector(), symbol_table, ctx2/*, base_type.get()*/);
					result.result = constructor_work_around(result, result.result)+_DS("/*call const wa*/");
					return result;
				}
				else if( expr_mem->selector()->is( AST::Node::NodeType::T_GET_EXPRESSION )
					&& STATIC_CAST( AST::GetExpression, expr_mem->selector())->mode == "bracket" )
				{
					str_before_base = "(Object*)(*";
					str_after_base = ")";
				}

				ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, base.token_symbol);
				ReturnValue selector_value = dispatchExpound( expr_mem->selector(), symbol_table, ctx2/*, base_type.get()*/);

				//std::cerr <<__FILE__<<" selector is instance "<< selector_value.expression_type << " '"<<selector_value.result<<"'"<<std::endl;

				result = selector_value;
				result.result = str_before_base+base.result+_DS2("/* path2 */")+str_after_base+selector_value.result;
			}
			else
			{
				//TODO: report error, and do not pass it
				std::cerr <<__FILE__<<" "<<__LINE__<< " -- '" << result.result <<"' '"<<base.result<<"'"<<std::endl;
				if(base.token_symbol2 )
					std::cerr <<" error happend here!"<<std::endl;
				// it's not correct method, we should return "Object" in getProperty

				std::string str_mid = "->";
				if( expr_mem->selector()->is( AST::Node::NodeType::T_GET_EXPRESSION )
					&& STATIC_CAST( AST::GetExpression, expr_mem->selector())->mode == "bracket" )
				{
					str_mid = "";
				}

				result = "("+result.result +")"+str_mid+dispatchExpound( expr_mem->selector(), symbol_table, ctx ).result;
			}
		}
		return result;
	}
private:
	std::string constructor_work_around( std::string base, std::string callee )
	{
		if( base != "")
			return " ( "+replace( callee, "new ", "new "+base+"::")+" ) ";
		return "("+callee+")";
	}

};

};


} } } } 

#endif 

