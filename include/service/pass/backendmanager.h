/* ******************************************************************\
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

#ifndef __TW_MAPLE_SERVICE_BACKEND_MANAGER_H__
#define __TW_MAPLE_SERVICE_BACKEND_MANAGER_H__

#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/prependdata.h>
#include <pnodehandler.h>
#include <as/symbol/variable.h>
#include <service/globalsettings.h>

namespace tw { namespace maple { namespace service { namespace pass {


struct BackendManager {

	static void exec(
			tw::maple::as::ast::ProgramList& pnode_list /* input program node */
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::PrependData prepend_data
			, std::string file_name /* write to */
			)
	{
		using tw::maple::backend::cpp::interpret::dispatchExpound;
		using tw::maple::as::symbol::ScopePtr;

		std::ofstream ofs_stream;
		ofs_stream.open( file_name.c_str() );
		// Interpret/Explain - Invoke Back-end Stream Out

		prepend_data.execute( ofs_stream );

		ofs_stream << SVC_GLOBAL_SETTINGS->prepend_codes <<std::endl;

		for (std::vector<tw::maple::as::ast::ProgramPtr>::iterator
				nodeItr = pnode_list.begin(); nodeItr != pnode_list.end(); nodeItr++)
		{
			tw::maple::backend::cpp::Context context;
			std::cerr << " backend passing: "<< (*nodeItr)->file_name << std::endl;
			ofs_stream << dispatchExpound(*nodeItr, symbol_table, context	).result;
		}
        ofs_stream << std::endl;
        if( SVC_GLOBAL_SETTINGS->declare_only == false || SVC_GLOBAL_SETTINGS->define_only )
        	declareStaticVariables( symbol_table, ofs_stream );

		ofs_stream.close();
	}

private:
	static void declareStaticVariables(
			tw::maple::as::symbol::ScopePtr symbol_table
			, std::ofstream& ofs_stream
			)
	{
		namespace ASYM = tw::maple::as::symbol;
		namespace INTERPRET = tw::maple::backend::cpp::interpret;
		using tw::maple::as::symbol::ScopePtr;

		std::vector<ASYM::SymbolPtr> childs;
		symbol_table->getChilds( childs/*out*/ );

//		ofs_stream << std::endl;
		for (std::vector<ASYM::SymbolPtr>::iterator
				child_itr = childs.begin(); child_itr != childs.end(); child_itr++)
		{

			if( ((*child_itr)->getSymbolProperties() & ASYM::Symbol::T_SCOPE ) )
			{
				ASYM::ScopePtr scope = STATIC_CAST(ASYM:: Scope, *child_itr );
				if( scope && !(scope->isIntrinsic()) )
					declareStaticVariables( scope, ofs_stream );
			}
			else if( ((*child_itr)->getSymbolProperties() & ASYM::Symbol::T_VARIABLE ) )
			{

				ASYM::VariablePtr variable = STATIC_CAST( ASYM::Variable, *child_itr );
				if( variable->isStatic() ){
					std::string str_is_const = variable->isConst() ? " const " : "";
					std::string str_var_type = "";
					ASYM::SymbolPtr symbol_type = variable->getTypeSymbol();
					if( symbol_type->preferStack())
						str_var_type = symbol_type->getFQN_and_instanceName();
					else
						str_var_type = symbol_type->getFQN_and_mappedName() + SVC_GLOBAL_SETTINGS->pointer_pattern /* '*'or 'Ptr' */;

					ofs_stream << str_is_const << str_var_type << " "<<variable->getFQN_noprefix();
					if(variable->getInitializeNode())
					{
						tw::maple::backend::cpp::Context context;
						ofs_stream << " = " << INTERPRET::dispatchExpound(variable->getInitializeNode(), symbol_table, context ).result;
					}
					ofs_stream << ";" <<std::endl;
				}
			}
			else
			{
//				ofs << indent(depth) << (*child_itr)->toString() <<std::endl;
			}
		}
	}

};

} } } } // pass.service.maple.tw
#endif /* PROGRAMNODELOADER_H_ */
