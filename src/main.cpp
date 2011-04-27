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

#include <iostream>
#include <fstream>

#include "AstDumper.h"  

#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/prepend_data.h>
#include <service/ConfigService.h>
#include <service/ArgumentsService.h>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

#include <as/symbol/Scope.h>
#include <as/symbol/Symbol.h>

#include <service/PassManagerService.h>

//namespace po = boost::program_options;


int main(int argc, char **argv)
{
	SVC_CONFIG;

	tw::maple::service::PassManagerService  major;

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
