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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_INSTANCEOF_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_INSTANCEOF_H__

#include <as/ast/expr/instanceof.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct InstanceOf : public Interpreter, public TemplatePrinter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::InstanceOfPtr bin = STATIC_CAST( AST::InstanceOf, node);

		std::string instance_name = dispatchExpound(bin->LHS(), symbol_table, ctx);
		ReturnValue type_result = dispatchExpound(bin->RHS(), symbol_table, ctx);
		std::string type_name = type_result.result;
		std::string type_fqn_no_prefix = type_name;

		if( ASY::ScopePtr classtype_ptr = DYNA_CAST(ASY::Scope, type_result.token_symbol)  )
		{ // just class...!!

			type_name = classtype_ptr->getFQN_and_mappedName();
			type_fqn_no_prefix = classtype_ptr->getFQN_noprefix();

			std::cerr << " RHS " << bin->RHS()->toString() << "  "<<type_name << std::endl;
		}

		std::list<PatternPtr> patterns;
		patterns.push_back( PatternPtr( new Pattern("instance_name", instance_name ) ));
		patterns.push_back( PatternPtr( new Pattern("type_name", type_name) ));
		patterns.push_back( PatternPtr( new Pattern("type_name_style2", type_fqn_no_prefix) ));

		return substitutePatterns( patterns );
	}
	InstanceOf()
		: TemplatePrinter("InstanceOf")
	{
		setTemplateString( "false/*not support instanceof*/" );
	}
private:

};

};


} } } } 

#endif 
