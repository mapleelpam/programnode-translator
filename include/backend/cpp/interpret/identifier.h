
#ifndef __BACKEDN_CPP_INTERPRET_IDENTIFIER_H__
#define __BACKEDN_CPP_INTERPRET_IDENTIFIER_H__

#include <as/ast/expression.h>
#include <as/ast/identifier.h>
#include <backend/cpp/interpret/interpreter.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

// Abstract
struct Identifier : public Interpreter
{   
	static void interpret( AST::Expression* exp, tw::maple::backend::cpp::Context* ctx )
	{
		AST::Identifier* li = dynamic_cast<AST::Identifier*>( exp );

		ctx->ofs_stream << li->value;

	}
};


} } } } }

#endif 

