/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// ProgrameNode Translator
// Copyright 2010 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __AS_AST_NODE_H__
#define __AS_AST_NODE_H__

#include <tr1/memory>
#include <as/ast/expression.h>


namespace tw { namespace maple { namespace as { namespace ast {

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
            T_FUNCTION_DEFINITION ,
            T_FUNCTION_NAME ,
            T_FUNCTION_SIGNATURE ,
            T_FUNCTION_RETTYPE ,
            T_FUNCTION_PARAMETERS ,
            T_FUNCTION_PARAMETER_ITEM ,
            T_FUNCTION_COMMON ,

            T_STMT_LIST ,
            T_ConstantNumber,

            // Expr
            T_BINARY_OPERATOR,
            T_UNARY_OPERATOR,
            T_Assignment,

            T_CALL,
            T_CompareOperator,
            T_InstanceOf,

            T_PostfixOperator,
            T_PrefixOperator,

            T_EXPR_LIST,
            T_ARGUMENTS,

            T_LITERAL_STRING,
            T_LITERAL_NUMBER,
            T_LITERAL_BOOLEAN,

            T_IDENTIFIER,

            T_RETURN_STATEMENT,

            T_VARIABLE_DECLARE,
            T_ASSIGNMENT,

            T_NODE_TYPE_END,
        };
    };

    virtual int nodeType(){	return _node_type;	};

    virtual void addNodeChild( std::tr1::shared_ptr< Node > c) { node_childs.push_back( c ); }

    std::vector< std::tr1::shared_ptr< Node > >    node_childs;

//    std::ostream& operater<< ( std::ostream&, Node& );
    virtual std::string toString() = 0;
protected:
    int _node_type;
};

typedef std::tr1::shared_ptr<Node>    NodePtr;


} } } }

#endif
