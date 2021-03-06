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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STORE_REGISTER_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STORE_REGISTER_H__

#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/special/store_register.h>
#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct StoreRegister: public Interpreter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::StoreRegisterPtr SREG = STATIC_CAST( AST::StoreRegister, node);

		ReturnValue v1 = dispatchExpound(SREG->getRegister(), symbol_table, ctx );
		ReturnValue v2 = dispatchExpound(SREG->getExpression(), symbol_table, ctx );

		if( (v2.result == "0") || (v2.result == "") || v2.result == "\"\"")
			return _DS2("/* ignore reset register -1 */#(endl)");
		return "IterateForeach itc(" + v2.result +")";
	}

};


} } } } }

#endif 


