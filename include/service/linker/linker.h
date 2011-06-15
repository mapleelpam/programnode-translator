/* ******************************************************************\
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com       *
 *                                                                   *
 * Licensed under the Apache License, Version 2.0 (the "License");   *
 * you may not use this file except in compliance with the License.  *
 * You may obtain a copy of the License at                           *
 *                                                                   *
 *   http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                   *
 * Unless required by applicable law or agreed to in writing,        *
 * software distributed under the License is distributed on an       *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY            *
 * KIND, either express or implied. See the License for the          *
 * specific language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 *     https://github.com/mapleelpam/programnode-translator          *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#ifndef __TW_MAPLE_SERVICE_LINLER_LINKER_H__
#define __TW_MAPLE_SERVICE_LINLER_LINKER_H__

#include <AstDumper.h>
#include <transport/TSimpleFileTransport.h>
#include <protocol/TJSONProtocol.h>

//using namespace ::apache::thrift;
//using namespace ::apache::thrift::protocol;
//using namespace ::apache::thrift::transport;
//using namespace ::apache::thrift::server;

namespace tw { namespace maple { namespace service { namespace linker {

class Linker : virtual public generated::AstDumperIf {

 public:
	boost::shared_ptr<tw::maple::generated::AstDumperClient> pm_module;

  Linker( std::string fn )
  	  : pm_module( )
  {
	  boost::shared_ptr<apache::thrift::transport::TSimpleFileTransport> transport( new apache::thrift::transport::TSimpleFileTransport( fn, true, true ) );
	  boost::shared_ptr<apache::thrift::protocol::TProtocol> protocol( new  apache::thrift::protocol::TJSONProtocol(transport) );

      pm_module.reset( new tw::maple::generated::AstDumperClient( protocol ) );
  }

  void startProgram(const std::string& version, const int64_t counter) {
    // Your implementation goes here
    printf("startProgram\n");
  }

  void endProgram() {
    // Your implementation goes here
    printf("endProgram\n");
  }

  void startPackage(const std::vector<std::string> & id) {
    // Your implementation goes here
    printf("startPackage\n");
    pm_module->startPackage( id );
  }

  void endPackage(const std::vector<std::string> & IDs) {
    // Your implementation goes here
    printf("endPackage\n");
    pm_module->endPackage( IDs );
  }

  void startFunctionDefinition(const bool isAbstract) {
    // Your implementation goes here
    printf("startFunctionDefinition\n");
    pm_module->startFunctionDefinition(isAbstract);
  }

  void functionAttribute(const std::vector<std::string> & attrs) {
    // Your implementation goes here
    printf("functionAttribute\n");
    pm_module->functionAttribute(attrs);
  }

  void functionName(const std::string& name, tw::maple::generated::FunctionType::type t) {
    // Your implementation goes here
    printf("functionName\n");
    pm_module->functionName(name, t);
  }

  void startFunctionCommon() {
    // Your implementation goes here
    printf("startFunctionCommon\n");
    pm_module->startFunctionCommon();
  }

  void startFunctionSignature(const std::string& type) {
    // Your implementation goes here
    printf("startFunctionSignature\n");
    pm_module->startFunctionSignature( type );
  }

  void startFunctionSignatureParameters() {
    // Your implementation goes here
    printf("startFunctionSignatureParameters\n");
    pm_module->startFunctionSignatureParameters();
  }

  void startFunctionSignatureParameterMember(const std::string& name, const std::vector<std::string> & type) {
    // Your implementation goes here
    printf("startFunctionSignatureParameterMember\n");
    pm_module->startFunctionSignatureParameterMember( name, type );
  }

  void endFunctionSignatureParameterMember() {
    // Your implementation goes here
    printf("endFunctionSignatureParameterMember\n");
    pm_module->endFunctionSignatureParameterMember();
  }

  void endFunctionSignatureParameters() {
    // Your implementation goes here
    printf("endFunctionSignatureParameters\n");
    pm_module->endFunctionSignatureParameters();
  }

  void endFunctionSignature() {
    // Your implementation goes here
    printf("endFunctionSignature\n");
    pm_module->endFunctionSignature();
  }

  void endFunctionCommon() {
    // Your implementation goes here
    printf("endFunctionCommon\n");
    pm_module->endFunctionCommon();
  }

  void endFunctionDefinition() {
    // Your implementation goes here
    printf("endFunctionDefinition\n");
    pm_module->endFunctionDefinition();
  }

  void startReturnStatement() {
    // Your implementation goes here
    printf("startReturnStatement\n");
    pm_module->startReturnStatement();
  }

  void endReturnStatement() {
    // Your implementation goes here
    printf("endReturnStatement\n");
    pm_module->endReturnStatement();
  }

  void startExprCondition() {
    // Your implementation goes here
    printf("startExprCondition\n");
    pm_module->startExprCondition();
  }

  void endExprCondition() {
    // Your implementation goes here
    printf("endExprCondition\n");
    pm_module->endExprCondition();
  }

  void startIfStatement() {
    // Your implementation goes here
    printf("startIfStatement\n");
    pm_module->startIfStatement();
  }

  void endIfStatement() {
    // Your implementation goes here
    printf("endIfStatement\n");
    pm_module->endIfStatement();
  }

  void startStmtExpression() {
    // Your implementation goes here
    printf("startStmtExpression\n");
    pm_module->startStmtExpression();
  }

  void endStmtExpression() {
    // Your implementation goes here
    printf("endStmtExpression\n");
    pm_module->endStmtExpression();
  }

  void startExpressionList() {
    // Your implementation goes here
    printf("startExpressionList\n");
    pm_module->startExpressionList();
  }

  void startCallExpression(const generated::CallExpression& call) {
    // Your implementation goes here
    printf("startCallExpression\n");
    pm_module->startCallExpression(call);
  }

  void startArgumentList() {
    // Your implementation goes here
    printf("startArgumentList\n");
    pm_module->startArgumentList();
  }

  void startOneArgument() {
    // Your implementation goes here
    printf("startOneArgument\n");
    pm_module->startOneArgument();
  }

  void endOneArgument() {
    // Your implementation goes here
    printf("endOneArgument\n");
    pm_module->endOneArgument();
  }

  void endArgumentList() {
    // Your implementation goes here
    printf("endArgumentList\n");
    pm_module->endArgumentList();
  }

  void endCallExpression() {
    // Your implementation goes here
    printf("endCallExpression\n");
    pm_module->endCallExpression();
  }

  void startBinaryExpression(const generated::BinaryExpression& op) {
    // Your implementation goes here
    printf("startBinaryExpression\n");
    pm_module->startBinaryExpression(op);
  }

  void endBinaryExpression() {
    // Your implementation goes here
    printf("endBinaryExpression\n");
    pm_module->endBinaryExpression();
  }

  void startInstanceOfExpression() {
    // Your implementation goes here
    printf("startInstanceOfExpression\n");
    pm_module->startInstanceOfExpression();
  }

  void endInstanceOfExpression() {
    // Your implementation goes here
    printf("endInstanceOfExpression\n");
    pm_module->endInstanceOfExpression();
  }

  void startIsOperator() {
    // Your implementation goes here
    printf("startIsOperator\n");
    pm_module->startIsOperator();
  }

  void endIsOperator() {
    // Your implementation goes here
    printf("endIsOperator\n");
    pm_module->endIsOperator();
  }

  void startUnaryExpression(const generated::UnaryExpression& op) {
    // Your implementation goes here
    printf("startUnaryExpression\n");
    pm_module->startUnaryExpression(op);
  }

  void endUnaryExpression() {
    // Your implementation goes here
    printf("endUnaryExpression\n");
    pm_module->endUnaryExpression();
  }

  void startVariableDeclare(const generated::VariableDeclare& var_decl) {
    // Your implementation goes here
    printf("startVariableDeclare\n");
    pm_module->startVariableDeclare(var_decl);
  }

  void endVariableDeclare() {
    // Your implementation goes here
    printf("endVariableDeclare\n");
    pm_module->endVariableDeclare();
  }

  void startAssignment() {
    // Your implementation goes here
    printf("startAssignment\n");
    pm_module->startAssignment();
  }

  void endAssignment() {
    // Your implementation goes here
    printf("endAssignment\n");
    pm_module->endAssignment();
  }

  void identifierExpression(const generated::Identifier& id) {
    // Your implementation goes here
    printf("identifierExpression\n");
    pm_module->identifierExpression(id);
  }

  void literalStringExpression(const generated::Literal& str) {
    // Your implementation goes here
    printf("literalStringExpression\n");
    pm_module->literalStringExpression(str);
  }

  void literalNumberExpression(const generated::Literal& str) {
    // Your implementation goes here
    printf("literalNumberExpression\n");
    pm_module->literalNumberExpression(str);
  }

  void literalBooleanExpression(const generated::Literal& str) {
    // Your implementation goes here
    printf("literalBooleanExpression\n");
    pm_module->literalBooleanExpression(str);
  }

  void endExpressionList() {
    // Your implementation goes here
    printf("endExpressionList\n");
    pm_module->endExpressionList();
  }

  void addImport(const std::vector<std::string> & packages) {
    // Your implementation goes here
    printf("addImport\n");
    pm_module->addImport(packages);
  }

  void startStmtList() {
    // Your implementation goes here
    printf("startStmtList\n");
    pm_module->startStmtList();
  }

  void endStmtList() {
    // Your implementation goes here
    printf("endStmtList\n");
    pm_module->endStmtList();
  }

  void startScope() {
    // Your implementation goes here
    printf("startScope\n");
    pm_module->startScope();
  }

  void endScope() {
    // Your implementation goes here
    printf("endScope\n");
    pm_module->endScope();
  }

  void startClassDefinition(const generated::ClassDefinition& class_define) {
    // Your implementation goes here
    printf("startClassDefinition\n");
    pm_module->startClassDefinition(class_define);
  }

  void startClassStmt() {
    // Your implementation goes here
    printf("startClassStmt\n");
    pm_module->startClassStmt();
  }

  void endClassStmt() {
    // Your implementation goes here
    printf("endClassStmt\n");
    pm_module->endClassStmt();
  }

  void endClassDefinition() {
    // Your implementation goes here
    printf("endClassDefinition\n");
    pm_module->endClassDefinition();
  }

  void startAttributeList() {
    // Your implementation goes here
    printf("startAttributeList\n");
    pm_module->startAttributeList();
  }

  void endAttributelist() {
    // Your implementation goes here
    printf("endAttributelist\n");
    pm_module->endAttributelist();
  }

  void startMemberExpression() {
    // Your implementation goes here
    printf("startMemberExpression\n");
    pm_module->startMemberExpression();
  }

  void endMemberExpression() {
    // Your implementation goes here
    printf("endMemberExpression\n");
    pm_module->endMemberExpression();
  }

  void startForStatement() {
    // Your implementation goes here
    printf("startForStatement\n");
    pm_module->startForStatement();
  }

  void startForInit() {
    // Your implementation goes here
    printf("startForInit\n");
    pm_module->startForInit();
  }

  void endForInit() {
    // Your implementation goes here
    printf("endForInit\n");
    pm_module->endForInit();
  }

  void startForStep() {
    // Your implementation goes here
    printf("startForStep\n");
    pm_module->startForStep();
  }

  void endForStep() {
    // Your implementation goes here
    printf("endForStep\n");
    pm_module->endForStep();
  }

  void endForStatement() {
    // Your implementation goes here
    printf("endForStatement\n");
    pm_module->endForStatement();
  }

  void startDoStatement() {
    // Your implementation goes here
    printf("startDoStatement\n");
    pm_module->startDoStatement();
  }

  void endDoStatement() {
    // Your implementation goes here
    printf("endDoStatement\n");
    pm_module->endDoStatement();
  }

  void startWhileStatement() {
    // Your implementation goes here
    printf("startWhileStatement\n");
    pm_module->startWhileStatement();
  }

  void endWhileStatement() {
    // Your implementation goes here
    printf("endWhileStatement\n");
    pm_module->endWhileStatement();
  }

  void defineMetaData(const generated::MetaData& metadata) {
    // Your implementation goes here
    printf("defineMetaData\n");
    pm_module->defineMetaData( metadata );
  }

};

} } } } //tw::maple::service::linker

#endif
