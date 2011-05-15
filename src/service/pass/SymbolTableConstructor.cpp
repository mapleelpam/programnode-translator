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

#include <as/ast/func/function_definition.h>
#include <as/ast/func/function_common.h>
#include <as/ast/func/function_signature.h>
#include <as/ast/func/function_parameters.h>
#include <as/ast/func/function_parameter_item.h>
#include <as/ast/func/function_attribute.h>
#include <as/ast/func/function_name.h>
#include <as/ast/stmt/package_definition.h>

#include <as/ast/stmt/class_definition.h>

#include <as/ast/variable_declare.h>
#include <as/symbol/Scope.h>
#include <as/symbol/Function.h>
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

		switch( (*nItr) -> nodeType() ) {
			case AST::Node::NodeType::T_FUNCTION_DEFINITION:
			{
				AST::FunctionDefinitionPtr fdef = STATIC_CAST( AST::FunctionDefinition, *nItr);
				AST::FunctionCommonPtr fcommon  = STATIC_CAST( AST::FunctionCommon, fdef->FunctionCommon() );
				BOOST_ASSERT( fcommon != NULL );


				AST::FunctionNamePtr fname  = STATIC_CAST( AST::FunctionName, fdef->FunctionName() );
				BOOST_ASSERT( fname != NULL );
				std::string str_func_name = fname->function_name ;

				ASY::FunctionPtr scope_func( symboltable->registerFunction( str_func_name ) );
				{
					AST::FunctionAttributePtr fattrs = STATIC_CAST( AST::FunctionAttribute, fdef->FunctionAttr());
					for( std::vector<std::string>::iterator sItr = fattrs->attrs.begin()
							; sItr != fattrs->attrs.end() ; sItr ++ ) {
//						std::cerr << " attributes " << *sItr <<std::endl;
						if( ((*sItr) == "public") )
							scope_func->setSymbolAttributes( ASY::Symbol::ATTR_PUBLIC );
						else if( ((*sItr) == "private") )
							scope_func->setSymbolAttributes( ASY::Symbol::ATTR_PRIVATE );
						else if( ((*sItr) == "static") )
							scope_func->setIsStatic( true );
						else
							std::cerr << " unknow attribute " << *sItr << std::endl;
					}
				}
				fdef -> setSymbol( scope_func );

				AST::FunctionSignaturePtr fsig  = STATIC_CAST( AST::FunctionSignature, fcommon->FunctionSignature() );
				ASY::FunctionPtr ptr_function =  STATIC_CAST( ASY::Function, scope_func );
//				ASYM::SymbolPtr p_type = symboltable->findType( fsig->FunctionReturnType );
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
				AST::ClassDefinitionPtr _class_define_ = STATIC_CAST( AST::ClassDefinition, *nItr);

				ASY::ScopePtr scope_class( symboltable->registerClass( _class_define_->getClassName() ) );
				_class_define_ -> setSymbol( scope_class );

				constructSymbols( _class_define_, scope_class );

			}	break;
			case AST::Node::NodeType::T_FUNCTION_PARAMETER_ITEM:
			{
				AST::FunctionParameterItemPtr pitem = std::tr1::static_pointer_cast<AST::FunctionParameterItem>(*nItr);
				std::string str_varname = pitem->ParamName();
				pitem -> setSymbol( symboltable->registerFunctionParameter( str_varname ) );

			}	break;
			case AST::Node::NodeType::T_VARIABLE_DECLARE:
			{
				AST::VariableDeclarePtr var = std::tr1::static_pointer_cast<AST::VariableDeclare>(*nItr);
				std::string str_varname = var->VariableName;
				var->setSymbol( symboltable->registerVariable( str_varname ) );
			}	break;
			case AST::Node::NodeType::T_SCOPE:
			{
				ASY::ScopePtr scope_stmt( symboltable->registerAnonymousScope( ) );
				(*nItr) -> setSymbol( scope_stmt );
				constructSymbols( *nItr, scope_stmt );

				if( scope_stmt->isDeletable() )
					symboltable->removeChild( scope_stmt );
			}	break;
			case AST::Node::NodeType::T_PACKAGE_DEFINITION:
			{
				AST::PackageDefinitionPtr pkg = std::tr1::static_pointer_cast<AST::PackageDefinition>(*nItr);
				ASY::ScopePtr scope_pkg( symboltable->registerPackage( pkg->package_names ) );
				constructSymbols( *nItr, symboltable);
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
	namespace ASYM = tw::maple::as::symbol;

	if( node->node_childs.size() == 0 )
		return;
	for (std::vector< AST::NodePtr >::iterator nItr =
			node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {


		ASYM::SymbolPtr symbol = (*nItr)->getSymbol();

		if(  symbol &&
			(symbol->getSymbolProperties() & ASYM::Symbol::T_VARIABLE) )
		{
			AST::VariableDeclarePtr var = std::tr1::static_pointer_cast<AST::VariableDeclare>(*nItr);

			{
				std::cerr << " variable name = "<<var->VariableName<<std::endl;
				std::cerr << " variable type size = "<<var->VariableType.size()<<std::endl;
			}

			ASYM::ScopePtr var_type_scope = symboltable;
			for( int idx = 0 ; idx < var->VariableType.size() - 1 ; idx ++ )
			{
				ASYM::SymbolPtr temp_pkg = var_type_scope->findSymbol( var->VariableType[idx] );
				if( temp_pkg && temp_pkg ->getSymbolProperties() == ASYM::Symbol::T_SCOPE )
				{
					var_type_scope = STATIC_CAST( ASYM::Scope , temp_pkg );
				} else {
					std::cerr<<var->VariableName <<" can't find scope - "<< var->VariableType[idx] << " "<< var->toString() <<std::endl;
				}
			}
			ASYM::SymbolPtr p_type = var_type_scope->findType( var->VariableType[var->VariableType.size() - 1]  );

			if( p_type )
				symbol->bindType( p_type );
			else {
				std::cerr<<var->VariableName <<" can't find type - "<< var->toString() <<std::endl;
				exit(1);
			}
		} else if(  symbol &&
			(symbol->getSymbolProperties() & ASYM::Symbol::T_SCOPE) )
		{
			ASYM::ScopePtr p_scope = STATIC_CAST( ASYM::Scope, symbol );
			switch( p_scope->getScopeType() ) {
			case ASYM::Scope::T_FUNCTION:
			{
				AST::FunctionDefinitionPtr fdef = STATIC_CAST( AST::FunctionDefinition, *nItr);
				AST::FunctionCommonPtr fcommon  = STATIC_CAST( AST::FunctionCommon, fdef->FunctionCommon() );
				BOOST_ASSERT( fcommon != NULL );
				AST::FunctionSignaturePtr fsig  = STATIC_CAST( AST::FunctionSignature, fcommon->FunctionSignature() );

				std::cerr << " try to bind function return type !!! "<<fsig->ReturnType<<std::endl;
				ASYM::SymbolPtr p_type = symboltable->findType( fsig->ReturnType );
				BOOST_ASSERT( p_type != NULL && "can't find symbol" );
				std::cerr << " try to bind function return type !!! "<<p_type->getFQN()<<std::endl;
				BOOST_ASSERT( p_type );
				symbol->bindType( p_type );

				// don't break!! trace to next
			}
			default:
				linkVariableType( *nItr, p_scope);
				break;
			}
		} else
			linkVariableType( *nItr, symboltable);
	}
}

} } } }//pass.service.maple.tw

