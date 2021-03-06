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

#include <global.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/prependdata.h>
#include <service/configservice.h>
#include <service/argumentsservice.h>
#include <service/passmanagerservice.h>
#include <service/globalsettings.h>
#include <as/symbol/scope.h>
#include <as/symbol/symbol.h>

//namespace po = boost::program_options;


int main(int argc, char **argv)
{
	SVC_CONFIG;
	SVC_SYMBOLTABLE;
	SVC_GLOBAL_SETTINGS;

	tw::maple::service::PassManagerService  major;

	try {
		SVC_ARGUMENTS->parse(argc,argv);
	} catch (std::exception &e) {
		std::cerr << "Unknown Arguments " << e.what()<< std::endl;
		SVC_ARGUMENTS->print_out_help();
		exit(1);
	} catch (...) {
		std::cout << "ERROR " << std::endl;
		std::cout << "ERROR " << "Error while parsing pnc options Exiting" << std::endl;
		exit(1);
	}

	major.exec();

    return 0;
}
