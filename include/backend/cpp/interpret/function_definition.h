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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_DEFINITION_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_FUNCTION_DEFINITION_H__

#include <as/ast/function_definition.h>
#include <as/ast/function_signature.h>
#include <as/ast/function_rettype.h>
#include <as/ast/function_common.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/template_printer.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct FunctionDefinition : public Interpreter, public TemplatePrinter
{   
	virtual std::string expound(::tw::maple::as::ast::NodePtr node,	tw::maple::backend::cpp::Context* ctx)
	{
		std::string result;

		AST::FunctionDefinitionPtr fdef = STATIC_CAST( AST::FunctionDefinition, node);

//		std::tr1::shared_ptr < AST::FunctionCommon > fcommon= std::tr1::static_pointer_cast<AST::FunctionCommon>( fdef -> FunctionCommon());
		AST::FunctionCommonPtr  fcommon = STATIC_CAST( AST::FunctionCommon, fdef -> FunctionCommon());


		// Function Return Type
		std::tr1::shared_ptr < AST::FunctionSignature > fsig
				= std::tr1::static_pointer_cast<AST::FunctionSignature>( fcommon -> FunctionSignature());

		std::string str_func_parameters = "";
		if (fsig->node_childs.size() > 1)
			str_func_parameters += dispatchExpound(fsig->FunctionParameter(), ctx); // parameters

		std::list<PatternPtr> patterns;

		patterns.push_back( PatternPtr( new Pattern("func_name", dispatchExpound(fdef->FunctionName(), ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("func_body", dispatchExpound(fcommon->FunctionBody(), ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("func_parameters", str_func_parameters ) ));
		patterns.push_back( PatternPtr( new Pattern("func_ret_type", dispatchExpound(fsig->FunctionReturnType(), ctx) ) ) );
		patterns.push_back( PatternPtr( new Pattern("endl", ctx->endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx->indent()) ));

		return substitutePatterns( _stmt_template, patterns);
	}

	FunctionDefinition()
	{
		_stmt_template = "%indent_tab%%func_ret_type% %func_name%(%func_parameters%){%endl%"
							"%func_body%"
							"%indent_tab%}"
							;
	}

	bool readConfig( boost::property_tree::ptree& pt )
	{
		_stmt_template = pt.get<std::string>("func_def.template", _stmt_template);
		return true;
	}
	bool writeConfig( boost::property_tree::ptree& pt )
	{
		pt.put<std::string>("func_def.template", _stmt_template);
		return true;
	}

private:
	std::string _stmt_template;
};

};


} } } } 

#endif 
