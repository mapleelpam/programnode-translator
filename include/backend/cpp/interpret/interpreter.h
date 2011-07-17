/* ******************************************************************\
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com       *
 *                                                                   *
 * Licensed under the Apache License, Version 2.0 (the "License");   *
 * you may not use this file except in compliance with the License.  *
 * You may obtain a copy of the License at                           *
 *                                                                   *
 *   http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                   *
 * Unless required by applicable law or agreed to in writing,        *
 * software distributed under the License is distributed on an       *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY            *
 * KIND, either express or implied. See the License for the          *
 * specific language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 * https://github.com/mapleelpam/programnode-translator              *
 *                                                                   *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple           *
 \*******************************************************************/


#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_INTERPRET_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_INTERPRET_H_

#include <as/ast/abstract/expression.h>
#include <backend/cpp/context.h>
#include <as/symbol/scope.h>

#define DEBUG_INTERPRET_ENTRY {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " enter function" <<std::endl;	}
#define DEBUG_INTERPRET_LEAVE {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " leave function" <<std::endl;	}


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

void initializeInterpreters();

struct Value
{
	std::string result;
	Value( const std::string& init )
		: result( init )
	{	}
	Value( const char* init )
		: result( std::string(init) )
	{	}
	Value()
		: result("")
	{	}
	void operator=( const std::string& rhs )
	{	result = rhs;	}

//	std::string operator=( Value& right )
//	{
//		return right.result;
//	}
	operator std::string()
	{
		return result;
	}
	std::string operator+( const std::string& right )
	{	return result + right;	}

	std::string operator+( const Value& right )
	{	return result + right.result;	}

	const Value operator+(const Value &other) const {
		return Value(*this) += other;
	}

	std::string operator+=( const Value& right )
	{	return result += right.result;	}
};

Value dispatchExpound(
		::tw::maple::as::ast::NodePtr node
		 , tw::maple::as::symbol::ScopePtr symbol_table
		 , ::tw::maple::backend::cpp::Context* ctx
		 , tw::maple::as::symbol::Scope* class_symbol_table
		 );

struct Interpreter
{

	virtual Value expound(
			::tw::maple::as::ast::NodePtr node
			 , tw::maple::as::symbol::ScopePtr symbol_table /* stmt symbol table */
			 , tw::maple::backend::cpp::Context* ctx
			 , tw::maple::as::symbol::Scope* class_symbol_table /* class symbol table */
			 )
	{
		std::cerr << " default expound " << std::endl;
		Value result = "";
		ctx->tree_depth ++;

		for (std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr =
				node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {
			result += dispatchExpound(*nItr, symbol_table, ctx, class_symbol_table);
		}

		ctx->tree_depth --;

		return result;
	}
//	virtual Value expound()
//	{
//		Value result = "";
//		return result;
//	}
};

} } } } }

#endif 
