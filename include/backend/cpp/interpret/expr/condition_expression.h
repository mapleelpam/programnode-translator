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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_CONDITION_EXPRESSION_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_CONDITION_EXPRESSION_H__

#include <as/ast/expr/condition_expression.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/scope.h>

#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ConditionExpression : public Interpreter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx

			)
	{
		namespace ASY = tw::maple::as::symbol;

		AST::ConditionExpressionPtr ce = STATIC_CAST( AST::ConditionExpression, node);

		ReturnValue expr_true = dispatchExpound( ce->ExpressionThen(), symbol_table, ctx);
		ReturnValue expr_false = dispatchExpound( ce->ExpressionElse(), symbol_table, ctx);

		const std::string s_scope_begin = "(", s_scope_end = ")";

		std::string result = s_scope_begin+"(" + dispatchExpound( ce->Condition(), symbol_table, ctx).result + ") ?";
		result += "(" + expr_true.result + ") : ";
		result += "(" + expr_false.result + ") " + s_scope_end;

		ReturnValue the_answer = result;
		if( expr_true.token_symbol == expr_false.token_symbol )
		{
			the_answer.token_symbol = expr_true.token_symbol;
		}

		return the_answer;
	}

};

};


} } } } 

#endif 
