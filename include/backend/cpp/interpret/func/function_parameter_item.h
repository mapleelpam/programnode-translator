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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_PARAMETER_ITEM_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_PARAMETER_ITEM_H__

#include <as/ast/func/function_parameter_item.h>
#include <backend/cpp/interpret/interpreter.h>

namespace AST = ::tw::maple::as::ast;

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

struct FunctionParameterItem : public Interpreter, public TemplatePrinter
{
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		AST::FunctionParameterItemPtr fParam = std::tr1::static_pointer_cast<AST::FunctionParameterItem>(node);

		ASY::VariablePtr symbol_var = STATIC_CAST( ASY::Variable, node->getSymbol() );
		ASY::SymbolPtr	symbol_type = symbol_var->getTypeSymbol();

		std::string str_var_type/* = invoke_type_mapper(  )*/;
		if( symbol_type->preferStack())
		{
			str_var_type = symbol_type->instanceName();
		}
		else
			str_var_type = symbol_type->getFQN_and_mappedName() + _pointer_pattern /* '*'or 'Ptr' */;


		if(fParam->hasInit())
			return str_var_type+" "+fParam->ParamName()+ " = "+ fParam->ParamInit();
		else
			return str_var_type+" "+fParam->ParamName();

	}
	FunctionParameterItem()
		: TemplatePrinter("FunctionParameterItem")
		,_pointer_pattern("*")
	{
	}
	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		_pointer_pattern = pt.get<std::string>(  configName()+".pointer_pattern", _pointer_pattern);
		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".pointer_pattern", _pointer_pattern);
		return TemplatePrinter::writeConfig( pt );
	}

private:
	std::string _pointer_pattern;

};

};


} } } } 

#endif 
