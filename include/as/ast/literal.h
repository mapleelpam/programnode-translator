

#ifndef __AS_AST_LITERAL_H__
#define __AS_AST_LITERAL_H__

#include <tr1/memory>
#include <as/ast/expression.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Literal: public Expression
{
    Literal( std::string v ) : value(v) {}
    int exprType()   {   return ExpressionType::T_LITERAL;  } 

    std::string value;
};

} } } }

#endif
