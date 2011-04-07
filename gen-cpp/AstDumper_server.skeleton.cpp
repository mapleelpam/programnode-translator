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

  void identifierExpression(const Identifier& id) {
    // Your implementation goes here
    printf("identifierExpression\n");
  }

  void literalStringExpression(const LiteralString& str) {
    // Your implementation goes here
    printf("literalStringExpression\n");
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

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void ping2(const int32_t echo) {
    // Your implementation goes here
    printf("ping2\n");
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

