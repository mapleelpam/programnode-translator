/* ***************************************************************
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 * ProgrameNode Translator
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
 *
 * https://github.com/mapleelpam/programnode-translator
 *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple
 * ***************************************************************/

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_IDENTIFIER_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_IDENTIFIER_H__

#include <as/ast/token/identifier.h>
#include <backend/cpp/interpret/interpreter.h>
#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

// Abstract
struct Identifier : public Interpreter
{
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			,	tw::maple::backend::cpp::Context* ctx)
	{
		namespace ASY = tw::maple::as::symbol;
		SHARED_PTR(AST::Identifier) li = std::tr1::static_pointer_cast<AST::Identifier>(node);

		if(li->qualifier != "")
		{
			std::string left = _replace_string( li->qualifier, ".", "::");

			return left+"::"+li->value;
		}
		else
		{
//			ASY::SymbolPtr symbol = symbol_table->findSymbol( result );
			
			return li->value;
		}
	}

private:
	std::string _replace_string(
	    const std::string &s, const std::string &SearchString, const std::string &ReplaceString
	    )
	{
		std::string result = s;
	    std::string::size_type p = 0;
	    while((p = result.find(SearchString, p)) != std::string::npos)
	    {
	        result.replace(p, SearchString.size(), ReplaceString);
	        p++;
	    }
	    return result;
	}
};


} } } } }

#endif 

