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
// Copyright 2011 mapleellpam at gmail.com   All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __TW_MAPLE_AS_AST_SATEMENTS_FOR_STMT_H__
#define __TW_MAPLE_AS_AST_SATEMENTS_FOR_STMT_H__

#include <as/ast/statement.h>
#include <as/ast/expression.h>


namespace tw { namespace maple { namespace as { namespace ast {

struct ForStatement : public Statement
{
	ForStatement() :
		Statement(Node::NodeType::T_STMT_FOR) {
	}

	NodePtr ForInit()	{	return node_childs[0];	}
	NodePtr ForCondition()	{	return node_childs[1];	}
	NodePtr ForStep()	{	return node_childs[2];	}
	NodePtr ForBody()	{	return node_childs[3];	}
	std::string toString()  {	return "node::for_stmt"; };
};
typedef std::tr1::shared_ptr<ForStatement> ForStatementPtr;

struct ForInit : public Expression
{
	ForInit() :
		Expression(Node::NodeType::T_FOR_INIT) {
	}
	std::string toString()  {	return "node::for_init"; };
};
typedef std::tr1::shared_ptr<ForInit> ForInitPtr;


struct ForStep : public Expression
{
	ForStep() :
		Expression(Node::NodeType::T_FOR_STEP) {
	}
	std::string toString()  {	return "node::for_step"; };
};
typedef std::tr1::shared_ptr<ForStep> ForStepPtr;

struct ForCondition : public Expression
{
	ForCondition() :
		Expression(Node::NodeType::T_FOR_STEP) {
	}
	std::string toString()  {	return "node::for_cond"; };
};
typedef std::tr1::shared_ptr<ForCondition> ForConditionPtr;

struct ForBody : public Expression
{
	ForBody() :
		Expression(Node::NodeType::T_FOR_BODY) {
	}
	std::string toString()  {	return "node::for_body"; };
};
typedef std::tr1::shared_ptr<ForBody> ForBodyPtr;
} } } }

#endif
