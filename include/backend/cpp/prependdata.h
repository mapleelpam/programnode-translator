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


#ifndef __TW_MAPLE_BACKEDN_PREPEND_DATA_H_
#define __TW_MAPLE_BACKEDN_PREPEND_DATA_H_

#include <global.h>
#include <service/configservice.h>

namespace tw { namespace maple { namespace backend { namespace cpp {

struct PrependData : public tw::maple::service::ConfigRequest
{
	PrependData();

	void execute( std::ofstream& os );

private:
	std::string PrefixWarning;
	std::string LicenseDeclare;
	std::string IncludeHeaders;
	std::string Authors;
	bool		ShowGeneratedTime;
	std::string _config_name;

protected:
	virtual bool readConfig( boost::property_tree::ptree& pt ); 		//inherit::ConfigRequest
	virtual bool writeConfig( boost::property_tree::ptree& pt );		//inherit::ConfigRequest
};

} } } }

#endif 
