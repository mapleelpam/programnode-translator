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
			, tw::maple::backend::cpp::Context* ctx
			, tw::maple::as::symbol::Scope* class_symbol_table
			)
	{
		namespace ASY = ::tw::maple::as::symbol;
		namespace AST = ::tw::maple::as::ast;

		ReturnValue result;

		AST::MemberExpressionPtr expr_mem = STATIC_CAST( AST::MemberExpression, node);

		if( expr_mem->base()->is( AST::Node::NodeType::T_EMPTY) )
		{
			return dispatchExpound( expr_mem->selector(), symbol_table, ctx, class_symbol_table);
		}
		else if( expr_mem->base()->is( AST::Node::NodeType::T_SUPER_EXPRESSION) )
		{
			result = dispatchExpound( expr_mem->selector(), symbol_table, ctx, class_symbol_table);
		}
		else
		{

			if( class_symbol_table == NULL && symbol_table )
				class_symbol_table = symbol_table->getParent();

			ReturnValue base = dispatchExpound( expr_mem->base(), symbol_table, ctx, NULL/*crazy?*/);
			result = base;

			if( base.token_symbol != NULL )
			{
				if(  expr_mem->selector()->is( AST::Node::NodeType::T_CALL )
					&& STATIC_CAST( AST::Call, expr_mem->selector())->isObjectConsturct() )
				{
					ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, base.token_symbol);
					return constructor_work_around(result, dispatchExpound(expr_mem->selector(), symbol_table, ctx, base_type.get()).result);
				}

				ASY::ScopePtr base_type	 = DYNA_CAST( ASY::Scope, base.token_symbol);
				result += _DS2("/* path2 */")+dispatchExpound( expr_mem->selector(), symbol_table, ctx, base_type.get()).result;
			}
			else
				result += _DS2("/* path3 */")+dispatchExpound( expr_mem->selector(), symbol_table, ctx, class_symbol_table ).result;
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
