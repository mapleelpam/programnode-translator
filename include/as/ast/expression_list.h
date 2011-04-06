
#ifndef __AS_AST_EXPRESSION_LIST_H_
#define __AS_AST_EXPRESSION_LIST_H_

#include <tr1/memory>
#include <as/ast/expression.h>


namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct ExpressionList : public Expression
{
    int exprType()    {    	return ExpressionType::T_EXPR_LIST;    }

};


} } } }

#endif
