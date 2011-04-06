
#ifndef __AS_AST_EXPRESSION__
#define __AS_AST_EXPRESSION__

#include <as/ast/node.h>
#include <tr1/memory>


namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Expression : public Node
{
    virtual int nodeType() {	return NodeType::T_EXPRESSION;	};

    struct ExpressionType
    {
        enum {
            T_ConstantNumber,

            T_BinaryOperator,
            T_Assignment,  

            T_CALL,
            T_CompareOperator,
            T_InstanceOf,

            T_PostfixOperator,
            T_PrefixOperator,

            T_EXPR_LIST,
            T_LITERAL,
        };
    };

    virtual int exprType() = 0;

};

typedef std::tr1::shared_ptr<Expression>    ExpressionPtr; 

} } } }

#endif
