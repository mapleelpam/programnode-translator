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
// Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __TW_MAPLE_AS_AST_VARIABLE_DECLARE_H__
#define __TW_MAPLE_AS_AST_VARIABLE_DECLARE_H__

#include <as/ast/abstract/expression.h>
#include <SyntaxTree_types.h>

namespace tw { namespace maple { namespace as { namespace ast {

struct VariableDeclare: public Expression
{
	VariableDeclare( tw::maple::generated::VariableDeclare var_decl )
		: Expression(Node::NodeType::T_VARIABLE_DECLARE)
		, VariableName( var_decl.name )
		, VariableType( var_decl.type )
		, VariableAttribute( var_decl.attributes )
	{
	}

    NodePtr varInit(){
    	if( node_childs.size() > 0)
    		return node_childs[0];
    	else
    		return NodePtr();
    }

    std::string toString()  {
    	if( 0 )
    		return "node::variable_declare";
    	else {
    		std::string answer = "node::variable_declare";
    		answer += "(name:"+VariableName+") (";
    		for( int idx = 0 ; idx < VariableType.size() ; idx ++ )
    		{
    			answer += ":"+VariableType[idx];
    		}
    		answer += ")";
    		return answer;
    	}

    };
    bool isPublic()
    {
    	for( std::vector<std::string>::iterator sItr = VariableAttribute.begin()
    			; sItr != VariableAttribute.end() ; sItr++ )
    	{
    		if( *sItr == "public")
    			return true;
    	}
    	return false;
    }
    bool isStatic()
    {
    	for( std::vector<std::string>::iterator sItr = VariableAttribute.begin()
    	    			; sItr != VariableAttribute.end() ; sItr++ )
    	{
    		if( *sItr == "static")
    			return true;
    	}
    	return false;
    }

    const std::string VariableName;
    std::vector<std::string> VariableType;
    std::vector<std::string> VariableAttribute;
};

typedef SHARED_PTR(VariableDeclare) VariableDeclarePtr;


} } } }

#endif
