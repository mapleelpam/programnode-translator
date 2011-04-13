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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_UNARY_OPERATOR_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_UNARY_OPERATOR_H__

#include <as/ast/unary_operator.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct UnaryOperator : public Interpreter
{   
	void interpret( AST::NodePtr node, cpp::Context* ctx )
	{

		AST::UnaryOperatorPtr bin = std::tr1::static_pointer_cast<
				AST::UnaryOperator>(node);

		ctx->ofs_stream << " " << resolve_operator(bin->op_type) << " ";
		dispatchDo(bin->subExpr(), ctx); // sub expression
	}
	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		std::string result;

		AST::UnaryOperatorPtr bin = std::tr1::static_pointer_cast<
				AST::UnaryOperator>(node);

		result +=  " " + resolve_operator(bin->op_type) + " ";
		result += dispatchExpound(bin->subExpr(), ctx); // sub expression

		return result;
	}

private:
	std::string resolve_operator( std::string str )
	{
		if( str == "plus")
			return "+";
		else if( str == "minus")
			return "-";
		else if( str == "not")
			return "!";
		else if( str == "bitwisenot")
			return "~";
		else {
			std::cerr << " can't resolve unary op string " << str << std::endl;
			exit(1);
		}
	}

};

};


} } } } 

#endif 
