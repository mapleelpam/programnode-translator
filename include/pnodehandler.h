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
#include <as/ast/literal.h>
#include <as/ast/literal_string.h>
#include <as/ast/expression_list.h>
#include <as/ast/identifier.h>
#include <as/ast/program.h>
#include <as/ast/arguments.h>
#include <as/ast/function_definition.h>
#include <as/ast/function_name.h>
#include <as/ast/function_rettype.h>
#include <as/ast/function_signature.h>
#include <as/ast/statement.h>
#include <as/ast/statement_list.h>
#include <as/ast/node.h>


using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
//tw::maple::generated::

namespace tw { namespace maple { 

class PNodeHandler : virtual public  generated::AstDumperIf {
public:
  PNodeHandler() {
    // Your initialization goes here
  }

  void startProgram()
  {
    printf("startProgram\n");

    _program_root . reset( new as::ast::Program() );
    _node_stack.push( _program_root );
  }

  void endProgram()
  {
    // Your implementation goes here
    printf("endProgram\n");

    // DO FOR WHAT?
  }

  void startPackage(const generated::StringList& id) {
    // Your implementation goes here
    printf("startPackage\n");
  }

  void endPackage(const generated::StringList& IDs) {
    // Your implementation goes here
    printf("endPackage\n");
  }

  void startFunctionDefinition() {
    // Your implementation goes here
    printf("startFunctionDefinition\n");


    std::tr1::shared_ptr<as::ast::FunctionDefinition> func_def( new as::ast::FunctionDefinition() );
    _node_stack . top() -> addNodeChild( func_def );
    _node_stack . push( func_def );
  }

  void startFunctionName() {
    // Your implementation goes here
    printf("startFunctionName\n");

    std::tr1::shared_ptr<as::ast::FunctionName> func_name( new as::ast::FunctionName() );
    _node_stack . top() -> addNodeChild( func_name );
    _node_stack . push( func_name );
  }

  void endFunctionName() {
    // Your implementation goes here
    printf("endFunctionName\n");

    _node_stack . pop();
  }

  void startFunctionSignature() {
    // Your implementation goes here
    printf("startFunctionSignature\n");


    std::tr1::shared_ptr<as::ast::FunctionSignature> exp_list( new as::ast::FunctionSignature );
    _node_stack . top() -> addNodeChild( exp_list );
    _node_stack . push( exp_list );
  }

  void endFunctionSignature() {
    // Your implementation goes here
    printf("startFunctionSignature\n");

    _node_stack . pop();
  }

  void startFunctionSignatureParameter() {
    // Your implementation goes here
    printf("startFunctionSignatureParameter\n");
  }

  void endFunctionSignatureParameter() {
    // Your implementation goes here
    printf("endFunctionSignatureParameter\n");
  }

  void startFunctionSignatureReturnType() {
    // Your implementation goes here
    printf("startFunctionSignatureReturnType\n");

    std::tr1::shared_ptr<as::ast::FunctionReturnType> exp_list( new as::ast::FunctionReturnType );
    _node_stack . top() -> addNodeChild( exp_list );
    _node_stack . push( exp_list );
  }

  void endFunctionSignatureReturnType() {
    // Your implementation goes here
    printf("endFunctionSignatureReturnType\n");
    _node_stack . pop();
  }

  void startFunctionBody() {
    // Your implementation goes here
    printf("startFunctionBody\n");
  }

  void endFunctionBody() {
    // Your implementation goes here
    printf("endFunctionBody\n");
  }

  void endFunctionDefinition() {
    // Your implementation goes here
    printf("endFunctionDefinition\n");
    _node_stack . pop( );
  }

  void startExpressionList()
  {
    // Your implementation goes here
    printf("startExpressionList\n");

    std::tr1::shared_ptr<as::ast::ExpressionList> exp_list( new as::ast::ExpressionList );
    _node_stack . top() -> addNodeChild( exp_list );
    _node_stack . push( exp_list );
  }

  void startCallExpression(const generated::CallExpression& call)
  {
	  // Your implementation goes here
		printf("startCallExpression\n");

		std::tr1::shared_ptr < as::ast::Call > exp_call(new as::ast::Call);
		_node_stack . top() -> addNodeChild(exp_call);
	    _node_stack . push( exp_call );
  }

  void startAgumentList() {
    // Your implementation goes here
    printf("startAgumentList\n");
    
    std::tr1::shared_ptr<as::ast::Arguments> args( new as::ast::Arguments);
    _node_stack . top () -> addNodeChild( args );
    _node_stack . push( args );
  }

  void endAgumentList() {
    // Your implementation goes here
    printf("endAgumentList\n");
    _node_stack . pop( );
  }

  void endCallExpression()
  {
    // Your implementation goes here
    printf("endCallExpression\n");
    _node_stack . pop( );
  }

  void identifierExpression(const generated::Identifier& id)
  {
    // Your implementation goes here
    printf("identifierExpression\n");
    std::tr1::shared_ptr<as::ast::Identifier> exp_id( new as::ast::Identifier(id.name) );
    _node_stack . top () -> addNodeChild( exp_id);
  }

  virtual void literalStringExpression(const generated::LiteralString& str)
  {
	    std::tr1::shared_ptr<as::ast::LiteralString> exp_literal( new as::ast::LiteralString( str.value ) );
	    _node_stack . top () -> addNodeChild( exp_literal);
  }
  void endExpressionList() {
    // Your implementation goes here
    printf("endExpressionList\n");
   _node_stack . pop ();
  }

  void addImport(const generated::StringList& packages) {
    // Your implementation goes here
    printf("addImport\n");
  }

  void startStmtList() {
    // Your implementation goes here
    printf("startStmtList\n");
    std::tr1::shared_ptr<as::ast::StatementList> stmts( new as::ast::StatementList);
    _node_stack . top () -> addNodeChild( stmts );
    _node_stack . push( stmts );
  }

  void endStmtList() {
    // Your implementation goes here
    printf("endStmtList\n");
    _node_stack . pop ();
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void ping2(const int32_t echo) {
    // Your implementation goes here
    printf("ping2\n");
  }

public:
  std::tr1::shared_ptr< as::ast::Program > getProgramNode() {	return _program_root;	};

private:
    std::stack< as::ast::NodePtr > 			_node_stack;

    std::tr1::shared_ptr< as::ast::Program > _program_root;

};

} } 

#endif
