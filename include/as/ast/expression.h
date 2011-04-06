
#ifndef __AS_AST_EXPRESSION__
#define __AS_AST_EXPRESSION__

#include <tr1/memory>


namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Expression
{
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

    virtual uint32_t    exprType() = 0;

    void addChild( std::tr1::shared_ptr<Expression> c) { childs.push_back( c ); }
protected:
    std::vector< std::tr1::shared_ptr<Expression> >    childs;
};

//using std::tr1::shared_ptr;
typedef std::tr1::shared_ptr<Expression>    ExpressionPtr; 

} } } }

#endif
