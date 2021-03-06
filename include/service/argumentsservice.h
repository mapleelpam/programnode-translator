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

#ifndef __TW_MAPLE_SERVICE_ARGUMENTS_SERVICE_H__
#define __TW_MAPLE_SERVICE_ARGUMENTS_SERVICE_H__

#include <map>
#include <iostream>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

namespace po = boost::program_options;

namespace tw { namespace maple { namespace service {

//struct OptionElement;

struct ArgElemenRequest
{
	virtual void init(po::options_description&, po::positional_options_description&) = 0;
	virtual void pass(po::variables_map&) = 0 ;

};

struct ArgumentService
{
	std::vector< ArgElemenRequest* > m_elements;

	void parse(int argc, char** argv)
	{
		po::variables_map args;
		po::store(po::command_line_parser(argc, argv).options(m_args_desc).positional(m_positional_argumnets_desc).run(), args);
		po::notify(args);

		for(std::vector<ArgElemenRequest*>::iterator itr = m_argument_elements.begin();
				itr != m_argument_elements.end() ; itr ++ )
		{
			(*itr)->pass(args);
		}
	}

	void print_out_help()
	{
		std::cout << m_args_desc << "\n";
	}

	static ArgumentService* instance()
	{
		static ArgumentService* _instance = NULL;
		if( _instance == NULL)
			_instance = new ArgumentService();
		return _instance;
	}
public:
	void registerPass( ArgElemenRequest* opt )
	{
		m_elements.push_back( opt );
		opt->init(m_args_desc, m_positional_argumnets_desc);

		m_argument_elements.push_back( opt );
	}
protected:
	// collect stages options
	po::options_description m_args_desc;
	po::positional_options_description m_positional_argumnets_desc;
	std::vector<ArgElemenRequest*> m_argument_elements;
};

#define SVC_ARGUMENTS (tw::maple::service::ArgumentService::instance())
} } }

#endif
