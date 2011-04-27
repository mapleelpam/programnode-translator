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


#ifndef __TW_MAPLE_AS_SYMBOL_SYMBOLTABLE_H__
#define __TW_MAPLE_AS_SYMBOL_SYMBOLTABLE_H__

#include "global.h"
#include <boost/assert.hpp>
#include <as/symbol/Symbol.h>
#include <as/symbol/Scope.h>
#include <as/symbol/action/Registrable.h>
#include <as/symbol/PrimitiveType.h>
#include <service/ConfigService.h>
#include <boost/foreach.hpp>

namespace tw { namespace maple { namespace as { namespace symbol {

typedef std::map< std::string, bool> PrimitiveMap;

struct SymbolTable : public tw::maple::service::ConfigRequest
{
	ScopePtr getRoot() {
		ScopePtr root(new Scope("root", Scope::T_PROGRAM_ROOT));


		for( PrimitiveMap::iterator sitr = m_primitive_types.begin(); sitr != m_primitive_types.end() ; sitr ++ )
		{
			root->addChild(  TypePtr(new PrimitiveType((*sitr).first, (*sitr).second) ) );
		}

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
	{
		m_primitive_types["int"] = false;
		m_primitive_types["float"] = false;
	}
	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
//		if(0)
		{
			std::string str_config_primitive = "primitive_types.";
			BOOST_FOREACH(boost::property_tree::ptree::value_type &pitr, pt.get_child( str_config_primitive ))
			{
				std::cerr<< "     load !!     "<<pitr.first<<std::endl;

				m_primitive_types[ pitr.first] = (pitr.second.get<std::string>( "" ) == "false");
			}
		}
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		std::string str_config_primitive = "primitive_types.";
		for( PrimitiveMap::iterator sitr = m_primitive_types.begin(); sitr != m_primitive_types.end() ; sitr ++ )
		{
			pt.put( str_config_primitive+(*sitr).first, int( (*sitr).second) );
		}
	}

	PrimitiveMap m_primitive_types;
};

#define SVC_SYMBOLTABLE (tw::maple::as::symbol::SymbolTable::instance())


}}}}//tw/maple/as/symbol

#endif


