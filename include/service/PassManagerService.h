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

#ifndef __TW_MAPLE_SERVICE_PASS_MANAGER_SVC_H__
#define __TW_MAPLE_SERVICE_PASS_MANAGER_SVC_H__

#include <map>
#include <list>
#include <service/ArgumentsService.h>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ptree_fwd.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <service/pass/ProgramNodeLoader.h>
#include <service/pass/BackendManager.h>
#include <service/pass/SymbolTableConstructor.h>
#include <as/symbol/Debug.h>

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
		if (args.count("help") > 0) {
			SVC_ARGUMENTS->print_out_help();
			exit(1);
		}
		if (args.count("symbol") > 0) {
			m_dump_symbol_table_only = true;
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
		tw::maple::as::symbol::ScopePtr				symbol_table = tw::maple::as::symbol::Scope::rootScope(); // Initialize is null

		tw::maple::service::pass::ProgramNodeLoader::exec( m_pnode_files, pnode_list/*out*/ );

		tw::maple::service::pass::SymbolTableConstructor::exec( pnode_list, symbol_table /* out */ );
		if( m_dump_symbol_table_only ) {
			std::ofstream ofs;
			if( m_out_file_path != "" )
				ofs.open(m_out_file_path.c_str());
			tw::maple::as::symbol::Debug::dump_symboltable( symbol_table, ofs );
			exit(0);
		}

		tw::maple::service::pass::BackendManager::exec( pnode_list, m_prepend,  m_out_file_path /* out */ );

	}
private:
	std::vector<std::string> m_pnode_files;
	std::string m_out_file_path;
	bool 		m_dump_symbol_table_only;
	tw::maple::backend::cpp::PrependData m_prepend;

};

} } }

#endif
