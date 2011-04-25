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

#include <service/pass/SymbolTableConstructor.h>
#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/function_definition.h>
#include <as/ast/variable_declare.h>
#include <as/symbol/Scope.h>


namespace tw { namespace maple { namespace service { namespace pass {

void SymbolTableConstructor:: constructSymbols(
		tw::maple::as::ast::NodePtr node /* input program node */
		, tw::maple::as::symbol::ScopePtr symboltable
		)
{
	namespace AST = tw::maple::as::ast;
	namespace CPP = tw::maple::backend::cpp::interpret;
	namespace ASY = tw::maple::as::symbol;

	for (std::vector< AST::NodePtr >::iterator nItr =
			node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {

		std::cout << "->>>>>      node -> name " << (*nItr)->toString() << std::endl;

		switch( (*nItr) -> nodeType() ) {
			case AST::Node::NodeType::T_FUNCTION_DEFINITION:
			{
				AST::FunctionDefinitionPtr fdef = STATIC_CAST( AST::FunctionDefinition, *nItr);
				std::string str_func_name = CPP::dispatchExpound(fdef->FunctionName(), NULL) ;
				std::cout << " get a function name = " << str_func_name << std::endl;
				ASY::ScopePtr scope_func( symboltable->registerFunction( str_func_name ) );
				constructSymbols( *nItr, scope_func );
			} 	break;
			case AST::Node::NodeType::T_CLASS_DEFINE:
			{

			}	break;
			case AST::Node::NodeType::T_VARIABLE_DECLARE:
			{
				AST::VariableDeclarePtr var = std::tr1::static_pointer_cast<AST::VariableDeclare>(*nItr);
				std::string str_varname = CPP::dispatchExpound(var->varName(), NULL);
				symboltable->registerVariable( str_varname );
			}	break;
			default:
				constructSymbols( *nItr, symboltable);
				break;
		}
	}
}

} } } }//pass.service.maple.tw

