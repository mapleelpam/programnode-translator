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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_GET_EXPRESSION_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_GET_EXPRESSION_H__

#include <as/ast/expr/get_expression.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;
namespace ASY = ::tw::maple::as::symbol;

struct GetExpression : public Interpreter
{   
	virtual ReturnValue expound(
			::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::GetExpressionPtr get = STATIC_CAST( AST::GetExpression, node);

		ReturnValue child_string = dispatchExpound(get->child(), symbol_table, ctx);

		if( get->mode == "lexical" )
		{
			ASY::FunctionPtr func = ASY::Findable::findFunction( symbol_table, child_string);
			if( func && !func->isSetter() && !func->isGetter() && !func->isSetter() && !func->isConstructor() )
			{
				child_string.result = "(void*)static_"+child_string.result;
			}
			return child_string;
		}
		else if( get->mode == "dot" )
		{
			if( ctx.expression_symbol != NULL )
			{
				if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE) || ctx.left_is_pointer )
				{  // TODO: guess this child_string is ??? primitive? or non-deletable
					child_string.result = "->"+_DS2("/*is variable*/")+child_string.result;
					return child_string;
				}
				else if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE) && !ctx.left_is_pointer )
				{  // TODO: guess this child_string is ??? primitive? or non-deletable
					child_string.result = "."+_DS2("/*is stack variable*/")+child_string.result;
					return child_string;
				}
				else if(ctx.expression_symbol->is( ASY::Symbol::T_SCOPE) )
				{ // should be a type
					child_string.result = "::"+_DS2("/*is scope*/")+child_string.result;
					return child_string;
				}
			}
		}
		else if( get->mode == "bracket" )
		{
			child_string = "[" + child_string.result+"]";
		}

		return child_string;
	}
};


} } } } }

#endif 
