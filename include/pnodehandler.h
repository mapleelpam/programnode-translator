 /*******************************************************************\
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


#ifndef __AST_DUMPER_HANDLER__
#define __AST_DUMPER_HANDLER__

#include <iostream>
#include <stack>
#include "AstDumper.h"
#include "SyntaxTree_constants.h"

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TSimpleFileTransport.h>
#include <protocol/TBinaryProtocol.h>

#include <as/ast/node.h>
#include <as/ast/token/super_expression.h>
#include <as/ast/token/literal_string.h>
#include <as/ast/token/literal_number.h>
#include <as/ast/token/literal_boolean.h>
#include <as/ast/token/literal_null.h>
#include <as/ast/token/empty.h>
#include <as/ast/token/this_expression.h>
#include <as/ast/token/identifier.h>
#include <as/ast/expr/call.h>
#include <as/ast/expr/increment_operator.h>
#include <as/ast/expr/member_expression.h>
#include <as/ast/expr/arguments.h>
#include <as/ast/token/argument.h>
#include <as/ast/func/function_definition.h>
#include <as/ast/func/function_name.h>
#include <as/ast/func/function_signature.h>
#include <as/ast/func/function_parameters.h>
#include <as/ast/func/function_parameter_item.h>
#include <as/ast/func/function_parameter_rest.h>
#include <as/ast/func/function_common.h>
#include <as/ast/func/function_attribute.h>
#include <as/ast/expr/binary_operator.h>
#include <as/ast/expr/instanceof.h>
#include <as/ast/expr/is.h>
#include <as/ast/expr/as.h>
#include <as/ast/expr/super_init.h>
#include <as/ast/expr/unary_operator.h>
#include <as/ast/expr/set_expression.h>
#include <as/ast/expr/get_expression.h>
#include <as/ast/expr/type_expression.h>
#include <as/ast/expr/condition_expression.h>
#include <as/ast/expr/attribute_list.h>
#include <as/ast/stmt/variable_declare.h>
#include <as/ast/stmt/return_stmt.h>
#include <as/ast/stmt/statement_list.h>
#include <as/ast/stmt/stmt_expression.h>
#include <as/ast/stmt/if_stmt.h>
#include <as/ast/stmt/class_definition.h>
#include <as/ast/stmt/class_stmt.h>
#include <as/ast/stmt/package_definition.h>
#include <as/ast/stmt/for_stmt.h>
#include <as/ast/stmt/do_stmt.h>
#include <as/ast/stmt/while_stmt.h>
#include <as/ast/stmt/scope_statement.h>
#include <as/ast/stmt/import_stmt.h>
#include <as/ast/stmt/expression_list.h>
#include <as/ast/stmt/program.h>



using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
//tw::maple::generated::


namespace AST = ::tw::maple::as::ast;

#define PUSH_STACK( ClassName ) \
		{ \
		if( DEBUG ) \
		std::cout << _node_stack.size() << "  start"<< #ClassName  <<" -> "<< _node_stack.top()->toString()<<" -:"<<_node_stack.top()->node_childs.size()<< std::endl; \
		as::ast::ClassName##Ptr __node__( new as::ast::ClassName()  ); \
		_node_stack . top() -> addNodeChild( __node__ ); \
		_node_stack . push( __node__ ); }

#define ADD_2_TOP( ClassName ) \
		{ \
		if( DEBUG ) \
		std::cout << _node_stack.size() << "  start"<< #ClassName  <<" -> "<< _node_stack.top()->toString()<<" -:"<<_node_stack.top()->node_childs.size()<< std::endl; \
		as::ast::ClassName##Ptr __node__( new as::ast::ClassName()  ); \
		_node_stack . top() -> addNodeChild( __node__ ); }

#define PUSH_STACK_WITH_INIT( ClassName, ... ) \
		{ \
		if( DEBUG ) \
		 std::cout << _node_stack.size() << "  start"<< #ClassName  <<" -> "<< _node_stack.top()->toString()<<" -:"<<_node_stack.top()->node_childs.size()<< std::endl; \
		as::ast::ClassName##Ptr __node__( new as::ast::ClassName(  __VA_ARGS__ )  ); \
		_node_stack . top() -> addNodeChild( __node__ ); \
		_node_stack . push( __node__ ); }

#define ADD_2_TOP_WITH_INIT( ClassName, ... ) \
		{ \
		if( DEBUG ) \
		std::cout << _node_stack.size() << "  start"<< #ClassName  <<" -> "<< _node_stack.top()->toString()<<" -:"<<_node_stack.top()->node_childs.size()<< std::endl; \
		as::ast::ClassName##Ptr __node__( new as::ast::ClassName(  __VA_ARGS__ )  ); \
		_node_stack . top() -> addNodeChild( __node__ ); }

#define CHECK_STACK_AND_POP( ClassName, NODE_TYPE ) \
		{ \
			if( ! _node_stack.top()->is( NODE_TYPE)  ){ \
	            std::cerr << " protocol error ---- expect '"<<#NODE_TYPE<<"' but get '" << _node_stack . top() -> toString()<<"'"<<std::endl; \
	            std::cerr << "please contact mapleelpam at gmail com"<<std::endl; \
	            exit(1); \
	        } \
		/*printf(" %lu end"#ClassName"\n", _node_stack.size() );*/ \
		_node_stack . pop(); \
		}\

namespace tw { namespace maple { 

class PNodeHandler : virtual public  generated::AstDumperIf {
	int DEBUG;
public:
  PNodeHandler() : _meta_data_dirty(false) {
	  DEBUG = 1;
    // Your initialization goes here
  }

  void startProgram( const std::string& version, const int64_t counter ) {
//		printf(" %lu startProgram\n", _node_stack.size());
		if( version != generated::g_SyntaxTree_constants.PROTO_VERSION
		 || counter != generated::g_SyntaxTree_constants.PROTO_COUNTER)
		{
			std::cerr << "protocol version not match"<<std::endl; \
			std::cerr << "expected version is '"<< generated::g_SyntaxTree_constants.PROTO_VERSION << "' '" << generated::g_SyntaxTree_constants.PROTO_COUNTER << "'"<<std::endl;
			std::cerr << "expected version but get '"<< version << "' '" << counter << "'"<<std::endl;
			exit(1);
		}
		_program_root . reset(new as::ast::Program());
		_node_stack.push(_program_root);
	}

	void endProgram() {
//		printf(" %lu endProgram\n", _node_stack.size());
		// DO FOR WHAT?
	}

	void startPackage(const std::vector<std::string>& id) {
      PUSH_STACK_WITH_INIT( PackageDefinition, id );
	}

	void endPackage(const std::vector<std::string>& IDs) {
		CHECK_STACK_AND_POP( PackageDefinition, AST::Node::NodeType::T_PACKAGE_DEFINITION );
	}

	void startFunctionDefinition( bool is_abstract ) {
		PUSH_STACK_WITH_INIT( FunctionDefinition, is_abstract );
	}

	void functionName(const std::string& n, tw::maple::generated::FunctionType::type t ) {
		ADD_2_TOP_WITH_INIT( FunctionName, n, t );
	}

	void startFunctionSignature( const std::string& return_type_name ) {
		PUSH_STACK_WITH_INIT( FunctionSignature, return_type_name );
	}

	void endFunctionSignature() {
		CHECK_STACK_AND_POP( FunctionSignature, AST::Node::NodeType::T_FUNCTION_SIGNATURE );
	}

	void startFunctionSignatureParameters() {
		PUSH_STACK( FunctionParameters );
	}

	void functionParameter( const std::string& name, const std::vector<std::string>& type, bool has_init, const std::string& init ) {
		ADD_2_TOP_WITH_INIT( FunctionParameterItem, name, type, has_init, init );
	}
	void functionParameterRest( const std::string& name ) {
		ADD_2_TOP_WITH_INIT( FunctionParameterRest, name );
	}

	void endFunctionSignatureParameters() {
		CHECK_STACK_AND_POP( FunctionParameters, AST::Node::NodeType::T_FUNCTION_PARAMETERS );
	}

	void startFunctionCommon() {
		PUSH_STACK( FunctionCommon );
	}

	void endFunctionCommon() {
		CHECK_STACK_AND_POP( FunctionCommon, AST::Node::NodeType::T_FUNCTION_COMMON );
	}

	void endFunctionDefinition() {
		CHECK_STACK_AND_POP( FunctionDefinition, AST::Node::NodeType::T_FUNCTION_DEFINITION );
	}

	void startExpressionList() {
		PUSH_STACK( ExpressionList );
	}

	void startStmtExpression() {
		PUSH_STACK( StmtExpression );
	}
	void endStmtExpression() {
		CHECK_STACK_AND_POP( StmtExpression, AST::Node::NodeType::T_STMT_EXPR );
	}
	void startCallExpression(const generated::CallExpression& call) {
		PUSH_STACK_WITH_INIT( Call, call.callee, call.mode, call.is_new);
	}

	void startArgumentList() {
		PUSH_STACK( Arguments );
	}
	void endArgumentList() {
		CHECK_STACK_AND_POP( ArgumentList, AST::Node::NodeType::T_ARGUMENTS );
	}
	void startOneArgument() {
		PUSH_STACK( Argument );
	}
	void endOneArgument() {
		CHECK_STACK_AND_POP( Argument, AST::Node::NodeType::T_ARGUMENT );
	}

	void endCallExpression() {
		CHECK_STACK_AND_POP( CallExpression, AST::Node::NodeType::T_CALL );
	}
	void startBinaryExpression(const generated::BinaryExpression& op) {
		PUSH_STACK_WITH_INIT( BinaryOperator, op.op );

	}
	void endBinaryExpression() {
		CHECK_STACK_AND_POP( StmtExpression, AST::Node::NodeType::T_BINARY_OPERATOR );
	}
	void startInstanceOfExpression() {
		PUSH_STACK( InstanceOf );
	}
	void endInstanceOfExpression() {
		CHECK_STACK_AND_POP( InstanceOf, AST::Node::NodeType::T_INSTANCEOF );

	}
	void startIsOperator() {
		PUSH_STACK( Is );
	}
	void endIsOperator() {
		CHECK_STACK_AND_POP( Is, AST::Node::NodeType::T_IS );
	}
	void startAsOperator() {
		PUSH_STACK( As );
	}
	void endAsOperator() {
		CHECK_STACK_AND_POP( As, AST::Node::NodeType::T_AS );
	}
	void startVariableDeclare( const generated::VariableDeclare& var_decl ) {
		PUSH_STACK_WITH_INIT( VariableDeclare, var_decl );
	}
	void endVariableDeclare() {
		CHECK_STACK_AND_POP( Variable, AST::Node::NodeType::T_VARIABLE_DECLARE );
	}
	void startSetExpression( const std::string& mode ) {
		PUSH_STACK_WITH_INIT( SetExpression, mode );
	}
	void endSetExpression( ) {
		CHECK_STACK_AND_POP( SetExpression, AST::Node::NodeType::T_SET_EXPRESSION );
	}
	void startTypeExpression( ) {
		PUSH_STACK( TypeExpression );
	}
	void endTypeExpression( ) {
		CHECK_STACK_AND_POP( TypeExpression, AST::Node::NodeType::T_TYPE_EXPRESSION );
	}
	void startGetExpression( const std::string& mode ) {
		std::cerr <<"------------------------> get expression "<<mode<<std::endl;
		PUSH_STACK_WITH_INIT( GetExpression, mode );
	}
	void endGetExpression() {
		CHECK_STACK_AND_POP( GetExpression, AST::Node::NodeType::T_GET_EXPRESSION );
	}
	void startUnaryExpression(const generated::UnaryExpression& op) {
		PUSH_STACK_WITH_INIT( UnaryOperator, op.op );
	}
	void endUnaryExpression() {
		CHECK_STACK_AND_POP( UnaryOperator, AST::Node::NodeType::T_UNARY_OPERATOR );
	}
	void startReturnStatement() {
		PUSH_STACK( ReturnStatement);
	}
	void endReturnStatement() {
		CHECK_STACK_AND_POP( ReturnStatement, AST::Node::NodeType::T_RETURN_STATEMENT );
	}

	void startSuperInit() {
		PUSH_STACK( SuperInit );
	}
	void endSuperInit() {
		CHECK_STACK_AND_POP( SuperInit, AST::Node::NodeType::T_SUPER_INIT );
	}
	void identifierExpression(const generated::Identifier& id) {
		if(DEBUG)
		{
			std::cout << _node_stack.size() << "  identifierExpression" << " -> "
				<< _node_stack.top()->toString() << ":"
				<< _node_stack.top()->node_childs.size() << ":" << id.name << " qualifier "<<id.qualifier
				<< std::endl;
		}
		as::ast::IdentifierPtr exp_id(
				new as::ast::Identifier(id.name, id.qualifier));
		_node_stack . top() -> addNodeChild(exp_id);
	}
	virtual void superExpression( ) {
		as::ast::SuperExpressionPtr exp_super(
				new as::ast::SuperExpression() );
		_node_stack . top() -> addNodeChild( exp_super );
	}
	virtual void thisExpression( ) {
		as::ast::ThisExpressionPtr exp_this(
			new as::ast::ThisExpression() );
		_node_stack . top() -> addNodeChild( exp_this );
	}
	virtual void literalStringExpression(const generated::Literal& str) {
		as::ast::LiteralStringPtr exp_literal(
			new as::ast::LiteralString(str.value));
		_node_stack . top() -> addNodeChild(exp_literal);
	}
	virtual void literalNumberExpression(const generated::Literal& num) {
		as::ast::LiteralNumberPtr exp_literal(
			new as::ast::LiteralNumber(num.value));
		_node_stack . top() -> addNodeChild(exp_literal);
	}
	virtual void literalBooleanExpression(const generated::Literal& num) {
		as::ast::LiteralBooleanPtr exp_literal(new as::ast::LiteralBoolean(num.value));
		_node_stack . top() -> addNodeChild(exp_literal);
	}
	virtual void literalNull( ) {
//		as::ast::LiteralNullPtr exp_literal(new as::ast::LiteralNull());
//		_node_stack . top() -> addNodeChild(exp_literal);

		ADD_2_TOP( LiteralNull );
	}
	void endExpressionList() {
		CHECK_STACK_AND_POP( ExpressionList, AST::Node::NodeType::T_EXPR_LIST );
	}

	void addImport(const std::vector<std::string>& packages) {
		printf(" %lu addImport\n", _node_stack.size());
	}

	void startStmtList() {
		PUSH_STACK( StatementList );
	}

	void endStmtList() {
		CHECK_STACK_AND_POP( StmtList, AST::Node::NodeType::T_STMT_LIST );
	}

	void startIfStatement() {
		PUSH_STACK( IfStatement );
	}

	void endIfStatement() {
		CHECK_STACK_AND_POP( IfStatement, AST::Node::NodeType::T_STMT_IF );
	}

	void startClassDefinition(const generated::ClassDefinition& class_define) {
//		printf(" %lu startClassDefine\n", _node_stack.size());
		as::ast::ClassDefinitionPtr class_node(
				new as::ast::ClassDefinition(class_define.name, class_define.inherits, class_define.interfaces, class_define.attributes));

//		std::cerr <<"-----------> class define attribute "<<class_define.attribute<<std::endl;
		_node_stack . top() -> addNodeChild(class_node);
		_node_stack . push(class_node);

		class_node->setHasBaseClass(class_define.has_baseclass);
		class_node->setHasInterface(class_define.has_interface);
		class_node->setHasAttribute(class_define.has_attr);
		class_node->setHasStatement(class_define.has_stmt);

		//class_node->setIntrinsic(class_define.attribute == "intrinsic" );

		class_node->setIsAbstract( class_define.object_type == generated::ObjectType::TYPE_CLASS ? false : true );
		if(_meta_data_dirty) {
//			std::cerr <<" hey i just attach a metadata to a class define node"<<std::endl;
			class_node->setMetaData(_meta_data);
			_meta_data_dirty = false;
		}
	}

	void startClassStmt() {
//		printf(" %lu startClassStmt\n", _node_stack.size());
		as::ast::ClassStmtPtr exp_list(new as::ast::ClassStmt);
		_node_stack . top() -> addNodeChild(exp_list);
		_node_stack . push(exp_list);
	}
	void endClassDefinition() {
		CHECK_STACK_AND_POP( ClassDefine, AST::Node::NodeType::T_CLASS_DEFINE );
	}
	void endClassStmt() {
		CHECK_STACK_AND_POP( ClassStmt, AST::Node::NodeType::T_CLASS_DEFINE_STMT );
	}
	void executeImport(const std::vector<std::string> & IDs ) {
		ADD_2_TOP_WITH_INIT( ImportStatement, IDs );
	}

	void functionAttribute( const std::vector<std::string>& sv ) {
		ADD_2_TOP_WITH_INIT( FunctionAttribute, sv );
	}

	void startMemberExpression() {
		PUSH_STACK( MemberExpression );
	}
	void endMemberExpression() {
		CHECK_STACK_AND_POP( MemberExpression, AST::Node::NodeType::T_MEMBER_EXPRESSION );
	}
	void startForStatement() {
		PUSH_STACK( ForStatement );
	}
	void startForInit() {
		PUSH_STACK( ForInit );
	}
	void startForStep() {
		PUSH_STACK( ForStep );
	}
	void endForStep() {
		CHECK_STACK_AND_POP( ForStep, AST::Node::NodeType::T_FOR_STEP );
	}
	void endForStatement() {
		CHECK_STACK_AND_POP( ForStatement, AST::Node::NodeType::T_STMT_FOR );
	}
	void endForInit() {
		CHECK_STACK_AND_POP( ForInit, AST::Node::NodeType::T_FOR_INIT );
	}
    void startDoStatement( ) {
		PUSH_STACK( DoStatement );
    }
    void endDoStatement( )  {
    	CHECK_STACK_AND_POP( DoStatement, AST::Node::NodeType::T_STMT_DO );
    }
    void startWhileStatement() {
    	PUSH_STACK( WhileStatement );
    }
    void endWhileStatement() {
    	CHECK_STACK_AND_POP( WhileStatement, AST::Node::NodeType::T_STMT_WHILE );
    }
    void startScope() {
    	PUSH_STACK( ScopeStatement );
    }
    void endScope() {
    	CHECK_STACK_AND_POP( ScopeStatement, AST::Node::NodeType::T_SCOPE );
    }
    void startIncrementExpression(const generated::IncrementType::type type, const std::string& token) {
      PUSH_STACK_WITH_INIT( IncrementOperator , type, token );
    }

    void endIncrementExpression() {
      // Your implementation goes here
      CHECK_STACK_AND_POP( IncrementOperator, AST::Node::NodeType::T_INCREMENT );
    }
    void startConditionExpression() {
      PUSH_STACK( ConditionExpression );
    }

    void endConditionExpression() {
      // Your implementation goes here
      CHECK_STACK_AND_POP( ConditionExpression, AST::Node::NodeType::T_CONDITION_EXPRESSION );
    }
    void empty() {
    	ADD_2_TOP( Empty );
    }
    void defineMetaData(const generated::MetaData& metadata) {
        // Your implementation goes here
        _meta_data = metadata;
        _meta_data_dirty = true;
    }
public:
   as::ast::ProgramPtr getProgramNode() {	return _program_root;	};

private:
    std::stack< as::ast::NodePtr>		_node_stack;
    as::ast::ProgramPtr					_program_root;
    generated::MetaData					_meta_data;
    bool								_meta_data_dirty;
};

} } 

#endif
