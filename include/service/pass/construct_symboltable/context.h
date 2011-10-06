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
 * https://github.com/mapleelpam/programnode-translator              *
 *                                                                   *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple           *
 \*******************************************************************/


#ifndef __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_CTX_H_
#define __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_PH2_CTX_H_

#include <as/ast/abstract/expression.h>
#include <backend/cpp/context.h>
#include <as/symbol/scope.h>

//#define DEBUG_INTERPRET_ENTRY {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " enter function" <<std::endl;	}
//#define DEBUG_INTERPRET_LEAVE {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " leave function" <<std::endl;	}

namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ {

struct Phase2Context
{
	Phase2Context()
	{
		enterScope(); // dummy enter
	}
	~Phase2Context()
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
//				std::cerr << " import name '" << (*import_itr)->name() <<"' try to find "<<name << std::endl;
				if( (*import_itr)->name() == name )
					return (*import_itr);
			}
		}

		return tw::maple::as::symbol::ScopePtr();
	}

	tw::maple::as::symbol::SymbolPtr find_symbol( std::string name )
	{
		tw::maple::as::symbol::ScopePtr p_scope = find_scope( name );
		return STATIC_CAST( tw::maple::as::symbol::Scope, p_scope );
	}
//public:
//	tw::maple::as::ast::ClassDefinitionPtr	m_class_definition_node;
private:
	typedef std::vector<tw::maple::as::symbol::ScopePtr> T_ImportList;
	typedef SHARED_PTR( T_ImportList ) P_ImportList;
	std::vector<P_ImportList>	m_stack;

};

typedef SHARED_PTR( Phase2Context )	Phase2ContextPtr;



} } } } }

#endif 
