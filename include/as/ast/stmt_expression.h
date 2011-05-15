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

#ifndef __TW_MAPLE_AS_AST_SATEMENTS_STMT_EXPR_H__
#define __TW_MAPLE_AS_AST_SATEMENTS_STMT_EXPR_H__

#include <as/ast/abstract/statement.h>


namespace tw { namespace maple { namespace as { namespace ast {

struct StmtExpression : public Statement
{
	StmtExpression() :
		Statement(Node::NodeType::T_STMT_EXPR) {
	}

	std::string toString()  {	return "node::stmt_expr"; };
};
typedef std::tr1::shared_ptr<StmtExpression> StmtExpressionPtr;


} } } }

#endif
