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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_SWITCH_STMT_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_SWITCH_STMT_H__

#include <as/ast/stmt/switch_stmt.h>
#include <backend/cpp/interpret/interpreter.h>
#include <backend/cpp/templateprinter.h>
#include <as/ast/token/case_label.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct SwitchStatement : public Interpreter, public TemplatePrinter
{

	virtual ReturnValue expound(::tw::maple::as::ast::NodePtr node
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			)
	{
		AST::SwitchStatementPtr SWITCH = std::tr1::static_pointer_cast<AST::SwitchStatement>(node);
		std::list<PatternPtr> patterns;


		ctx.tree_depth ++ ;
		std::string s_switch_body = dispatchExpound(SWITCH->SWitchBody(), symbol_table, ctx);
		ctx.tree_depth -- ;

		ReturnValue switch_expr = dispatchExpound(SWITCH->SwitchExpression(), symbol_table, ctx);

		COMPELETE_PATTERNS( patterns, ctx );

		std::string debug;

		std::vector < std::string > list;
		bool has_default = false;
		{
			findAllCase(SWITCH->SWitchBody(), symbol_table, ctx, list /*out*/, has_default /*out*/);

			for (int idx = 0; idx < list.size(); idx++) {
				debug += "/* " + list[idx] + " */";
			}
		}
		if( has_default )
			std::cerr << " ---- has default = true"<<std::endl;

		return substitutePatterns( frontOfSwitch(list, has_default, switch_expr)+s_switch_body+backOfSwitch(), patterns );

//		patterns.push_back( PatternPtr( new Pattern("switch_expression", s_switch_expr ) ));
//		patterns.push_back( PatternPtr( new Pattern("switch_body", s_switch_body ) ));
//		return frontOfSwitch(list)+substitutePatterns( patterns );
	}

	SwitchStatement()
		: TemplatePrinter("SwitchStatement")
	{
		setTemplateString( "#(indent_tab)switch(#(switch_expression)){#(endl)"
				"#(switch_body)"
				"#(indent_tab)};#(endl)" );
	}

private:
	void findAllCase( AST::NodePtr body
			, tw::maple::as::symbol::ScopePtr symbol_table
			, tw::maple::backend::cpp::Context& ctx
			, std::vector<std::string>& list /*out*/
			, bool& has_default /*out*/
			)
	{
		if( !body->is( AST::Node::NodeType::T_STMT_LIST) )
		{
			findAllCase( body->node_childs[0], symbol_table, ctx, list, has_default ); // TODO: ker ker
			return;
		}

		for (std::vector<std::tr1::shared_ptr<tw::maple::as::ast::Node> >::iterator nItr =
			body->node_childs.begin(); nItr != body->node_childs.end(); nItr++)
		{
			if( (*nItr)->is( AST::Node::NodeType::T_DEFAULT_LABEL) )
			{
				std::cerr << " hey i got the default label \n";
				has_default = true;
			}

			if( !(*nItr)->is( AST::Node::NodeType::T_CASE_LABEL) )
				continue;


			AST::CaseLabelPtr LABEL = DYNA_CAST(AST::CaseLabel, *nItr);
			if( LABEL )
			{
				std::string str_expr = dispatchExpound(LABEL->label(), symbol_table, ctx);
				list.push_back( str_expr );
			}

		}

//		return "";
	}

	std::string frontOfSwitch( std::vector < std::string >& case_list, bool has_default, ReturnValue& switch_expr )
	{
		std::string result = "#(indent_tab)do{#(endl)";
		const std::string s_expr_pattern = " __expression__";

		{
			if( switch_expr.token_symbol )
				result += "#(indent_tab_add)"+getTypeString(switch_expr.token_symbol)+" "+s_expr_pattern;
			else
				result += "#(indent_tab_add)int "+s_expr_pattern;
			result += " = " +switch_expr.result+";#(endl)";
		}
		for (int idx = 0; idx < case_list.size(); idx++) {
			std::string label_string = "caselabel_" + case_list[idx];
			label_string = removeSpecialChar(label_string);

			result += "#(indent_tab_add)if( "+s_expr_pattern+" == " + case_list[idx] + " ) { goto "+ label_string+"; }#(endl)";
		}
		if( has_default )
			result += "#(indent_tab_add)goto defaultlabel;#(endl)";

		return result;
	}
	std::string backOfSwitch()
	{
		return "#(indent_tab_add)break;#(endl)#(indent_tab)}while(1);#(endl)";
	}


};

};


} } } } 

#endif 
