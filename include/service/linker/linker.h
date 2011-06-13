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

#include "AstDumper.h"


//using namespace ::apache::thrift;
//using namespace ::apache::thrift::protocol;
//using namespace ::apache::thrift::transport;
//using namespace ::apache::thrift::server;

namespace tw { namespace maple { namespace service { namespace linker {

class Linker : virtual public generated::AstDumperIf {
 public:
  Linker() {
    // Your initialization goes here
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
  }

  void endPackage(const std::vector<std::string> & IDs) {
    // Your implementation goes here
    printf("endPackage\n");
  }

  void startFunctionDefinition(const bool isAbstract) {
    // Your implementation goes here
    printf("startFunctionDefinition\n");
  }

  void functionAttribute(const std::vector<std::string> & attrs) {
    // Your implementation goes here
    printf("functionAttribute\n");
  }

  void functionName(const std::string& name) {
    // Your implementation goes here
    printf("functionName\n");
  }

  void startFunctionCommon() {
    // Your implementation goes here
    printf("startFunctionCommon\n");
  }

  void startFunctionSignature(const std::string& type) {
    // Your implementation goes here
    printf("startFunctionSignature\n");
  }

  void startFunctionSignatureParameters() {
    // Your implementation goes here
    printf("startFunctionSignatureParameters\n");
  }

  void startFunctionSignatureParameterMember(const std::string& name, const std::vector<std::string> & type) {
    // Your implementation goes here
    printf("startFunctionSignatureParameterMember\n");
  }

  void endFunctionSignatureParameterMember() {
    // Your implementation goes here
    printf("endFunctionSignatureParameterMember\n");
  }

  void endFunctionSignatureParameters() {
    // Your implementation goes here
    printf("endFunctionSignatureParameters\n");
  }

  void endFunctionSignature() {
    // Your implementation goes here
    printf("endFunctionSignature\n");
  }

  void endFunctionCommon() {
    // Your implementation goes here
    printf("endFunctionCommon\n");
  }

  void endFunctionDefinition() {
    // Your implementation goes here
    printf("endFunctionDefinition\n");
  }

  void startReturnStatement() {
    // Your implementation goes here
    printf("startReturnStatement\n");
  }

  void endReturnStatement() {
    // Your implementation goes here
    printf("endReturnStatement\n");
  }

  void startExprCondition() {
    // Your implementation goes here
    printf("startExprCondition\n");
  }

  void endExprCondition() {
    // Your implementation goes here
    printf("endExprCondition\n");
  }

  void startIfStatement() {
    // Your implementation goes here
    printf("startIfStatement\n");
  }

  void endIfStatement() {
    // Your implementation goes here
    printf("endIfStatement\n");
  }

  void startStmtExpression() {
    // Your implementation goes here
    printf("startStmtExpression\n");
  }

  void endStmtExpression() {
    // Your implementation goes here
    printf("endStmtExpression\n");
  }

  void startExpressionList() {
    // Your implementation goes here
    printf("startExpressionList\n");
  }

  void startCallExpression(const generated::CallExpression& call) {
    // Your implementation goes here
    printf("startCallExpression\n");
  }

  void startArgumentList() {
    // Your implementation goes here
    printf("startArgumentList\n");
  }

  void startOneArgument() {
    // Your implementation goes here
    printf("startOneArgument\n");
  }

  void endOneArgument() {
    // Your implementation goes here
    printf("endOneArgument\n");
  }

  void endArgumentList() {
    // Your implementation goes here
    printf("endArgumentList\n");
  }

  void endCallExpression() {
    // Your implementation goes here
    printf("endCallExpression\n");
  }

  void startBinaryExpression(const generated::BinaryExpression& op) {
    // Your implementation goes here
    printf("startBinaryExpression\n");
  }

  void endBinaryExpression() {
    // Your implementation goes here
    printf("endBinaryExpression\n");
  }

  void startInstanceOfExpression() {
    // Your implementation goes here
    printf("startInstanceOfExpression\n");
  }

  void endInstanceOfExpression() {
    // Your implementation goes here
    printf("endInstanceOfExpression\n");
  }

  void startIsOperator() {
    // Your implementation goes here
    printf("startIsOperator\n");
  }

  void endIsOperator() {
    // Your implementation goes here
    printf("endIsOperator\n");
  }

  void startUnaryExpression(const generated::UnaryExpression& op) {
    // Your implementation goes here
    printf("startUnaryExpression\n");
  }

  void endUnaryExpression() {
    // Your implementation goes here
    printf("endUnaryExpression\n");
  }

  void startVariableDeclare(const generated::VariableDeclare& var_decl) {
    // Your implementation goes here
    printf("startVariableDeclare\n");
  }

  void endVariableDeclare() {
    // Your implementation goes here
    printf("endVariableDeclare\n");
  }

  void startAssignment() {
    // Your implementation goes here
    printf("startAssignment\n");
  }

  void endAssignment() {
    // Your implementation goes here
    printf("endAssignment\n");
  }

  void identifierExpression(const generated::Identifier& id) {
    // Your implementation goes here
    printf("identifierExpression\n");
  }

  void literalStringExpression(const generated::Literal& str) {
    // Your implementation goes here
    printf("literalStringExpression\n");
  }

  void literalNumberExpression(const generated::Literal& str) {
    // Your implementation goes here
    printf("literalNumberExpression\n");
  }

  void literalBooleanExpression(const generated::Literal& str) {
    // Your implementation goes here
    printf("literalBooleanExpression\n");
  }

  void endExpressionList() {
    // Your implementation goes here
    printf("endExpressionList\n");
  }

  void addImport(const std::vector<std::string> & packages) {
    // Your implementation goes here
    printf("addImport\n");
  }

  void startStmtList() {
    // Your implementation goes here
    printf("startStmtList\n");
  }

  void endStmtList() {
    // Your implementation goes here
    printf("endStmtList\n");
  }

  void startScope() {
    // Your implementation goes here
    printf("startScope\n");
  }

  void endScope() {
    // Your implementation goes here
    printf("endScope\n");
  }

  void startClassDefinition(const generated::ClassDefinition& class_define) {
    // Your implementation goes here
    printf("startClassDefinition\n");
  }

  void startClassStmt() {
    // Your implementation goes here
    printf("startClassStmt\n");
  }

  void endClassStmt() {
    // Your implementation goes here
    printf("endClassStmt\n");
  }

  void endClassDefinition() {
    // Your implementation goes here
    printf("endClassDefinition\n");
  }

  void startAttributeList() {
    // Your implementation goes here
    printf("startAttributeList\n");
  }

  void endAttributelist() {
    // Your implementation goes here
    printf("endAttributelist\n");
  }

  void startMemberExpression() {
    // Your implementation goes here
    printf("startMemberExpression\n");
  }

  void endMemberExpression() {
    // Your implementation goes here
    printf("endMemberExpression\n");
  }

  void startForStatement() {
    // Your implementation goes here
    printf("startForStatement\n");
  }

  void startForInit() {
    // Your implementation goes here
    printf("startForInit\n");
  }

  void endForInit() {
    // Your implementation goes here
    printf("endForInit\n");
  }

  void startForStep() {
    // Your implementation goes here
    printf("startForStep\n");
  }

  void endForStep() {
    // Your implementation goes here
    printf("endForStep\n");
  }

  void endForStatement() {
    // Your implementation goes here
    printf("endForStatement\n");
  }

  void startDoStatement() {
    // Your implementation goes here
    printf("startDoStatement\n");
  }

  void endDoStatement() {
    // Your implementation goes here
    printf("endDoStatement\n");
  }

  void startWhileStatement() {
    // Your implementation goes here
    printf("startWhileStatement\n");
  }

  void endWhileStatement() {
    // Your implementation goes here
    printf("endWhileStatement\n");
  }

  void defineMetaData(const generated::MetaData& metadata) {
    // Your implementation goes here
    printf("defineMetaData\n");
  }

};

//int main(int argc, char **argv) {
//  int port = 9090;
//  shared_ptr<Linker> handler(new Linker());
//  shared_ptr<TProcessor> processor(new AstDumperProcessor(handler));
//  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
//  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
//  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
//
//  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
//  server.serve();
//  return 0;
//}

} } } } //tw::maple::service::linker

#endif
