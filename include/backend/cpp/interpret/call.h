
#ifndef __BACKEDN_CPP_INTERPRET_CALL_H
#define __BACKEDN_CPP_INTERPRET_CALL_H

#include <as/ast/expression.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

// Abstract
struct Call : public Interpreter 
{   
    void        do( ::tw::maple::as::ast::Expression* exp )
    {   
        ::tw::maple::as::ast::Call* call = dynamic_cast<::tw::maple::as::ast::Call*>( exp );
    }

};


} } } } 

#endif 
