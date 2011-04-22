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

#ifndef __TW_MAPLE_SERVICE_PROGRAMNODELOADER_H_
#define __TW_MAPLE_SERVICE_PROGRAMNODELOADER_H_

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TSimpleFileTransport.h>
#include <protocol/TBinaryProtocol.h>
#include <protocol/TJSONProtocol.h>


#include "pnodehandler.h"

namespace tw { namespace maple { namespace service { namespace pass {


struct ProgramNodeLoader {

	static void exec(
			std::vector<std::string> file_list  /* input */
			, tw::maple::as::ast::ProgramList& pnode_list /* output */
			)
	{
		// File Open
		for (std::vector<std::string>::iterator fileItr = file_list.begin()
				; fileItr != file_list.end(); fileItr++)
		{
			pnode_list . push_back(  exec_one( *fileItr ) );
		}
	}

private:
	static as::ast::ProgramPtr exec_one( std::string file )
    {
        boost::shared_ptr<tw::maple::PNodeHandler> something( new tw::maple::PNodeHandler() );
        boost::shared_ptr<TSimpleFileTransport> transport(new TSimpleFileTransport(file,true,true));
        boost::shared_ptr<tw::maple::generated::AstDumperProcessor> processor( new tw::maple::generated::AstDumperProcessor( something ) );

        transport->open();
        boost::shared_ptr<TProtocol> io(new TJSONProtocol(transport));

        try {
            while( true )
                processor->process( io, io, NULL );
        } catch (TTransportException ex ) {
            std::cout << "handler: " << ex.what()<<std::endl;
        }

        transport->close();

//        return  std::tr1::shared_ptr< as::ast::Program >();
        return something->getProgramNode();
    }
};

} } } } // pass.service.maple.tw
#endif /* PROGRAMNODELOADER_H_ */
