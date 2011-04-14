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

#ifndef __TW_MAPLE_SERVICE_CONFIGSERVICE_H__
#define __TW_MAPLE_SERVICE_CONFIGSERVICE_H__

#include <map>
#include <list>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>


namespace tw { namespace maple { namespace service {


class ConfigRequest
{
public:
	ConfigRequest();
	virtual bool readConfig( boost::property_tree::ptree& ) = 0;
	virtual bool writeConfig( boost::property_tree::ptree& ) = 0;
};

struct ConfigService
{
	void registerElement( ConfigRequest* creq )
	{
		m_config_elements.push_back( creq );
	}

	void load( const std::string& filename )
	{
		boost::property_tree::ptree _ptree;
		read_info( filename, _ptree );

		for( std::list<ConfigRequest*>::iterator citr = m_config_elements.begin();
				citr != m_config_elements.end() ; citr ++ )
		{
			(*citr)->readConfig( _ptree );
		}
	}

	void save( const std::string& filename )
	{
		boost::property_tree::ptree _ptree;
//		read_info( filename, _ptree );

		for( std::list<ConfigRequest*>::iterator citr = m_config_elements.begin();
				citr != m_config_elements.end() ; citr ++ )
		{
			(*citr)->writeConfig( _ptree );
		}
		write_info( filename, _ptree);
	}

private:
	std::list<ConfigRequest*> m_config_elements;

public:
	static ConfigService* instance()	{
		static ConfigService* _instance;

		if( _instance == NULL )
			_instance = new ConfigService();
		return _instance;
	}

};

#define SVC_CONFIG tw::maple::service::ConfigService::instance()

} } }

#endif
