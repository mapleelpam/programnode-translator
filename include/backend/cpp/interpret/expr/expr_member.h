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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_EXPRMEMBER_H_
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_EXPR_EXPRMEMBER_H_

#include <as/ast/expr/expr_member.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/scope.h>

#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ExpressionMember : public Interpreter, public TemplatePrinter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx)
	{
		namespace ASY = tw::maple::as::symbol;

		std::string result;

		AST::ExpressionMemberPtr expr_mem = STATIC_CAST( AST::ExpressionMember, node);

		if( expr_mem->node_childs.size() == 1 )
		{
			result += dispatchExpound(*(expr_mem->node_childs.begin()), symbol_table, ctx);
		}
		else if( expr_mem->node_childs.size() == 2 )
		{
			std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr = expr_mem->node_childs.begin();

			result += dispatchExpound(*nItr, symbol_table, ctx);
			nItr ++;

			if(  (*nItr)->nodeType() == AST::Node::NodeType::T_CALL
				&& STATIC_CAST( AST::Call, *nItr)->isObjectConsturct() )
			{
				return constructor_work_around(result,dispatchExpound(*nItr, symbol_table, ctx));
			}
			else
			{
				if( symbol_table->isInstance( result, "::"))
				{
					ASY::SymbolPtr instance = symbol_table->findSymbol( result );
					ASY::VariablePtr variable = DYNA_CAST( ASY::Variable, instance );

					if( variable /* && function_ptr && function_ptr->isGetter()*/ )
					{
						ASY::SymbolPtr instance_type = variable -> getTypeSymbol();
						ASY::ScopePtr  instance_class_type = DYNA_CAST( ASY::Scope, instance_type );
						result += "->/*fuck2*/" + dispatchExpound(*nItr, instance_class_type, ctx) ;

					}

					else
					{

						std::cerr << "can't find symbol '" << result << "' in symboltable '" << symbol_table->name() << "'" << std::endl;
//						exit(1);
						result += "->/*fuck " + symbol_table->name()+"*/" + dispatchExpound(*nItr, symbol_table, ctx);
					}
				}
				else 
				{
					result += "::" + dispatchExpound(*nItr, symbol_table, ctx);
				}
			}
		}
		else
		{
			std::cerr << "there's some strange in member get expression"<<std::endl;
			std::cerr << "pls contact mapleelpam at gmail.com" << std::endl;
			exit(1);
		}

		return result;
	}
private:
	std::string constructor_work_around( std::string base, std::string callee )
	{
		return replace( callee, "new ", "new "+base+"::");
	}

public:
	ExpressionMember()
		: TemplatePrinter("ExpressionMember")
	{

		m_tpl_setter_prepend = "set_";
		m_tpl_getter_prepend = "get_";
	}
private:
	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_tpl_setter_prepend	= pt.get<std::string>( configName()+".template.setter_prepend", m_tpl_setter_prepend);
		m_tpl_getter_prepend	= pt.get<std::string>( configName()+".template.getter_prepend", m_tpl_getter_prepend);

		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".template.setter_prepend", m_tpl_setter_prepend);
		pt.put<std::string>( configName()+".template.getter_prepend", m_tpl_getter_prepend);

		return TemplatePrinter::writeConfig( pt );
	}
private:
	std::string m_tpl_setter_prepend;
	std::string m_tpl_getter_prepend;
};

};


} } } } 

#endif 
