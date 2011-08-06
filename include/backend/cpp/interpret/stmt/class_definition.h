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

#include <as/ast/stmt/class_definition.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ClassDefinition : public Interpreter, public TemplatePrinter
{   

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{

		AST::ClassDefinitionPtr _class_define_ = STATIC_CAST( AST::ClassDefinition, node);
		if( _class_define_->isIntrinsic() || _class_define_->isNativeClass())
		{
//			return "";  // Ignore Intrinsic
			return "/* "+_class_define_->getClassName()+ " is intrinsic, and ignore */";
		}
		ASY::ScopePtr	symbol_class = _class_define_->getClassSymbol();

		std::string class_stmt = "";
		if( _class_define_->hasStatement() ) {
			ctx.tree_depth ++;
				class_stmt = dispatchExpound(_class_define_->classStmt(), symbol_class, ctx/*, symbol_class.get()*/);
			ctx.tree_depth --;
		}

		std::string class_inherit = getInheritsString(_class_define_, symbol_class, ctx);

		std::string class_base = "";
		if (_class_define_->hasBaseClass() ) {
			class_base += _class_define_->Inherits()[0];
//		} else if (_default_base_object != "") {
		} else {
			class_base = m_default_base_object;
		}

		/* change both symbol table into class symbol */
		std::string class_implements = getImplementsListString(_class_define_, symbol_class, ctx);

		std::list<PatternPtr> patterns;

		patterns.push_back( PatternPtr( new Pattern("class_name", _class_define_->getClassName() ) ));
		patterns.push_back( PatternPtr( new Pattern("class_properties", getClassMemberVariableProperties( symbol_class ) )) );
		patterns.push_back( PatternPtr( new Pattern("class_stmt", class_stmt ) ));
		patterns.push_back( PatternPtr( new Pattern("class_inherit", class_inherit ) ));
		patterns.push_back( PatternPtr( new Pattern("class_implements_list", class_implements ) ));
		patterns.push_back( PatternPtr( new Pattern("class_base", class_base ) ));
		patterns.push_back( PatternPtr( new Pattern("class_type", _class_define_->isAbstract()?"struct":"class" ) ));
		patterns.push_back( PatternPtr( new Pattern("class_default_constructor", symbol_class->noContructor()?getDefaultConstructor(symbol_class,ctx):"" ) ));

		COMPELET_PATTERNS( patterns, ctx );


		std::string result = 
				substitutePatterns(  _class_define_->isAbstract()? m_tpl_interface : m_tpl_class
						, patterns );

		return result;
	}

	ClassDefinition()
		: TemplatePrinter("ClassDefinition")
		, m_default_base_object("")
		, m_tpl_property("")
		, _inherit_type(BOTH)
	{
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
	}

	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_default_base_object = pt.get<std::string>(  configName()+".inherit.base", m_default_base_object);
		m_tpl_class = pt.get<std::string>(  configName()+".template.class", m_tpl_class);
		m_tpl_interface = pt.get<std::string>(  configName()+".template.interface", m_tpl_interface);
		m_tpl_property = pt.get<std::string>(  configName()+".template.property", m_tpl_property);
		_inherit_type = pt.get<int>(  configName()+".inherit.type", (_inherit_type));
		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".inherit.base", m_default_base_object);
		pt.put<std::string>( configName()+".template.class", m_tpl_class);
		pt.put<std::string>( configName()+".template.interface", m_tpl_interface);
		pt.put<std::string>( configName()+".template.property", m_tpl_property);
		pt.put<int>( configName()+".inherit.type", _inherit_type);
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

	std::string m_tpl_class;
	std::string m_tpl_interface;
	std::string m_tpl_property;
	std::string m_tpl_setter;
	std::string m_tpl_getter;

	int	_inherit_type;

private:
	std::string getInheritsString(
				AST::ClassDefinitionPtr _class_define_
				, ASY::ScopePtr symbol_class
				, tw::maple::backend::cpp::Context& ctx
				
				)
	{
		std::string class_inherit = "";

		if( ( _inherit_type == ONLY_EXTENDS || _inherit_type == BOTH ) && _class_define_->hasBaseClass() )
		{
			class_inherit += ": public "+ symbol_class->getInherit()->getFQN_and_mappedName();
		}
		if( ( _inherit_type == ONLY_IMPLEMENTS || _inherit_type == BOTH) && _class_define_->hasInterface() )
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
		std::string answer = "#(indent_tab_add)public: "+symbol_class->name()+"()";

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
				if ( var && !var->isStatic() ) {
					std::string str_var_type;
					if( symbol_type->preferStack())
						str_var_type = symbol_type->getFQN_and_instanceName();
					else
						str_var_type = symbol_type->getFQN_and_mappedName() + "*" /* '*'or 'Ptr' */;

					// PROPERTY
					{
						std::list<PatternPtr> patterns;

						patterns.push_back( PatternPtr( new Pattern("property_type", str_var_type ) ));
						patterns.push_back( PatternPtr( new Pattern("property_name", var->name() ) ));

						answer += "#(indent_tab_add)"+substitutePatterns(m_tpl_property, patterns );
					}
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
						patterns.push_back( PatternPtr( new Pattern("variable_name", var->name() ) ));
						if( getter_not_found )
							answer += "#(indent_tab_add)"+substitutePatterns(m_tpl_getter, patterns ) + "#(endl)";
						if( setter_not_found )
							answer += "#(indent_tab_add)"+substitutePatterns(m_tpl_setter, patterns ) + "#(endl)";
					}
					answer += "#(endl)";
				}
			}
		}
		return answer;
	}
};

} } } } }

#endif 
