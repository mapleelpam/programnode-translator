 /*******************************************************************\
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
 *     https://github.com/mapleelpam/programnode-translator          *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#include <service/pass/symboltableconstructor.h>
#include <backend/cpp/interpret/interpreter.h>

#include <as/ast/func/function_definition.h>
#include <as/ast/func/function_common.h>
#include <as/ast/func/function_signature.h>
#include <as/ast/func/function_parameters.h>
#include <as/ast/func/function_parameter_item.h>
#include <as/ast/func/function_parameter_rest.h>
#include <as/ast/func/function_attribute.h>
#include <as/ast/func/function_name.h>
#include <as/ast/token/identifier.h>
#include <as/ast/stmt/package_definition.h>
#include <as/ast/stmt/class_definition.h>
#include <as/ast/stmt/import_stmt.h>
#include <as/ast/stmt/variable_declare.h>

#include <as/symbol/scope.h>
#include <as/symbol/function.h>
#include <as/symbol/variable.h>
#include <as/symbol/parameter.h>
#include <as/symbol/varianttype.h>

#include <service/pass/construct_symboltable/ph2_inherit/phase2_import_stmt.h>
#include <service/pass/construct_symboltable/ph3_binding/phase3_variable_declare.h>
#include <service/pass/construct_symboltable/ph3_binding/phase3_function_define.h>
#include <service/pass/construct_symboltable/ph3_binding/phase3_import_stmt.h>
#include <service/pass/construct_symboltable/ph3_binding/phase3_call_expr.h>
#include <service/pass/construct_symboltable/ph3_binding/phase3_parameter.h>
#include <service/pass/construct_symboltable/ph3_binding/phase3_parameter_rest.h>
#include <service/pass/construct_symboltable/ph3_binding/phase3_identifier.h>

namespace tw { namespace maple { namespace service { namespace pass {


void SymbolTableConstructor:: constructSymbols(
		tw::maple::as::ast::NodePtr node /* input program node */
		, tw::maple::as::symbol::ScopePtr symboltable
		, std::string classname
		)
{
	namespace AST = tw::maple::as::ast;
	namespace CPP = tw::maple::backend::cpp::interpret;
	namespace ASY = tw::maple::as::symbol;

	if( node==NULL || node->node_childs.size() == 0 )
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
						else if( ((*sItr) == "protected") )
							scope_func->setSymbolAttributes( ASY::Symbol::ATTR_PROTECTED);
						else if( ((*sItr) == "static") )
							scope_func->setIsStatic( true );
						else
							std::cerr << " unknow attribute " << *sItr << std::endl;
					}
				}
//				std::cerr << "abcdefg "<<str_func_name << "  " << fname->function_type<<"  "<<symboltable->name()<<std::endl;
				scope_func -> setFunctionType( fname->function_type );

//				std::cerr << " class name = " << classname << " function_name = " <<str_func_name << std::endl;
				if( classname!="" && classname == str_func_name )
				{
//					std::cerr << " set true " << std::endl;
					scope_func -> setIsConstructor( true );
				}
				else
				{
//					std::cerr << " set false " << std::endl;
					scope_func -> setIsConstructor( false );
				}

				fdef -> setSymbol( scope_func );
				fdef -> setFunctionSymbol( scope_func );

				AST::FunctionSignaturePtr fsig  = STATIC_CAST( AST::FunctionSignature, fcommon->FunctionSignature() );

				if(	fsig->FunctionParameter() )
					constructSymbols( fsig->FunctionParameter(), scope_func, classname );
				constructSymbols( fcommon->FunctionBody(), scope_func, classname );
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
				scope_class -> setMappedName( _class_define_->getMappedClassName() );
				scope_class -> setInstanceName( _class_define_->getInstanceName() );
				_class_define_ -> setSymbol( scope_class );
				_class_define_ -> setClassSymbol( scope_class );
				constructSymbols( _class_define_, scope_class, _class_define_->getClassName() );

			}	break;
			case AST::Node::NodeType::T_FUNCTION_PARAMETER_ITEM:
			{
				AST::FunctionParameterItemPtr pitem = std::tr1::static_pointer_cast<AST::FunctionParameterItem>(*nItr);
				std::string str_varname = pitem->ParamName();
				ASY::SymbolPtr sym_param= symboltable->registerFunctionParameter( str_varname, pitem->hasInit() ) ;
				pitem -> setSymbol( sym_param );

			}	break;
			case AST::Node::NodeType::T_FUNCTION_PARAMETER_REST:
			{
				AST::FunctionParameterRestPtr pitem = std::tr1::static_pointer_cast<AST::FunctionParameterRest>(*nItr);
				std::string str_varname = pitem->m_param_name;
				pitem -> setSymbol( symboltable->registerFunctionParameter( str_varname, false ) );

			}	break;
			case AST::Node::NodeType::T_VARIABLE_DECLARE:
			{
				AST::VariableDeclarePtr var = std::tr1::static_pointer_cast<AST::VariableDeclare>(*nItr);
				std::string str_varname = var->VariableName;

				ASY::VariablePtr symbol_var( symboltable->registerVariable( str_varname ) );
				var->setSymbol( symbol_var );

				symbol_var->setIsStatic( var->isStatic() );
				if( var->varInit() )
					symbol_var->setInitializeNode( var->varInit() );

			}	break;
			case AST::Node::NodeType::T_SCOPE:
			{
				ASY::ScopePtr scope_stmt( symboltable->registerAnonymousScope( ) );
				(*nItr) -> setSymbol( scope_stmt );
				constructSymbols( *nItr, scope_stmt, classname );

				if( scope_stmt->isDeletable() )
					symboltable->removeChild( scope_stmt );
			}	break;
			case AST::Node::NodeType::T_PACKAGE_DEFINITION:
			{
				AST::PackageDefinitionPtr pkg = std::tr1::static_pointer_cast<AST::PackageDefinition>(*nItr);
				ASY::ScopePtr scope_pkg( symboltable->registerPackage( pkg->package_names ) );
				(*nItr) -> setSymbol( scope_pkg );
				constructSymbols( *nItr, scope_pkg, classname );
			}	break;

			case AST::Node::NodeType::T_IMPORT_STMT:
				break;
			default:
				constructSymbols( *nItr, symboltable, classname );
				break;
		}
	}
}
void SymbolTableConstructor:: linkClassInherit(
		tw::maple::as::ast::NodePtr node /* input program node */
		, tw::maple::as::symbol::ScopePtr symboltable
		, tw::maple::service::pass::cs::Phase2ContextPtr local_context
		)
{
//	std::cerr <<  " link class inherit iterate  " <<std::endl;
	BOOST_ASSERT( symboltable != NULL && "ph2: try to linke class inherit");
	namespace AST = tw::maple::as::ast;
	namespace CPP = tw::maple::backend::cpp::interpret;
	namespace ASY = tw::maple::as::symbol;

	if( node==NULL || node->node_childs.size() == 0 )
		return;

	for (std::vector< AST::NodePtr >::iterator nItr =
			node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {

		switch( (*nItr) -> nodeType() ) {
		case AST::Node::NodeType::T_IMPORT_STMT:
		{
			using tw::maple::service::pass::cs::ph2::Phase2_ImportStatement;
			AST::ImportStatementPtr ast_import = std::tr1::static_pointer_cast<AST::ImportStatement>(*nItr);
			Phase2_ImportStatement::pass( ast_import, symboltable, local_context );
		}
		break;
		case AST::Node::NodeType::T_CLASS_DEFINE:
		{
			ASY::SymbolPtr symbol = (*nItr)->getSymbol();
			ASY::ScopePtr class_symbol = STATIC_CAST( ASY::Scope, symbol );
			AST::ClassDefinitionPtr _class_define_ = STATIC_CAST( AST::ClassDefinition, *nItr);

			if( _class_define_->Inherits().size() != 0)
				{
				ASY::SymbolPtr inherit_symbol = local_context->find_symbol( _class_define_->Inherits()[0] );

				if( inherit_symbol == NULL )
					inherit_symbol = symboltable -> findSymbol( _class_define_->Inherits()[0] );
				if( inherit_symbol == NULL )
				{
					std::cerr << _class_define_->Inherits()[0] << " not found ph2"<<std::endl;
					exit(1);
				}
				ASY::ScopePtr inherit_scope = STATIC_CAST( ASY::Scope, inherit_symbol );
				class_symbol->setInhrit( inherit_scope.get() );
			}
			linkClassInherit( *nItr, class_symbol, local_context );

		}	break;
		case AST::Node::NodeType::T_PACKAGE_DEFINITION:
		{
			ASY::SymbolPtr symbol = (*nItr)->getSymbol();
			ASY::ScopePtr p_scope = STATIC_CAST( ASY::Scope, symbol );

			local_context->enterScope();
				linkClassInherit( *nItr, p_scope, local_context );
			local_context->leaveScope();
		}
			break;
		case AST::Node::NodeType::T_SUPER_INIT:
		{
		}
			break;
		default:
			linkClassInherit( *nItr, symboltable, local_context );
			break;
		}
	}

}
void SymbolTableConstructor::linkVariableType(
		tw::maple::as::ast::NodePtr node /* input program node */
		, tw::maple::as::symbol::ScopePtr symboltable
		, tw::maple::service::pass::cs::Phase2ContextPtr local_context
		)
{
	namespace AST = tw::maple::as::ast;
//	namespace CPP = tw::maple::backend::cpp::interpret;
	namespace ASY = tw::maple::as::symbol;

//	using tw::maple::cs::ph2;

	if( node == NULL || node->node_childs.size() == 0 )
		return;
	for (std::vector< AST::NodePtr >::iterator nItr =
			node->node_childs.begin(); nItr != node->node_childs.end(); nItr++)
	{
		using tw::maple::service::pass::cs::ph3::Phase3_ImportStatement;
		using tw::maple::service::pass::cs::ph3::Phase3_VariableDeclare;
		using tw::maple::service::pass::cs::ph3::Phase3_FunctionDefine;
		using tw::maple::service::pass::cs::ph3::Phase3_Parameter;
		using tw::maple::service::pass::cs::ph3::Phase3_ParameterRest;
		using tw::maple::service::pass::cs::ph3::Phase3_Identifier;

		ASY::SymbolPtr symbol = (*nItr)->getSymbol();

		if( (*nItr) -> nodeType()  == AST::Node::NodeType::T_IMPORT_STMT )
		{
			AST::ImportStatementPtr ast_import = std::tr1::static_pointer_cast<AST::ImportStatement>(*nItr);
			Phase3_ImportStatement::pass( ast_import, symboltable, local_context );
			continue;
		}

		if( (*nItr) -> nodeType()  == AST::Node::NodeType::T_CALL )
		{
			AST::CallPtr ast_import = std::tr1::static_pointer_cast<AST::Call>(*nItr);
			tw::maple::service::pass::cs::ph3::Phase3_CallExpression::pass( ast_import, symboltable, local_context );
			linkVariableType( *nItr, symboltable, local_context );/*link it's arguments*/
			continue;
		}
		if( (*nItr) -> is( AST::Node::NodeType::T_IDENTIFIER ) )
		{
			AST::IdentifierPtr ast_id = std::tr1::static_pointer_cast<AST::Identifier>(*nItr);
			tw::maple::service::pass::cs::ph3::Phase3_Identifier::pass( ast_id, symboltable, local_context );
			continue;
		} 
		if(  symbol && symbol->is( ASY::Symbol::T_VARIABLE) )
		{
			AST::VariableDeclarePtr ast_var = DYNA_CAST(AST::VariableDeclare, (*nItr) );
			AST::FunctionParameterItemPtr ast_param = DYNA_CAST(AST::FunctionParameterItem, (*nItr) );
			AST::FunctionParameterRestPtr ast_param_rest = DYNA_CAST(AST::FunctionParameterRest, (*nItr) );
			if( ast_var )
				Phase3_VariableDeclare::pass( ast_var, symbol, symboltable, local_context );
			else if( ast_param )
			{
				Phase3_Parameter::pass( ast_param, symbol, symboltable, local_context );
			}
			else if( ast_param_rest )
			{
				Phase3_ParameterRest::pass( ast_param_rest, symbol, symboltable, local_context );
			}
			else
			{
				std::cerr <<" unexpected error "<<__FILE__<<" "<<__LINE__<<std::endl;
				exit(1);
			}

			// TODO: TBR: don't need enter
			linkVariableType( *nItr, symboltable, local_context );
		} else if(  symbol && symbol->is( ASY::Symbol::T_SCOPE) )
		{
			ASY::ScopePtr p_scope = STATIC_CAST( ASY::Scope, symbol );
			switch( p_scope->getScopeType() ) {
			case ASY::Scope::T_FUNCTION:
			{
				AST::FunctionDefinitionPtr ast_func = STATIC_CAST( AST::FunctionDefinition, *nItr);
				ASY::FunctionPtr symbol_func = STATIC_CAST( ASY::Function, symbol);
				Phase3_FunctionDefine::pass( ast_func, symbol_func, symboltable, local_context );
			}
				local_context->enterScope();
					linkVariableType( *nItr, p_scope, local_context );
				local_context->leaveScope();
				break;
			case ASY::Scope::T_CLASS:
			{
				AST::ClassDefinitionPtr ast_class = STATIC_CAST( AST::ClassDefinition, *nItr);
				p_scope -> setIsIntrinsic( ast_class->isIntrinsic() ||  ast_class->isNativeClass() );

			}
				local_context->enterScope();
					linkVariableType( *nItr, p_scope, local_context );
				local_context->leaveScope();
				break;
			default:
				local_context->enterScope();
					linkVariableType( *nItr, p_scope, local_context );
				local_context->leaveScope();
				break;
			}
		} else
			linkVariableType( *nItr, symboltable, local_context );
	}
}

void SymbolTableConstructor::constructFunctionType(
		tw::maple::as::symbol::ScopePtr symboltable
		)
{
	namespace ASY = tw::maple::as::symbol;
	for (std::vector<ASY::SymbolPtr>::iterator child_itr = symboltable->m_childs.begin(), E = symboltable->m_childs.end()
			; child_itr != E; child_itr++)
	{

		if( ((*child_itr)->getSymbolProperties() & ASY::Symbol::T_SCOPE ) )
		{
			ASY::ScopePtr scope_ptr = DYNA_CAST( ASY::Scope, *child_itr);
			if( scope_ptr->is( ASY::Scope::T_FUNCTION) )
			{
				ASY::FunctionPtr func_ptr = DYNA_CAST( ASY::Function, scope_ptr);

				for (std::vector<ASY::SymbolPtr>::iterator var_itr = func_ptr->m_childs.begin(), E = func_ptr->m_childs.end()
							; var_itr != E; var_itr++)
				{
					if( ((*var_itr)->getSymbolProperties() & ASY::Symbol::T_PARAMETER ) )
					{
						ASY::VariablePtr variable_ptr = DYNA_CAST(ASY::Variable, *var_itr);
						func_ptr->addParameterType( variable_ptr->getTypeSymbol() );
					}
				}

			}
			else
				constructFunctionType( scope_ptr );
		}
	}
}


void SymbolTableConstructor::symbolTableAnalyze(
		tw::maple::as::ast::NodePtr node /* input program node */
		, tw::maple::as::symbol::ScopePtr symboltable
		)
{
	namespace AST = tw::maple::as::ast;
	namespace CPP = tw::maple::backend::cpp::interpret;
	namespace ASY = tw::maple::as::symbol;

	if( node == NULL || node->node_childs.size() == 0 )
		return;
	for (std::vector< AST::NodePtr >::iterator nItr =
			node->node_childs.begin(), E = node->node_childs.end();
			nItr != E; nItr++)
	{
		ASY::SymbolPtr symbol = (*nItr)->getSymbol();

		if (symbol && (symbol->is( ASY::Symbol::T_SCOPE) ))
		{
			ASY::ScopePtr p_scope = STATIC_CAST( ASY::Scope, symbol );
			switch (p_scope->getScopeType()) {
			case ASY::Scope::T_FUNCTION: {
				ASY::FunctionPtr p_func = STATIC_CAST( ASY::Function, symbol );
				if(p_func->isConstructor())
					p_func->getParent()->setNoConstrtuctor(false);
			}
			break;
			default:
				symbolTableAnalyze(*nItr, p_scope );
				break;
			}
		}
		else
			symbolTableAnalyze(*nItr, symboltable );
	}
}

void SymbolTableConstructor::superInitLinking(
			tw::maple::as::ast::NodePtr node /* input program node */
			, tw::maple::as::ast::FunctionDefinitionPtr function
			)
{
	namespace AST = tw::maple::as::ast;
	namespace ASY = tw::maple::as::symbol;

	for (std::vector< AST::NodePtr >::iterator nItr =
				node->node_childs.begin(), E = node->node_childs.end();
				nItr != E; nItr++)
	{
		ASY::SymbolPtr symbol = (*nItr)->getSymbol();

		if( (*nItr)->is(  AST::Node::NodeType::T_FUNCTION_DEFINITION ))
		{
			AST::FunctionDefinitionPtr function_ast = DYNA_CAST(AST::FunctionDefinition, *nItr);
			superInitLinking( *nItr, function_ast );
		}
		else if( (*nItr)->is( AST::Node::NodeType::T_SUPER_INIT ) )
		{
			if( function != NULL )
			{
				AST::SuperInitPtr super_init_ast = DYNA_CAST( AST::SuperInit, *nItr);
				function->mp_parent_initilizer = super_init_ast.get();
			}
		}
		else
			superInitLinking( *nItr, function );
	}
}
} } } }//pass.service.maple.tw

