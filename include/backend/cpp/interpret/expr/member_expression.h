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

		if( expr_mem->base()->is( AST::Node::NodeType::T_EMPTY) )
		{
			return dispatchExpound( expr_mem->selector(), symbol_table, ctx);
		}
		else if( expr_mem->base()->is( AST::Node::NodeType::T_SUPER_EXPRESSION) )
		{
			ReturnValue super = dispatchExpound( expr_mem->base(), symbol_table, ctx);
			ASY::Scope* inherit_type = (ASY::Scope*)( super.token_symbol2 );

			tw::maple::backend::cpp::Context ctx2 = ctx;
			ctx2.expression_symbol = super.token_symbol2;
			ReturnValue selector_value = dispatchExpound(expr_mem->selector(), symbol_table, ctx2/*, inherit_type*/);
			selector_value = super.token_symbol2->getFQN()+selector_value.result;

			return selector_value;
		}
		else
		{

//			if( class_symbol_table == NULL && symbol_table )
//				class_symbol_table = symbol_table->getParent();

			ReturnValue base = dispatchExpound( expr_mem->base(), symbol_table, ctx/*crazy?*/);
			result = base;

			if( base.token_symbol != NULL )
			{
				std::cerr <<__FILE__<<" "<<base.token_symbol->getFQN() << std::endl;
				tw::maple::backend::cpp::Context ctx2 = ctx;
				ctx2.left_is_instance = base.is_instance;
				std::cerr <<__FILE__<<" is instance "<< base.is_instance << std::endl;
				ctx2.expression_symbol = base.token_symbol.get();
				if(  expr_mem->selector()->is( AST::Node::NodeType::T_CALL )
					&& STATIC_CAST( AST::Call, expr_mem->selector())->isObjectConsturct() )
				{
					ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, base.token_symbol);
					return constructor_work_around(result, dispatchExpound(expr_mem->selector(), symbol_table, ctx2/*, base_type.get()*/).result);
				}

				ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, base.token_symbol);
				ReturnValue selector_value = dispatchExpound( expr_mem->selector(), symbol_table, ctx2/*, base_type.get()*/);
				result = selector_value;
				result.result = base.result+_DS2("/* path2 */")+selector_value.result;
//				result = _DS2("/* path2 */")+selector_value.result;
//				result.token_symbol = selector_value.token_symbol;
//				result.token_symbol2 = selector_value.token_symbol2;
			}
			else
			{
				//TODO: report error, and do not pass it
				std::cerr <<__FILE__<<" "<<__LINE__<<std::endl;
				result += _DS2("/* path3 */")+dispatchExpound( expr_mem->selector(), symbol_table, ctx ).result;
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
