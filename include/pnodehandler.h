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
#include <as/ast/unary_operator.h>
#include <as/ast/variable_declare.h>
#include <as/ast/statement.h>
#include <as/ast/return_stmt.h>
#include <as/ast/statement_list.h>
#include <as/ast/assignment.h>
#include <as/ast/node.h>

#include <as/ast/if_stmt.h>
#include <as/ast/if_stmt_condition.h>
#include <as/ast/if_stmt_then.h>
#include <as/ast/if_stmt_else.h>

#include <as/ast/class_define.h>
#include <as/ast/class_name.h>
#include <as/ast/class_stmt.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
//tw::maple::generated::

namespace AST = ::tw::maple::as::ast;

#define CHECK_STACK_AND_POP( NODE_TYPE ) \
        if(_node_stack.top()->nodeType() != NODE_TYPE ){ \
            std::cerr << " protocol error ---- expect '"<<#NODE_TYPE<<"' but get '" << _node_stack . top() -> toString()<<"'"<<std::endl; \
            exit(1); \
        }

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

      printf(" %lu endProgram\n", _node_stack.size() );

      // DO FOR WHAT?
  }

  void startPackage(const generated::StringList& id) {

      printf(" %lu startPackage\n", _node_stack.size() );
  }

  void endPackage(const generated::StringList& IDs) {

      printf(" %lu endPackage\n", _node_stack.size() );
  }

  void startFunctionDefinition() {

      printf(" %lu startFunctionDefinition\n", _node_stack.size() );


      as::ast::FunctionDefinitionPtr func_def( new as::ast::FunctionDefinition() );
      _node_stack . top() -> addNodeChild( func_def );
      _node_stack . push( func_def );
  }

  void startFunctionName() {

      printf(" %lu startFunctionName\n", _node_stack.size() );

      as::ast::FunctionNamePtr func_name( new as::ast::FunctionName() );
      _node_stack . top() -> addNodeChild( func_name );
      _node_stack . push( func_name );
  }

  void endFunctionName() {

      printf(" %lu endFunctionName\n", _node_stack.size() );

      _node_stack . pop();
  }

  void startFunctionSignature() {

      printf(" %lu startFunctionSignature\n", _node_stack.size() );


      as::ast::FunctionSignaturePtr fsig( new as::ast::FunctionSignature );
      _node_stack . top() -> addNodeChild( fsig );
      _node_stack . push( fsig );
  }

  void endFunctionSignature() {

      printf(" %lu endFunctionSignature\n", _node_stack.size() );
      _node_stack . pop();
  }

  void startFunctionSignatureParameters() {

      printf(" %lu startFunctionSignatureParameters\n", _node_stack.size() );

      std::cout << " current stack top is " << _node_stack . top() -> toString() << std::endl;

      as::ast::FunctionParametersPtr fsig_param( new as::ast::FunctionParameters );
      _node_stack . top() -> addNodeChild( fsig_param );
      _node_stack . push( fsig_param );
  }

  void startFunctionSignatureParameterMember() {

      printf(" %lu startFunctionSignatureParameterMember\n", _node_stack.size() );
      as::ast::FunctionParameterItemPtr fsig( new as::ast::FunctionParameterItem );
      _node_stack . top() -> addNodeChild( fsig );
      _node_stack . push( fsig );
  }

  void endFunctionSignatureParameterMember() {

      printf(" %lu endFunctionSignatureParameterMember\n", _node_stack.size() );
      _node_stack . pop();
  }

  void endFunctionSignatureParameters() {

      printf(" %lu endFunctionSignatureParameters\n", _node_stack.size() );
      _node_stack . pop();
  }

  void startFunctionSignatureReturnType() {

      printf(" %lu startFunctionSignatureReturnType\n", _node_stack.size() );

      as::ast::FunctionReturnTypePtr exp_list( new as::ast::FunctionReturnType );
      _node_stack . top() -> addNodeChild( exp_list );
      _node_stack . push( exp_list );
  }

  void endFunctionSignatureReturnType() {

      printf(" %lu endFunctionSignatureReturnType\n", _node_stack.size() );
      _node_stack . pop();
  }

  void startFunctionCommon() {

      printf(" %lu startFunctionCommon\n", _node_stack.size() );

      as::ast::FunctionCommonPtr fCommon( new as::ast::FunctionCommon );
      _node_stack . top() -> addNodeChild( fCommon );
      _node_stack . push( fCommon );
  }

  void endFunctionCommon() {

      printf(" %lu endFunctionCommon\n", _node_stack.size() );
      _node_stack . pop();
  }

  void endFunctionDefinition() {

      printf(" %lu endFunctionDefinition\n", _node_stack.size() );
      _node_stack . pop( );
  }

  void startExpressionList()
  {
      printf(" %lu startExpressionList\n", _node_stack.size() );
      as::ast::ExpressionListPtr exp_list( new as::ast::ExpressionList );
      _node_stack . top() -> addNodeChild( exp_list );
      _node_stack . push( exp_list );
  }

  void startCallExpression(const generated::CallExpression& call)
  {

      printf(" %lu startCallExpression\n", _node_stack.size() );

      as::ast::CallPtr exp_call(new as::ast::Call(call.is_new));
      _node_stack . top() -> addNodeChild(exp_call);
      _node_stack . push( exp_call );
  }

  void startAgumentList() {

      printf(" %lu startAgumentList\n", _node_stack.size() );

      as::ast::ArgumentsPtr args( new as::ast::Arguments);
      _node_stack . top () -> addNodeChild( args );
      _node_stack . push( args );
  }

  void endAgumentList() {

      printf(" %lu endAgumentList\n", _node_stack.size() );
      _node_stack . pop( );
  }

  void endCallExpression()
  {

      printf(" %lu endCallExpression\n", _node_stack.size() );
      _node_stack . pop( );
  }
  void startBinaryExpression(const generated::BinaryExpression& op)
  {

      printf(" %lu startBinaryExpression\n", _node_stack.size() );

      as::ast::BinaryOperatorPtr as_node( new as::ast::BinaryOperator(op.op));
      _node_stack . top() -> addNodeChild(as_node);
      _node_stack . push(as_node);
  }
  void endBinaryExpression() {

      printf(" %lu endBinaryExpression\n", _node_stack.size() );
      _node_stack . pop( );

  }
  void startVariableDeclare() {
      printf(" %lu startVariableDeclare\n", _node_stack.size());
      as::ast::VariableDeclarePtr as_node(new as::ast::VariableDeclare());
      _node_stack . top() -> addNodeChild(as_node);
      _node_stack . push(as_node);
  }
  void endVariableDeclare() {

      printf(" %lu endVariableDeclare\n", _node_stack.size());
      _node_stack . pop();

  }

  void startAssignment() {
      printf(" %lu startAssignment\n", _node_stack.size());
      as::ast::AssignmentPtr as_node(new as::ast::Assignment());
      _node_stack . top() -> addNodeChild(as_node);
      _node_stack . push(as_node);
  }
  void endAssignment() {
      printf(" %lu endAssignment\n", _node_stack.size());
      _node_stack . pop();

  }
  void startUnaryExpression(const generated::UnaryExpression& op)
  {

      printf("startUnaryExpression\n");
      as::ast::UnaryOperatorPtr as_node( new as::ast::UnaryOperator(op.op));
      _node_stack . top() -> addNodeChild(as_node);
      _node_stack . push(as_node);
  }
  void endUnaryExpression() {

      printf("endUnaryExpression\n");
      _node_stack . pop( );

  }


  void startReturnStatement()
  {

      printf(" %lu startReturnStatement\n", _node_stack.size() );
      as::ast::ReturnStatementPtr op( new as::ast::ReturnStatement);
      _node_stack . top() -> addNodeChild(op);
      _node_stack . push(op);
  }

  void endReturnStatement()
  {

      printf(" %lu endReturnStatement\n", _node_stack.size() );
      _node_stack . pop();
  }

  void identifierExpression(const generated::Identifier& id)
  {

      printf(" %lu identifierExpression\n", _node_stack.size() );
      as::ast::IdentifierPtr exp_id( new as::ast::Identifier(id.name) );
      _node_stack . top () -> addNodeChild( exp_id);
  }

  virtual void literalStringExpression(const generated::Literal& str)
  {
      as::ast::LiteralStringPtr exp_literal( new as::ast::LiteralString( str.value ) );
      _node_stack . top () -> addNodeChild( exp_literal);
  }
  virtual void literalNumberExpression(const generated::Literal& num)
  {
      as::ast::LiteralNumberPtr exp_literal( new as::ast::LiteralNumber( num.value ) );
      _node_stack . top () -> addNodeChild( exp_literal);
  }
  virtual void literalBooleanExpression(const generated::Literal& num)
  {
      as::ast::LiteralBooleanPtr exp_literal( new as::ast::LiteralBoolean( num.value ) );
      _node_stack . top () -> addNodeChild( exp_literal);
  }
  void endExpressionList() {

      printf(" %lu endExpressionList\n", _node_stack.size() );
      _node_stack . pop ();
  }

  void addImport(const generated::StringList& packages) {

      printf(" %lu addImport\n", _node_stack.size() );
  }

  void startStmtList() {

      printf(" %lu startStmtList\n", _node_stack.size() );
      as::ast::StatementListPtr stmts( new as::ast::StatementList);
      _node_stack . top () -> addNodeChild( stmts );
      _node_stack . push( stmts );
  }

  void endStmtList() {
      printf(" %lu endStmtList\n", _node_stack.size() );
      _node_stack . pop ();
  }

  void startIfStatement() {

      printf(" %lu startIfStatement\n", _node_stack.size() );

      as::ast::IfStatementPtr ifStmt( new as::ast::IfStatement );
      _node_stack . top() -> addNodeChild( ifStmt );
      _node_stack . push( ifStmt );
  }
  void startIfStatement_Condition() {

      printf(" %lu startIfStatement_Condition\n", _node_stack.size() );

      as::ast::IfStatementConditionPtr ifStmt( new as::ast::IfStatementCondition );
      _node_stack . top() -> addNodeChild(ifStmt  );
      _node_stack . push( ifStmt );
  }
  void startIfStatement_Then() {

      printf(" %lu startIfStatement_Then\n", _node_stack.size() );

      as::ast::IfStatementThenPtr ifStmt( new as::ast::IfStatementThen );
      _node_stack . top() -> addNodeChild(ifStmt  );
      _node_stack . push( ifStmt );
  }
  void startIfStatement_Else() {

      printf(" %lu startIfStatement_Else\n", _node_stack.size() );

      as::ast::IfStatementElsePtr ifStmt( new as::ast::IfStatementElse );
      _node_stack . top() -> addNodeChild( ifStmt  );
      _node_stack . push( ifStmt );
  }
  void endIfStatement() {
      printf(" %lu endIfStatement\n", _node_stack.size() );
       CHECK_STACK_AND_POP( AST::Node::NodeType::T_IF_STMT );
      _node_stack . pop ();
  }
  void endIfStatement_Condition() {
      printf(" %lu endIfStatement_Condition\n", _node_stack.size() );
       CHECK_STACK_AND_POP( AST::Node::NodeType::T_IF_STMT_CONDITION );
      _node_stack . pop ();
  }
  void endIfStatement_Then() {
      printf(" %lu endIfStatement_Then\n", _node_stack.size() );
       CHECK_STACK_AND_POP( AST::Node::NodeType::T_IF_STMT_THEN );
      _node_stack . pop ();
  }
  void endtIfStatement_Else() {
      printf(" %lu endIfStatement_Else\n", _node_stack.size() );
       CHECK_STACK_AND_POP( AST::Node::NodeType::T_IF_STMT_ELSE );
      _node_stack . pop ();
  }

  void startClassDefine()
  {
      printf(" %lu startClassDefine\n", _node_stack.size() );
      as::ast::ClassDefinePtr exp_list( new as::ast::ClassDefine );
      _node_stack . top() -> addNodeChild( exp_list );
      _node_stack . push( exp_list );
  }
  void startClassName()
    {
        printf(" %lu startClassName\n", _node_stack.size() );
        as::ast::ClassNamePtr exp_list( new as::ast::ClassName );
        _node_stack . top() -> addNodeChild( exp_list );
        _node_stack . push( exp_list );
    }
  void startClassStmt()
      {
          printf(" %lu startClassStmt\n", _node_stack.size() );
          as::ast::ClassStmtPtr exp_list( new as::ast::ClassStmt );
          _node_stack . top() -> addNodeChild( exp_list );
          _node_stack . push( exp_list );
      }
  void endClassDefine() {
      printf(" %lu endClassDefine\n", _node_stack.size() );
      CHECK_STACK_AND_POP( AST::Node::NodeType::T_CLASS_DEFINE );
      _node_stack . pop ();
  }
  void endClassName() {
        printf(" %lu endClassName\n", _node_stack.size() );
        CHECK_STACK_AND_POP( AST::Node::NodeType::T_CLASS_DEFINE_NAME );
        _node_stack . pop ();
    }
  void endClassStmt() {
        printf(" %lu endClassDefine\n", _node_stack.size() );
        CHECK_STACK_AND_POP( AST::Node::NodeType::T_CLASS_DEFINE_STMT );
        _node_stack . pop ();
    }
public:
   as::ast::ProgramPtr getProgramNode() {	return _program_root;	};

private:
    std::stack< as::ast::NodePtr > 			_node_stack;

     as::ast::ProgramPtr _program_root;

};

} } 

#endif
