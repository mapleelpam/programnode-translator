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
            T_ARGUMENTS,

            T_LITERAL_STRING,
            T_LITERAL_NUMBER,

            T_IDENTIFIER,

            T_FUNCTION_DEFINITION,
        };
    };

    virtual int exprType() = 0;

};

typedef std::tr1::shared_ptr<Expression>    ExpressionPtr; 

} } } }

#endif
