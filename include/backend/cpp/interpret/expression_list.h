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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_LIST_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_LIST_H__

#include <as/ast/expression_list.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;


// Abstract
struct ExpressionList : public Interpreter, public TemplatePrinter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx)
	{
		std::string result;

		std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = node->node_childs.begin();
		if( nItr != node->node_childs.end() ) {
			result += dispatchExpound(*nItr, symbol_table, ctx);

			for( nItr++ ; nItr != node->node_childs.end() ; nItr ++ )
			{
				if( symbol_table->isInstance( result, "::"))
				{
					result += "->" + dispatchExpound(*nItr, symbol_table, ctx);
				}
				else
					result += "::" + dispatchExpound(*nItr, symbol_table, ctx);
			}
		}

		return result;
	}
	ExpressionList()
		: TemplatePrinter("ExpressionList")
	{

		m_tpl_setter_prepend = "set_";
		m_tpl_getter_prepend = "get_";
	}

	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_tpl_setter_prepend	= pt.get<std::string>( configName()+".template.setter_prepend", m_tpl_setter_prepend);
		m_tpl_getter_prepend	= pt.get<std::string>( configName()+".template.getter_prepend", m_tpl_getter_prepend);

		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".template.setter_prepend", m_tpl_setter_prepend);
		pt.put<std::string>( configName()+".template.getter_prepend", m_tpl_getter_prepend);

		return TemplatePrinter::writeConfig( pt );
	}
private:
	std::string m_tpl_setter_prepend;
	std::string m_tpl_getter_prepend;
};

};


} } } } 

#endif 
