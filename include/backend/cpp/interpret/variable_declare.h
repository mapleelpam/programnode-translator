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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_VARIABLE_DECLARE_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_VARIABLE_DECLARE_H__

#include <global.h>
#include <as/ast/variable_declare.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <boost/foreach.hpp>
#include <as/symbol/variable.h>

namespace AST = ::tw::maple::as::ast;

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

typedef std::map< std::string,std::string > StringMap;

struct VariableDeclare : public Interpreter, public TemplatePrinter
{   

	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx)
	{

		namespace ASY = tw::maple::as::symbol;

		std::string result;

		AST::VariableDeclarePtr var = std::tr1::static_pointer_cast<AST::VariableDeclare>(node);

//		std::string var_type = var->VariableType[0];
		std::string var_type = "";
		if( (var->VariableType).size() == 1 )
		{
			var_type = invoke_type_mapper( (var->VariableType)[0] );
		}
		else
		{

			var_type += (var->VariableType)[0];
			for( int idx = 1 ; idx < var->VariableType.size()  ; idx ++ )
			{
				var_type += "::" + (var->VariableType)[idx];
			}
			var_type = invoke_type_mapper( var_type );
		}

		ASY::VariablePtr symbol_var = STATIC_CAST( ASY::Variable, node->getSymbol() );

		std::string var_name = var->VariableName;
		std::string var_attr = var->isPublic()?"public:":"";
		std::string var_init = "";

		if ( var->varInit() && symbol_var && !(symbol_var->isClassMember()) )
	 		var_init = " = " + dispatchExpound( var->varInit(), symbol_table, ctx );

		std::list<PatternPtr> patterns;
		patterns.push_back( PatternPtr( new Pattern("var_attribute", var_attr) ));
		patterns.push_back( PatternPtr( new Pattern("var_type", var_type) ));
		patterns.push_back( PatternPtr( new Pattern("var_name", var_name) ));
		patterns.push_back( PatternPtr( new Pattern("var_init", var_init) ));
		patterns.push_back( PatternPtr( new Pattern("var_is_static", (var->isStatic())? "static ":"") ) );
		patterns.push_back( PatternPtr( new Pattern("endl", ctx->endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx->indent()) ));

		return substitutePatterns( patterns );
	}

	VariableDeclare()
		: TemplatePrinter("VariableDeclare")
		, _default_type_mapper("#(type_name)*")
	{
		_primitive_type_mapper[ "int" ] = "int";
		_primitive_type_mapper[ "float" ] = "float";

		setTemplateString( "#(var_attribute)#(endl)#(indent_tab)#(var_is_static)#(var_type) #(var_name) #(var_init);#(endl)" );
//		setTemplateString( "#indent_tab##var_type# #var_name#;#endl#" );
	}


	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		{
			std::string str_config_primitive = configName() +".type.mapper.";
			BOOST_FOREACH(boost::property_tree::ptree::value_type &pitr, pt.get_child( str_config_primitive ))
				_primitive_type_mapper[ pitr.first] = pitr.second.get<std::string>( "");
		}

		_default_type_mapper = pt.get<std::string>(  configName()+".type.mapper.__DEFAULT__", _default_type_mapper);

		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{

		std::string str_config_primitive = configName() +".type.mapper.";
		for( StringMap::iterator sitr = _primitive_type_mapper.begin(); sitr != _primitive_type_mapper.end() ; sitr ++ )
		{
			pt.put( str_config_primitive+(*sitr).first,(*sitr).second);
		}

		pt.put<std::string>( configName()+".type.mapper.__DEFAULT__", _default_type_mapper);

		return TemplatePrinter::writeConfig( pt );
	}
private:
	std::string invoke_type_mapper( const std::string type_name )
	{
		StringMap::iterator sitr = _primitive_type_mapper.find( type_name );
		if( sitr == _primitive_type_mapper.end() ){
			return _replace_string( _default_type_mapper, "#(type_name)", type_name);
		} else {
			return sitr -> second;
		}
	}

	StringMap _primitive_type_mapper;
	std::string _default_type_mapper;
};

};


} } } } 

#endif 
