
#ifndef __BACKEDN_CPP_INTERPRET_CALL_H
#define __BACKEDN_CPP_INTERPRET_CALL_H

#include <as/ast/expression.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

// Abstract
struct Call : public Interpreter
{   
	static void interpret( AST::Expression* exp, tw::maple::backend::cpp::Context* ctx )
	{
		std::cout << exp->node_childs.size() <<std::endl;
		std::tr1::shared_ptr<AST::Node> callee;
		std::tr1::shared_ptr<AST::Node> args;

		callee = exp->node_childs[ 0 ];
		args = exp->node_childs[ 1 ];


		dispatchDo(callee, ctx);
		ctx->ofs_stream << " ( ";
			dispatchDo(args, ctx);
		ctx->ofs_stream << " ) ";
//		for (std::vector<std::tr1::shared_ptr<AST::Node> >::iterator nItr =
//				exp->node_childs.begin(); nItr != exp->node_childs.end(); nItr++)
//		{
//			dispatchDo(*nItr, ctx);
//		}

	}
};


} } } } }

#endif 
