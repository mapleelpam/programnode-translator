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



#ifndef __AST_DUMPER_HANDLER__
#define __AST_DUMPER_HANDLER__

#include <iostream>
#include <stack>
#include "AstDumper.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TSimpleFileTransport.h>
#include <protocol/TBinaryProtocol.h>

#include <as/ast/call.h>
#include <as/ast/literal_string.h>
#include <as/ast/literal_number.h>
#include <as/ast/literal_boolean.h>
#include <as/ast/expression_list.h>
#include <as/ast/identifier.h>
#include <as/ast/program.h>
#include <as/ast/arguments.h>
#include <as/ast/function_definition.h>
#include <as/ast/function_name.h>
#include <as/ast/function_rettype.h>
#include <as/ast/function_signature.h>
#include <as/ast/function_parameters.h>
#include <as/ast/function_parameter_item.h>
#include <as/ast/function_common.h>
#include <as/ast/binary_operator.h>
#include <as/ast/statement.h>
#include <as/ast/return_stmt.h>
#include <as/ast/statement_list.h>
#include <as/ast/node.h>


using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
//tw::maple::generated::

namespace AST = ::tw::maple::as::ast;


namespace tw { namespace maple { 

class PNodeHandler : virtual public  generated::AstDumperIf {
public:
  PNodeHandler() {
    // Your initialization goes here
  }

  void startProgram()
  {
    printf(" %lu startProgram\n", _node_stack.size() );

    _program_root . reset( new as::ast::Program() );
    _node_stack.push( _program_root );
  }

  void endProgram()
  {
    // Your implementation goes here
    printf(" %lu endProgram\n", _node_stack.size() );

    // DO FOR WHAT?
  }

  void startPackage(const generated::StringList& id) {
    // Your implementation goes here
    printf(" %lu startPackage\n", _node_stack.size() );
  }

  void endPackage(const generated::StringList& IDs) {
    // Your implementation goes here
    printf(" %lu endPackage\n", _node_stack.size() );
  }

  void startFunctionDefinition() {
    // Your implementation goes here
    printf(" %lu startFunctionDefinition\n", _node_stack.size() );


    std::tr1::shared_ptr<as::ast::FunctionDefinition> func_def( new as::ast::FunctionDefinition() );
    _node_stack . top() -> addNodeChild( func_def );
    _node_stack . push( func_def );
  }

  void startFunctionName() {
    // Your implementation goes here
    printf(" %lu startFunctionName\n", _node_stack.size() );

    std::tr1::shared_ptr<as::ast::FunctionName> func_name( new as::ast::FunctionName() );
    _node_stack . top() -> addNodeChild( func_name );
    _node_stack . push( func_name );
  }

  void endFunctionName() {
    // Your implementation goes here
    printf(" %lu endFunctionName\n", _node_stack.size() );

    _node_stack . pop();
  }

  void startFunctionSignature() {
    // Your implementation goes here
    printf(" %lu startFunctionSignature\n", _node_stack.size() );


    std::tr1::shared_ptr<as::ast::FunctionSignature> fsig( new as::ast::FunctionSignature );
    _node_stack . top() -> addNodeChild( fsig );
    _node_stack . push( fsig );
  }

  void endFunctionSignature() {
    // Your implementation goes here
    printf(" %lu endFunctionSignature\n", _node_stack.size() );
    _node_stack . pop();
  }

  void startFunctionSignatureParameters() {
    // Your implementation goes here
    printf(" %lu startFunctionSignatureParameters\n", _node_stack.size() );

    std::cout << " current stack top is " << _node_stack . top() -> toString() << std::endl;

    std::tr1::shared_ptr<as::ast::FunctionParameters> fsig_param( new as::ast::FunctionParameters );
    _node_stack . top() -> addNodeChild( fsig_param );
    _node_stack . push( fsig_param );
  }

  void startFunctionSignatureParameterMember() {
    // Your implementation goes here
    printf(" %lu startFunctionSignatureParameterMember\n", _node_stack.size() );
    std::tr1::shared_ptr<as::ast::FunctionParameterItem> fsig( new as::ast::FunctionParameterItem );
    _node_stack . top() -> addNodeChild( fsig );
    _node_stack . push( fsig );
  }

  void endFunctionSignatureParameterMember() {
    // Your implementation goes here
    printf(" %lu endFunctionSignatureParameterMember\n", _node_stack.size() );
    _node_stack . pop();
  }

  void endFunctionSignatureParameters() {
    // Your implementation goes here
    printf(" %lu endFunctionSignatureParameters\n", _node_stack.size() );
    _node_stack . pop();
  }

  void startFunctionSignatureReturnType() {
    // Your implementation goes here
    printf(" %lu startFunctionSignatureReturnType\n", _node_stack.size() );

    std::tr1::shared_ptr<as::ast::FunctionReturnType> exp_list( new as::ast::FunctionReturnType );
    _node_stack . top() -> addNodeChild( exp_list );
    _node_stack . push( exp_list );
  }

  void endFunctionSignatureReturnType() {
    // Your implementation goes here
    printf(" %lu endFunctionSignatureReturnType\n", _node_stack.size() );
    _node_stack . pop();
  }

  void startFunctionCommon() {
    // Your implementation goes here
    printf(" %lu startFunctionCommon\n", _node_stack.size() );

    std::tr1::shared_ptr<as::ast::FunctionCommon> fCommon( new as::ast::FunctionCommon );
    _node_stack . top() -> addNodeChild( fCommon );
    _node_stack . push( fCommon );
  }

  void endFunctionCommon() {
    // Your implementation goes here
    printf(" %lu endFunctionCommon\n", _node_stack.size() );
    _node_stack . pop();
  }

  void endFunctionDefinition() {
    // Your implementation goes here
    printf(" %lu endFunctionDefinition\n", _node_stack.size() );
    _node_stack . pop( );
  }

  void startExpressionList()
  {
    // Your implementation goes here
    printf(" %lu startExpressionList\n", _node_stack.size() );

    std::tr1::shared_ptr<as::ast::ExpressionList> exp_list( new as::ast::ExpressionList );
    _node_stack . top() -> addNodeChild( exp_list );
    _node_stack . push( exp_list );
  }

  void startCallExpression(const generated::CallExpression& call)
  {
	  // Your implementation goes here
		printf(" %lu startCallExpression\n", _node_stack.size() );

		std::tr1::shared_ptr < as::ast::Call > exp_call(new as::ast::Call);
		_node_stack . top() -> addNodeChild(exp_call);
	    _node_stack . push( exp_call );
  }

  void startAgumentList() {
    // Your implementation goes here
    printf(" %lu startAgumentList\n", _node_stack.size() );
    
    std::tr1::shared_ptr<as::ast::Arguments> args( new as::ast::Arguments);
    _node_stack . top () -> addNodeChild( args );
    _node_stack . push( args );
  }

  void endAgumentList() {
    // Your implementation goes here
    printf(" %lu endAgumentList\n", _node_stack.size() );
    _node_stack . pop( );
  }

  void endCallExpression()
  {
    // Your implementation goes here
    printf(" %lu endCallExpression\n", _node_stack.size() );
    _node_stack . pop( );
  }
  void startBinaryExpression(const generated::BinaryExpression& op)
  {
    // Your implementation goes here
		printf("startBinaryExpression\n");
		as::ast::BinaryOperatorPtr as_node( new as::ast::BinaryOperator(op.op));
		_node_stack . top() -> addNodeChild(as_node);
		_node_stack . push(as_node);
  }
  void endBinaryExpression() {
    // Your implementation goes here
    printf("endBinaryExpression\n");
    _node_stack . pop( );

  }

  void startReturnStatement()
  {
	// Your implementation goes here
	printf("startReturnStatement\n");
	std::tr1::shared_ptr<as::ast::ReturnStatement> op( new as::ast::ReturnStatement);
	_node_stack . top() -> addNodeChild(op);
	_node_stack . push(op);
  }

  void endReturnStatement()
  {
	// Your implementation goes here
	printf("endReturnStatement\n");
	_node_stack . pop();
  }

  void identifierExpression(const generated::Identifier& id)
  {
    // Your implementation goes here
    printf(" %lu identifierExpression\n", _node_stack.size() );
    std::tr1::shared_ptr<as::ast::Identifier> exp_id( new as::ast::Identifier(id.name) );
    _node_stack . top () -> addNodeChild( exp_id);
  }

  virtual void literalStringExpression(const generated::Literal& str)
  {
	    std::tr1::shared_ptr<as::ast::LiteralString> exp_literal( new as::ast::LiteralString( str.value ) );
	    _node_stack . top () -> addNodeChild( exp_literal);
  }
  virtual void literalNumberExpression(const generated::Literal& num)
  {
	    std::tr1::shared_ptr<as::ast::LiteralNumber> exp_literal( new as::ast::LiteralNumber( num.value ) );
	    _node_stack . top () -> addNodeChild( exp_literal);
  }
  virtual void literalBooleanExpression(const generated::Literal& num)
  {
  	    std::tr1::shared_ptr<as::ast::LiteralBoolean> exp_literal( new as::ast::LiteralBoolean( num.value ) );
  	    _node_stack . top () -> addNodeChild( exp_literal);
  }
  void endExpressionList() {
    // Your implementation goes here
    printf(" %lu endExpressionList\n", _node_stack.size() );
   _node_stack . pop ();
  }

  void addImport(const generated::StringList& packages) {
    // Your implementation goes here
    printf(" %lu addImport\n", _node_stack.size() );
  }

  void startStmtList() {
    // Your implementation goes here
    printf(" %lu startStmtList\n", _node_stack.size() );
    std::tr1::shared_ptr<as::ast::StatementList> stmts( new as::ast::StatementList);
    _node_stack . top () -> addNodeChild( stmts );
    _node_stack . push( stmts );
  }

  void endStmtList() {
    // Your implementation goes here
    printf(" %lu endStmtList\n", _node_stack.size() );
    _node_stack . pop ();
  }

  void ping() {
    // Your implementation goes here
    printf(" %lu ping\n", _node_stack.size() );
  }

  void ping2(const int32_t echo) {
    // Your implementation goes here
    printf(" %lu ping2\n", _node_stack.size() );
  }

public:
  std::tr1::shared_ptr< as::ast::Program > getProgramNode() {	return _program_root;	};

private:
    std::stack< as::ast::NodePtr > 			_node_stack;

    std::tr1::shared_ptr< as::ast::Program > _program_root;

};

} } 

#endif
