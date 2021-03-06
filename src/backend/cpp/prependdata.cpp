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

#include <backend/cpp/prependdata.h>

namespace tw { namespace maple { namespace backend { namespace cpp {

PrependData::PrependData()
	: tw::maple::service::ConfigRequest("PrependData")
	, Authors( "Unknown" )
	, _config_name("prepend_data")
	, ShowGeneratedTime(false)
{
	PrefixWarning = "/* THIS FILE IS GENREATED BY pn-translater, you should not modify this file.*/";
	LicenseDeclare = "/* NO LICNESE DECLARE */";
	IncludeHeaders = "#include <stdio.h>\n";
}


void PrependData::execute( std::ofstream& os )
{
	os << PrefixWarning << std::endl;
	os << LicenseDeclare << std::endl;
	os << "// Auther : "<< Authors << std::endl;
	os << IncludeHeaders << std::endl;

	//TODO: generated time
}

bool PrependData::readConfig( boost::property_tree::ptree& pt )
{
	PrefixWarning = pt.get<std::string>( _config_name+".prefix_warning", PrefixWarning);
	LicenseDeclare = pt.get<std::string>( _config_name+".license_declare", LicenseDeclare);
	Authors = pt.get<std::string>( _config_name+".authors", Authors);
	IncludeHeaders = pt.get<std::string>( _config_name+".headers", IncludeHeaders);
	return true;
}
bool PrependData::writeConfig( boost::property_tree::ptree& pt )
{
	pt.put<std::string>( _config_name+".prefix_warning", PrefixWarning);
	pt.put<std::string>( _config_name+".license_declare", LicenseDeclare);
	pt.put<std::string>( _config_name+".authors", Authors);
	pt.put<std::string>( _config_name+".headers", IncludeHeaders);
	return true;
}

} /*cpp*/ } /*backend*/ } /*maple*/ } /*tw*/

