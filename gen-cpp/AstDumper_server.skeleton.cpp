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

  void executeImport(const std::vector<std::string> & id) {
    // Your implementation goes here
    printf("executeImport\n");
  }

  void startFunctionDefinition(const bool isAbstract) {
    // Your implementation goes here
    printf("startFunctionDefinition\n");
  }

  void functionAttribute(const std::vector<std::string> & attrs) {
    // Your implementation goes here
    printf("functionAttribute\n");
  }

  void functionName(const std::string& name, const FunctionType::type func_type) {
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

  void functionParameter(const std::string& name, const std::vector<std::string> & type, const bool has_init, const std::string& init) {
    // Your implementation goes here
    printf("functionParameter\n");
  }

  void functionParameterRest(const std::string& name) {
    // Your implementation goes here
    printf("functionParameterRest\n");
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

  void endIfStatement() {
    // Your implementation goes here
    printf("endIfStatement\n");
  }

  void startConditionExpression() {
    // Your implementation goes here
    printf("startConditionExpression\n");
  }

  void endConditionExpression() {
    // Your implementation goes here
    printf("endConditionExpression\n");
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

  void startInvokeExpression(const CallExpression& call) {
    // Your implementation goes here
    printf("startInvokeExpression\n");
  }

  void endInvokeExpression() {
    // Your implementation goes here
    printf("endInvokeExpression\n");
  }

  void startBinaryExpression(const BinaryExpression& op) {
    // Your implementation goes here
    printf("startBinaryExpression\n");
  }

  void endBinaryExpression() {
    // Your implementation goes here
    printf("endBinaryExpression\n");
  }

  void startFilter() {
    // Your implementation goes here
    printf("startFilter\n");
  }

  void endFilter() {
    // Your implementation goes here
    printf("endFilter\n");
  }

  void startIncrementExpression(const IncrementType::type type, const std::string& token) {
    // Your implementation goes here
    printf("startIncrementExpression\n");
  }

  void endIncrementExpression() {
    // Your implementation goes here
    printf("endIncrementExpression\n");
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

  void startAsOperator(const std::string& type_name) {
    // Your implementation goes here
    printf("startAsOperator\n");
  }

  void endAsOperator() {
    // Your implementation goes here
    printf("endAsOperator\n");
  }

  void startUnaryExpression(const UnaryExpression& op) {
    // Your implementation goes here
    printf("startUnaryExpression\n");
  }

  void endUnaryExpression() {
    // Your implementation goes here
    printf("endUnaryExpression\n");
  }

  void startVariableDeclare(const VariableDeclare& var_decl) {
    // Your implementation goes here
    printf("startVariableDeclare\n");
  }

  void endVariableDeclare() {
    // Your implementation goes here
    printf("endVariableDeclare\n");
  }

  void startSetExpression(const std::string& mode) {
    // Your implementation goes here
    printf("startSetExpression\n");
  }

  void endSetExpression() {
    // Your implementation goes here
    printf("endSetExpression\n");
  }

  void startGetExpression(const std::string& mode) {
    // Your implementation goes here
    printf("startGetExpression\n");
  }

  void endGetExpression() {
    // Your implementation goes here
    printf("endGetExpression\n");
  }

  void superExpression() {
    // Your implementation goes here
    printf("superExpression\n");
  }

  void startSuperInit() {
    // Your implementation goes here
    printf("startSuperInit\n");
  }

  void endSuperInit() {
    // Your implementation goes here
    printf("endSuperInit\n");
  }

  void identifierExpression(const Identifier& id) {
    // Your implementation goes here
    printf("identifierExpression\n");
  }

  void attributeIdentifierExpression(const Identifier& id) {
    // Your implementation goes here
    printf("attributeIdentifierExpression\n");
  }

  void literalXMLExpression(const std::string& str) {
    // Your implementation goes here
    printf("literalXMLExpression\n");
  }

  void literalStringExpression(const std::string& str) {
    // Your implementation goes here
    printf("literalStringExpression\n");
  }

  void literalNumberExpression(const std::string& str) {
    // Your implementation goes here
    printf("literalNumberExpression\n");
  }

  void literalBooleanExpression(const std::string& str) {
    // Your implementation goes here
    printf("literalBooleanExpression\n");
  }

  void literalArrayBegin() {
    // Your implementation goes here
    printf("literalArrayBegin\n");
  }

  void literalArrayEnd() {
    // Your implementation goes here
    printf("literalArrayEnd\n");
  }

  void literalNull() {
    // Your implementation goes here
    printf("literalNull\n");
  }

  void thisExpression() {
    // Your implementation goes here
    printf("thisExpression\n");
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

  void startClassDefinition(const ClassDefinition& class_define) {
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

  void startMemberExpression() {
    // Your implementation goes here
    printf("startMemberExpression\n");
  }

  void endMemberExpression() {
    // Your implementation goes here
    printf("endMemberExpression\n");
  }

  void startSwitchStatement() {
    // Your implementation goes here
    printf("startSwitchStatement\n");
  }

  void endSwitchStatement() {
    // Your implementation goes here
    printf("endSwitchStatement\n");
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

  void startTypeExpression() {
    // Your implementation goes here
    printf("startTypeExpression\n");
  }

  void endTypeExpression() {
    // Your implementation goes here
    printf("endTypeExpression\n");
  }

  void defineMetaData(const MetaData& metadata) {
    // Your implementation goes here
    printf("defineMetaData\n");
  }

  void startTryStatement() {
    // Your implementation goes here
    printf("startTryStatement\n");
  }

  void endTryStatement() {
    // Your implementation goes here
    printf("endTryStatement\n");
  }

  void startThrowStatement() {
    // Your implementation goes here
    printf("startThrowStatement\n");
  }

  void endThrowStatement() {
    // Your implementation goes here
    printf("endThrowStatement\n");
  }

  void startCatchClauseStatement() {
    // Your implementation goes here
    printf("startCatchClauseStatement\n");
  }

  void endCatchClauseStatement() {
    // Your implementation goes here
    printf("endCatchClauseStatement\n");
  }

  void startFinallyClauseStatement() {
    // Your implementation goes here
    printf("startFinallyClauseStatement\n");
  }

  void endFinallyClauseStatement() {
    // Your implementation goes here
    printf("endFinallyClauseStatement\n");
  }

  void startCaseLabel() {
    // Your implementation goes here
    printf("startCaseLabel\n");
  }

  void endCaseLabel() {
    // Your implementation goes here
    printf("endCaseLabel\n");
  }

  void defaultCaseLabel() {
    // Your implementation goes here
    printf("defaultCaseLabel\n");
  }

  void breakStatement() {
    // Your implementation goes here
    printf("breakStatement\n");
  }

  void continueStatement() {
    // Your implementation goes here
    printf("continueStatement\n");
  }

  void beginDeleteExpression(const std::string& mode) {
    // Your implementation goes here
    printf("beginDeleteExpression\n");
  }

  void endDeleteExpression() {
    // Your implementation goes here
    printf("endDeleteExpression\n");
  }

  void empty() {
    // Your implementation goes here
    printf("empty\n");
  }

  void startStoreRegister() {
    // Your implementation goes here
    printf("startStoreRegister\n");
  }

  void endStoreRegister() {
    // Your implementation goes here
    printf("endStoreRegister\n");
  }

  void startLoadRegister() {
    // Your implementation goes here
    printf("startLoadRegister\n");
  }

  void endLoadRegister() {
    // Your implementation goes here
    printf("endLoadRegister\n");
  }

  void registerNode(const int32_t reg) {
    // Your implementation goes here
    printf("registerNode\n");
  }

  void startHasNext() {
    // Your implementation goes here
    printf("startHasNext\n");
  }

  void endHasNext() {
    // Your implementation goes here
    printf("endHasNext\n");
  }

  void startCoerce() {
    // Your implementation goes here
    printf("startCoerce\n");
  }

  void endCoerce() {
    // Your implementation goes here
    printf("endCoerce\n");
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

