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
// Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __TW_MAPLE_SERVICE_BACKEND_MANAGER_H__
#define __TW_MAPLE_SERVICE_BACKEND_MANAGER_H__

#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/prependdata.h>
#include <pnodehandler.h>
#include <as/symbol/variable.h>

namespace tw { namespace maple { namespace service { namespace pass {


struct BackendManager {

	static void exec(
			tw::maple::as::ast::ProgramList& pnode_list /* input program node */
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::PrependData prepend_data
			, std::string file_name /* write to */
			)
	{
		namespace INTERPRET = tw::maple::backend::cpp::interpret;

		tw::maple::backend::cpp::Context context;
		context.ofs_stream.open( file_name.c_str() );
		// Interpret/Explain - Invoke Back-end Stream Out

		prepend_data.execute( context.ofs_stream );

		for (std::vector<tw::maple::as::ast::ProgramPtr>::iterator
				nodeItr = pnode_list.begin(); nodeItr != pnode_list.end(); nodeItr++) {
			context.ofs_stream << INTERPRET::dispatchExpound(*nodeItr, symbol_table, &context);
		}
		declareStaticVariables( symbol_table, context );

		context.ofs_stream.close();
	}

private:
	static void declareStaticVariables(
			tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			)
	{
		namespace ASYM = tw::maple::as::symbol;

		std::vector<ASYM::SymbolPtr> childs;
		symbol_table->getChilds( childs/*out*/ );
		for (std::vector<ASYM::SymbolPtr>::iterator
				child_itr = childs.begin(); child_itr != childs.end(); child_itr++) {

			if( ((*child_itr)->getSymbolProperties() & ASYM::Symbol::T_SCOPE ) )
			{
				ASYM::ScopePtr scope = STATIC_CAST(ASYM:: Scope, *child_itr );
				if( scope )
					declareStaticVariables( scope, ctx );
			} else if( ((*child_itr)->getSymbolProperties() & ASYM::Symbol::T_VARIABLE ) ) {

				ASYM::VariablePtr variable = STATIC_CAST( ASYM::Variable, *child_itr );
				if( variable->isStatic() ){
					ctx.ofs_stream << variable ->getTypeSymbol()->getFQN() << " "<<variable->getFQN()<<";"<<std::endl;
				}
			} else {
//				ofs << indent(depth) << (*child_itr)->toString() <<std::endl;
			}
		}
	}

};

} } } } // pass.service.maple.tw
#endif /* PROGRAMNODELOADER_H_ */