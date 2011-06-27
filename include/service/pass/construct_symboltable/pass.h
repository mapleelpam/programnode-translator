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


#ifndef __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_H_
#define __TW_MAPLE_SERVICE_PASS_CONSTRUCTOR_SYMBOL_TABLE_H_

#include <as/ast/abstract/expression.h>
#include <backend/cpp/context.h>
#include <as/symbol/scope.h>

//#define DEBUG_INTERPRET_ENTRY {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " enter function" <<std::endl;	}
//#define DEBUG_INTERPRET_LEAVE {std::cout << typeid(*this).name() << "::"<<__FUNCTION__<< " leave function" <<std::endl;	}


namespace tw { namespace maple { namespace service { namespace pass {  namespace cs /*I.E. Construct SymbolTable */ {


struct constructor_stage { enum type { PH1_SYMBOL, PH2_BINDING, PH3_ANALYZE }; };

template< typename N, int Stage>
struct Pass
{
	//Abstract
};


struct Phase2Context
{
	typedef std::vector<tw::maple::as::symbol::ScopePtr> T_ImportList;
	typedef SHARED_PTR( T_ImportList ) P_ImportList;
	std::stack<P_ImportList>	m_stack;

	void enterScope()
	{
		m_stack . push( P_ImportList( new T_ImportList() ) );
	}

	void leaveScope()
	{
		m_stack . pop();
	}
};

typedef SHARED_PTR( Phase2Context )	Phase2ContextPtr;



} } } } }

#endif 
