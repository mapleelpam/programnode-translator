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

#ifndef __TW_MAPLE_AS_SYMBOL_PREDEF_H_
#define __TW_MAPLE_AS_SYMBOL_PREDEF_H_

#include "global.h"
#include <boost/assert.hpp>
#include <as/symbol/scope.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct PreDefine
{
	static void dump_symboltable(
			tw::maple::as::symbol::ScopePtr root
			, std::ofstream& ofs
			, int depth = 0
			)
	{

		std::vector<SymbolPtr> childs;
		root->getChilds( childs/*out*/ );
		namespace AST = tw::maple::as::ast;
		for (std::vector<SymbolPtr>::iterator
				child_itr = childs.begin(); child_itr != childs.end(); child_itr++) {

			if( ((*child_itr)->getSymbolProperties() & Symbol::T_SCOPE ) )
			{
				ScopePtr scope = STATIC_CAST( Scope, *child_itr );

				if( scope->is( Scope::T_CLASS ) )
				{
					ofs << indent(depth) <<  "SMART_PTR("<<scope->name()<<");"<<std::endl;
				}
				if( scope->is( Scope::T_PACKAGE ) )
				{
					ofs << indent(depth) <<  "namespace "<<scope->name()<<"{"<<std::endl;
				}

				if( scope )
					dump_symboltable( scope, ofs, depth+1 );

				if( scope->is( Scope::T_PACKAGE ) )
				{
					ofs << indent(depth) <<  "} /*"<<scope->name()<<"*/"<<std::endl;
				}
			}
//			else {
//				ofs << indent(depth) << (*child_itr)->toString() <<std::endl;
//			}
		}
	}
private:
	static std::string indent( int dpeth )
	{
			std::string ans = "";
			for( int idx = 0 ; idx < dpeth ; idx ++)
				ans += "  ";//TODO: replace by indent scape
            return ans;

	}

};

}}}}//tw/maple/as/symbol

#endif


