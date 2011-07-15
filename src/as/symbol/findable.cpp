 /*******************************************************************\
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
 * downward language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 *     https://github.com/mapleelpam/programnode-translator          *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#include <global.h>
#include <as/symbol/symbol.h>
#include <as/symbol/scope.h>
#include <as/symbol/variable.h>
#include <as/symbol/action/registrable.h>
#include <as/symbol/function.h>
#include <as/symbol/action/findable.h>

namespace tw { namespace maple {namespace as {namespace symbol {

ScopePtr Findable::findPackage( Scope* stable, const std::string& pkgs_name )
{

	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{
		if( (*I)->name() == pkgs_name && (*I)->getSymbolProperties() == Symbol::T_SCOPE)
		{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_PACKAGE )
			{
				return pkg_symbol;
			}
		}
	}
}

ScopePtr Findable::findClassType_downward( Scope* stable, const std::string& class_name )
{
	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{
//		std::cerr << " in find ct '" << stable->getFQN() <<"' '"<< (*I)->name() <<"'"<< std::endl;
		if( (*I)->name() == class_name && (*I)->getSymbolProperties() == Symbol::T_SCOPE)
		{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_CLASS )
			{
				return pkg_symbol;
			}
		}
		if( (*I)->name() == "" && (*I)->getSymbolProperties() == Symbol::T_SCOPE )
		{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_PACKAGE )
			{
				ScopePtr found = findClassType_downward( pkg_symbol.get() , class_name );
				if( found )
					return found;
			}
		}
	}
	return ScopePtr();
}


ScopePtr Findable::findClassType( Scope* stable, const std::string& class_name )
{
	ScopePtr found = findClassType_downward( stable, class_name );
	if( found )
		return found;
	else if( stable->m_parent )
		return findClassType( stable->m_parent, class_name );
	else
		return ScopePtr();
}


}}}}//tw/maple/as/symbol

