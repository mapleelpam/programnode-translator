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
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx
			, tw::maple::as::symbol::Scope* class_symbol_table
			)
	{
		namespace ASY = tw::maple::as::symbol;

		AST::ConditionExpressionPtr ce = STATIC_CAST( AST::ConditionExpression, node);


		std::string result = "(" + dispatchExpound( ce->Condition(), symbol_table, ctx, class_symbol_table) + ") ?";
		result += "(" + dispatchExpound( ce->ExpressionThen(), symbol_table, ctx, class_symbol_table) + ") : ";
		result += "(" + dispatchExpound( ce->ExpressionElse(), symbol_table, ctx, class_symbol_table) + ") ";

		return result;
	}

};

};


} } } } 

#endif 