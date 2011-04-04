
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

namespace tw { namespace maple { namespace generated {

class AstDumperHandler : virtual public  AstDumperIf {
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

} } } 

int main(int argc, char **argv) {

    boost::shared_ptr<tw::maple::generated::AstDumperHandler> something( new tw::maple::generated::AstDumperHandler() );
    boost::shared_ptr<TSimpleFileTransport> transport(new TSimpleFileTransport("1.pn",true,true));
    boost::shared_ptr<tw::maple::generated::AstDumperProcessor> processor( new tw::maple::generated::AstDumperProcessor( something ) );



    try {
        transport->open();
        boost::shared_ptr<TProtocol> io(new TBinaryProtocol(transport));
        
//        processor->process( io, io, NULL );
//        processor->process( io, io, NULL );

        transport->close();

    }
    catch (TTransportException ex )
    {
        std::cout << "handler: " << ex.what()<<std::endl;
        return 1;
    }

    return 0;
}
