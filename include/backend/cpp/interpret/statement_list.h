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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_LIST_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_LIST_H__

#include <as/ast/statement_list.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct StatementList : public Interpreter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		std::string result;

		ctx->tree_depth ++;

		bool is_first = true;
        int _idx = 0;
		printf("%s:%d\n",__FILE__,__LINE__);

		for (std::vector<std::tr1::shared_ptr<AST::Node> >::iterator nItr =
				node->node_childs.begin(); nItr != node->node_childs.end(); nItr++)
		{
			printf("%s:%d\n",__FILE__,__LINE__);

            std::cerr << "@@in stmt list's interpret - "<<ctx->tree_depth.toInt() << " ---- counter "<<_idx++<< " listsize "<<node->node_childs.size()<<std::endl;
			result += dispatchExpound(*nItr, ctx);

			// Tail Dirty Flag Handle
			if( is_first )
				is_first = false;
			else
				result += "\n";
			printf("%s:%d\n",__FILE__,__LINE__);

		}

		ctx->tree_depth --;

		printf("%s:%d\n",__FILE__,__LINE__);


		return result;
	}
};

};


} } } } 

#endif 
