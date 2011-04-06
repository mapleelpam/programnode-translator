#include <iostream>
#include <vector>
#include <backend/cpp/interpret/interpreter.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

void Interpreter::dispatchDo( ::tw::maple::as::ast::Expression* expr) 
{
    switch( expr->exprType() )
    {

        case ::tw::maple::as::ast::Expression::ExpressionType::T_CALL:
            std::cout << "T_CALL "<<std::endl;
            break;
        case ::tw::maple::as::ast::Expression::ExpressionType::T_EXPR_LIST:
            std::cout << "T_CALL "<<std::endl;
            break;
        case ::tw::maple::as::ast::Expression::ExpressionType::T_LITERAL:
            std::cout << "T_CALL "<<std::endl;
            break;
    };

}

} } } } }
