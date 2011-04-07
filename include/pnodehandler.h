
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
#include <as/ast/literal_string.h>
#include <as/ast/expression_list.h>
#include <as/ast/identifier.h>
#include <as/ast/program.h>
#include <as/ast/arguments.h>
#include <as/ast/node.h>

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

  void startProgram()
  {
    printf("startProgram\n");

    _program_root . reset( new as::ast::Program() );
    _node_stack.push( _program_root );
  }

  void endProgram()
  {
    // Your implementation goes here
    printf("endProgram\n");

    // DO FOR WHAT?
  }

  void startPackage(const generated::StringList& id) {
    // Your implementation goes here
    printf("startPackage\n");
  }

  void endPackage(const generated::StringList& IDs) {
    // Your implementation goes here
    printf("endPackage\n");
  }

  void startExpressionList()
  {
    // Your implementation goes here
    printf("startExpressionList\n");

    std::tr1::shared_ptr<as::ast::ExpressionList> exp_list( new as::ast::ExpressionList );
    _node_stack . top() -> addNodeChild( exp_list );
    _node_stack . push( exp_list );
  }

  void startCallExpression(const generated::CallExpression& call)
  {
	  // Your implementation goes here
		printf("startCallExpression\n");

		std::tr1::shared_ptr < as::ast::Call > exp_call(new as::ast::Call);
		_node_stack . top() -> addNodeChild(exp_call);
	    _node_stack . push( exp_call );
  }

  void startAgumentList() {
    // Your implementation goes here
    printf("startAgumentList\n");
    
    std::tr1::shared_ptr<as::ast::Arguments> args( new as::ast::Arguments);
    _node_stack . top () -> addNodeChild( args );
    _node_stack . push( args );
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
    std::tr1::shared_ptr<as::ast::Identifier> exp_id( new as::ast::Identifier(id.name) );
    _node_stack . top () -> addNodeChild( exp_id);
  }

  virtual void literalStringExpression(const generated::LiteralString& str)
  {
	    std::tr1::shared_ptr<as::ast::LiteralString> exp_literal( new as::ast::LiteralString( str.value ) );
	    _node_stack . top () -> addNodeChild( exp_literal);
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

public:
  std::tr1::shared_ptr< as::ast::Program > getProgramNode() {	return _program_root;	};

private:
    std::stack< as::ast::NodePtr > 			_node_stack;

    std::tr1::shared_ptr< as::ast::Program > _program_root;

};

} } 

#endif
