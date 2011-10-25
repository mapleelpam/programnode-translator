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
		std::string ro_rhs, lo_rhs;
		AST::SetExpressionPtr set = STATIC_CAST( AST::SetExpression, node);

		ctx.inter_type = Context::LHS;
		bool lft_is_setter = ctx.lfs_is_setter = false;
		ReturnValue lhs_value = dispatchExpound(set->LHS(), symbol_table, ctx);
		lft_is_setter = ctx.lfs_is_setter;

		ctx.inter_type = Context::RHS;
		ReturnValue rhs_value = dispatchExpound(set->RHS(), symbol_table, ctx/*TODO: SHOULD NOT BE*/ );

		ctx.inter_type = Context::RHS;

		std::string prefix = (set->mode == "dot") ? "->" : "";
		if( ctx.expression_symbol != NULL )
		{
			if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE) )
			{
				if( set->mode != "bracket" )
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

		std::string str_type_cast = "";

		if( lhs_value.token_symbol )
		{
			if( lhs_value.token_symbol != rhs_value.token_symbol)
			{
				if (lhs_value.token_symbol->preferStack())
				{
					str_type_cast = "(" + lhs_value.token_symbol->getFQN_and_instanceName() + ")";
					lo_rhs = "(";
					ro_rhs = ")";
				}
				else if ( DYNA_CAST(ASY::VariantType, lhs_value.token_symbol ) )
					str_type_cast += ""; // ignore
				else if (lhs_value.token_symbol -> name() == "Function")
					str_type_cast = ""; // ignore
				else
				{	// every time variable prefer heap, it should be ObjectBase
					str_type_cast = "(" + lhs_value.token_symbol->getFQN_noprefix() + "*)(Object*)";
					lo_rhs = "(";
					ro_rhs = ")";
				}
			}
		}

		if( lft_is_setter )
			return prefix+lhs_value.result + "( " + rhs_value.result+" )";
		else if( set->mode == "bracket")
		{
			ASY::Variable* symbol_var;
			if( ctx.expression_symbol && (symbol_var = dynamic_cast<ASY::Variable*>( ctx.expression_symbol)) )
			{
				ASY::SymbolPtr symbol_type = symbol_var->getTypeSymbol();
				ASY::ScopePtr  symbol_class_type = DYNA_CAST( ASY::Scope, symbol_type );

				if( symbol_class_type && !(symbol_class_type->isClass("Array")) )
				{
					return prefix+"->setProperty("+lhs_value.result + ", " + rhs_value.result +" ) ";
				}
			}
			// else; default
			return prefix+"["+lhs_value.result + "] = " + rhs_value.result;
		}
		else
			return prefix+lhs_value.result + " = " + str_type_cast + lo_rhs + rhs_value.result + ro_rhs;
	}
};


} } } } }

#endif 
