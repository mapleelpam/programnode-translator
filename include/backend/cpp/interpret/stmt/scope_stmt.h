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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_SCOPE_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_DO_STMT_H__

#include <as/ast/stmt/do_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ScopeStatement : public Interpreter
{

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		std::cerr << " default expound " << std::endl;
		std::string result = "";
//		ctx.tree_depth ++;

		// Very important thing here, enter the symbol table
		ASY::SymbolPtr scope_symbol = node->getSymbol();
		ASY::ScopePtr scope_symboltable = DYNA_CAST( ASY::Scope, scope_symbol );

		for (std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr =
				node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {
			result += dispatchExpound(*nItr, (scope_symboltable)?scope_symboltable:symbol_table, ctx);
		}

//		ctx.tree_depth --;

		return result;
	}

};

};


} } } } 

#endif 
