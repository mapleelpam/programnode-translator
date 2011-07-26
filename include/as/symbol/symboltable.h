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

#ifndef __TW_MAPLE_AS_SYMBOL_SYMBOLTABLE_H__
#define __TW_MAPLE_AS_SYMBOL_SYMBOLTABLE_H__

#include "global.h"
#include <as/symbol/symbol.h>
#include <as/symbol/scope.h>
#include <as/symbol/action/registrable.h>
#include <as/symbol/primitivetype.h>
#include <as/symbol/varianttype.h>
#include <service/configservice.h>
#include <boost/foreach.hpp>

namespace tw { namespace maple { namespace as { namespace symbol {

//typedef std::map< std::string, bool> PrimitiveMap;
typedef std::map< std::string,std::string > StringMap;

struct SymbolTable : public tw::maple::service::ConfigRequest
{
	ScopePtr getRoot() {
		ScopePtr root(new Scope("root", Scope::T_PROGRAM_ROOT));
		for( StringMap::iterator sitr = _primitive_type_mapper.begin(); sitr != _primitive_type_mapper.end() ; sitr ++ )
			root->addChild(  TypePtr(new PrimitiveType((*sitr).first, (*sitr).second) ) );
		root->addChild( VariantTypePtr( new VariantType()) );

		return root;
	}


	static SymbolTable* instance()
	{
		static SymbolTable* _instance = NULL;
		if( _instance == NULL)
			_instance = new SymbolTable();
		return _instance;
	}

	SymbolTable()
		: m_pattern_of_star("Object")
	{
		_primitive_type_mapper[ "int" ] = "int";
		_primitive_type_mapper[ "float" ] = "float";
		_primitive_type_mapper[ "Boolean" ] = "bool";
		_primitive_type_mapper[ "Void" ] = "void";
	}
	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		{
			std::string str_config_primitive = "primitive_types.mapper.";
			BOOST_FOREACH(boost::property_tree::ptree::value_type &pitr, pt.get_child( str_config_primitive ))
				_primitive_type_mapper[ pitr.first] = pitr.second.get<std::string>( "");
		}

		m_pattern_of_star = pt.get( "symboltable.pattern_of_star",  m_pattern_of_star );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		std::string str_config_primitive = "primitive_types.mapper.";
		for( StringMap::iterator sitr = _primitive_type_mapper.begin(); sitr != _primitive_type_mapper.end() ; sitr ++ )
		{
					pt.put( str_config_primitive+(*sitr).first,(*sitr).second);
		}

		pt.put( "symboltable.pattern_of_star",  m_pattern_of_star );
	}

	StringMap _primitive_type_mapper;
	std::string		m_pattern_of_star;
};

#define SVC_SYMBOLTABLE (tw::maple::as::symbol::SymbolTable::instance())


}}}}//tw/maple/as/symbol

#endif


