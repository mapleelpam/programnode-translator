
#ifndef __AS_AST_PROGRAM__
#define __AS_AST_PROGRAM__

#include <tr1/memory>
#include <as/ast/node.h>

namespace tw { namespace maple { namespace as { namespace ast {

struct Program : public Node
{
public:
    virtual int nodeType() {	return NodeType::T_PROGRAM;	};
};

} } } }

#endif
