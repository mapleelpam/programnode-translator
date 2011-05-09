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

		for( int idx = 0 ; idx < expr_mem->m_bases.size() ; idx ++ )
			result += expr_mem->m_bases[idx];

		std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = expr_mem->node_childs.begin();
		if( nItr != node->node_childs.end() ) {
			result += dispatchExpound(*nItr, symbol_table, ctx);

			for( nItr++ ; nItr != node->node_childs.end() ; nItr ++ )
			{
					result += "->" + dispatchExpound(*nItr, symbol_table, ctx);
			}
		}


		return result;
	}
};

};


} } } } 

#endif 
