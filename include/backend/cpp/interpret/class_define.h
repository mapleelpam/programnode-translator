/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// ProgrameNode Translator
// Copyright 2011 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CLASS_DEFINE_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CLASS_DEFINE_H__

#include <as/ast/class_define.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/template_printer.h>


namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ClassDefine : public Interpreter, public TemplatePrinter
{   

	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		AST::ClassDefinePtr _class_define_ = STATIC_CAST( AST::ClassDefine, node);

		std::string class_name = dispatchExpound(_class_define_->className(), ctx);
		ctx->tree_depth ++;
			std::string class_stmt = dispatchExpound(_class_define_->classStmt(), ctx);
		ctx->tree_depth --;

		std::string class_inherit = "";
		std::string class_inherit_token = "";
		if( _class_define_->hasBaseClass() ){
			class_inherit = dispatchExpound(_class_define_->node_childs[1], ctx);
			class_inherit_token = " : public ";
		} else if( _default_base_object != ""){
			class_inherit = _default_base_object;
			class_inherit_token = " : public ";
		}

		std::list<PatternPtr> patterns;

		patterns.push_back( PatternPtr( new Pattern("class_name", class_name ) ));
		patterns.push_back( PatternPtr( new Pattern("class_stmt", class_stmt ) ));
		patterns.push_back( PatternPtr( new Pattern("class_inherit", class_inherit ) ));
		patterns.push_back( PatternPtr( new Pattern("class_inherit_token", class_inherit_token ) ));

		patterns.push_back( PatternPtr( new Pattern("endl", ctx->endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx->indent()) ));

		std::string result = substitutePatterns( patterns );

		return result;
	}

	ClassDefine()
		: TemplatePrinter("ClassDefine")
		, _default_base_object("")
	{
		setTemplateString( "%(indent_tab)class %(class_name) %(class_inherit_token) %(class_inherit) %(endl)%(indent_tab){%(endl)"
							"%(class_stmt)"
							"%(indent_tab)};%(endl)" )
							;
	}

	virtual bool readConfig( boost::property_tree::ptree& pt )
	{

		_default_base_object = pt.get<std::string>(  configName()+".inherit.base", _default_base_object);

		return TemplatePrinter::readConfig( pt );
	}
	virtual bool writeConfig( boost::property_tree::ptree& pt )
	{

		pt.put<std::string>( configName()+".inherit.base", _default_base_object);

		return TemplatePrinter::writeConfig( pt );
	}

private:
	std::string _default_base_object;
};

};


} } } } 

#endif 
