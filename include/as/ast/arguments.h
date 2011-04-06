
#ifndef __AS_AST_ARGUMENTS_H_
#define __AS_AST_ARGUMENTS_H_

#include <tr1/memory>
#include <as/ast/expression.h>


namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Arguments : public Expression
{
    int exprType()
    {
    	return ExpressionType::T_ARGUMENTS;
    }

};


} } } }

#endif
