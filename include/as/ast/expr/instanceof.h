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

#ifndef __TW_MAPLE_AS_AST_INSTANCE_OF_H_
#define __TW_MAPLE_AS_AST_INSTANCE_OF_H_

#include <tr1/memory>
#include <as/ast/expression.h>

namespace tw { namespace maple { namespace as { namespace ast {

struct InstanceOf: public Expression
{
	InstanceOf( ) :
		Expression(Node::NodeType::T_INSTANCEOF)
	{
	}

    int exprType()   {   return Node::NodeType::T_INSTANCEOF;  }

    NodePtr LHS(){	return node_childs[0];	}
    NodePtr RHS(){	return node_childs[1];	}

    std::string toString()  {	return "node::instanceof"; };
    bool check(){	return node_childs.size() == 2;	};

};

typedef std::tr1::shared_ptr<InstanceOf> InstanceOfPtr;


} } } }

#endif
