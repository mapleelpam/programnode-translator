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

#ifndef __TW_MAPLE_SERVICE_PASS_MANAGER_SVC_H__
#define __TW_MAPLE_SERVICE_PASS_MANAGER_SVC_H__

#include <global.h>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ptree_fwd.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <service/pass/programnodeloader.h>
#include <service/pass/backendmanager.h>
#include <service/pass/symboltableconstructor.h>
#include <service/argumentsservice.h>
#include <service/globalsettings.h>
#include <as/symbol/action/debug.h>
#include <as/symbol/action/predef.h>
#include <as/symbol/symboltable.h>


namespace tw { namespace maple { namespace service {

class PassManagerService : public tw::maple::service::ArgElemenRequest
{
public:
	PassManagerService()
		: m_dump_symbol_table_only(false)
	{
		SVC_ARGUMENTS->registerPass(this);
		namespace INTERPRET = tw::maple::backend::cpp::interpret;
		INTERPRET::initializeInterpreters();
	}
	void init(po::options_description& optionDesc, po::positional_options_description& posOptionDesc)
	{
			optionDesc.add_options()
	    	    ("help,h",    "this help message")
	    	    ("output,o",    po::value<std::string>(), "outputfiles")
	    	    ("input,i",    po::value<std::vector<std::string> >(), "inputfiles")
	    	    ("symbol",   " dump symbol table only (and exit)")
	        ;
			posOptionDesc.add("input", -1);
	}
	void pass(po::variables_map& args)
	{
//		fprintf(stderr," in psm \n");
		if (args.count("help") > 0) {
			SVC_ARGUMENTS->print_out_help();
			exit(1);
		}
		if (args.count("symbol") > 0) {
			m_dump_symbol_table_only = true;
			fprintf(stderr," dump symobl table only\n");
		}
		m_pnode_files = args["input"].as< std::vector<std::string > >();
		if (args.count("output") > 0) {
			m_out_file_path  = args["output"].as<std::string> ();
		}
	}

	void exec()
	{
		// File Open
		std::vector< tw::maple::as::ast::ProgramPtr > pnode_list;
		tw::maple::as::symbol::ScopePtr				symbol_table = SVC_SYMBOLTABLE->getRoot() ; // Initialize is null

		tw::maple::service::pass::ProgramNodeLoader::exec( m_pnode_files, pnode_list/*out*/ );

		tw::maple::service::pass::SymbolTableConstructor::exec( pnode_list, symbol_table /* out */ );

		if( m_dump_symbol_table_only ) {
			std::ofstream ofs;
			if( m_out_file_path != "" )
				ofs.open(m_out_file_path.c_str());
			tw::maple::as::symbol::Debug::dump_symboltable( symbol_table, ofs );
			exit(0);
		}
		if( SVC_GLOBAL_SETTINGS->predef_only ) {
			std::ofstream ofs;
			if (m_out_file_path != "")
				ofs.open(m_out_file_path.c_str());
			tw::maple::as::symbol::PreDefine::dump_symboltable(symbol_table, ofs);
			exit(0);
		}

		tw::maple::service::pass::BackendManager::exec( pnode_list, symbol_table, m_prepend,  m_out_file_path /* out */ );


	}
private:
	std::vector<std::string> m_pnode_files;
	std::string m_out_file_path;
	bool 		m_dump_symbol_table_only;
	tw::maple::backend::cpp::PrependData m_prepend;

};

} } }

#endif
