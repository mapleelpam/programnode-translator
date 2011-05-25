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
// Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#include <as/symbol/scope.h>
#include <as/symbol/function.h>
#include <as/ast/node.h>
#include <as/ast/program.h>


#ifndef __TW_MAPLE_SERVICE_SYMBOL_TABLE_CONSTRUCTOR_H__
#define __TW_MAPLE_SERVICE_SYMBOL_TABLE_CONSTRUCTOR_H__

namespace tw { namespace maple { namespace service { namespace pass {

struct SymbolTableConstructor {
	static void exec(
			tw::maple::as::ast::ProgramList& pnode_list /* input program node */
			, tw::maple::as::symbol::ScopePtr root
			)
	{
		namespace AST = tw::maple::as::ast;

		for (std::vector< AST::ProgramPtr>::iterator nodeItr = pnode_list.begin()
			; nodeItr != pnode_list.end(); nodeItr++)
			constructSymbols( *nodeItr, root, "");

		for (std::vector< AST::ProgramPtr>::iterator nodeItr = pnode_list.begin()
			; nodeItr != pnode_list.end(); nodeItr++)
			linkVariableType( *nodeItr, root);
	}

private:
	static void constructSymbols(
			tw::maple::as::ast::NodePtr node /* input program node */
			, tw::maple::as::symbol::ScopePtr symboltable
			, std::string className
			);
	static void linkVariableType(
			tw::maple::as::ast::NodePtr node /* input program node */
			, tw::maple::as::symbol::ScopePtr symboltable
			);
};

} } } }//pass.service.maple.tw
#endif /* INFOMATIONCONSTRUCTOR_H_ */
