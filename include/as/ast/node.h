
#ifndef __AS_AST_NODE_H__
#define __AS_AST_NODE_H__

#include <tr1/memory>
#include <as/ast/expression.h>


namespace tw { namespace maple { namespace as { namespace ast {

// Abstract Class
struct Node
{
    struct NodeType
    {
        enum {
        	T_EXPRESSION ,
        	T_PROGRAM ,
        };
    };

    virtual int nodeType() = 0;

    virtual void addNodeChild( std::tr1::shared_ptr< Node > c) { _node_childs.push_back( c ); }
protected:
    std::vector< std::tr1::shared_ptr< Node > >    _node_childs;
};

//using std::tr1::shared_ptr;
//typedef std::tr1::shared_ptr<Expression>    ExpressionPtr;

} } } }

#endif
