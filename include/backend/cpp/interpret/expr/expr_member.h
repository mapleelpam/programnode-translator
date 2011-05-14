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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_EXPRMEMBER_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_EXPRMEMBER_H_

#include <as/ast/expr/expr_member.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/template_printer.h>
#include <as/symbol/Scope.h>

#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ExpressionMember : public Interpreter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx)
	{
		namespace ASY = tw::maple::as::symbol;

		std::string result;

		AST::ExpressionMemberPtr expr_mem = STATIC_CAST( AST::ExpressionMember, node);

		if( expr_mem->node_childs.size() == 1 )
		{
			result += dispatchExpound(*(expr_mem->node_childs.begin()), symbol_table, ctx);
		}
		else if( expr_mem->node_childs.size() == 2 )
		{
			std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = expr_mem->node_childs.begin();

			result += dispatchExpound(*nItr, symbol_table, ctx);
			nItr ++;

			if(  (*nItr)->nodeType() == AST::Node::NodeType::T_CALL
				&& STATIC_CAST( AST::Call, *nItr)->isObjectConsturct() )
			{
				return constructor_work_around(result,dispatchExpound(*nItr, symbol_table, ctx));
			}
			else
			{
				if( symbol_table->isInstance( result, "::"))
					result += "->" + dispatchExpound(*nItr, symbol_table, ctx);
				else
					result += "::" + dispatchExpound(*nItr, symbol_table, ctx);
			}
		}
		else
		{
			std::cerr << "there's some strange in member get expression"<<std::endl;
			std::cerr << "pls contact mapleelpam at gmail.com" << std::endl;
			exit(1);
		}

		return result;
	}
private:
	std::string constructor_work_around( std::string base, std::string callee )
	{
		return _replace_string( callee, "new ", "new "+base+"::");
	}
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

};


} } } } 

#endif 
