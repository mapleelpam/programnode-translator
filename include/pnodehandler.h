
#ifndef __AST_DUMPER_HANDLER__
#define __AST_DUMPER_HANDLER__

#include <iostream>
#include "AstDumper.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TSimpleFileTransport.h>
#include <protocol/TBinaryProtocol.h>

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

  void startProgram() {
    // Your implementation goes here
    printf("startProgram\n");
  }

  void endProgram() {
    // Your implementation goes here
    printf("endProgram\n");
  }

  void startPackage(const generated::StringList& id) {
    // Your implementation goes here
    printf("startPackage\n");
  }

  void endPackage(const generated::StringList& IDs) {
    // Your implementation goes here
    printf("endPackage\n");
  }

  void startExpressionList() {
    // Your implementation goes here
    printf("startExpressionList\n");
  }

  void startCallExpression(const generated::CallExpression& call) {
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

  void identifierExpression(const generated::Identifier& id) {
    // Your implementation goes here
    printf("identifierExpression\n");
  }

  void endExpressionList() {
    // Your implementation goes here
    printf("endExpressionList\n");
  }

  void addImport(const generated::StringList& packages) {
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

} } 

#endif
