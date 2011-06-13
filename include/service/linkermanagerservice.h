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

#ifndef __TW_MAPLE_SERVICE_LINKER_MANAGER_SVC_H__
#define __TW_MAPLE_SERVICE_LINKER_MANAGER_SVC_H__

#include <global.h>
#include <service/linker/linker.h>
#include <service/argumentsservice.h>

#include <protocol/TJSONProtocol.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TSimpleFileTransport.h>
#include <server/TSimpleServer.h>

namespace tw { namespace maple { namespace service {

class LinkerManagerService : public tw::maple::service::ArgElemenRequest
{

public:
	LinkerManagerService()
	{
		SVC_ARGUMENTS->registerPass(this);
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
		if (args.count("output") > 0) {
			m_out_file_path  = args["output"].as<std::string> ();
		}
	}

	void exec()
	{
        boost::shared_ptr<tw::maple::service::linker::Linker> TheLinker( new tw::maple::service::linker::Linker(m_out_file_path) );
        TheLinker->pm_module->startProgram( "0.0.1", 1);

		for (std::vector<std::string>::iterator fileItr = m_pnode_files.begin()
						; fileItr != m_pnode_files.end(); fileItr++)
		{

	        boost::shared_ptr<apache::thrift::transport::TSimpleFileTransport> transport(new apache::thrift::transport::TSimpleFileTransport(*fileItr,true,true));
	        boost::shared_ptr<tw::maple::generated::AstDumperProcessor> processor( new tw::maple::generated::AstDumperProcessor( TheLinker ) );

	        transport->open();
	        boost::shared_ptr<apache::thrift::protocol::TProtocol> io(new apache::thrift::protocol::TJSONProtocol(transport));

	        try {
	            while( true )
	                processor->process( io, io, NULL );
	        } catch (apache::thrift::transport::TTransportException ex ) {
	            std::cout << "handler: " << ex.what()<<std::endl;
	        }

	        transport->close();
		}

		TheLinker->pm_module->endProgram();
	}
private:
	std::vector<std::string> m_pnode_files;
	std::string m_out_file_path;
};

} } }

#endif //__TW_MAPLE_SERVICE_LINKER_MANAGER_SVC_H__
