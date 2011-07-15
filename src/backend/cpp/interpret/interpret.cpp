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

#include <global.h>
#include <backend/cpp/interpret/interpreter.h>


#include <backend/cpp/interpret/expression_list.h>
#include <backend/cpp/interpret/expr/call.h>
#include <backend/cpp/interpret/token/literal_string.h>
#include <backend/cpp/interpret/token/literal_number.h>
#include <backend/cpp/interpret/token/literal_boolean.h>
#include <backend/cpp/interpret/token/literal_null.h>
#include <backend/cpp/interpret/token/identifier.h>
#include <backend/cpp/interpret/token/empty.h>
#include <backend/cpp/interpret/token/this_expression.h>
#include <backend/cpp/interpret/statement_list.h>
#include <backend/cpp/interpret/func/function_definition.h>
#include <backend/cpp/interpret/func/function_name.h>
#include <backend/cpp/interpret/func/function_parameters.h>
#include <backend/cpp/interpret/func/function_parameter_item.h>
#include <backend/cpp/interpret/arguments.h>
#include <backend/cpp/interpret/argument.h>
#include <backend/cpp/interpret/return_stmt.h>
#include <backend/cpp/interpret/expr/binary_operator.h>
#include <backend/cpp/interpret/expr/increment_operator.h>
#include <backend/cpp/interpret/expr/unary_operator.h>
#include <backend/cpp/interpret/expr/condition_expression.h>
#include <backend/cpp/interpret/variable_declare.h>
#include <backend/cpp/interpret/stmt/if_stmt.h>
#include <backend/cpp/interpret/stmt/for_stmt.h>
#include <backend/cpp/interpret/stmt/while_stmt.h>
#include <backend/cpp/interpret/stmt/do_stmt.h>
#include <backend/cpp/interpret/stmt_expression.h>
#include <backend/cpp/interpret/expr/is.h>
#include <backend/cpp/interpret/expr/as.h>
#include <backend/cpp/interpret/expr/instanceof.h>
#include <backend/cpp/interpret/stmt/class_definition.h>
#include <backend/cpp/interpret/stmt/package_definition.h>
#include <backend/cpp/interpret/stmt/import_stmt.h>
#include <backend/cpp/interpret/expr/member_expression.h>
#include <backend/cpp/interpret/expr/set_expression.h>
#include <backend/cpp/interpret/expr/get_expression.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

static Interpreter* interpreterResolver[ ::tw::maple::as::ast::Node::NodeType::T_NODE_TYPE_END];

void initializeInterpreters()
{
	static Interpreter* p_def_expounder = NULL;
	if (p_def_expounder == NULL) { // Initialize
		p_def_expounder = new Interpreter();
		for (int idx = 0; idx < AST::Node::NodeType::T_NODE_TYPE_END; idx++)
			interpreterResolver[idx] = p_def_expounder;
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_DEFINITION] = new FunctionDefinition();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_NAME] = new FunctionName();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_PARAMETERS]	= new FunctionParameter();
		interpreterResolver[AST::Node::NodeType::T_FUNCTION_PARAMETER_ITEM] = new FunctionParameterItem();
		interpreterResolver[AST::Node::NodeType::T_STMT_LIST] = new StatementList();
		interpreterResolver[AST::Node::NodeType::T_EXPR_LIST] = new ExpressionList();
		interpreterResolver[AST::Node::NodeType::T_ARGUMENTS] = new Arguments();
		interpreterResolver[AST::Node::NodeType::T_ARGUMENT] = new Argument();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_STRING] = new LiteralString();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_NUMBER] = new LiteralNumber();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_BOOLEAN] = new LiteralBoolean();
		interpreterResolver[AST::Node::NodeType::T_LITERAL_NULL] = new LiteralNull();
		interpreterResolver[AST::Node::NodeType::T_IDENTIFIER] = new Identifier();
		interpreterResolver[AST::Node::NodeType::T_BINARY_OPERATOR]	= new BinaryOperator();
		interpreterResolver[AST::Node::NodeType::T_INSTANCEOF] = new InstanceOf();
		interpreterResolver[AST::Node::NodeType::T_IS] = new Is();
		interpreterResolver[AST::Node::NodeType::T_AS] = new As();
		interpreterResolver[AST::Node::NodeType::T_UNARY_OPERATOR] = new UnaryOperator();
		interpreterResolver[AST::Node::NodeType::T_RETURN_STATEMENT] = new ReturnStatement();
		interpreterResolver[AST::Node::NodeType::T_VARIABLE_DECLARE] = new VariableDeclare();
		interpreterResolver[AST::Node::NodeType::T_SET_EXPRESSION] = new SetExpression();
		interpreterResolver[AST::Node::NodeType::T_GET_EXPRESSION] = new GetExpression();
		interpreterResolver[AST::Node::NodeType::T_CALL] = new Call();
		interpreterResolver[AST::Node::NodeType::T_STMT_IF] = new IfStatement();
		interpreterResolver[AST::Node::NodeType::T_STMT_EXPR] = new StmtExpression();

		interpreterResolver[AST::Node::NodeType::T_CLASS_DEFINE] = new ClassDefinition();
		interpreterResolver[AST::Node::NodeType::T_PACKAGE_DEFINITION] = new PackageDefinition();

		interpreterResolver[AST::Node::NodeType::T_MEMBER_EXPRESSION] = new MemberExpression();

		interpreterResolver[AST::Node::NodeType::T_STMT_FOR] = new ForStatement();
		interpreterResolver[AST::Node::NodeType::T_STMT_DO] = new DoStatement();
		interpreterResolver[AST::Node::NodeType::T_STMT_WHILE] = new WhileStatement();
		interpreterResolver[AST::Node::NodeType::T_IMPORT_STMT] = new ImportStatement();
		interpreterResolver[AST::Node::NodeType::T_INCREMENT] = new IncrementOperator();

		interpreterResolver[AST::Node::NodeType::T_THIS] = new ThisExpression();
		interpreterResolver[AST::Node::NodeType::T_CONDITION_EXPRESSION] = new ConditionExpression();
		interpreterResolver[AST::Node::NodeType::T_EMPTY] = new Empty();
	}
}


std::string dispatchExpound(
		::tw::maple::as::ast::NodePtr node
		 , tw::maple::as::symbol::ScopePtr symbol_table
		 , ::tw::maple::backend::cpp::Context* ctx
		 , tw::maple::as::symbol::Scope* class_symbol_table
		)
{
	BOOST_ASSERT( node != NULL );

	namespace AST = ::tw::maple::as::ast;
	Interpreter* to = interpreterResolver[ node->nodeType() ];

	if( to == NULL ){
		std::cerr << "error: can't resolve expound - type id = "<<node->toString()<<std::endl;
		exit(1);
	} else {
		std::cout <<" dispatch - " << node->toString() << " number " << node->nodeType()<<std::endl;
		return to->expound(node,symbol_table,ctx, class_symbol_table );
	}

}

} /*interpret*/ } /*cpp*/ } /*backend*/ } /*maple*/ } /*tw*/

