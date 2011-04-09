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

#ifndef __TW_MAPLE_AS_AST_VARIABLE_DECLARE_H__
#define __TW_MAPLE_AS_AST_VARIABLE_DECLARE_H__

#include <tr1/memory>
#include <as/ast/expression.h>

namespace tw { namespace maple { namespace as { namespace ast {

struct VariableDeclare: public Expression
{
	VariableDeclare( ) :
		Expression(Node::NodeType::T_VARIABLE_DECLARE)
	{
	}

    int exprType()   {   return _node_type;  }

    NodePtr varType(){	return node_childs[1];	}
    NodePtr varName(){	return node_childs[0];	}


    std::string toString()  {	return "node::variable_declare"; };
    bool check(){	return node_childs.size() == 2;	};

};

typedef std::tr1::shared_ptr<VariableDeclare> VariableDeclarePtr;


} } } }

#endif