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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_DEFINITION_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_DEFINITION_H__

#include <as/ast/func/function_definition.h>
#include <as/ast/func/function_signature.h>
#include <as/ast/func/function_attribute.h>
#include <as/ast/func/function_common.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/symbol/function.h>
#include <as/symbol/variable.h>
#include <backend/cpp/interpret/interpreter.h>
#include <service/globalsettings.h>

#include <global.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;
namespace ASY = tw::maple::as::symbol;

struct FunctionDefinition : public Interpreter, public TemplatePrinter
{   
	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{

		std::string result;

		AST::FunctionDefinitionPtr fdef = STATIC_CAST( AST::FunctionDefinition, node);
		AST::FunctionCommonPtr  fcommon = STATIC_CAST( AST::FunctionCommon, fdef -> FunctionCommon());
		BOOST_ASSERT( fcommon != NULL );

		// Function Return Type
		AST::FunctionSignaturePtr fsig
				= STATIC_CAST( AST::FunctionSignature, fcommon -> FunctionSignature());

		ReturnValue str_func_parameters = fsig->node_childs.size()
				? dispatchExpound(fsig->FunctionParameter(), symbol_table, ctx)
				:"";

		ctx.without_type = true;
		ReturnValue str_func_arguments = fsig->node_childs.size()
				? dispatchExpound(fsig->FunctionParameter(), symbol_table, ctx)
				:"";
		ctx.without_type = false;

		std::list<PatternPtr> patterns;

		ASY::FunctionPtr	symbol_function = fdef->getFunctionSymbol();

		if( symbol_function->isIntrinsic() )
		{
			return "";  // Ignore Intrinsic
		}

		std::string 		str_function_attribute;
		switch( symbol_function->getSymbolAttribtues() )
		{
			case ASY::Symbol::ATTR_NONE:
			{
				if( symbol_function->isMemberFunction() )
					str_function_attribute="public";
				else
					str_function_attribute="";
			}
			break;
			case ASY::Symbol::ATTR_PRIVATE:	str_function_attribute="private";	break;
			case ASY::Symbol::ATTR_PUBLIC:	str_function_attribute="public";	break;
			case ASY::Symbol::ATTR_PROTECTED:	str_function_attribute="protected";	break;
		}
		std::string str_func_attr_stmt = (str_function_attribute=="")?"":str_function_attribute+": ";
		if( SVC_GLOBAL_SETTINGS -> declare_only )	str_func_attr_stmt = "";
		std::string str_numof_parameter;
		{
			std::stringstream ss;
			ss << symbol_function->numberOfParameter();
			ss >> str_numof_parameter;

		}
		std::string str_numof_default_parameter;
		{
			std::stringstream ss;
			ss << symbol_function->numberOfDefaultParameter();
			ss >> str_numof_default_parameter;
		}
		std::string str_func_name = _function_name_mapper( symbol_function->name(), symbol_function );
		std::string str_func_name_prefix = "";
		if( symbol_function->getParent() -> is(ASY::Scope::T_CLASS)
				&& SVC_GLOBAL_SETTINGS -> declare_only )
			str_func_name_prefix = symbol_function->getParent()->name()+"::";
		std::string str_function_body;
		{
			if( fdef->isAbstract)
			{
				str_function_body = std::string(" = 0;#(endl)");
			}
			else if ( SVC_GLOBAL_SETTINGS -> define_only )
			{
				str_function_body = ";";
			}
			else
			{
				ctx.tree_depth ++ ; ctx.tree_depth ++ ;
				str_function_body = std::string("#(endl)#(indent_tab_add){#(endl)")
				+ dispatchExpound(fcommon->FunctionBody(), symbol_function, ctx).result
				+ "#(indent_tab_add)}#(endl)";
				ctx.tree_depth -- ; ctx.tree_depth -- ;
			}
		}

		std::string str_function_return_type = symbol_function->isConstructor() ? "":
				(symbol_function->ReturnType()->preferStack() ? symbol_function->ReturnType()->getFQN_and_instanceName() :
						symbol_function->ReturnType()->getFQN_and_mappedName() + m_pointer_pattern ) ;

		if( ! symbol_function->isConstructor() )
			str_function_return_type = ( str_function_return_type == "" ) ? "void" : str_function_return_type;

		std::string tpl_function_signature;
		if( symbol_function->isMemberFunction() )
		{
			if(symbol_function->isConstructor())
				tpl_function_signature = m_tpl_constructor_function_signature;
			else if(symbol_function->isStatic() || fdef->isAbstract )
				tpl_function_signature = m_tpl_normal_function_signature;
			else
				tpl_function_signature = m_tpl_member_function_signature;
		}else
			tpl_function_signature = m_tpl_normal_function_signature;

		std::string str_function_parameter_types = "";
		{
			std::vector<ASY::SymbolPtr>::iterator nItr = symbol_function->m_types.begin(), E = symbol_function->m_types.end();
			nItr ++;
			for( ; nItr != E ; nItr ++ )
			{
				ASY::SymbolPtr symbol_type = *nItr;
				if( symbol_type->preferStack())
					str_function_parameter_types += ", "+symbol_type->getFQN_and_instanceName();
				else
					str_function_parameter_types +=  ", "+symbol_type->getFQN_and_mappedName() + "*"/* '*'or 'Ptr' */;

			}
		}
		

		std::string str_static_instance;
		if( !(SVC_GLOBAL_SETTINGS -> declare_only) &&
			symbol_function->getEverUsedLikeVariable()
				&& !symbol_function->isGetter()
				&& !symbol_function->isSetter() 
				&& !symbol_function->isConstructor() )
		{
			str_static_instance = m_tpl_static_instance;
		}

		std::string str_prefix_parameter = "";
		{
			std::string pname, ptype;
			bool found;
			fdef->getPrefixParameterName( pname, ptype, found);
			if( found )
			{
				for( std::vector<ASY::SymbolPtr>::iterator itr = symbol_function->m_childs.begin(), E = symbol_function->m_childs.end()
					; itr != E ; itr ++ )
				{
					if((*itr)->name() == pname )
					{
						if( ASY::ParameterPtr sym_param = DYNA_CAST(ASY::Parameter, *itr ) )
						{
							ASY::SymbolPtr symbol_type = sym_param->getTypeSymbol();
							if( symbol_type->preferStack())
								str_prefix_parameter += symbol_type->getFQN_and_instanceName()+" "+ sym_param->name();
							else
								str_prefix_parameter += symbol_type->getFQN_and_mappedName() + "* "/* '*'or 'Ptr' */+ sym_param->name();
						}
					}
				}
			}
		}
		std::string str_is_virtual = "";
		if (fdef->isAbstract ||
		    (!symbol_function->isConstructor() && (m_default_virtual &&
		    		(!symbol_function->isStatic())&&symbol_function->isMemberFunction() )) )
				str_is_virtual = "virtual ";
		if( SVC_GLOBAL_SETTINGS -> declare_only )
			str_is_virtual = "";

		std::string str_is_static = "";
		if (symbol_function->isStatic() && (!SVC_GLOBAL_SETTINGS -> declare_only) )
			str_is_static = "static ";

		patterns.push_back( PatternPtr( new Pattern("func_static_instance", str_static_instance )));

		patterns.push_back( PatternPtr( new Pattern("common",  (str_func_parameters.result)==""?"":"," ) ) );
		patterns.push_back( PatternPtr( new Pattern("parent_name",  symbol_function->getParent()->name() ) ) );

		patterns.push_back( PatternPtr( new Pattern("function_signature", tpl_function_signature )));
		patterns.push_back( PatternPtr( new Pattern("function_attribute", str_function_attribute) ));
		patterns.push_back( PatternPtr( new Pattern("function_attribute_stmt", str_func_attr_stmt )) );
		patterns.push_back( PatternPtr( new Pattern("func_name", str_func_name) ));
		patterns.push_back( PatternPtr( new Pattern("func_name_prefix", str_func_name_prefix) ));
		patterns.push_back( PatternPtr( new Pattern("func_body",  str_function_body )) );
		patterns.push_back( PatternPtr( new Pattern("func_parameters", str_func_parameters.result ) ));
		patterns.push_back( PatternPtr( new Pattern("func_parameters_variable_only", _function_parameter_argonly(symbol_function) ) ));
		patterns.push_back( PatternPtr( new Pattern("func_parameters_number", str_numof_parameter ) ));
		patterns.push_back( PatternPtr( new Pattern("func_default_parameters_number", str_numof_default_parameter ) ));
		patterns.push_back( PatternPtr( new Pattern("func_parameter_types", str_function_parameter_types )) ); 
		patterns.push_back( PatternPtr( new Pattern("func_arguments", str_func_arguments.result ) ));
		patterns.push_back( PatternPtr( new Pattern("func_ret_type",  str_function_return_type ) ) );
		patterns.push_back( PatternPtr( new Pattern("function_is_static", str_is_static ) ) );
		patterns.push_back( PatternPtr( new Pattern("function_is_virtual", str_is_virtual ) ) );
		patterns.push_back( PatternPtr( new Pattern("function_enter", (fdef->isAbstract || SVC_GLOBAL_SETTINGS -> define_only )? "" : m_tpl_enter_function) ) );
		patterns.push_back( PatternPtr( new Pattern("enter_stmt", fdef->getEnterFunctionMapper() != "" ? fdef->getEnterFunctionMapper() : "/*enter function*/" ) ) );
		patterns.push_back( PatternPtr( new Pattern("function_leave", (fdef->isAbstract || SVC_GLOBAL_SETTINGS -> define_only )? "" : m_tpl_leave_function) ) );
		patterns.push_back( PatternPtr( new Pattern("member_initial", (symbol_function->isConstructor())? getMemberInitializer(symbol_function,fdef->mp_parent_initilizer,ctx) : "") ) );
		patterns.push_back( PatternPtr( new Pattern("prefix_parameters", str_prefix_parameter) ) );
		patterns.push_back( PatternPtr( new Pattern("postfix_parameters", "") ) );
		patterns.push_back( PatternPtr( new Pattern("contructor_prefix_info", ( SVC_GLOBAL_SETTINGS -> declare_only ) ?
															"":m_tpl_constructor_prefix_info) ) );


		COMPELET_PATTERNS( patterns, ctx );

		return substitutePatterns( patterns );
	}

	FunctionDefinition()
		: TemplatePrinter("FunctionDefinition")
		, m_pointer_pattern("*")
		, m_default_virtual( true )
	{
		setTemplateString(  "#(function_signature)"
							"#(member_initial)"

							"#(function_enter)"
							"#(func_body)"
							"#(function_leave)"
                            "#(func_static_instance)"
							"#(endl)"
							 )
							;
		m_tpl_normal_function_signature = m_tpl_constructor_function_signature = m_tpl_member_function_signature =
				"#(indent_tab)#(function_attribute_stmt)""#(endl)"
				"#(indent_tab)"
				"#(function_is_static)"
				"#(function_is_virtual)"
				"#(func_ret_type) #(func_name_prefix)#(func_name)(#(prefix_parameters)#(func_parameters)#(postfix_parameters))"
; 
        m_tpl_static_instance = "#(endl)#(indent_tab)"
            "static #(func_ret_type) #(func_name_prefix)static_#(func_name)( ObjectPtr p#(common) #(prefix_parameters)#(func_parameters)#(postfix_parameters)){ ((#(parent_name)*)(Object*)p)->#(func_name)(#(func_parameters_variable_only)); }#(endl)"
        ;

		m_tpl_enter_function = "#(endl)#(indent_tab){#(endl)#(indent_tab_add)#(enter_stmt)";
		m_tpl_leave_function = "#(indent_tab_add)/*leave function*/#(endl)#(indent_tab)}";

		m_tpl_setter_prepend = "set_";
		m_tpl_getter_prepend = "get_";

		m_tpl_constructor_prefix_info = "";
	}

	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		m_tpl_normal_function_signature = pt.get<std::string>( configName()+".template.normal_signature", m_tpl_normal_function_signature);
		m_tpl_member_function_signature = pt.get<std::string>( configName()+".template.member_signature", m_tpl_member_function_signature);
		m_tpl_constructor_function_signature = pt.get<std::string>( configName()+".template.constructor_signature", m_tpl_constructor_function_signature);

		m_tpl_enter_function = pt.get<std::string>(  configName()+".template.enter_function", m_tpl_enter_function);
		m_tpl_leave_function = pt.get<std::string>(  configName()+".template.leave_function", m_tpl_leave_function);

		m_tpl_setter_prepend	= pt.get<std::string>( configName()+".template.setter_prepend", m_tpl_setter_prepend);
		m_tpl_getter_prepend	= pt.get<std::string>( configName()+".template.getter_prepend", m_tpl_getter_prepend);

		m_pointer_pattern = pt.get<std::string>(  configName()+".pointer_pattern", m_pointer_pattern);

		m_tpl_constructor_prefix_info = pt.get<std::string>( configName()+".contructor_prefix_info", m_tpl_constructor_prefix_info);


		m_default_virtual = pt.get<bool>( configName()+".default_virtual", m_default_virtual);
		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".template.normal_signature", m_tpl_normal_function_signature);
		pt.put<std::string>( configName()+".template.member_signature", m_tpl_member_function_signature);
		pt.put<std::string>( configName()+".template.constructor_signature", m_tpl_constructor_function_signature);

		pt.put<std::string>( configName()+".template.enter_function", m_tpl_enter_function);
		pt.put<std::string>( configName()+".template.leave_function", m_tpl_leave_function);

		pt.put<std::string>( configName()+".template.setter_prepend", m_tpl_setter_prepend);
		pt.put<std::string>( configName()+".template.getter_prepend", m_tpl_getter_prepend);
		pt.put<std::string>( configName()+".pointer_pattern", m_pointer_pattern);
		pt.put<std::string>( configName()+".contructor_prefix_info", m_tpl_constructor_prefix_info);

		pt.put<bool>( configName()+".default_virtual",m_default_virtual);
		return TemplatePrinter::writeConfig( pt );
	}

private:
	std::string m_tpl_enter_function;
	std::string m_tpl_leave_function;

	std::string m_tpl_args_prefix;
	std::string m_tpl_args_postfix;

	std::string m_tpl_setter_prepend;
	std::string m_tpl_getter_prepend;

	std::string m_tpl_normal_function_signature;
	std::string m_tpl_member_function_signature;
	std::string m_tpl_constructor_function_signature;
	std::string m_tpl_static_instance;
	std::string m_tpl_constructor_prefix_info;

	bool		m_default_virtual;
	std::string m_pointer_pattern;

private:
	std::string getMemberInitializer(
			ASY::FunctionPtr symbol_function
			, AST::SuperInit* parent_init
			, tw::maple::backend::cpp::Context& ctx
			
			)
	{
		std::string answer = "";
		std::vector<ASY::SymbolPtr> childs;
		symbol_function->getParent()->getChilds( childs/*out*/ );

		if( parent_init )
		{
			ASY::Scope* symbol_class = symbol_function->m_parent;
			answer+= ": "+symbol_class->m_inherit->name()+"("+dispatchExpound(parent_init->node_childs[0], symbol_function, ctx).result+")";
		}

		for (std::vector<ASY::SymbolPtr>::iterator child_itr = childs.begin(); child_itr
				!= childs.end(); child_itr++) {

//			std::cout << "symbol name = "<< (*child_itr)->name()<<std::endl;
			if (((*child_itr)->getSymbolProperties() & ASY::Symbol::T_VARIABLE))
			{
				ASY::VariablePtr var = STATIC_CAST( ASY::Variable, *child_itr );
				if( var->getInitializeNode() != NULL && !var->isStatic() )
				{
					answer += (answer==""?":":",")
						+ var->name() + "("
						+ dispatchExpound(var->getInitializeNode(), symbol_function, ctx).result
						+")";
				}
			}
		}

		return answer;
	}

	std::string _function_name_mapper( std::string function_name, ASY::FunctionPtr symbol_function )
	{
		if( symbol_function -> isGetter() )
			return m_tpl_getter_prepend+function_name;
		if( symbol_function -> isSetter() )
			return m_tpl_setter_prepend+function_name;
		return function_name;
	}
	std::string _function_parameter_argonly( ASY::FunctionPtr symbol_function )
	{
		std::string answer;
		for( std::vector<ASY::SymbolPtr>::iterator itr = symbol_function->m_childs.begin(), E = symbol_function->m_childs.end()
				; itr != E ; itr ++ )
		{
			ASY::ParameterPtr symbol_param = DYNA_CAST( ASY::Parameter, *itr );
			if( symbol_param )
				answer += (answer==""?"":" ,")+symbol_param->name();
		}
		return answer;
	}
};

}


} } } } 

#endif 

