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
#include <as/ast/function_attribute.h>
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
		AST::FunctionAttributePtr fattr = STATIC_CAST( AST::FunctionAttribute, fdef->FunctionAttr());
		AST::FunctionCommonPtr  fcommon = STATIC_CAST( AST::FunctionCommon, fdef -> FunctionCommon());
		if( fcommon == NULL ){
			printf(" hey !!!!!,  i cna't cast function common \n");
			exit(1);
		}

		// Function Return Type
		std::tr1::shared_ptr < AST::FunctionSignature > fsig
				= std::tr1::static_pointer_cast<AST::FunctionSignature>( fcommon -> FunctionSignature());

		std::string str_func_parameters = "";
		if (fsig->node_childs.size() > 1)
			str_func_parameters += dispatchExpound(fsig->FunctionParameter(), ctx); // parameters

		std::list<PatternPtr> patterns;


		std::string str_func_name = dispatchExpound(fdef->FunctionName(), ctx) ;

		std::string str_function_attribute = dispatchExpound( fattr, ctx) ;
		if( str_function_attribute != "")
			str_function_attribute+=":";

		patterns.push_back( PatternPtr( new Pattern("function_attribute", str_function_attribute+ ctx->endl()) ));
		patterns.push_back( PatternPtr( new Pattern("func_name", str_func_name+ "   ") ));
		patterns.push_back( PatternPtr( new Pattern("func_body", dispatchExpound(fcommon->FunctionBody(), ctx) ) ));
		patterns.push_back( PatternPtr( new Pattern("func_parameters", str_func_parameters ) ));
		patterns.push_back( PatternPtr( new Pattern("func_ret_type", dispatchExpound(fsig->FunctionReturnType(), ctx) ) ) );
		patterns.push_back( PatternPtr( new Pattern("endl", ctx->endl() ) ));
		patterns.push_back( PatternPtr( new Pattern("indent_tab", ctx->indent()) ));

		return substitutePatterns( patterns );
	}

	FunctionDefinition()
		: TemplatePrinter("FunctionDefinition")
	{
		setTemplateString(  "#(function_attribute)"
							"#(indent_tab)#(func_ret_type) #(func_name)(#(func_parameters))#(endl)#(indent_tab){#(endl)"
							"#(func_body)"
							"#(indent_tab)}#(endl)" )
							;
	}
};

};


} } } } 

#endif 
