

#ifndef __BACKEDN_CPP_INTERPRET_INTERPRET_H_
#define __BACKEDN_CPP_INTERPRET_INTERPRET_H_

#include <as/ast/expression.h>
#include <as/ast/call.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

// Abstract
struct Interpreter
{   
    static void dispatchDo( ::tw::maple::as::ast::Expression*);
//    virtual void        do( ::tw::maple::as::ast::Expression*) = 0;

};


} } } } }

#endif 
