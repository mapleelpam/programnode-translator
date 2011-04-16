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
#include <backend/cpp/prepend_data.h>
#include <service/ConfigService.h>
#include <service/ArgumentsService.h>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

//namespace po = boost::program_options;

class MajorClass : public tw::maple::service::ArgElemenRequest
{
public:
	MajorClass()
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
	        ;
			posOptionDesc.add("input", -1);
	}
	void pass(po::variables_map& args)
	{
		if (args.count("help") > 0) {
			SVC_ARGUMENTS->print_out_help();
			exit(1);
		}
		m_pnode_files = args["input"].as< std::vector<std::string > >();
		m_out_file_path  = args["output"].as<std::string> ();
	}

	void exec()
	{
		// File Open
		std::vector< tw::maple::as::ast::ProgramPtr > pnode_list;
		for (std::vector<std::string>::iterator fileItr = m_pnode_files.begin()
				; fileItr != m_pnode_files.end(); fileItr++)
		{
			tw::maple::as::ast::ProgramPtr  proot = tw::maple::PNodeReader::open( *fileItr );
			pnode_list . push_back( proot );
		}

		{
			namespace INTERPRET = tw::maple::backend::cpp::interpret;

			tw::maple::backend::cpp::Context context;
			context.ofs_stream.open( m_out_file_path.c_str() );
			// Interpret/Explain - Invoke Back-end Stream Out

			m_prepend.execute( context.ofs_stream );


			for (std::vector<tw::maple::as::ast::ProgramPtr>::iterator
					nodeItr = pnode_list.begin(); nodeItr != pnode_list.end(); nodeItr++) {
				context.ofs_stream << INTERPRET::dispatchExpound(*nodeItr, &context);
			}

			context.ofs_stream.close();
		}
	}
private:
	std::vector<std::string> m_pnode_files;
	std::string m_out_file_path;
	tw::maple::backend::cpp::PrependData m_prepend;

};

int main(int argc, char **argv)
{
	SVC_CONFIG;

	MajorClass  major;

	try {
		SVC_ARGUMENTS->parse(argc,argv);
	} catch (std::exception &e) {
		std::cerr << "Unknown Arguments " << e.what()<< std::endl;
		SVC_ARGUMENTS->print_out_help();
		exit(1);
	} catch (...) {
		std::cout << "ERROR " << std::endl;
		std::cout << "ERROR " << "Error while parsing zcc-flex options Exiting" << std::endl;
		exit(0);
	}

	major.exec();

    return 0;
}
