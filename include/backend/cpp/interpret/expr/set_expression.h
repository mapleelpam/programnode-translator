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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_SET_EXPRESSION_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_SET_EXPRESSION_H__

#include <as/ast/expr/set_expression.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;
namespace ASY = ::tw::maple::as::symbol;

struct SetExpression : public Interpreter
{   
	virtual ReturnValue expound(
			::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		std::string result;
		AST::SetExpressionPtr set = STATIC_CAST( AST::SetExpression, node);

		ctx.inter_type = Context::LHS;
		bool lft_is_setter = ctx.lfs_is_setter = false;
		std::string str_rhs = dispatchExpound(set->LHS(), symbol_table, ctx);
		lft_is_setter = ctx.lfs_is_setter;

		ctx.inter_type = Context::RHS;
		std::string str_lhs = dispatchExpound(set->RHS(), symbol_table, ctx/*TODO: SHOULD NOT BE*/ );

		ctx.inter_type = Context::RHS;

		std::string prefix = (set->mode == "dot") ? "->" : "";
		if( ctx.expression_symbol != NULL )
		{
			if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE) )
			{
				prefix = "->";
			}
			else if(ctx.expression_symbol->is( ASY::Symbol::T_SCOPE) )
			{
				if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE) || ctx.left_is_pointer )
					prefix = "->";
				else
					prefix = "::";
			}
		}

		if( lft_is_setter )
			return prefix+str_rhs + "( " + str_lhs+" )";
		else if( set->mode == "bracket")
			return prefix+"["+str_rhs + "] = " + str_lhs;
		else
			return prefix+str_rhs + " = " + str_lhs;
	}
};


} } } } }

#endif 
