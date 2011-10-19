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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CLASS_DEFINE_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CLASS_DEFINE_H__

#include <global.h>
#include <as/ast/stmt/class_definition.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/parameter.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ClassDefinition : public Interpreter, public TemplatePrinter
{   

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{

		using ::tw::maple::as::symbol::Findable;
		AST::ClassDefinitionPtr _class_define_ = STATIC_CAST( AST::ClassDefinition, node);
		if( _class_define_->isIntrinsic() || _class_define_->isNativeClass())
		{
			return "";  // Ignore Intrinsic
//			return "/* "+_class_define_->getClassName()+ " is intrinsic, and ignore */";
		}
		ASY::ScopePtr	symbol_class = _class_define_->getClassSymbol();


		std::string class_stmt = "";
		if( _class_define_->hasStatement() ) {
			ctx.tree_depth ++;
			ctx.statement_class_symbol = symbol_class;
				class_stmt = dispatchExpound(_class_define_->classStmt(), symbol_class, ctx/*, symbol_class.get()*/);
			ctx.tree_depth --;
//			ctx.statement_class_symbol = NULL;
		}

		std::string class_inherit = getInheritsString(_class_define_, symbol_class, ctx);

		std::string class_base = "";
		std::string class_base_fqn = "";
		std::string class_base_fqn_noprefix = "";
		if ( symbol_class -> getInherit() ) {
			class_base += _class_define_->Inherits()[0];
			

			class_base_fqn = symbol_class -> getInherit() -> getFQN();
			class_base_fqn_noprefix = symbol_class -> getInherit() -> getFQN_noprefix();
		} else {
			class_base_fqn = class_base = m_default_base_object;
			class_base_fqn_noprefix = m_default_base_object;
		}

		/* change both symbol table into class symbol */
		std::string class_implements = getImplementsListString(_class_define_, symbol_class, ctx);

		std::list<PatternPtr> patterns;

		if( SVC_GLOBAL_SETTINGS -> declare_only )
			return class_stmt;

		if( symbol_class->isNoReflection() )
		{

		}

		patterns.push_back( PatternPtr( new Pattern("class_reflection",symbol_class->isNoReflection()?"":m_tpl_reflection) ));
		patterns.push_back( PatternPtr( new Pattern("class_properties", getClassMemberVariableProperties( symbol_class ) )) );
		patterns.push_back( PatternPtr( new Pattern("class_stmt", class_stmt ) ));
		patterns.push_back( PatternPtr( new Pattern("class_inherit", class_inherit ) ));
		patterns.push_back( PatternPtr( new Pattern("class_implements_list", class_implements ) ));
		patterns.push_back( PatternPtr( new Pattern("class_base", class_base ) ));
		patterns.push_back( PatternPtr( new Pattern("class_base_fqn", class_base_fqn ) ));
		patterns.push_back( PatternPtr( new Pattern("class_base_fqn2", class_base_fqn_noprefix ) ));
		patterns.push_back( PatternPtr( new Pattern("class_type", _class_define_->isAbstract()?"struct":"class" ) ));
		patterns.push_back( PatternPtr( new Pattern("class_default_constructor", symbol_class->noContructor()?getDefaultConstructor(symbol_class,ctx):"" ) ));
		patterns.push_back( PatternPtr( new Pattern("method_info",  getMethodInfo(symbol_class) )));
		patterns.push_back( PatternPtr( new Pattern("class_name", _class_define_->getClassName() ) ));
		patterns.push_back( PatternPtr( new Pattern("class_fqn", symbol_class->getFQN() ) ));
		patterns.push_back( PatternPtr( new Pattern("class_fqn2", symbol_class->getFQN_noprefix() ) ));


		COMPELETE_PATTERNS( patterns, ctx );


		std::string result = 
				substitutePatterns(  _class_define_->isAbstract()? m_tpl_interface :
						(symbol_class->isNoReflection()? m_tpl_class_not_reflection :m_tpl_class)
						, patterns );

		return result;
	}

	ClassDefinition()
		: TemplatePrinter("ClassDefinition")
		, m_default_base_object("")
		, m_tpl_property_begin("")
		, m_tpl_property("")
		, m_tpl_property_end("")
		, m_inherit_type(BOTH)
	{
		m_tpl_class_not_reflection =
		m_tpl_class = ( "#(indent_tab)#(class_type) #(class_name) #(class_inherit) #(endl)#(indent_tab){#(endl)"
							"#(class_properties)"
							"#(class_stmt)"
							"#(class_default_constructor)"
							"#(endl)#(indent_tab)};#(endl)" )
							;
		m_tpl_interface = ( "#(indent_tab) #(class_type) #(class_name)  #(endl)#(indent_tab){#(endl)"
							"#(class_stmt)"
							"#(endl)#(indent_tab)};#(endl)" )
							;
		m_tpl_setter = "void set_#(variable_name)( #(variable_type) i ){ #(variable_name) = i;	}";
		m_tpl_getter = "#(variable_type) get_#(variable_name)( ) const { return #(variable_name);	}";

		m_tpl_void_method_info = "";
		m_tpl_normal_method_info = "";
		m_tpl_reflection = "";
		m_tpl_constructor_info = "#(endl)#(indent_tab_add)public: #(class_name)()";
	}

	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_default_base_object = pt.get<std::string>( configName()+".inherit.base", m_default_base_object);

		m_tpl_class = pt.get<std::string>( configName()+".template.class", m_tpl_class);
		m_tpl_class_not_reflection = pt.get<std::string>( configName()+".template.class_not_object", m_tpl_class_not_reflection);

		m_tpl_interface = pt.get<std::string>( configName()+".template.interface", m_tpl_interface);
		m_tpl_property = pt.get<std::string>( configName()+".template.property", m_tpl_property);
		m_tpl_property_begin = pt.get<std::string>( configName()+".template.property_begin", m_tpl_property_begin);
		m_tpl_property_end = pt.get<std::string>( configName()+".template.property_end", m_tpl_property_end);

		m_tpl_setter = pt.get<std::string>( configName()+".template.default_setter", m_tpl_setter);
		m_tpl_getter = pt.get<std::string>( configName()+".template.default_getter", m_tpl_getter);

		m_tpl_void_method_info = pt.get<std::string>( configName()+".template.info.void_method", m_tpl_void_method_info);
		m_tpl_normal_method_info = pt.get<std::string>( configName()+".template.info.normal_method", m_tpl_normal_method_info);
		m_tpl_constructor_info = pt.get<std::string>( configName()+".template.info.constructor", m_tpl_constructor_info);

		m_tpl_reflection = pt.get<std::string>( configName()+".template.reflection", m_tpl_reflection);

		m_inherit_type = pt.get<int>(  configName()+".inherit.type", (m_inherit_type));
		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".inherit.base", m_default_base_object);

		pt.put<std::string>( configName()+".template.class", m_tpl_class);
		pt.put<std::string>( configName()+".template.class_not_object", m_tpl_class_not_reflection);

		pt.put<std::string>( configName()+".template.interface", m_tpl_interface);
		pt.put<std::string>( configName()+".template.property", m_tpl_property);
		pt.put<std::string>( configName()+".template.property_begin", m_tpl_property_begin);
		pt.put<std::string>( configName()+".template.property_end", m_tpl_property_end);

		pt.put<std::string>(  configName()+".template.default_setter", m_tpl_setter);
		pt.put<std::string>(  configName()+".template.default_getter", m_tpl_getter);

		pt.put<std::string>( configName()+".template.info.void_method", m_tpl_void_method_info);
		pt.put<std::string>( configName()+".template.info.normal_method", m_tpl_normal_method_info);
		pt.put<std::string>( configName()+".template.info.constructor", m_tpl_constructor_info);
		pt.put<std::string>( configName()+".template.reflection", m_tpl_reflection);

		pt.put<int>( configName()+".inherit.type", m_inherit_type);
		return TemplatePrinter::writeConfig( pt );
	}

	enum InheritType
	{
		NONE,
		ONLY_EXTENDS,
		ONLY_IMPLEMENTS,
		BOTH,
	};
private:
	std::string m_default_base_object;

	std::string m_tpl_class, m_tpl_class_not_reflection;
	std::string m_tpl_interface;
	std::string m_tpl_property;
	std::string m_tpl_property_begin;
	std::string m_tpl_property_end;
	std::string m_tpl_setter;
	std::string m_tpl_getter;

	std::string m_tpl_void_method_info;
	std::string m_tpl_normal_method_info;
	std::string m_tpl_constructor_info;

	std::string m_tpl_reflection;
	int	m_inherit_type;

private:
	std::string getInheritsString(
				AST::ClassDefinitionPtr _class_define_
				, ASY::ScopePtr symbol_class
				, tw::maple::backend::cpp::Context& ctx
				
				)
	{
		std::string class_inherit = "";

		if( ( m_inherit_type == ONLY_EXTENDS || m_inherit_type == BOTH ) && _class_define_->hasBaseClass() )
		{
			class_inherit += ": public "+ symbol_class->getInherit()->getFQN_and_mappedName();
		}
		if( ( m_inherit_type == ONLY_IMPLEMENTS || m_inherit_type == BOTH) && _class_define_->hasInterface() )
		for( int idx = 0 ; idx < _class_define_->Implements ().size() ; idx ++){
			class_inherit += class_inherit=="" ? " : " : " , ";
			class_inherit += " public "+ _class_define_->Implements()[idx];
		}

		if( m_default_base_object != "" &&  (!_class_define_->hasBaseClass()) ){
			class_inherit += class_inherit=="" ? " : " : " , ";
			class_inherit += " public " + m_default_base_object;
		}

		return class_inherit;
	}
	std::string getImplementsListString(
				AST::ClassDefinitionPtr _class_define_
				, ASY::ScopePtr symbol_class
				, tw::maple::backend::cpp::Context& ctx
				
				)
	{
		std::string answer = "";
		if( _class_define_->hasInterface() )
		for( int idx = 0 ; idx < _class_define_->Implements ().size() ; idx ++){
			answer += answer=="" ? "" : ",";
			answer += _class_define_->Implements()[idx];
		}
		return answer;
	}

	std::string getDefaultConstructor(
			ASY::ScopePtr symbol_class,
			tw::maple::backend::cpp::Context& ctx
			
			)
	{
//		std::string answer = "#(indent_tab_add)CONSTRUCTOR_INFO_0_A_0_DA("+symbol_class->name()+");#(endl)#(indent_tab_add)public: "+symbol_class->name()+"()";
		std::string answer = m_tpl_constructor_info;

		std::vector<ASY::SymbolPtr> childs;
		symbol_class->getChilds(childs/*out*/);
		for (std::vector<ASY::SymbolPtr>::iterator child_itr = childs.begin(); child_itr
				!= childs.end(); child_itr++) {
			if (((*child_itr)->getSymbolProperties() & ASY::Symbol::T_VARIABLE)) {
				ASY::VariablePtr var = STATIC_CAST( ASY::Variable, *child_itr );
				if (var->getInitializeNode() != NULL && var->isStatic() == false) {
					answer += "#(endl)#(indent_tab_add):" + var->name() + "("
									+ dispatchExpound(
										var->getInitializeNode(),
										symbol_class/*TODO: should use function's parent*/,
										ctx
										).result + ")";
				}
			}
		}
		answer += "#(endl)#(indent_tab_add){}#(endl)";

		return answer;
	}

	std::string getClassMemberVariableProperties(
			ASY::ScopePtr symbol_class
			)
	{
		std::string answer;
		std::vector<ASY::SymbolPtr> childs;
		symbol_class->getChilds(childs/*out*/);
		for (std::vector<ASY::SymbolPtr>::iterator child_itr = childs.begin(); child_itr
				!= childs.end(); child_itr++) {
			if (((*child_itr)->getSymbolProperties() & ASY::Symbol::T_VARIABLE)) {
				ASY::VariablePtr var = STATIC_CAST( ASY::Variable, *child_itr );
				ASY::SymbolPtr	symbol_type = var->getTypeSymbol();
				if ( var && !var->isStatic() && !var->isConst()) {
					std::string str_var_type;
					if( symbol_type->preferStack())
						str_var_type = symbol_type->getFQN_and_instanceName();
					else
						str_var_type = symbol_type->getFQN_and_mappedName() + "*" /* '*'or 'Ptr' */;

					std::string str_var_attr = var->getSymbolAttribtues() == ASY::Symbol::ATTR_PUBLIC ? "public" : "private";

//					// PROPERTY
//					{
//						std::list<PatternPtr> patterns;
//
//						patterns.push_back( PatternPtr( new Pattern("property_type", str_var_type ) ));
//						patterns.push_back( PatternPtr( new Pattern("property_name", var->name() ) ));
//
//						answer += "#(indent_tab_add)"+substitutePatterns(m_tpl_property, patterns );
//					}
					// add setter and getter
					{
						std::vector<ASY::SymbolPtr> candidates = ASY::Findable::findClassMembers( symbol_class, var->name() );

						bool getter_not_found = true;
						bool setter_not_found = true;
						for( std::vector<ASY::SymbolPtr>::iterator itr = candidates.begin(), E = candidates.end()
							; itr != E ; itr ++ )
						{
							ASY::FunctionPtr symbol_func = DYNA_CAST( ASY::Function, *itr );
							if( symbol_func && symbol_func -> isGetter() )
								getter_not_found = false;
							else if( symbol_func && symbol_func -> isGetter() )
								setter_not_found = false;
						}
						std::list<PatternPtr> patterns;

						patterns.push_back( PatternPtr( new Pattern("variable_type", str_var_type ) ));
						patterns.push_back( PatternPtr( new Pattern("variable_name", var->mappedName() ) ));
						patterns.push_back( PatternPtr( new Pattern("variable_attribute", str_var_attr ) ));
						if( getter_not_found )
							answer += "#(indent_tab_add)"+substitutePatterns(m_tpl_getter, patterns ) + "#(endl)";
						if( setter_not_found )
							answer += "#(indent_tab_add)"+substitutePatterns(m_tpl_setter, patterns ) + "#(endl)";
					}
					answer += "#(endl)";
				}
			}
		}

		if( symbol_class->isNoReflection() )
			return answer; // end of this line

		answer += m_tpl_property_begin;
		for (std::vector<ASY::SymbolPtr>::iterator child_itr = childs.begin(); child_itr
				!= childs.end(); child_itr++) {
			if (((*child_itr)->getSymbolProperties() & ASY::Symbol::T_VARIABLE)) {
				ASY::VariablePtr var = STATIC_CAST( ASY::Variable, *child_itr );
				ASY::SymbolPtr	symbol_type = var->getTypeSymbol();
				if ( var && !var->isStatic() ) {
					std::string str_var_type;
					if( symbol_type->preferStack())
						str_var_type = symbol_type->getFQN_and_instanceName();
					else
						str_var_type = symbol_type->getFQN_and_mappedName() + "*" /* '*'or 'Ptr' */;

					std::string str_var_attr = var->getSymbolAttribtues() == ASY::Symbol::ATTR_PUBLIC ? "public" : "private";

					// PROPERTY
					{
						std::list<PatternPtr> patterns;

						patterns.push_back( PatternPtr( new Pattern("property_type", str_var_type ) ));
						patterns.push_back( PatternPtr( new Pattern("property_name", var->name() ) ));

						answer += "#(indent_tab_add)"+substitutePatterns(m_tpl_property, patterns );
					}
					answer += "#(endl)";
				}
			}
		}
		answer += m_tpl_property_end;
		return answer;
	}

	std::string getMethodInfo( ASY::ScopePtr symbol_class )
	{
		std::string answer;

		for(std::vector<ASY::SymbolPtr>::iterator nItr = symbol_class->m_childs.begin(), E = symbol_class->m_childs.end()
				; nItr != E ; nItr ++ )
		{
			ASY::FunctionPtr member_function = DYNA_CAST(ASY::Function, *nItr );

			if( member_function && !member_function->isSetter() && !member_function->isGetter() && !member_function->isConstructor())
			{
				std::string str_parameters;
				{
					std::vector<ASY::SymbolPtr>::iterator nItr = member_function->m_types.begin(), E = member_function->m_types.end();
					nItr ++;
					for( ; nItr != E ; nItr ++ )
					{
						//if( nItr == E ) break;
						ASY::SymbolPtr symbol_type = *nItr;
						if( symbol_type->preferStack())
							str_parameters += ", "+symbol_type->getFQN_and_instanceName();
						else
							//str_parameters += symbol_type->getFQN_and_mappedName() + m_pointer_pattern /* '*'or 'Ptr' */;
							str_parameters +=  ", "+symbol_type->getFQN_and_mappedName() + "*"/* '*'or 'Ptr' */;

					}
				}
				std::string str_numof_parameter;
				{
					std::stringstream ss;
					ss << member_function->numberOfParameter();
					ss >> str_numof_parameter;
				}
				std::list<PatternPtr> patterns;
				patterns.push_back( PatternPtr( new Pattern("numof_parameter", str_numof_parameter ) ));
				patterns.push_back( PatternPtr( new Pattern("function_name", member_function->name() ) ));

				ASY::SymbolPtr func_type = member_function->ReturnType();
				std::string str_func_type;
				if( func_type->preferStack())
					str_func_type = func_type->getFQN_and_instanceName();
				else
					str_func_type = func_type->getFQN_and_mappedName() + "*"/* '*'or 'Ptr' */;

				patterns.push_back( PatternPtr( new Pattern("function_type", str_func_type ) ));
				patterns.push_back( PatternPtr( new Pattern("function_parameters", str_parameters ) ));

				if( func_type->name() != "Void" )
				{
					answer+= substitutePatterns(  m_tpl_normal_method_info, patterns );
				}
				else if( func_type->name() == "Void" )
				{
					answer+= substitutePatterns(  m_tpl_void_method_info, patterns );
				}
			}
		}

		return answer;
	}
};

} } } } }

#endif 
