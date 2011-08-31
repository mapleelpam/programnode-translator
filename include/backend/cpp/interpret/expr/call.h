/* ******************************************************************\
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com       *
 *                                                                   *
 * Licensed under the Apache License, Version 2.0 (the "License");   *
 * you may not use this file except in compliance with the License.  *
 * You may obtain a copy of the License at                           *
 *                                                                   *
 *   http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                   *
 * Unless required by applicable law or agreed to in writing,        *
 * software distributed under the License is distributed on an       *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY            *
 * KIND, either express or implied. See the License for the          *
 * specific language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 * https://github.com/mapleelpam/programnode-translator              *
 *                                                                   *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple           *
 \*******************************************************************/

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_CALL_H
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_CALL_H

#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/ast/abstract/expression.h>
#include <as/ast/expr/call.h>

namespace AST = ::tw::maple::as::ast;

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

// Abstract
struct Call : public Interpreter, public TemplatePrinter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			)
	{
		namespace ASY = tw::maple::as::symbol;
		using tw::maple::as::symbol::Findable;

		ReturnValue result;
		std::string str_callee_name = "";
		std::string str_tpl_expression = m_tpl_normal_call;
		std::string str_prefix = "";
		AST::CallPtr call = STATIC_CAST( AST::Call, node);
		ASY::FunctionPtr callee_type;

//		std::cerr << " in call expound - "<<get_full_functionname( call->callee )<<std::endl;

		if (call->isObjectConsturct()) {
			str_callee_name +=  " new ";
			std::string type_name = get_full_functionname( call->callee );
			ASY::SymbolPtr p_type = call->getCalleeType();
			result.token_symbol = p_type;
			if( p_type != NULL && p_type->getFQN_and_mappedName() != "" )
			{
				result.token_symbol = p_type;
				result.expression_type = ReturnValue::HEAP;
				str_callee_name += p_type->getFQN_and_mappedName();
			}
			else
			{
				str_callee_name += type_name;
			}

			if( p_type )
			{
				callee_type = Findable::findFunction( DYNA_CAST( ASY::Scope, p_type), call->callee[call->callee.size() - 1 ]);
			}
		}
		else
		{
			if( call->mode == "dot" )
			{
				std::string right = get_full_functionname( call->callee );
				if( ctx.expression_symbol != NULL )
				{

					ASY::Scope* left_scope = NULL;
					if( ctx.expression_symbol->is(ASY::Symbol::T_VARIABLE ))
//					if( ctx.left_is_instance )
					{
						//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;

						ASY::Variable* var_symbol = (ASY::Variable*) ctx.expression_symbol;
						left_scope = (ASY::Scope*)(var_symbol -> getTypeSymbol().get());
					}
					else
					{
						left_scope = (ASY::Scope*)(ctx.expression_symbol);
					}

//					std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
					if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE)
							|| ctx.left_is_pointer )
					{  // TODO: guess this child_string is ??? primitive? or non-deletable
						str_prefix = "->";
						str_callee_name += right;
					}
					else if(ctx.expression_symbol->is( ASY::Symbol::T_SCOPE) )
					{ // should be a type
						if(ctx.left_is_pointer) // TBR 0720
							str_callee_name += _DS2("/* call left is pointer type */")+( "->"+right);
						else
							str_callee_name += _DS2("/* call left is scope */")+( "::"+right);
					}

					ASY::SymbolPtr callee_symbol = Findable::findFunction(left_scope,right);
					ASY::FunctionPtr callee_func_symbol = DYNA_CAST(ASY::Function, callee_symbol);

					if( callee_func_symbol != NULL)
					{
						result.token_symbol = callee_func_symbol->ReturnType();
						result.expression_type =
								callee_func_symbol->ReturnType()->preferStack() ? ReturnValue::STACK : ReturnValue::HEAP;
						callee_type = callee_func_symbol;
					} else
					{
						/* do for waht? */
						str_tpl_expression = m_tpl_undefined_member_call;
					}
				}
				else
				{
					std::cerr << " call(dot) expression error, should pass left symbol" << std::endl;
					exit(1);
				}

			}
			else
			{
//				ASY::SymbolPtr p_type = call->getCalleeType();
				str_callee_name += get_full_functionname( call->callee );
				callee_type = Findable::findFunction( symbol_table, str_callee_name );
			}
		}
		std::string str_arguments;
//		result +=  "( ";
		if (call->getArgs())
		{
			tw::maple::backend::cpp::Context ctx2 = ctx;
			ctx2 . callee_type = callee_type;
//			std::cerr << " in call expound - try to evaluate args"<<call->getArgs()->toString()<<std::endl;
			str_arguments += dispatchExpound( call->getArgs(), symbol_table, ctx2);
		}
//		result += " )";

//		std::cerr << " in call interpreter  = (end)" << std::endl;
		std::string str_numof_arguments = getNumofArguments( call->getArgs() );

		std::list<PatternPtr> patterns;
		patterns.push_back( PatternPtr( new Pattern("expression", str_tpl_expression) ));
		patterns.push_back( PatternPtr( new Pattern("argc", str_arguments) ));
		patterns.push_back( PatternPtr( new Pattern("argn", str_numof_arguments) ));
		patterns.push_back( PatternPtr( new Pattern("argc2", str_arguments != ""?","+str_arguments :"") ));
		patterns.push_back( PatternPtr( new Pattern("callee_name", str_callee_name) ));
		patterns.push_back( PatternPtr( new Pattern("prefix", str_prefix) ));

		std::string str_answer;

		{
	
			if( callee_type != NULL && (callee_type->getCallerMapper() != "") )
				str_answer = substitutePatterns( "#(prefix)"+callee_type->getCallerMapper(), patterns );
			else
				str_answer = substitutePatterns( patterns );
		}
		result.result = str_answer;

		return result;
	}

	Call()
		: TemplatePrinter("Call")
	{
		setTemplateString("#(expression)");
		m_tpl_undefined_member_call = "#(prefix)invoke(\"#(callee_name)\", false, 0 #(argc2) )";
		m_tpl_normal_call = "#(prefix)#(callee_name)(#(argc))";
	}
	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_tpl_undefined_member_call = pt.get<std::string>( configName()+".template.undefine_member_call", m_tpl_undefined_member_call);
		m_tpl_normal_call = pt.get<std::string>( configName()+".template.normal_call", m_tpl_normal_call);
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".template.undefine_member_call", m_tpl_undefined_member_call);
		pt.put<std::string>( configName()+".template.normal_call", m_tpl_normal_call);
	}

private:
	std::string m_tpl_undefined_member_call;
	std::string m_tpl_normal_call;
private:
	const std::string get_full_functionname( const std::vector<std::string> fn )
	{
		std::string ans = fn[0];
		for( int idx = 1 ; idx < fn.size() ; idx ++ )
		{
			ans += "::"+fn[idx];
		}
		return ans;
	}
	
	const std::string getNumofArguments( AST::NodePtr node )
	{
		std::string str_numof_args;
		AST::ArgumentsPtr args = DYNA_CAST( AST::Arguments, node );
		if( args == NULL ) return "0";
		std::stringstream ss;
		ss << args->node_childs.size();
		ss >> str_numof_args;

		return str_numof_args;

	}
};


} } } } }

#endif 
