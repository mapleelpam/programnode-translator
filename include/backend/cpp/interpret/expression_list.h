
#ifndef __BACKEDN_CPP_INTERPRET_EXPR_LIST_H__
#define __BACKEDN_CPP_INTERPRET_EXPR_LIST_H__

#include <as/ast/expression.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/context.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;


// Abstract
struct ExpressionList : public Interpreter
{   
	static void interpret( AST::Expression* exp, tw::maple::backend::Context* ctx )
	{
		bool is_first = true;
		for (std::vector<std::tr1::shared_ptr<AST::Node> >::iterator nItr =
				exp->node_childs.begin(); nItr != exp->node_childs.end(); nItr++)
		{
			dispatchDo(*nItr, ctx);

			// Tail Dirty Flag Handle
			if( is_first )
				is_first = false;
			else
				ctx->ofs_stream << ", ";
		}

		ctx->ofs_stream << " ; " << std::endl;
	}
};

};


} } } } 

#endif 
