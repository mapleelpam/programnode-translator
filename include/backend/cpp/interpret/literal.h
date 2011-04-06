
#ifndef __BACKEDN_CPP_INTERPRET_LITERAL_H__
#define __BACKEDN_CPP_INTERPRET_LITERAL_H__

#include <as/ast/expression.h>
#include <as/ast/literal.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/context.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

// Abstract
struct Literal : public Interpreter
{   
	static void interpret( AST::Expression* exp, tw::maple::backend::Context* ctx )
	{
		AST::Literal* li = dynamic_cast<AST::Literal*>( exp );

		ctx->ofs_stream << li->value;

	}
};


} } } } }

#endif 

