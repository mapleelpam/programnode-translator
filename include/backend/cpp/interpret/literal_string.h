
#ifndef __BACKEDN_CPP_INTERPRET_LITERAL_STRING_H__
#define __BACKEDN_CPP_INTERPRET_LITERAL_STRING_H__

#include <as/ast/expression.h>
#include <as/ast/literal.h>
#include <backend/cpp/interpret/interpreter.h>
#include <as/ast/literal_string.h>



namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

// Abstract
struct LiteralString : public Interpreter
{   
	static void interpret( AST::Expression* exp, tw::maple::backend::cpp::Context* ctx )
	{
		AST::LiteralString* li = dynamic_cast<AST::LiteralString*>( exp );

		ctx->ofs_stream << "\""<< li->value << "\"";

	}
};


} } } } }

#endif 

