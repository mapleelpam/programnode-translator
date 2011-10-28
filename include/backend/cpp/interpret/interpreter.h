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
 * https://github.com/mapleelpam/programnode-translator              *
 *                                                                   *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple           *
 \*******************************************************************/


#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_INTERPRET_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_INTERPRET_H_

#include <service/globalsettings.h>
#include <as/ast/abstract/expression.h>
#include <backend/cpp/context.h>
#include <as/symbol/scope.h>
#include <as/symbol/variable.h>
#include <backend/cpp/interpret/returnvalue.h>

#define DEBUG_INTERPRET_ENTRY {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " enter function" <<std::endl;	}
#define DEBUG_INTERPRET_LEAVE {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " leave function" <<std::endl;	}


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

void initializeInterpreters();

ReturnValue dispatchExpound(
		::tw::maple::as::ast::NodePtr node
		 , tw::maple::as::symbol::ScopePtr symbol_table
		 , ::tw::maple::backend::cpp::Context& ctx
//		 
		 );

struct Interpreter
{

	virtual ReturnValue expound(
			::tw::maple::as::ast::NodePtr node
			 , tw::maple::as::symbol::ScopePtr symbol_table /* stmt symbol table */
			 , tw::maple::backend::cpp::Context& ctx
			 )
	{
		ReturnValue result = "";
		for (std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr =
				node->node_childs.begin(); nItr != node->node_childs.end(); nItr++) {
			result += dispatchExpound(*nItr, symbol_table, ctx);
		}


//		return std::string("/*default begin*/")+result.result+std::string("/*default end*/");
        return result;
	}

protected:
	std::string removeSpecialChar( std::string label_string )
	{
		label_string = replace( label_string, "\"", "_dq_");	// double quotation mark
		label_string = replace( label_string, "(", "_lp_");		// parenthesis
		label_string = replace( label_string, ")", "_rp_");
		label_string = replace( label_string, "[", "_lsb_"); 	//	square bracket
		label_string = replace( label_string, "]", "_rsb_");
		label_string = replace( label_string, "{", "_lbs_");
		label_string = replace( label_string, "}", "_rbs_");
		label_string = replace( label_string, ",", "_cn_");		// common
		label_string = replace( label_string, ":", "_sn_");		// semicolon
		label_string = replace( label_string, "\\", "_sl_");		// slash

		return label_string;
	}
	std::string getTypeString( tw::maple::as::symbol::SymbolPtr symbol )
	{
		namespace ASY = tw::maple::as::symbol;
		std::string		s_type;
		ASY::SymbolPtr	symbol_type;

		if( ASY::VariablePtr variable = DYNA_CAST(ASY::Variable, symbol) )
		{
			symbol_type = variable->getTypeSymbol();
		}
		else
			symbol_type = symbol;

		if( symbol_type->preferStack())
			s_type = symbol_type->getFQN_and_instanceName();
		else
			s_type = symbol_type->getFQN_and_mappedName() + SVC_GLOBAL_SETTINGS->pointer_pattern /* '*'or 'Ptr' */;

		return s_type;
	}
};

} } } } }

#endif 
