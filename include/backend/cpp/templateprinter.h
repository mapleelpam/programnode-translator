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


#ifndef __TW_MAPLE_BACKEDN_TEMPLATE_PRINTER_H__
#define __TW_MAPLE_BACKEDN_TEMPLATE_PRINTER_H__

#include <fstream>
#include <list>
#include <tr1/memory>
#include <service/configservice.h>

namespace tw { namespace maple { namespace backend { namespace cpp {


struct Pattern
{
	Pattern( std::string p, std::string c) : pattern(p), content(c) {}
	std::string pattern;
	std::string content;
};

typedef std::tr1::shared_ptr<Pattern>    PatternPtr;

class TemplatePrinter : public tw::maple::service::ConfigRequest
{
public:
	std::string substitutePatterns( std::string& in, std::list<PatternPtr>& patterns)
	{
		std::string out = in;
		for( std::list<PatternPtr>::iterator itr = patterns.begin() ; itr != patterns.end() ; itr ++)
			out = replace( out, "#("+(*itr)->pattern+")", (*itr)->content );

		return out;
	}
	std::string substitutePatterns( std::list<PatternPtr>& patterns)
	{
		return substitutePatterns( _template, patterns );
	}


	virtual bool readConfig( boost::property_tree::ptree& pt )	//inherit::ConfigRequest
	{
		_template = pt.get<std::string>( _config_name+".template", _template);
		return true;
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )	//inherit::ConfigRequest
	{
		pt.put<std::string>( _config_name+".template", _template);
		return true;
	}

protected:
	std::string  configName(){	return _config_name;	}
	void setTemplateString( std::string str ) {	_template = str;	}

	TemplatePrinter( std::string n)
	: tw::maple::service::ConfigRequest("TemplatePrinter."+n), _config_name(n)
	{}
private:
	std::string _config_name;
	std::string _template;
};

} } } }

#endif 
