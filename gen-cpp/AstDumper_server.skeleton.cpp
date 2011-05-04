// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "AstDumper.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace tw::maple::generated;

class AstDumperHandler : virtual public AstDumperIf {
 public:
  AstDumperHandler() {
    // Your initialization goes here
  }

  void startProgram() {
    // Your implementation goes here
    printf("startProgram\n");
  }

  void endProgram() {
    // Your implementation goes here
    printf("endProgram\n");
  }

  void startPackage(const StringList& id) {
    // Your implementation goes here
    printf("startPackage\n");
  }

  void endPackage(const StringList& IDs) {
    // Your implementation goes here
    printf("endPackage\n");
  }

  void startFunctionDefinition(const bool isAbstract) {
    // Your implementation goes here
    printf("startFunctionDefinition\n");
  }

  void functionAttribute(const StringList& attrs) {
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

  void startFunctionSignatureParameterMember(const std::string& name, const std::string& type) {
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

  void startIfStatement() {
    // Your implementation goes here
    printf("startIfStatement\n");
  }

  void startIfStatement_Condition() {
    // Your implementation goes here
    printf("startIfStatement_Condition\n");
  }

  void endIfStatement_Condition() {
    // Your implementation goes here
    printf("endIfStatement_Condition\n");
  }

  void startIfStatement_Then() {
    // Your implementation goes here
    printf("startIfStatement_Then\n");
  }

  void endIfStatement_Then() {
    // Your implementation goes here
    printf("endIfStatement_Then\n");
  }

  void startIfStatement_Else() {
    // Your implementation goes here
    printf("startIfStatement_Else\n");
  }

  void endtIfStatement_Else() {
    // Your implementation goes here
    printf("endtIfStatement_Else\n");
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

  void startCallExpression(const CallExpression& call) {
    // Your implementation goes here
    printf("startCallExpression\n");
  }

  void startAgumentList() {
    // Your implementation goes here
    printf("startAgumentList\n");
  }

  void endAgumentList() {
    // Your implementation goes here
    printf("endAgumentList\n");
  }

  void endCallExpression() {
    // Your implementation goes here
    printf("endCallExpression\n");
  }

  void startBinaryExpression(const BinaryExpression& op) {
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

  void startUnaryExpression(const UnaryExpression& op) {
    // Your implementation goes here
    printf("startUnaryExpression\n");
  }

  void endUnaryExpression() {
    // Your implementation goes here
    printf("endUnaryExpression\n");
  }

  void startVariableDeclare(const std::string& name, const std::string& type, const std::string& attributes) {
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

  void identifierExpression(const Identifier& id) {
    // Your implementation goes here
    printf("identifierExpression\n");
  }

  void literalStringExpression(const Literal& str) {
    // Your implementation goes here
    printf("literalStringExpression\n");
  }

  void literalNumberExpression(const Literal& str) {
    // Your implementation goes here
    printf("literalNumberExpression\n");
  }

  void literalBooleanExpression(const Literal& str) {
    // Your implementation goes here
    printf("literalBooleanExpression\n");
  }

  void endExpressionList() {
    // Your implementation goes here
    printf("endExpressionList\n");
  }

  void addImport(const StringList& packages) {
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

  void startClassDefine(const ClassDefine& class_define) {
    // Your implementation goes here
    printf("startClassDefine\n");
  }

  void startClassStmt() {
    // Your implementation goes here
    printf("startClassStmt\n");
  }

  void endClassStmt() {
    // Your implementation goes here
    printf("endClassStmt\n");
  }

  void endClassDefine() {
    // Your implementation goes here
    printf("endClassDefine\n");
  }

  void startAttributeList() {
    // Your implementation goes here
    printf("startAttributeList\n");
  }

  void endAttributelist() {
    // Your implementation goes here
    printf("endAttributelist\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<AstDumperHandler> handler(new AstDumperHandler());
  shared_ptr<TProcessor> processor(new AstDumperProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

