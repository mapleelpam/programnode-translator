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
 *     https://github.com/mapleelpam/programnode-translator          *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#ifndef __PNC_TW_MAPLE_BACKEDN_CONTEXT_H__
#define __PNC_TW_MAPLE_BACKEDN_CONTEXT_H__

#include <fstream>
#include <as/symbol/scope.h>

#define COMPELET_PATTERNS( P, C ) \
	{ \
	P.push_back( PatternPtr( new Pattern("endl", C.endl() ) )); \
	P.push_back( PatternPtr( new Pattern("indent_tab", C.indent()) )); \
	P.push_back( PatternPtr( new Pattern("indent_tab_sub", C.indentSub()) )); \
	P.push_back( PatternPtr( new Pattern("indent_tab_add", C.indentAdd()) )); \
	}

namespace tw { namespace maple { namespace backend { namespace cpp {

struct Context
{
	enum InterpretType
	{
		LHS,
		RHS,
//		DELETE
	};
	struct ScopeContext
	{
		ScopeContext()
		{
			enterScope(); // dummy enter
		}
		~ScopeContext()
		{
			leaveScope(); // dummy enter
		}

		void enterScope()
		{
			m_stack . push_back( P_ImportList( new T_ImportList() ) );
		}

		void leaveScope()
		{
			m_stack . pop_back();
		}

		void add_import( tw::maple::as::symbol::ScopePtr p_class )
		{
			(m_stack . back()) -> push_back( p_class );
		}

		tw::maple::as::symbol::ScopePtr find_scope( std::string name )
		{
			for( std::vector<P_ImportList>::iterator scope_itr = m_stack.begin() , E = m_stack.end()
					; scope_itr != E ; scope_itr ++ )
			{
				P_ImportList p_import_list = *(scope_itr);

				for( T_ImportList::iterator import_itr = p_import_list -> begin(), E = p_import_list -> end()
					; import_itr != E ; import_itr ++ )
				{
					if( (*import_itr)->name() == name )
					{
						return (*import_itr);
					}
				}
			}

			return tw::maple::as::symbol::ScopePtr();
		}

		tw::maple::as::symbol::SymbolPtr find_symbol( std::string name )
		{
			tw::maple::as::symbol::ScopePtr p_scope = find_scope( name );
			return STATIC_CAST( tw::maple::as::symbol::Scope, p_scope );
		}
	private:
		typedef std::vector<tw::maple::as::symbol::ScopePtr> T_ImportList;
		typedef SHARED_PTR( T_ImportList ) P_ImportList;
		std::vector<P_ImportList>	m_stack;
	};

	struct IndentContext
	{
		IndentContext() : indent(0){}
		int operator++(int) // Postfix
		{
			return indent++;
		}
		int operator++() // Prefix
		{
			return ++indent;
		}
		int operator--(int) // Postfix
		{
			return indent--;
		}
		int operator--() // Prefix
		{
			return --indent;
		}
		int toInt()
        {
            return indent;
        }
		std::string toString()
		{
			std::string ans = "";
			for( int idx = 0 ; idx < indent ; idx ++)
				ans += "    ";//TODO: replace by indent scape
            return ans;
		}
		private:
		int		indent;
	};

    std::string indent()
    {
        return tree_depth.toString();
    }
    std::string indentAdd()
    {
    	tree_depth++;
		std::string answer = tree_depth.toString();
		tree_depth--;
		return answer;
    }
    std::string indentSub()
    {
    	tree_depth --;
    	std::string answer = tree_depth.toString();
    	tree_depth ++;
        return answer;
    }

    std::string endl()
    {
        return "\n";
    }
    Context()
    	: inter_type( RHS )
    	, lfs_is_setter( false )
    	, expression_symbol( NULL )
    	, statement_class_symbol( tw::maple::as::symbol::ScopePtr() )
    	, left_is_pointer( false )
    	, without_type(false)
    	, is_delete( false )
    {

    }

	IndentContext	tree_depth;
	ScopeContext	tableof_imported;	//handle import

	InterpretType   inter_type;
	bool			lfs_is_setter;
	bool			left_is_pointer;
	bool			without_type; // for param
	bool			is_delete;

	tw::maple::as::symbol::Symbol*	expression_symbol;
	tw::maple::as::symbol::ScopePtr	statement_class_symbol;
	tw::maple::as::symbol::ScopePtr	call_arguments_symbol;

	tw::maple::as::symbol::FunctionPtr	callee_type;

//	tw::maple::as::symbol::SymbolPtr		token_class_type;
};

} } } }

#endif 
