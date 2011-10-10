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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_IDENTIFIER_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_IDENTIFIER_H__

#include <global.h>

#include <as/ast/token/identifier.h>
#include <backend/cpp/templateprinter.h>
#include <backend/cpp/interpret/interpreter.h>
#include <as/symbol/function.h>
#include <as/symbol/variable.h>
#include <as/symbol/action/findable.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

#define DEBUG {std::cerr<<__FILE__<<":"<<__LINE__<<std::endl;}

struct Identifier : public Interpreter, public TemplatePrinter
{
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		namespace ASY = tw::maple::as::symbol;
		using tw::maple::as::symbol::Findable;
		SHARED_PTR(AST::Identifier) li = std::tr1::static_pointer_cast<AST::Identifier>(node);

		if(li->qualifier != "")
		{
			tw::maple::as::symbol::ScopePtr pkg_scope = symbol_table;

			std::string left = replace( li->qualifier, ".", "::");

			// only here we need to find package !!!
			std::vector<std::string> tokens = tokenize( li->qualifier, ".", false);
			for( std::vector<std::string>::iterator I = tokens.begin(), E = tokens.end()
					; I != E ; I ++ )
			{
				tw::maple::as::symbol::SymbolPtr temp_pkg = pkg_scope->findSymbol(
						*I);
				if (temp_pkg && temp_pkg ->getSymbolProperties()
						== tw::maple::as::symbol::Symbol::T_SCOPE) {
					pkg_scope
							= STATIC_CAST( tw::maple::as::symbol::Scope , temp_pkg );
				} else {
					std::cerr << " can't find scope - "
							<< *I << " '"
							<< node->toString() << "'" << std::endl;
					exit(1);
				}
			}
			ASY::SymbolPtr symbol_ptr = pkg_scope->findSymbol( li->value );
			if( symbol_ptr )
			{
//				ctx-> token_class_type = symbol_ptr;
				ReturnValue result;
				result =  left+"::"+ li->value + _DS2("/* find symbol */");
				result.token_symbol = symbol_ptr;
				return result;
			}
			else
				return left+"::"+li->value + _DS2("/* can't find symbol */");
		}
		else
		{
			{ // just class...!!
				if( ASY::ScopePtr classtype_ptr = ASY::Findable::findClassType(symbol_table.get(),li->value))
				{
//					ctx-> token_class_type = classtype_ptr;
					ReturnValue result =  classtype_ptr->name()+_DS2("/* found class type */");
					result.token_symbol = classtype_ptr;
					return result;
				}
			}
			{ // just variable or getter
				if( ctx.inter_type==Context::RHS )
				{
					std::vector<ASY::SymbolPtr> candidates;
					if( ctx.expression_symbol )
					{
						ASY::Scope* type_scope = (ASY::Scope*)ctx.expression_symbol;
						if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE ) )
						{
							ASY::Variable* var_sym =(ASY::Variable*) (ctx.expression_symbol);
							type_scope = (ASY::Scope*)( var_sym->getTypeSymbol().get() );
						}
						candidates = ASY::Findable::findRHS_Candidates(type_scope,li->value);
						if( candidates.size() == 0) //TODO: Bug here!!!
							candidates = ASY::Findable::findRHS_Candidates(symbol_table,li->value);
					}
					else
						candidates = ASY::Findable::findRHS_Candidates(symbol_table,li->value);

					if( candidates.size() == 0 )
					{	// TODO: move to front
						// find in import
						ASY::SymbolPtr s = ctx.tableof_imported.find_symbol( li->value );
						if( s ){
							ReturnValue result = s->getFQN();
							result.token_symbol = s;
							result.token_symbol2 = s.get();
							return result;
						}
					}

					if( candidates.size() > 0 )
					{
						for( int idx = 0 ; idx < candidates.size() ; idx ++ )
						{
							ASY::SymbolPtr instance = candidates[idx];

							ASY::FunctionPtr function_ptr = DYNA_CAST( ASY::Function, instance );
							if( function_ptr && function_ptr->isGetter() )
							{
								ReturnValue result =  "get_" +  li->value + "()";
								result.token_symbol = function_ptr->ReturnType();
								result.expression_type =
									function_ptr->ReturnType()->preferStack() ? ReturnValue::STACK : ReturnValue::HEAP;
								return result;
							}
							ASY::VariablePtr variable_ptr = DYNA_CAST( ASY::Variable, instance );
							if( variable_ptr )
							{
								std::string id;
								{
									id = variable_ptr->mappedName();
									if( id == "") 	id = variable_ptr->name();
								}
								ReturnValue result = id+_DS2("/* found variable */");
//								result.token_symbol = variable_ptr->getTypeSymbol();
								result.token_symbol = variable_ptr;

								if( variable_ptr -> getTypeSymbol() -> preferStack() )
									result.expression_type = ReturnValue::STACK;
								else
									result.expression_type = ReturnValue::HEAP;
								return result;
							}
						}
					}
					else if( li -> is_attribute )
					{
//						std::cerr<<" not support attribute "<<std::endl;
//						exit(1);
						{ // invoke attribute mapper
							std::list<PatternPtr> patterns;
							patterns.push_back( PatternPtr( new Pattern("id", li->value) ));

							ReturnValue result;
							result.result = substitutePatterns( m_tpl_attribute_call, patterns );
							result.token_symbol = Findable::findClassType( symbol_table, "Object" );
							if( result.token_symbol == NULL )
							{
								std::cerr << " can't find Object "<< std::endl;
								exit(1);
							}
							return result;
						}
					}
					else
					{
						ASY::SymbolPtr callee_type = Findable::findFunction( symbol_table, li->value );
						if( callee_type )
							return li->value+_DS2("/* found a function */");
						{ // invoke mapper
							std::list<PatternPtr> patterns;
							patterns.push_back( PatternPtr( new Pattern("id", li->value) ));

							if( ctx.is_delete )
								return substitutePatterns( m_tpl_undefined_member_delete, patterns );
							else if( ctx.is_delete_item )
								return substitutePatterns( m_tpl_item_delete, patterns );
							else
								return substitutePatterns( m_tpl_undefined_member_call, patterns );
						}	
	
						std::cerr << " can't find scope - "
							<< li->value << " '"
							<< node->toString() << "'" << std::endl;
						// TODO: find symboltable then -> class_symbol_table
						// TODO: TBO 0719
//						exit(1);
						return li->value+_DS("/* can't found variable */");
					}
				}
				 // just variable or setter
				else if( ctx.inter_type==Context::LHS )
				{
					//std::cerr << __FILE__ <<":"<<__LINE__<<std::endl;
					std::vector<ASY::SymbolPtr> candidates;
					if( ctx.expression_symbol )
					{
					//	std::cerr << __FILE__ <<":"<<__LINE__<<std::endl;
						ASY::Scope* type_scope = (ASY::Scope*)ctx.expression_symbol;
						if(ctx.expression_symbol->is( ASY::Symbol::T_VARIABLE ) )
						{
							ASY::Variable* var_sym =(ASY::Variable*) (ctx.expression_symbol);
							type_scope = (ASY::Scope*)( var_sym->getTypeSymbol().get() );
						}
						candidates = ASY::Findable::findLHS_Candidates(type_scope,li->value);
						if( candidates.size() == 0) //TODO: Bug here!!!
							candidates = ASY::Findable::findLHS_Candidates(symbol_table,li->value);
					}
					else
					{
					//	std::cerr << __FILE__ <<":"<<__LINE__<<node->toString()<<std::endl;
						candidates = ASY::Findable::findLHS_Candidates(symbol_table,li->value);
					}


					if( candidates.size() > 0 )
					{
						for( int idx = 0 ; idx < candidates.size() ; idx ++ )
						{
							ASY::SymbolPtr instance = candidates[idx];

							ASY::FunctionPtr function_ptr = DYNA_CAST( ASY::Function, instance );
							if( function_ptr && function_ptr->isSetter() )
							{
								ctx.lfs_is_setter = true;
								ReturnValue result =  "set_" +  li->value;
								return result;
							}
							ASY::VariablePtr variable_ptr = DYNA_CAST( ASY::Variable, instance );
							if( variable_ptr )
							{
								ReturnValue result = li->value+_DS2("/* found variable */");
								result.token_symbol = variable_ptr->getTypeSymbol();
								result.expression_type = ReturnValue::HEAP;
								return result;
							}
						}
					}
					else
					{
						std::cerr << " can't find scope - "
							<< li->value << " '"
							<< node->toString() << "'" << std::endl;
						// TODO: find symboltable then -> class_symbol_table
						exit(1);

					}

				}
			}
		}
	}

	Identifier()
		: TemplatePrinter("Identifier")
	{
		m_tpl_undefined_member_call = "getProperty(\"#(id)\" )";
		m_tpl_undefined_member_delete = "removeProperty(\"#(id)\" )";
		m_tpl_item_delete = "removeItem(\"#(id)\" )";
		m_tpl_attribute_call = "getAttribute(\"#(id)\" )";
	}
	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_tpl_undefined_member_call = pt.get<std::string>( configName()+".template.undefine_member_call", m_tpl_undefined_member_call);
		m_tpl_attribute_call = pt.get<std::string>( configName()+".template.attribute_call", m_tpl_attribute_call);
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".template.undefine_member_call", m_tpl_undefined_member_call);
		pt.put<std::string>( configName()+".template.attribute_call", m_tpl_attribute_call);
	}

private:
	std::string m_tpl_undefined_member_call;
	std::string	m_tpl_attribute_call;
	std::string m_tpl_undefined_member_delete;
	std::string m_tpl_item_delete;
};


} } } } }

#endif 

