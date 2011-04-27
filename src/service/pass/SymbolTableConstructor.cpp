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
#include <as/ast/function_common.h>
#include <as/ast/function_signature.h>
#include <as/ast/function_parameters.h>
#include <as/ast/function_parameter_item.h>

#include <as/ast/class_define.h>

#include <as/ast/variable_declare.h>
#include <as/symbol/Scope.h>
#include <backend/cpp/context.h>

namespace tw { namespace maple { namespace service { namespace pass {

void SymbolTableConstructor:: constructSymbols(
		tw::maple::as::ast::NodePtr node /* input program node */
		, tw::maple::as::symbol::ScopePtr symboltable
		)
{
	namespace AST = tw::maple::as::ast;
	namespace CPP = tw::maple::backend::cpp::interpret;
	namespace ASY = tw::maple::as::symbol;

	if( node->node_childs.size() == 0 )
		return;
	for (std::vector< AST::NodePtr >::iterator nItr =
			node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {

		std::cout << "->>>>>      node -> name " << (*nItr)->toString() << std::endl;

		switch( (*nItr) -> nodeType() ) {
			case AST::Node::NodeType::T_FUNCTION_DEFINITION:
			{
				AST::FunctionDefinitionPtr fdef = STATIC_CAST( AST::FunctionDefinition, *nItr);
				AST::FunctionCommonPtr fcommon  = STATIC_CAST( AST::FunctionCommon, fdef->FunctionCommon() );
				AST::FunctionSignaturePtr fsig  = STATIC_CAST( AST::FunctionSignature, fcommon->FunctionSignature() );


				std::string str_func_name = CPP::dispatchExpound(fdef->FunctionName(), NULL) ;
				std::cout << " get a function name = " << str_func_name << std::endl;

				ASY::ScopePtr scope_func( symboltable->registerFunction( str_func_name ) );
				fdef -> setSymbol( scope_func );

				if(	fsig->FunctionParameter() )
					constructSymbols( fsig->FunctionParameter(), scope_func );
				constructSymbols( fcommon->FunctionBody(), scope_func );
			} 	break;
			case AST::Node::NodeType::T_FUNCTION_SIGNATURE:
			{
				std::cout <<" hey it's function sigantur " << std::endl;
			}	break;
			case AST::Node::NodeType::T_CLASS_DEFINE:
			{
				::tw::maple::backend::cpp::Context tmp_contexts;
				AST::ClassDefinePtr _class_define_ = STATIC_CAST( AST::ClassDefine, *nItr);
				std::string class_name = CPP::dispatchExpound(_class_define_->className(), &tmp_contexts);

				ASY::ScopePtr scope_class( symboltable->registerClass( class_name ) );
				_class_define_ -> setSymbol( scope_class );

				constructSymbols( _class_define_, scope_class );

			}	break;
			case AST::Node::NodeType::T_FUNCTION_PARAMETER_ITEM:
			{
				AST::FunctionParameterItemPtr pitem = std::tr1::static_pointer_cast<AST::FunctionParameterItem>(*nItr);
				std::string str_varname = CPP::dispatchExpound(pitem->ParamName(), NULL);
				pitem -> setSymbol( symboltable->registerFunctionParameter( str_varname ) );

			}	break;
			case AST::Node::NodeType::T_VARIABLE_DECLARE:
			{
				AST::VariableDeclarePtr var = std::tr1::static_pointer_cast<AST::VariableDeclare>(*nItr);
				std::string str_varname = CPP::dispatchExpound(var->varName(), NULL);
				var->setSymbol( symboltable->registerVariable( str_varname ) );
			}	break;
			case AST::Node::NodeType::T_IF_STMT_THEN:
			case AST::Node::NodeType::T_IF_STMT_ELSE:
			{
				ASY::ScopePtr scope_stmt( symboltable->registerAnonymousScope( ) );
				(*nItr) -> setSymbol( scope_stmt );
				constructSymbols( *nItr, scope_stmt );

				if( scope_stmt->isDeletable() )
					symboltable->removeChild( scope_stmt );
			}	break;
			default:
				constructSymbols( *nItr, symboltable);
				break;
		}
	}
}

void SymbolTableConstructor::linkVariableType(
		tw::maple::as::ast::NodePtr node /* input program node */
		, tw::maple::as::symbol::ScopePtr symboltable
		)
{
	namespace AST = tw::maple::as::ast;
	namespace CPP = tw::maple::backend::cpp::interpret;
	namespace ASY = tw::maple::as::symbol;

	if( node->node_childs.size() == 0 )
		return;
	for (std::vector< AST::NodePtr >::iterator nItr =
			node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {

	}
}

} } } }//pass.service.maple.tw

