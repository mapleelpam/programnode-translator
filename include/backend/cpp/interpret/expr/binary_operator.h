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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_BINARY_OPERATOR_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_BINARY_OPERATOR_H__

#include <as/symbol/action/findable.h>
#include <as/ast/expr/binary_operator.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct BinaryOperator : public Interpreter
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
		std::string op =  resolve_operator( bin->op_type );
		ReturnValue rhs = dispatchExpound(bin->RHS(), symbol_table, ctx);

		if( (lhs.token_symbol || rhs.token_symbol ) && lhs.token_symbol != rhs.token_symbol )
		{
			if( bin->op_type == "plus" )
			{		
				//if( lhs.token_symbol->name() == "String" && rhs.token_symbol->name() == "Number" )
				if( lhs.token_symbol && resolve_typename(lhs.token_symbol) == "String"  )
				{
					result.result = "("+lhs.result + op+ "Number(" +rhs.result+").toString() )";
				}
				else if( rhs.token_symbol && resolve_typename(rhs.token_symbol) == "String" )
				{
					result.result = "( Number("+lhs.result+").toString()" + op + rhs.result + ")";
				}
				else
					result.result = lhs.result + op + rhs.result;
			}
			else
			result.result = lhs.result + op + rhs.result;
		}
		else
			result.result = lhs.result + op + rhs.result; 

		result.token_symbol = ( lhs.token_symbol ? lhs.token_symbol : rhs.token_symbol );

		return result;
	}
private:
	inline const std::string resolve_typename( tw::maple::as::symbol::SymbolPtr token )
	{
		namespace ASY = ::tw::maple::as::symbol;

		if( token == NULL )	return "";

		ASY::VariablePtr symbol_var = DYNA_CAST( ASY::Variable, token );
		ASY::SymbolPtr symbol_type;
		if( symbol_type && (symbol_type = symbol_var->getTypeSymbol()) )
		{
			return symbol_type->name();
		}

		return "";
	}
	inline const std::string resolve_operator( std::string str ) const
	{
		if( str == "plus")
			return "+";
		else if( str == "minus")
			return "-";
		else if( str == "mult")
			return "*";
		else if( str == "div")
			return "/";
		else if( str == "modulus")
			return "%";
		else if( str == "lessthan")
			return "<";
		else if( str == "lessthanorequals")
			return "<=";
		else if( str == "greaterthan")
			return ">";
		else if( str == "greaterthanorequals")
			return ">=";
		else if( str == "equals")
			return "==";
		else if( str == "notequals")
			return "!=";
		else if( str == "logicaland")
			return "&&";
		else if( str == "logicalor")
			return "||";
		else if( str == "bitwiseand")
			return "&";
		else if( str == "bitwiseor")
			return "|";
		else {
			std::cerr << " can't resolve binary op string '" << str << "'"<<std::endl;
			exit(1);
		}
	}

};

};


} } } } 

#endif 
