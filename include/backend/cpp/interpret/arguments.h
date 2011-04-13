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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_ARGUMENTS_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_ARGUMENTS_H_

#include <as/ast/arguments.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;


// Abstract
struct Arguments : public Interpreter
{   
	void interpret( AST::NodePtr node, tw::maple::backend::cpp::Context* ctx )
	{
//		for (std::vector<std::tr1::shared_ptr<AST::Node> >::iterator nItr =
//				node->node_childs.begin(); nItr != node->node_childs.end(); nItr++)
//		{
//			dispatchDo(*nItr, ctx);
//		}

		std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = node->node_childs.begin();
		if( nItr != node->node_childs.end() ) {
			dispatchDo(*nItr, ctx);

			for( nItr++ ; nItr != node->node_childs.end() ; nItr ++ )
			{
				ctx->ofs_stream << ", ";
				dispatchDo(*nItr, ctx);
			}
		}
	}
	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		std::string result = "";
		std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = node->node_childs.begin();
		if( nItr != node->node_childs.end() ) {
			result += dispatchExpound(*nItr, ctx);

			for( nItr++ ; nItr != node->node_childs.end() ; nItr ++ )
			{
				result += ", " + dispatchExpound(*nItr, ctx);
			}
		}
		return result;
	}
};


typedef std::tr1::shared_ptr<Arguments>    ArgumentsPtr;


} } } } }

#endif 
