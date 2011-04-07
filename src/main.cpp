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
// Copyright 2010 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#include <iostream>
#include <fstream>

#include "AstDumper.h"  
#include "pnodehandler.h" 
#include "pnode_reader.h"

#include <backend/cpp/interpret/interpreter.h>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

namespace po = boost::program_options;

int main(int argc, char **argv)
{

	po::options_description 			m_options_desc;
	po::positional_options_description	m_positional_options_desc;

	m_options_desc.add_options()
	    ("help,h",    "this help message")
	    ("output,o",    po::value<std::string>(), "outputfiles")
	    ("input,i",    po::value<std::vector<std::string> >(), "inputfiles")
    ;
	m_positional_options_desc.add("input", -1);


	po::variables_map args;
	po::store(po::command_line_parser(argc, argv).options(m_options_desc).positional(m_positional_options_desc).run(), args);
	po::notify(args);


	if (args.count("help") > 0)
	{
		std::cout << m_options_desc << "\n";
		return 0;
	}

	std::vector<std::string> m_pnode_files = args["input"].as< std::vector<std::string > >();
	std::string out_file_path  = args["output"].as<std::string> ();


	// File Open
	std::vector< std::tr1::shared_ptr< tw::maple::as::ast::Program > > pnode_list;
	for (std::vector<std::string>::iterator fileItr = m_pnode_files.begin()
			; fileItr != m_pnode_files.end(); fileItr++)
	{
		std::tr1::shared_ptr< tw::maple::as::ast::Program > proot = tw::maple::PNodeReader::open( *fileItr );
		pnode_list . push_back( proot );
	}

	{
		namespace INTERPRET = tw::maple::backend::cpp::interpret;

//		std::ofstream os_file;
		tw::maple::backend::cpp::Context context;
		context.ofs_stream.open( out_file_path.c_str() );
		// Interpret/Explain - Invoke Back-end Stream Out

		for (std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Program> >::iterator
				nodeItr = pnode_list.begin(); nodeItr != pnode_list.end(); nodeItr++) {
			INTERPRET::dispatchDo(*nodeItr, &context);
		}

		context.ofs_stream.close();
	}

    return 0;
}
