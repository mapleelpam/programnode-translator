
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
#include <as/ast/literal.h>
#include <as/ast/expression_list.h>

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

    std::tr1::shared_ptr<as::ast::ExpressionList> exp_list( new as::ast::ExpressionList );
    if( !_node_stack . empty() )
         _node_stack . top () -> addChild( exp_list );
    _node_stack . push( exp_list );
  }

  void startCallExpression(const generated::CallExpression& call) {
    // Your implementation goes here
    printf("startCallExpression\n");

    std::tr1::shared_ptr<as::ast::Call> exp_call( new as::ast::Call );
    _node_stack . top () -> addChild( exp_call );
    _node_stack . push( exp_call );
  }

  void startAgumentList() {
    // Your implementation goes here
    printf("startAgumentList\n");
    
    std::tr1::shared_ptr<as::ast::ExpressionList> exp_list( new as::ast::ExpressionList);
    _node_stack . top () -> addChild( exp_list );
    _node_stack . push( exp_list );
  }

  void endAgumentList() {
    // Your implementation goes here
    printf("endAgumentList\n");
    _node_stack . pop( );
  }

  void endCallExpression() {
    // Your implementation goes here
    printf("endCallExpression\n");
    _node_stack . pop( );
  }

  void identifierExpression(const generated::Identifier& id) {
    // Your implementation goes here
    printf("identifierExpression\n");
    std::tr1::shared_ptr<as::ast::Literal> exp_literal( new as::ast::Literal(id.name) );
    _node_stack . top () -> addChild( exp_literal);
  }

  void endExpressionList() {
    // Your implementation goes here
    printf("endExpressionList\n");
    _node_stack . pop ();
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

private:
    std::vector< as::ast::ExpressionPtr > _arguments; 
    std::stack< as::ast::ExpressionPtr > _node_stack;
};

} } 

#endif
