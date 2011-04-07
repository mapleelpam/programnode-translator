

#ifndef __AS_AST_IDENTIFIER_H__
#define __AS_AST_IDENTIFIER_H__

#include <tr1/memory>
#include <as/ast/expression.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Identifier: public Expression
{
	Identifier( std::string v ) : value(v) {}
    int exprType()   {   return ExpressionType::T_IDENTIFIER;  }

    std::string value;
};

} } } }

#endif
