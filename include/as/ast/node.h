/* ***************************************************************
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 * ProgrameNode Translator
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
 *
 * https://github.com/mapleelpam/programnode-translator
 *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple
 * ***************************************************************/

#ifndef __TW_MAPLE_AS_AST_NODE_H__
#define __TW_MAPLE_AS_AST_NODE_H__

#include <global.h>
#include <as/symbol/symbol.h>


namespace tw { namespace maple { namespace as { namespace ast {

namespace ASYM = tw::maple::as::symbol;

// Abstract Class
struct Node
{
	Node(int ntype) :
		_node_type(ntype) {
	}

    struct NodeType
    {
        enum {
        	T_PROGRAM ,

        	// Stmt
        	T_PACKAGE_DEFINITION,

            T_FUNCTION_DEFINITION ,
            T_FUNCTION_NAME ,
            T_FUNCTION_SIGNATURE ,
            T_FUNCTION_PARAMETERS ,
            T_FUNCTION_PARAMETER_ITEM ,
            T_FUNCTION_COMMON ,

            T_STMT_LIST ,
            T_SCOPE,
            T_ConstantNumber,

            // Expr
            T_BINARY_OPERATOR,
            T_INCREMENT,
            T_INSTANCEOF,
            T_IS,
            T_AS,
            T_UNARY_OPERATOR,

            T_CALL,
            T_CompareOperator,

            T_PostfixOperator,
            T_PrefixOperator,

            T_STMT_EXPR,
            T_EXPR_LIST,
            T_ARGUMENTS,
            T_ARGUMENT,

            T_LITERAL_STRING,
            T_LITERAL_NUMBER,
            T_LITERAL_BOOLEAN,
            T_LITERAL_NULL,

            T_IDENTIFIER,

            T_RETURN_STATEMENT,

            T_VARIABLE_DECLARE,
            T_SET_EXPRESSION,
            T_GET_EXPRESSION,
            T_TYPE_EXPRESSION,

            T_SUPER_EXPRESSION,
            T_SUPER_INIT,

            T_EXPR_CONDITION,
            T_STMT_IF,

            T_STMT_FOR,
            	T_FOR_INIT,
            	T_FOR_STEP,
            T_STMT_DO,
            T_STMT_WHILE,

            T_CLASS_DEFINE,
            T_CLASS_DEFINE_STMT,

            T_COMP_CLASS_ATTRIBUTE,

            T_COMP_FUNCTION_ATTRIBUTE,


            T_MEMBER_EXPRESSION,
            T_THIS,

            T_IMPORT_STMT,

            T_CONDITION_EXPRESSION, /*()?():()*/
            T_EMPTY,

            T_NODE_TYPE_END,

        };
    };

    virtual int nodeType(){	return _node_type;	};
    bool is(	int t	) {	return _node_type == t;	}	// REMIND MYSELF !!!!!! USE THIS FUNCTION

    virtual void addNodeChild( SHARED_PTR(Node) c) { node_childs.push_back( c ); }

    std::vector< SHARED_PTR(Node) >    node_childs;

    virtual std::string toString() = 0;
protected:
    int	_node_type;

public:
    void setSymbol( ASYM::SymbolPtr s )	{	_related_symbol = s;	}
    ASYM::SymbolPtr getSymbol( )	{	return _related_symbol;	}

protected:
    ASYM::SymbolPtr	_related_symbol;

};

typedef SHARED_PTR(Node)    NodePtr;


} } } }

#endif
