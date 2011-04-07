

#ifndef __BACKEDN_CPP_INTERPRET_INTERPRET_H_
#define __BACKEDN_CPP_INTERPRET_INTERPRET_H_

#include <as/ast/expression.h>
#include <as/ast/call.h>
#include <backend/cpp/context.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

void dispatchDo( tw::maple::as::ast::NodePtr, tw::maple::backend::cpp::Context* );

struct Interpreter
{

};

} } } } }

#endif 
