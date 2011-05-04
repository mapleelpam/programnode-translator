/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// ProgrameNode Translator
// Copyright 2011 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __BACKEDN_CPP_INTERPRET_STMT_PACKAGE_DEFINITION_H__
#define __BACKEDN_CPP_INTERPRET_STMT_PACKAGE_DEFINITION_H__

#include <as/ast/stmt/package_definition.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct PackageDefinition : public Interpreter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx)
	{
		std::cerr << " in PackageDefinition scope!!" << std::endl;

		AST::PackageDefinitionPtr ast_pkg = STATIC_CAST( AST::PackageDefinition, node);


		std::string result = "";

		for( std::vector<std::string>::iterator sItr = ast_pkg->package_names.begin()
				; sItr != ast_pkg->package_names.end() ; sItr++ )
		{
			result += "namespace "+ *sItr+ "{ ";
		}

			ctx->tree_depth ++;
			for (std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr =
					node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {
//				std::cerr << "-------------------------------------> in PackageDefinition scope!!" << std::endl;
				result += dispatchExpound(*nItr, symbol_table,  ctx);
			}
			ctx->tree_depth --;

		for( std::vector<std::string>::iterator sItr = ast_pkg->package_names.begin()
						; sItr != ast_pkg->package_names.end() ; sItr++ )
		{
			result += "} /* "+ *sItr+ "*/ ";
		}

		return result;
	}

	PackageDefinition()
	{

	}
};


} } } } }

#endif 
