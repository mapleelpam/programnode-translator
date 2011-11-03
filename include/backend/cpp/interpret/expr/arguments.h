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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_ARGUMENTS_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_ARGUMENTS_H_

#include <as/ast/expr/arguments.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/varianttype.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret { 

// Abstract
struct Arguments : public Interpreter, public TemplatePrinter
{   
	virtual ReturnValue expound(
			::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			)
	{
		namespace AST = ::tw::maple::as::ast;
		namespace ASY = ::tw::maple::as::symbol;

		ReturnValue result = "";


		int counter = 0;
		for( std::vector<tw::maple::as::ast::NodePtr>::iterator
				nItr = node->node_childs.begin(), E = node->node_childs.end()
				; nItr != E ; nItr ++, counter ++ )
		{
			ASY::SymbolPtr arg_type;
			if( ctx.callee_type && (ctx.callee_type->m_types.size() > counter+1))
			{
				arg_type = ctx.callee_type->m_types[counter+1];
			}

			std::string prefix = (counter == 0? std::string(""):std::string(", "));
			ReturnValue arg_result = dispatchExpound(*nItr, symbol_table, ctx);
			if( arg_type && arg_type != arg_result.token_symbol )
			{
				if( arg_result.token_symbol )
				{
					std::cerr <<" argument type = "<<arg_result.token_symbol->toString()<<std::endl;
				}
				if( arg_type->preferStack() )
					prefix += "("+arg_type->getFQN_and_instanceName()+")";
				else if( DYNA_CAST(ASY::VariantType, arg_type ) )
					prefix += ""; // ignore
				else if( arg_type -> name() == "Function" )
					prefix += ""; // ignore
				else
					prefix += "("+arg_type->getFQN_and_mappedName() + "*)"+m_default_pcast_postfix;
			}

			result +=  prefix + arg_result.result;
		}

		return result;
	}
	static ReturnValue special_expound_type2(
			::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			)
	{

		namespace AST = ::tw::maple::as::ast;
		namespace ASY = ::tw::maple::as::symbol;

		ReturnValue result = "";


		int counter = 0;
		for( std::vector<tw::maple::as::ast::NodePtr>::iterator
				nItr = node->node_childs.begin(), E = node->node_childs.end()
				; nItr != E ; nItr ++, counter ++ )
		{
			ASY::SymbolPtr arg_type;
			if( ctx.callee_type && (ctx.callee_type->m_types.size() > counter+1))
				arg_type = ctx.callee_type->m_types[counter+1];

			std::string prefix = (counter == 0? std::string(""):std::string(", "));
			ReturnValue one_arg_result = dispatchExpound(*nItr, symbol_table, ctx);
			std::string s_enum;

			if(  one_arg_result.token_symbol )
			{
				if( getTypeString(one_arg_result.token_symbol) == "String" || getTypeString(one_arg_result.token_symbol) == "::NativeString")
					s_enum = " TYPE_STRING, ";
				else if( getTypeString(one_arg_result.token_symbol) == "Object" || getTypeString(one_arg_result.token_symbol) == "::ObjectPtr")
					s_enum = " TYPE_OBJECT, ";
				else if( getTypeString(one_arg_result.token_symbol) == "Int" || getTypeString(one_arg_result.token_symbol) == "NativeInt")
					s_enum = " TYPE_INT, ";
				else if( getTypeString(one_arg_result.token_symbol) == "UInt")
					s_enum = " TYPE_UINT, ";
				else if( getTypeString(one_arg_result.token_symbol) == "Boolean")
					s_enum = " TYPE_BOOLEAN, ";
				else if( getTypeString(one_arg_result.token_symbol) == "Number")
					s_enum = " TYPE_NUMBER, ";
				else if( getTypeString(one_arg_result.token_symbol) == "Function")
					s_enum = " TYPE_FUNCTION, ";
				else
					s_enum = " /*can't resolved  "+getTypeString(one_arg_result.token_symbol)+"*/, ";
			}
			else
			{
//				std::cerr <<" empty token symbol "<<__FILE__<<":"<<__LINE__<<"contact maple !!!! blahblahblah"<<std::endl;
//				exit(1);
				s_enum = " TYPE_OBJECT, ";
			}
//			if( arg_type && arg_type != arg_result.token_symbol )
//			{
//				if( arg_result.token_symbol )
//				{
//					std::cerr <<" argument type = "<<arg_result.token_symbol->toString()<<std::endl;
//				}
//				if( arg_type->preferStack() )
//					prefix += "("+arg_type->getFQN_and_instanceName()+")";
//				else if( DYNA_CAST(ASY::VariantType, arg_type ) )
//					prefix += ""; // ignore
//				else if( arg_type -> name() == "Function" )
//					prefix += ""; // ignore
//				else
//					prefix += "("+arg_type->getFQN_and_mappedName() + "*)"+m_default_pcast_postfix;
//			}

			result +=  prefix +s_enum+one_arg_result.result;
		}

		return result;
	}
	Arguments()
		: TemplatePrinter("Arguments")
		, m_default_pcast_postfix("")
	{
		
	}
private:
	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_default_pcast_postfix = pt.get<std::string>( configName()+".pcast_postfix", m_default_pcast_postfix );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".pcast_postfix", m_default_pcast_postfix );
	}

	std::string m_default_pcast_postfix;
};

} } } } }

#endif 
