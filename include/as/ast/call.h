
#ifndef __AS_AST_CALL_
#define __AS_AST_CALL_

#include <as/ast/expression.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Call : public Expression
{
    int     exprType()   {   return ExpressionType::T_CALL;  } 
    void    addChild( std::tr1::shared_ptr<Expression> ){   };

};


} } } }


#endif
