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

#ifndef __AS_AST_EXPRESSION_LIST_H_
#define __AS_AST_EXPRESSION_LIST_H_

#include <as/ast/abstract/expression.h>


namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct ExpressionList : public Expression
{
	ExpressionList() :
		Expression(Node::NodeType::T_EXPR_LIST)
	{
	}
    int exprType()    {    	return NodeType::T_EXPR_LIST;    }
    std::string toString()  {	return "node::expression_list"; };
};

typedef SHARED_PTR(ExpressionList) ExpressionListPtr;

} } } }

#endif
