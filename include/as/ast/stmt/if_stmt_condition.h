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
// Copyright 2010 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __AS_AST_SATEMENTS_IF_STMT_CONDITION_H__
#define __AS_AST_SATEMENTS_IF_STMT_CONDITION_H__

#include <as/ast/statement.h>


namespace tw { namespace maple { namespace as { namespace ast {

struct IfStatementCondition : public Statement
{
	IfStatementCondition() :
		Statement(Node::NodeType::T_IF_STMT_CONDITION) {
	}

	std::string toString()  {	return "node::if_stmt_condition"; };
};

typedef SHARED_PTR(IfStatementCondition) IfStatementConditionPtr;

} } } }

#endif
