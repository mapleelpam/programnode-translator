
#ifndef __AST_DUMPER_READER_
#define __AST_DUMPER_READER_

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TSimpleFileTransport.h>
#include <protocol/TBinaryProtocol.h>
#include <protocol/TJSONProtocol.h>

#include "pnodehandler.h" 

#include <as/ast/program.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

namespace tw { namespace maple { 


class PNodeReader 
{
public:
    static std::tr1::shared_ptr< as::ast::Program > open( std::string file )
    {
        boost::shared_ptr<tw::maple::PNodeHandler> something( new tw::maple::PNodeHandler() );
        boost::shared_ptr<TSimpleFileTransport> transport(new TSimpleFileTransport(file,true,true));
        boost::shared_ptr<tw::maple::generated::AstDumperProcessor> processor( new tw::maple::generated::AstDumperProcessor( something ) );

        transport->open();
        boost::shared_ptr<TProtocol> io(new TJSONProtocol(transport));

        try {
            while( true )
                processor->process( io, io, NULL );
        } catch (TTransportException ex ) {
            std::cout << "handler: " << ex.what()<<std::endl;
        }

        transport->close(); 

//        return  std::tr1::shared_ptr< as::ast::Program >();
        return something->getProgramNode();
    }

};

} }
#endif
