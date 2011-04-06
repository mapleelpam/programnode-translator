
#ifndef __BACKEDN_CPP_INTERPRET_ARGUMENTS_H_
#define __BACKEDN_CPP_INTERPRET_ARGUMENTS_H_

#include <as/ast/arguments.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;


// Abstract
struct Arguments : public Interpreter
{   
	static void interpret( AST::Expression* exp, tw::maple::backend::Context* ctx )
	{
		for (std::vector<std::tr1::shared_ptr<AST::Node> >::iterator nItr =
				exp->node_childs.begin(); nItr != exp->node_childs.end(); nItr++)
		{
			dispatchDo(*nItr, ctx);
		}

	}
};

};


} } } } 

#endif 
