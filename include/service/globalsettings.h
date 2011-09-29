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

#ifndef __TW_MAPLE_SERVICE_GLOBAL_SETTINGS_H__
#define __TW_MAPLE_SERVICE_GLOBAL_SETTINGS_H__

#include <global.h>
#include <service/argumentsservice.h>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ptree_fwd.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>


namespace tw { namespace maple { namespace service {


struct GlobalSettings  : public ArgElemenRequest
{
	void init(po::options_description& optionDesc, po::positional_options_description& posOptionDesc)
	{
			optionDesc.add_options()
				("debug","debug message")
	    	    ("define", "define only (header)")
	    	    ("declare", "declare only (source)")
	    	    ("predef", "pre deinfe only (declare name only)")
	    	    ("prepend_codes", po::value<std::string>(), "prepend cpp codes before reall translate")
	        ;
	}

	void pass(po::variables_map& args)
	{
		if (args.count("define") > 0) {
			define_only = true;
		}
		if (args.count("declare") > 0) {
			declare_only = true;
		}
		if (args.count("predef") > 0) {
			predef_only = true;
		}
		if (args.count("prepend_codes") > 0) {
			prepend_codes = args["prepend_codes"].as<std::string>();
		}
		if (args.count("debug"))
			show_debug_message = true;
	}


private:
	GlobalSettings()
		: define_only(false)
		, declare_only(false)
		, predef_only(false)
		, prepend_codes("")
		, show_debug_message(false)
	{
		SVC_ARGUMENTS->registerPass(this);
	}



public:
	static GlobalSettings* instance()	{
		static GlobalSettings* _instance;

		if( _instance == NULL )
			_instance = new GlobalSettings();
		return _instance;
	}

	bool		define_only;
	bool		declare_only;
	bool		predef_only;
	std::string	prepend_codes;

	bool		show_debug_message;
};

#define SVC_GLOBAL_SETTINGS tw::maple::service::GlobalSettings::instance()

} } }

#endif
