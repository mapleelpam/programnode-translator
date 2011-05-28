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

	virtual std::string expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context* ctx)
	{

		AST::ClassDefinitionPtr _class_define_ = STATIC_CAST( AST::ClassDefinition, node);
		if( _class_define_->isIntrinsic())
			return "";  // Ignore Intrinsic
		ASY::ScopePtr	symbol_class = _class_define_->getClassSymbol();

		std::string class_stmt = "";
		if( _class_define_->hasStatement() ) {
			ctx->tree_depth ++;
				class_stmt = dispatchExpound(_class_define_->classStmt(), symbol_table, ctx);
			ctx->tree_depth --;
		}

		std::string class_inherit = "";
		if( _class_define_->hasBaseClass() | _class_define_->hasInterface() ){
			for( int idx = 0 ; idx < _class_define_->Inherits().size() ; idx ++){
				class_inherit += class_inherit=="" ? " : " : " , ";
				class_inherit += " public "+ _class_define_->Inherits()[idx];
			}
			for( int idx = 0 ; idx < _class_define_->Implements ().size() ; idx ++){
				class_inherit += class_inherit=="" ? " : " : " , ";
				class_inherit += " public "+ _class_define_->Implements()[idx];
			}
		}
		if( _default_base_object != "" &&  (!_class_define_->hasBaseClass()) ){
			class_inherit += class_inherit=="" ? " : " : " , ";
			class_inherit += " public " + _default_base_object;
		}

		std::string class_base = "";
		if (_class_define_->hasBaseClass() ) {
			class_base += _class_define_->Inherits()[0];
		} else if (_default_base_object != "") {
			class_base = _default_base_object;
		}

		std::list<PatternPtr> patterns;

		patterns.push_back( PatternPtr( new Pattern("class_name", _class_define_->getClassName() ) ));
		patterns.push_back( PatternPtr( new Pattern("class_stmt", class_stmt ) ));
		patterns.push_back( PatternPtr( new Pattern("class_inherit", class_inherit ) ));
		patterns.push_back( PatternPtr( new Pattern("class_base", class_base ) ));
		patterns.push_back( PatternPtr( new Pattern("class_type", _class_define_->isAbstract()?"struct":"class" ) ));
		patterns.push_back( PatternPtr( new Pattern("class_default_constructor", symbol_class->noContructor()?getDefaultConstructor(symbol_class,ctx):"" ) ));

		patterns.push_back( PatternPtr( new Pattern("endl", ctx->endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx->indent()) ));


		std::string result = "\n/*begin*/\n"
				+substitutePatterns(  _class_define_->isAbstract()? _template_interface : _template_class
						, patterns )
				+"\n/*end*/\n";

		return result;
	}

	ClassDefinition()
		: TemplatePrinter("ClassDefinition")
		, _default_base_object("")
	{
		_template_class = ( "#(indent_tab) #(class_type) #(class_name)  #(class_inherit) #(endl)#(indent_tab){#(endl)"
							"#(class_stmt)"
							"#(class_default_constructor)"
							"#(endl)#(indent_tab)};#(endl)" )
							;
		_template_interface = ( "#(indent_tab) #(class_type) #(class_name)  #(endl)#(indent_tab){#(endl)"
							"#(class_stmt)"
							"#(endl)#(indent_tab)};#(endl)" )
							;
	}

	virtual bool readConfig( boost::property_tree::ptree& pt )
	{
		_default_base_object = pt.get<std::string>(  configName()+".inherit.base", _default_base_object);
		_template_class = pt.get<std::string>(  configName()+".template.class", _template_class);
		_template_interface = pt.get<std::string>(  configName()+".template.interface", _template_interface);
		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>( configName()+".inherit.base", _default_base_object);
		pt.put<std::string>( configName()+".template.class", _template_class);
		pt.put<std::string>( configName()+".template.interface", _template_interface);
		return TemplatePrinter::writeConfig( pt );
	}

private:
	std::string _default_base_object;

	std::string _template_class;
	std::string _template_interface;

private:
	std::string getDefaultConstructor(
			ASY::ScopePtr symbol_class,
			tw::maple::backend::cpp::Context* ctx)
	{
		std::string answer = "#(indent_tab)public: "+symbol_class->name()+"()";

		std::vector<ASY::SymbolPtr> childs;
		symbol_class->getChilds(childs/*out*/);
		for (std::vector<ASY::SymbolPtr>::iterator child_itr = childs.begin(); child_itr
				!= childs.end(); child_itr++) {

			std::cout << "symbol name = " << (*child_itr)->name() << std::endl;
			if (((*child_itr)->getSymbolProperties() & ASY::Symbol::T_VARIABLE)) {
				ASY::VariablePtr var = STATIC_CAST( ASY::Variable, *child_itr );
				if (var->getInitializeNode() != NULL && var->isStatic() == false) {
					answer
							+= ":" + var->name() + "("
									+ dispatchExpound(
											var->getInitializeNode(),
											symbol_class/*TODO: should use function's parent*/,
											ctx) + ")";
				}
			}
		}
		answer += "#(endl)#(indent_tab){}#(endl)";

		return answer;
	}
};

} } } } }

#endif 
