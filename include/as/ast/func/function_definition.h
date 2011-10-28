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

#ifndef __AS_AST_FUNCTION_DEFINITION_H__
#define __AS_AST_FUNCTION_DEFINITION_H__

#include <as/ast/abstract/statement.h>
#include <as/ast/expr/super_init.h>
#include <global.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct FunctionDefinition: public Statement
{
	FunctionDefinition( bool is_abstract )
		: Statement(Node::NodeType::T_FUNCTION_DEFINITION)
		, isAbstract( is_abstract )
		, mp_parent_initilizer( NULL )
	{
	}

    // Public Assert !!
    NodePtr FunctionAttr()	{	return node_childs[0];	}
    NodePtr FunctionName()	{	return node_childs[1];	}
    NodePtr FunctionCommon(){	return node_childs[2];	}

    std::string toString()  {	return "node::function_definition"; };

    const bool isAbstract;

    std::string getCallerMapper()
    {
	    if(m_metadata.id == "mapper")
	    {
		    if(m_metadata.keyvalues.find("caller") != m_metadata.keyvalues.end() )
		    {
			    return m_metadata.keyvalues["caller"];
		    }
	    }
	    return "";
    }
    std::string getEnterFunctionMapper()
    {
	    if(m_metadata.id == "mapper")
	    {
		    if(m_metadata.keyvalues.find("enter_function") != m_metadata.keyvalues.end() )
		    {
			    return m_metadata.keyvalues["enter_function"];
		    }
	    }
	    return "";
    }
    void getPrefixParameterName( std::string& name, std::string& type, bool& found)
    {
    	found = false;
	    if(m_metadata.id == "mapper")
	    {
		    if(m_metadata.keyvalues.find("prefix_parameter") != m_metadata.keyvalues.end() )
		    {
		    	found = true;
			    std::string prefix = m_metadata.keyvalues["prefix_parameter"];
			    std::vector<std::string> tokens = tokenize( prefix, ":", "false");

			    name = tokens[0];
			    type = tokens[1];
		    }
	    }
    }
    bool isSupported( )
    {
	    if(m_metadata.id == "native")
	    {
		    if(m_metadata.keyvalues.find("support") != m_metadata.keyvalues.end() )
		    {
			    std::string answer = m_metadata.keyvalues["support"];
			    if( answer == "none" )
			    	return false;
		    }
	    }
	    return true;
    }
public:
    void setFunctionSymbol( ASYM::FunctionPtr s )	{	_related_function_symbol = s;	}
    ASYM::FunctionPtr getFunctionSymbol( )	{	return _related_function_symbol;	}
protected:
    ASYM::FunctionPtr		_related_function_symbol;
public:
    SuperInit*				mp_parent_initilizer;
};

typedef SHARED_PTR(FunctionDefinition) FunctionDefinitionPtr;


} } } }

#endif
