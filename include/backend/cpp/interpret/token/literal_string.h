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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_STRING_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_LITERAL_STRING_H__

#include <global.h>
#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/token/literal_string.h>
#include <as/symbol/action/findable.h>
#include <backend/cpp/templateprinter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct LiteralString : public Interpreter, public TemplatePrinter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		namespace AST = ::tw::maple::as::ast;
		namespace ASY = ::tw::maple::as::symbol;
		using tw::maple::as::symbol::Findable;

		ASY::SymbolPtr symbol_string = Findable::findClassType( symbol_table, "String" );

		AST::LiteralStringPtr li = std::tr1::static_pointer_cast<AST::LiteralString>(node);

		std::string v = special_replace( li->value);
		ReturnValue result = s_typecast+"(\"" + v + "\")";
		result.token_symbol = symbol_string;
		return result;
	}

	LiteralString()
		: TemplatePrinter("LiteralString")
	{
		s_typecast = "";
	}
private:
	std::string special_replace( const std::string in )
	{
		std::string ans = in ;
		ans = replace(ans, "\\", "\\\\");
		ans = replace(ans, "\n", "\\n");
		ans = replace(ans, "\t", "\\t");
		ans = replace(ans, "\r", "\\r");
		ans = replace(ans, "\b", "\\b");
		ans = replace(ans, "\f", "\\f");
		ans = replace(ans, "\"", "\\\"");
//		ans = replace(ans, "\0", "\\\0");
		ans = replace(ans, "\v", "\\\v");
//		ans = replace(ans, "\a", "\\\a");
		ans = replace(ans, "\f", "\\\f");
		ans = replace(ans, "\'", "\\\'");
		ans = replace(ans, "\?", "\\\?");

		return ans;
	}

	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		s_typecast = pt.get<std::string>( configName()+".typecast", s_typecast);
		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".typecast", s_typecast);
		return TemplatePrinter::writeConfig( pt );
	}

	std::string s_typecast;
};


} } } } }

#endif 

