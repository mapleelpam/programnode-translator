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
 * Copyright 2012 mapleellpam at gmail dot com   All rights reserved.
 *
 * https://github.com/mapleelpam/programnode-translator
 *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple
 * ***************************************************************/

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_FILTER_OPERATOR_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_FILTER_OPERATOR_H__

#include <as/symbol/action/findable.h>
#include <as/ast/expr/filter_operator.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct FilterOperator : public Interpreter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		using tw::maple::as::symbol::Findable;
		AST::BinaryOperatorPtr bin = STATIC_CAST( AST::BinaryOperator, node);

		ReturnValue result;

		ReturnValue lhs = dispatchExpound(bin->LHS(), symbol_table, ctx);
		ReturnValue rhs = dispatchExpound(bin->RHS(), symbol_table, ctx);

		AST::NodePtr eq_lhs, eq_rhs;
		locate_the_expression( bin->RHS(), eq_lhs, eq_rhs );

		{
			Context ctx2 = ctx;
			ctx2.disable_mapper = true;
			result += lhs.result + "->attribute_match("
				+dispatchExpound(eq_lhs, symbol_table, ctx2).result +", "
				+dispatchExpound(eq_rhs, symbol_table, ctx).result +")";

			result.token_symbol = Findable::findClassType( symbol_table, "XML" );
			result.expression_type = ExpressionType::HEAP;

		}

		return result;
	}
private:

	void locate_the_expression ( ::tw::maple::as::ast::NodePtr input
			, ::tw::maple::as::ast::NodePtr& eq_lhs /* out */
			, ::tw::maple::as::ast::NodePtr& eq_rhs /* out */ )
	{
		if( input->nodeType() == AST::Node::NodeType::T_EXPR_LIST)
		{
			locate_the_expression( input, eq_lhs, eq_rhs );
			return;
		}
		else if( input->nodeType() == AST::Node::NodeType::T_BINARY_OPERATOR)
		{
			AST::BinaryOperatorPtr bin = STATIC_CAST( AST::BinaryOperator, input);
			if( bin->op_type == "equals")
			{
				eq_lhs = bin->LHS();
				eq_rhs = bin->RHS();
				return;
			}
		}
	}

};

} } } } }

#endif 
