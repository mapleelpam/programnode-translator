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
#include <backend/cpp/interpret/arguments.h>
#include <backend/cpp/interpret/call.h>
#include <backend/cpp/interpret/literal_string.h>
#include <backend/cpp/interpret/identifier.h>
#include <backend/cpp/interpret/statement_list.h>
#include <backend/cpp/interpret/function_definition.h>
#include <backend/cpp/interpret/function_name.h>
#include <backend/cpp/interpret/function_return_type.h>
#include <backend/cpp/interpret/function_signature.h>
#include <backend/cpp/interpret/function_parameter.h>
#include <backend/cpp/interpret/program_root.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

void dispatchDo( tw::maple::as::ast::NodePtr node, tw::maple::backend::cpp::Context* ctx )
{
	if( node == NULL ){
		std::cerr << "error: dispatchDo - can't get null node"<<std::endl;
		exit(1);
	}

	static Interpreter* interpreterResolver[AST::Node::NodeType::T_NODE_TYPE_END];
	static bool _1st_enter = true;

	namespace AST = ::tw::maple::as::ast;
	if( _1st_enter )
	{ // Initialize
		_1st_enter = false;
		for( int idx = 0 ; idx < AST::Node::NodeType::T_NODE_TYPE_END; idx ++ )
			interpreterResolver[ idx ] = NULL;

		interpreterResolver[AST::Node::NodeType::T_PROGRAM] = new Interpreter();

		interpreterResolver[AST::Node::NodeType::T_FUNCTION_DEFINITION] = new FunctionDefinition();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_NAME] = new FunctionName();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_SIGNATURE] = new FunctionSignature();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_RETTYPE] = new FunctionReturnType();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_PARAMETER] = new FunctionParameter();

		interpreterResolver[AST::Node::NodeType::T_STMT_LIST] = new StatementList();
//		interpreterResolver[AST::Node::NodeType::T_ConstantNumber] = new StatementList();,
//		            // Expr
//		            T_BinaryOperator,
//		            T_Assignment,


		interpreterResolver[AST::Node::NodeType::T_CALL] = new Call();
//		            T_CompareOperator,
//		            T_InstanceOf,
//
//		            T_PostfixOperator,
//		            T_PrefixOperator,
		interpreterResolver[AST::Node::NodeType::T_EXPR_LIST] = new ExpressionList();
		interpreterResolver[AST::Node::NodeType::T_ARGUMENTS] = new Arguments();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_STRING] = new Arguments();
		interpreterResolver[AST::Node::NodeType::T_IDENTIFIER] = new Identifier();
	}
	Interpreter* to = interpreterResolver[ node->nodeType() ];
	if( to == NULL ){
		std::cerr << "error: can't resolve interpreter - type id = "<<node->toString()<<std::endl;
		exit(1);
	} else {
		std::cout <<" dispatch - " << node->toString()<<std::endl;
		to->interpret(node,ctx);
	}

}

//void dispatchDo( tw::maple::as::ast::NodePtr node, tw::maple::backend::cpp::Context* ctx )
//{
//	namespace AST = ::tw::maple::as::ast;
//
//	switch (node->nodeType()) {
//
//	case AST::Node::NodeType::T_EXPRESSION: {
//		tw::maple::as::ast::Expression* expr = dynamic_cast<tw::maple::as::ast::Expression*> (&(*node));
//		switch (expr->exprType()) {
//
//		case ::tw::maple::as::ast::Expression::ExpressionType::T_CALL:
//			std::cout << "T_CALL " << std::endl;
//			Call::interpret( expr, ctx );
//
//			break;
//		case ::tw::maple::as::ast::Expression::ExpressionType::T_EXPR_LIST:
//			std::cout << "T_EXPR_LIST " << std::endl;
//
//			ExpressionList::interpret( expr, ctx );
//			break;
//		case ::tw::maple::as::ast::Expression::ExpressionType::T_IDENTIFIER:
//			std::cout << "T_IDENTIFIER " << std::endl;
//			Identifier::interpret( expr, ctx );
//			break;
//		case ::tw::maple::as::ast::Expression::ExpressionType::T_LITERAL_STRING:
//			std::cout << "T_LITERAL " << std::endl;
//			LiteralString::interpret( expr, ctx );
//			break;
//		case ::tw::maple::as::ast::Expression::ExpressionType::T_ARGUMENTS:
//			std::cout << "T_ARGUMENTS " << std::endl;
//			Arguments::interpret( expr, ctx );
//			break;
//		}
//		break;
//	}
//	case AST::Node::NodeType::T_PROGRAM:{
//		std::cout << "T_PROGRAM " << std::endl;
//
//		for( std::vector< std::tr1::shared_ptr< AST::Node > >::iterator nItr = node->node_childs.begin()
//				; nItr != node->node_childs.end() ; nItr ++ )
//		{
//			dispatchDo( *nItr, ctx );
//		}
//		break;
//	}
//
//	case AST::Node::NodeType::T_STATEMENT: {
//		tw::maple::as::ast::Statement* stmt = dynamic_cast<tw::maple::as::ast::Statement*> (&(*node));
//
//		switch (stmt->stmtType()) {
//		case ::tw::maple::as::ast::Statement::StatementType::T_STMT_LIST: {
//			std::cout << "T_STMT_LIST " << std::endl;
//			StatementList::interpret( stmt, ctx );
//			break;
//		}
//		case ::tw::maple::as::ast::Statement::StatementType::T_FUNCTION_DEFINITION: {
//			std::cout << "T_FUNCTION_DEFINITION " << std::endl;
//			FunctionDefinition::interpret( stmt, ctx );
//			break;
//		}
//		case ::tw::maple::as::ast::Statement::StatementType::T_FUNCTION_NAME: {
//			std::cout << "T_FUNCTION_NAME " << std::endl;
//			FunctionName::interpret(stmt, ctx);
//			break;
//		}
//		case ::tw::maple::as::ast::Statement::StatementType::T_FUNCTION_RETTYPE: {
//			std::cout << "T_FUNCTION_RETTYPE " << std::endl;
//			FunctionReturnType::interpret(stmt, ctx);
//			break;
//		}
//		case ::tw::maple::as::ast::Statement::StatementType::T_FUNCTION_SIGNATURE: {
//			std::cout << "T_FUNCTION_SIGNATURE " << std::endl;
//			FunctionSignature::interpret(stmt, ctx);
//			break;
//		}
//		}
//
//	}
//
//	};
//
//}

} } } } }
