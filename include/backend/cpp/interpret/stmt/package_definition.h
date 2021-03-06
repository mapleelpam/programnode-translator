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

#ifndef __BACKEDN_CPP_INTERPRET_STMT_PACKAGE_DEFINITION_H__
#define __BACKEDN_CPP_INTERPRET_STMT_PACKAGE_DEFINITION_H__

#include <as/ast/stmt/package_definition.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct PackageDefinition : public Interpreter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{

		AST::PackageDefinitionPtr ast_pkg = STATIC_CAST( AST::PackageDefinition, node);


		std::string prefix = "\n";
		std::string inside = "";
		std::string postfix = "";

		for( std::vector<std::string>::iterator sItr = ast_pkg->package_names.begin()
				; sItr != ast_pkg->package_names.end() ; sItr++ )
		{
			prefix += "namespace "+ *sItr+ "{ ";
		}
//		result +="\n";

		ASY::SymbolPtr pkg_symbol = node->getSymbol();
		ASY::ScopePtr pkg_scope = DYNA_CAST( ASY::Scope, pkg_symbol );

			ctx.tree_depth ++;	ctx.tableof_imported.enterScope();
			for (std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr =
					node->node_childs.begin(); nItr != node->node_childs.end(); nItr++)
			{
				inside += dispatchExpound(*nItr, ((pkg_scope)?pkg_scope:symbol_table),  ctx);
			}
			ctx.tree_depth --;	ctx.tableof_imported.leaveScope();



		for( std::vector<std::string>::iterator sItr = ast_pkg->package_names.begin(), E = ast_pkg->package_names.end()
						; sItr != E ; sItr++ )
		{
			postfix += "} /* "+ (*sItr=="" ? "anonymouse" : *sItr )+ "*/";
		}

		if( inside == "")
			return "";
		else
			return prefix+inside+postfix;
	}

};


} } } } }

#endif 
