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

#ifndef __AS_AST_NODE_STATEMENT_H__
#define __AS_AST_NODE_STATEMENT_H__

#include <as/ast/node.h>
#include <tr1/memory>


namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct Statement : public Node
{
    virtual int nodeType() {	return NodeType::T_STATEMENT;	};

    struct StatementType
    {
        enum {
            T_FUNCTION_DEFINITION ,
            T_FUNCTION_NAME ,
            T_FUNCTION_SIGNATURE ,
            T_FUNCTION_RETTYPE ,
            T_FUNCTION_PARAMETER ,
            T_STMT_LIST ,
        };
    };

    virtual int stmtType() = 0;

};

typedef std::tr1::shared_ptr<Statement>    StatementPtr;

} } } }

#endif
