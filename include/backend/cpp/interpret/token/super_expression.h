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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_SUPER_EXPRESSION_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_SUPER_EXPRESSION_H__

#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/token/this_expression.h>
#include <global.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct SuperExpression : public Interpreter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			, tw::maple::as::symbol::Scope* class_symbol_table
			)
	{
		tw::maple::as::symbol::Scope* type = findInheritParent( symbol_table );
		ReturnValue answer="";
		answer.token_symbol2 = type;
		return  answer;
	}

private:
	tw::maple::as::symbol::Scope* findInheritParent(  tw::maple::as::symbol::ScopePtr symbol_table )
	{
		 tw::maple::as::symbol::Scope* answer = symbol_table.get();
		 std::cerr <<" 0 " << answer->getFQN();
		 while( answer != NULL && ! (answer->is(tw::maple::as::symbol::Scope::T_CLASS) ) )
		 {
			 std::cerr <<" 1 " << answer->getFQN();
			 answer = answer->getParent();
			 std::cerr <<" 2 " << answer->getFQN();
		 }
		 if( answer != NULL )
		 {
			 std::cerr <<" 3 " << answer->getFQN();
			 std::cerr <<" 4 " << answer->getInherit()->getFQN();
			 return answer->getInherit();
		 }
		 return NULL;
	}
};


} } } } }

#endif 

