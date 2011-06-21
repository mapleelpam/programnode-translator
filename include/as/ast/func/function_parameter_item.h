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

#ifndef __AS_AST_FUNCTION_PARAMETER_ITEM_H__
#define __AS_AST_FUNCTION_PARAMETER_ITEM_H__

#include <as/ast/abstract/statement.h>

namespace tw { namespace maple { namespace as { namespace ast {

// Abstract
struct FunctionParameterItem : public Statement
{
	FunctionParameterItem( const std::string& name, const std::vector<std::string>& type, bool has_init, const std::string& init_value )
		: Statement(Node::NodeType::T_FUNCTION_PARAMETER_ITEM)
		, m_param_name( name )
		, m_param_type( type )
		, m_has_init( has_init)
		, m_init_value( init_value )
	{
//		std::cerr <<" --------------------------------> init '"<<init_value<<"'"<<std::endl;
	}

	int stmtType()   {   return Node::NodeType::T_FUNCTION_PARAMETER_ITEM;  }

	std::string ParamType(){	return m_param_type[0];	}
	std::string ParamName(){	return m_param_name;	}

    std::string toString()  {	return "node::function_signature_parameter_item"; };

    std::string ParamInit(){	return m_init_value;	}
    bool		hasInit(){	return m_has_init;	}
private:
    const std::string m_param_name;
    const std::vector<std::string> m_param_type;
    const bool 	m_has_init;
    const std::string m_init_value;
};

typedef SHARED_PTR(FunctionParameterItem) FunctionParameterItemPtr;


} } } }

#endif
