#include <iostream>
#include <vector>
#include <backend/cpp/interpret/interpreter.h>

#include <backend/cpp/interpret/expression_list.h>
#include <backend/cpp/interpret/arguments.h>
#include <backend/cpp/interpret/call.h>
#include <backend/cpp/interpret/literal.h>
#include <backend/cpp/interpret/literal_string.h>
#include <backend/cpp/interpret/identifier.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

void dispatchDo( tw::maple::as::ast::NodePtr node, tw::maple::backend::cpp::Context* ctx )
{
	namespace AST = ::tw::maple::as::ast;

	switch (node->nodeType()) {

	case AST::Node::NodeType::T_EXPRESSION: {
		tw::maple::as::ast::Expression* expr = dynamic_cast<tw::maple::as::ast::Expression*> (&(*node));
		switch (expr->exprType()) {

		case ::tw::maple::as::ast::Expression::ExpressionType::T_CALL:
			std::cout << "T_CALL " << std::endl;
			Call::interpret( expr, ctx );

			break;
		case ::tw::maple::as::ast::Expression::ExpressionType::T_EXPR_LIST:
			std::cout << "T_EXPR_LIST " << std::endl;

			ExpressionList::interpret( expr, ctx );
			break;
		case ::tw::maple::as::ast::Expression::ExpressionType::T_IDENTIFIER:
			std::cout << "T_IDENTIFIER " << std::endl;
			Identifier::interpret( expr, ctx );
			break;
		case ::tw::maple::as::ast::Expression::ExpressionType::T_LITERAL_STRING:
			std::cout << "T_LITERAL " << std::endl;
			LiteralString::interpret( expr, ctx );
			break;
		case ::tw::maple::as::ast::Expression::ExpressionType::T_ARGUMENTS:
			std::cout << "T_ARGUMENTS " << std::endl;
			Arguments::interpret( expr, ctx );
			break;
		}
		break;
	}
	case AST::Node::NodeType::T_PROGRAM:{
		std::cout << "T_PROGRAM " << std::endl;

		for( std::vector< std::tr1::shared_ptr< AST::Node > >::iterator nItr = node->node_childs.begin()
				; nItr != node->node_childs.end() ; nItr ++ )
		{
			dispatchDo( *nItr, ctx );
		}
		break;
	}
	};

}

} } } } }
