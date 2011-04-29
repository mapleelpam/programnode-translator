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

#include <iostream>
#include <vector>
#include <backend/cpp/interpret/interpreter.h>
#include <stdlib.h>

#include <backend/cpp/interpret/expression_list.h>
#include <backend/cpp/interpret/call.h>
#include <backend/cpp/interpret/literal_string.h>
#include <backend/cpp/interpret/literal_number.h>
#include <backend/cpp/interpret/literal_boolean.h>
#include <backend/cpp/interpret/identifier.h>
#include <backend/cpp/interpret/statement_list.h>
#include <backend/cpp/interpret/function_definition.h>
#include <backend/cpp/interpret/function_name.h>
#include <backend/cpp/interpret/function_return_type.h>
#include <backend/cpp/interpret/function_parameters.h>
#include <backend/cpp/interpret/function_parameter_item.h>
#include <backend/cpp/interpret/arguments.h>
#include <backend/cpp/interpret/return_stmt.h>
#include <backend/cpp/interpret/binary_operator.h>
#include <backend/cpp/interpret/unary_operator.h>
#include <backend/cpp/interpret/variable_declare.h>
#include <backend/cpp/interpret/assignment.h>
#include <backend/cpp/interpret/if_stmt.h>
#include <backend/cpp/interpret/stmt_expression.h>
#include <backend/cpp/interpret/is.h>
#include <backend/cpp/interpret/instanceof.h>
#include <backend/cpp/interpret/class_define.h>
#include <backend/cpp/interpret/class_base.h>
#include <backend/cpp/interpret/class_name.h>
#include <backend/cpp/interpret/stmt/package_definition.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

static Interpreter* interpreterResolver[ ::tw::maple::as::ast::Node::NodeType::T_NODE_TYPE_END];

void initializeInterpreters()
{
	static bool _1st_enter = true;
	if (_1st_enter) { // Initialize
		_1st_enter = false;
		for (int idx = 0; idx < AST::Node::NodeType::T_NODE_TYPE_END; idx++)
			interpreterResolver[idx] = NULL;

		interpreterResolver[AST::Node::NodeType::T_PROGRAM] = new Interpreter();
		//
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_DEFINITION]
				= new FunctionDefinition();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_NAME]
				= new FunctionName();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_RETTYPE]
				= new FunctionReturnType();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_PARAMETERS]
				= new FunctionParameter();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_PARAMETER_ITEM]
				= new FunctionParameterItem();

		interpreterResolver[AST::Node::NodeType::T_STMT_LIST]
				= new StatementList();
		interpreterResolver[AST::Node::NodeType::T_EXPR_LIST]
				= new ExpressionList();
		interpreterResolver[AST::Node::NodeType::T_ARGUMENTS] = new Arguments();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_STRING]
				= new LiteralString();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_NUMBER]
				= new LiteralNumber();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_BOOLEAN]
				= new LiteralBoolean();
		interpreterResolver[AST::Node::NodeType::T_IDENTIFIER]
				= new Identifier();
		interpreterResolver[AST::Node::NodeType::T_BINARY_OPERATOR]
				= new BinaryOperator();
		interpreterResolver[AST::Node::NodeType::T_INSTANCEOF]
					= new InstanceOf();
		interpreterResolver[AST::Node::NodeType::T_IS]
					= new Is();
		interpreterResolver[AST::Node::NodeType::T_UNARY_OPERATOR]
				= new UnaryOperator();
		interpreterResolver[AST::Node::NodeType::T_RETURN_STATEMENT]
				= new ReturnStatement();

		interpreterResolver[AST::Node::NodeType::T_VARIABLE_DECLARE]
				= new VariableDeclare();
		interpreterResolver[AST::Node::NodeType::T_ASSIGNMENT]
				= new Assignment();
		interpreterResolver[AST::Node::NodeType::T_CALL] = new Call();
		interpreterResolver[AST::Node::NodeType::T_IF_STMT] = new IfStatement();
		interpreterResolver[AST::Node::NodeType::T_STMT_EXPR] = new StmtExpression();

		/* TODO: implement this */
		interpreterResolver[AST::Node::NodeType::T_IF_STMT_CONDITION]
				= new Interpreter();
		interpreterResolver[AST::Node::NodeType::T_IF_STMT_THEN]
				= new Interpreter();
		interpreterResolver[AST::Node::NodeType::T_IF_STMT_ELSE]
				= new Interpreter();

		interpreterResolver[AST::Node::NodeType::T_CLASS_DEFINE]
				= new ClassDefine();
		interpreterResolver[AST::Node::NodeType::T_CLASS_DEFINE_NAME]
				= new ClassName();
		interpreterResolver[AST::Node::NodeType::T_CLASS_DEFINE_STMT]
				= new Interpreter();

		interpreterResolver[AST::Node::NodeType::T_COMP_CLASS_BASE]
				= new ClassInheritBase();

		interpreterResolver[AST::Node::NodeType::T_COMP_CLASS_ATTRIBUTE]
				= new Interpreter();

		interpreterResolver[AST::Node::NodeType::T_COMP_FUNCTION_ATTRIBUTE]
				= new Interpreter();

		interpreterResolver[AST::Node::NodeType::T_PACKAGE_DEFINITION]
		        = new PackageDefinition();
	}
}


std::string dispatchExpound( ::tw::maple::as::ast::NodePtr node, ::tw::maple::backend::cpp::Context* ctx )
{
	if( node == NULL ){
		std::cerr << "error: dispatchDo - can't get null node"<<std::endl;
		exit(1);
	}

	namespace AST = ::tw::maple::as::ast;
	Interpreter* to = interpreterResolver[ node->nodeType() ];
	if( to == NULL ){
		std::cerr << "error: can't resolve expound - type id = "<<node->toString()<<std::endl;
		exit(1);
	} else {
		std::cout <<" dispatch - " << node->toString() << " number " << node->nodeType()<<std::endl;
		return to->expound(node,ctx);
	}

}

} /*interpret*/ } /*cpp*/ } /*backend*/ } /*maple*/ } /*tw*/

