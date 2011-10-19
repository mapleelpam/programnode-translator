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
 *     https://github.com/mapleelpam/programnode-translator          *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_VARIABLE_DECLARE_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_VARIABLE_DECLARE_H__

#include <global.h>
#include <as/ast/stmt/variable_declare.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <boost/foreach.hpp>
#include <as/symbol/variable.h>

namespace AST = ::tw::maple::as::ast;

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct VariableDeclare : public Interpreter, public TemplatePrinter
{   

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		namespace ASY = tw::maple::as::symbol;

		std::string result;

		AST::VariableDeclarePtr var = std::tr1::static_pointer_cast<AST::VariableDeclare>(node);
		ASY::VariablePtr symbol_var = STATIC_CAST( ASY::Variable, node->getSymbol() );
		ASY::SymbolPtr	symbol_type = symbol_var->getTypeSymbol();

		if( symbol_var->isClassMember()
			&& SVC_GLOBAL_SETTINGS -> define_only )
			return "";

		std::string str_var_type/* = invoke_type_mapper(  )*/;

		if( symbol_type->preferStack())
			str_var_type = symbol_type->getFQN_and_instanceName();
		else
			str_var_type = symbol_type->getFQN_and_mappedName() + SVC_GLOBAL_SETTINGS->pointer_pattern /* '*'or 'Ptr' */;

		std::string var_name = symbol_var->mappedName() == "" ? symbol_var->name() : symbol_var->mappedName();
		std::string var_attr = "";
		if( symbol_var -> isClassMember() )
			var_attr = var->is("public")?"public" : (var->is("private") ? "private" : "protected");

		ReturnValue var_init = "";

		if ( var->varInit() && symbol_var && !(symbol_var->isClassMember()) )
		{
			var_init = dispatchExpound( var->varInit(), symbol_table, ctx ).result;
			std::string str_type_cast = "";
			if (var_init.token_symbol != symbol_type) {
				if (symbol_type->preferStack())
					str_type_cast += "("
							+ symbol_type->getFQN_and_instanceName() + ")";
				else if (DYNA_CAST(ASY::VariantType, symbol_type ))
					str_type_cast += ""; // ignore
				else if ( symbol_type -> name() == "Function")
					str_type_cast += ""; // ignore
				else
					str_type_cast += "(" + symbol_type->getFQN_and_mappedName()
							+ "*)";
			}


			var_init.result = " = " + str_type_cast + var_init.result;
		}

		std::list<PatternPtr> patterns;
		patterns.push_back( PatternPtr( new Pattern("var_attribute", var_attr) ));
		patterns.push_back( PatternPtr( new Pattern("var_attribute_stmt", var_attr=="" ? "" : var_attr+": ") ));
		patterns.push_back( PatternPtr( new Pattern("var_type", str_var_type) ));
		patterns.push_back( PatternPtr( new Pattern("var_name", var_name) ));
		patterns.push_back( PatternPtr( new Pattern("var_init", var_init.result) ));
		patterns.push_back( PatternPtr( new Pattern("var_is_static", (var->is("static"))? "static ":"") ) );
		patterns.push_back( PatternPtr( new Pattern("var_is_const", (var->is("const"))? "const ":"") ) );


		COMPELETE_PATTERNS( patterns, ctx );

		return substitutePatterns( patterns );
	}

	VariableDeclare()
		: TemplatePrinter("VariableDeclare")
//		, m_pointer_pattern("*")
	{
		setTemplateString( "#(indent_tab)#(var_attribute_stmt)#(var_is_static)#(var_is_const)#(var_type) #(var_name) #(var_init);#(endl)" );
	}


	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
//		m_pointer_pattern = pt.get<std::string>(  configName()+".pointer_pattern", m_pointer_pattern);
		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
//		pt.put<std::string>( configName()+".pointer_pattern", m_pointer_pattern);
		return TemplatePrinter::writeConfig( pt );
	}
private:
//	std::string m_pointer_pattern;
};

};


} } } } 

#endif 
