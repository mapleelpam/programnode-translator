
#include <iostream>
#include "AstDumper.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TSimpleFileTransport.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

class AstDumperHandler : virtual public ast::dumper::AstDumperIf 
{
 public:
  AstDumperHandler() {
   // Your initialization goes here
  }

  void ping() {
   // Your implementation goes here
    printf("ping\n");
  }
  void ping2( const int32_t a) {
   // Your implementation goes here
    printf("ping2 %d\n",a);
  }


};

int main(int argc, char **argv) {

    boost::shared_ptr<AstDumperHandler> something( new AstDumperHandler() );
    boost::shared_ptr<TSimpleFileTransport> transport(new TSimpleFileTransport("1.pn",true,true));
    boost::shared_ptr<ast::dumper::AstDumperProcessor> processor( new ast::dumper::AstDumperProcessor( something ) );



    try {
        AstDumperHandler something;

        transport->open();
        boost::shared_ptr<TProtocol> io(new TBinaryProtocol(transport));
        
        processor->process( io, io, NULL );
        processor->process( io, io, NULL );

        transport->close();

    }
    catch (TTransportException ex )
    {
        std::cout << "handler: " << ex.what()<<std::endl;
        return 1;
    }

    return 0;
}
