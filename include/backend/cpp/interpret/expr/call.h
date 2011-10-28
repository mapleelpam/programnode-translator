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

#include "backend/cpp/interpret/expr/arguments.h"

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
		AST::CallPtr CALL = STATIC_CAST( AST::Call, node);
		ASY::FunctionPtr callee_type;
		ASY::ScopePtr constructor_type;

		std::string str_special_call_patterns = "";
//		std::cerr << " in call expound - "<<get_full_functionname( call->callee )<<std::endl;

		if (CALL->isObjectConsturct()) {
			str_callee_name = "";
			std::string type_name = get_full_functionname( CALL->callee );
			ASY::SymbolPtr p_type = CALL->getCalleeType();
			//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
			result.token_symbol = p_type;
			if( p_type != NULL /*&& p_type->getFQN_and_mappedName() != ""*/ )
			{
				result.token_symbol = p_type;
				result.expression_type = ExpressionType::HEAP;
				//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
				str_callee_name += "new "+p_type->getFQN_and_mappedName();
			}
			else
			{
				std::cerr <<" callee constructor not found '"<<type_name<<"'"<<std::endl; exit(1);
				std::vector<ASY::SymbolPtr> cans = Findable::findRHS_Candidates( symbol_table, type_name );
				if( cans.size() > 0 )
				{
					ASY::SymbolPtr symbol_cans = *(cans.begin());
					if( ASY::VariablePtr variable_cans = DYNA_CAST(ASY::Variable, symbol_cans) )
					{
						str_special_call_patterns = "#(callee_name)->getXCClass()->newInstance(#(argn))";
						str_callee_name += "( Object* ) "+type_name;

						result.token_symbol = Findable::findClassType( symbol_table, "Object" );
						result.expression_type = ExpressionType::HEAP;
					}
					else
					{
						//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
						str_callee_name += "new "+type_name;
					}
				}
				else
				{
					//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
					str_callee_name += "new "+type_name;
				}
			}

			if( p_type && DYNA_CAST( ASY::Scope, p_type))
			{
				callee_type = Findable::findFunction( DYNA_CAST( ASY::Scope, p_type), CALL->callee[CALL->callee.size() - 1 ]);
			}
		}
		else
		{
			if( CALL->mode == "dot" )
			{
				std::string right = get_full_functionname( CALL->callee );
				if( ctx.expression_symbol != NULL )
				{

					ASY::Scope* left_scope = NULL;
					if( ctx.expression_symbol->is(ASY::Symbol::T_VARIABLE ))
//					if( ctx.left_is_instance )
					{
						////std::cerr << __FILE__<<":"<<__LINE__<<std::endl;

						ASY::Variable* var_symbol = (ASY::Variable*) ctx.expression_symbol;
						left_scope = (ASY::Scope*)(var_symbol -> getTypeSymbol().get());
					}
					else
					{
						left_scope = (ASY::Scope*)(ctx.expression_symbol);
					}

//					//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
					if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE)
							&& ctx.left_expr_type )
					{  // TODO: guess this child_string is ??? primitive? or non-deletable
						str_prefix = "->";
						str_callee_name += right;
					}
					else if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE)
							&& !ctx.left_expr_type )
					{  // TODO: guess this child_string is ??? primitive? or non-deletable
						str_prefix = ".";
						str_callee_name += right;
					}
					else if(ctx.expression_symbol->is( ASY::Symbol::T_SCOPE) )
					{ // should be a type
						str_prefix = "->";
						if(ctx.left_expr_type) // TBR 0720
							str_callee_name += _DS2("/* call left is pointer type */")+(right);
						else
						{
							str_prefix = "::";
							str_callee_name += _DS2("/* call left is scope */")+( right);
						}
					}
					else
					{
						str_prefix = "->";
					}

					ASY::SymbolPtr callee_symbol = Findable::findFunction(left_scope,right);
					ASY::FunctionPtr callee_func_symbol = DYNA_CAST(ASY::Function, callee_symbol);

					if( callee_func_symbol != NULL)
					{
						result.token_symbol = callee_func_symbol->ReturnType();
						result.expression_type =
								callee_func_symbol->ReturnType()->preferStack() ? ExpressionType::STACK : ExpressionType::HEAP;
						callee_type = callee_func_symbol;
					} else
					{
						/* do for waht? */
						str_tpl_expression = m_tpl_undefined_member_call;
						result.token_symbol = Findable::findClassType( symbol_table, "Object" );
						result.expression_type = ExpressionType::HEAP;
					}
				}
				else
				{
					//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
					std::cerr << " call(dot) expression error, should pass left symbol" << std::endl;
					exit(1);
				}

			}
			else // not Dot
			{
//				ASY::SymbolPtr p_type = call->getCalleeType();
				str_callee_name += get_full_functionname( CALL->callee );
				callee_type = Findable::findFunction( symbol_table, str_callee_name );
				if( callee_type == NULL )
				{
					callee_type = DYNA_CAST( ASY::Function, CALL->getCalleeType());
					if( callee_type )
					{
						str_callee_name = callee_type->getFQN();
					}

				}
				if( callee_type == NULL )
					constructor_type = Findable::findClassType(symbol_table.get(), str_callee_name);

			}
		}
		std::string str_arguments;
		std::string str_arguments_type2;

		if (CALL->getArgs())
		{
			tw::maple::backend::cpp::Context ctx2 = ctx;
			ctx2 . callee_type = callee_type;
//			std::cerr << " in call expound - try to evaluate args"<<call->getArgs()->toString()<<std::endl;
			str_arguments = dispatchExpound( CALL->getArgs(), symbol_table, ctx2);
		}

		if (CALL->getArgs() && callee_type && (callee_type->getCallerMapper() != ""))
		{
			tw::maple::backend::cpp::Context ctx2 = ctx;
			ctx2 . callee_type = callee_type;
			str_arguments_type2 = Arguments::special_expound_type2( CALL->getArgs(), symbol_table, ctx2 );
		}

//		std::cerr << " in call interpreter  = (end)" << std::endl;

		if( callee_type == NULL && constructor_type )
			str_callee_name = constructor_type->getFQN_and_instanceName();
		std::string str_numof_arguments = getNumofArguments( CALL->getArgs() );

		std::list<PatternPtr> patterns;
		patterns.push_back( PatternPtr( new Pattern("expression", str_tpl_expression) ));
		patterns.push_back( PatternPtr( new Pattern("argc", str_arguments) ));
		patterns.push_back( PatternPtr( new Pattern("argc_type2", str_arguments_type2+"/*it's type two*/") ));
		patterns.push_back( PatternPtr( new Pattern("argn", str_numof_arguments) ));
		patterns.push_back( PatternPtr( new Pattern("argc2", str_arguments != ""?","+str_arguments :"") ));
		patterns.push_back( PatternPtr( new Pattern("callee_name", str_callee_name) ));
		patterns.push_back( PatternPtr( new Pattern("prefix", str_prefix) ));

		std::string str_answer;

		//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
		{
	
			if( str_special_call_patterns != "" )
			{
				str_answer = substitutePatterns( str_special_call_patterns, patterns );
			}
			else if(callee_type != NULL && (callee_type->getCallerMapper() != "") )
				str_answer = substitutePatterns( "#(prefix)"+callee_type->getCallerMapper(), patterns );
			else
				str_answer = substitutePatterns( patterns );
		}
		//std::cerr << __FILE__<<":"<<__LINE__<<std::endl;
		if (CALL->isObjectConsturct())
			str_answer = "("+str_answer+")";
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
