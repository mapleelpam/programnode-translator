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

#include <service/configservice.h>

namespace tw { namespace maple { namespace service {



ConfigRequest::ConfigRequest( std::string n )
	: _name(n)
{
	SVC_CONFIG->registerElement(this);
}

void ConfigService::loadConfig( const std::string& filename )
{
	boost::property_tree::ptree _ptree;
	read_info( filename, _ptree );

	for( std::list<ConfigRequest*>::iterator citr = m_config_elements.begin();
			citr != m_config_elements.end() ; citr ++ )	{
		(*citr)->readConfig( _ptree );
	}
}

void ConfigService::saveConfig( const std::string& filename )
{
	boost::property_tree::ptree _ptree;
	for( std::list<ConfigRequest*>::iterator citr = m_config_elements.begin();
			citr != m_config_elements.end() ; citr ++ )	{
		(*citr)->writeConfig( _ptree );
	}
	//write_xml( filename, _ptree);
	write_info( filename, _ptree);
}

} /*service*/ } /*maple*/ } /*tw*/
