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

#define merge_and_copy( T, to, from) \
{ \
	for( T::iterator I = from.begin(), E = from.end() \
			; I != E ; I ++ ) \
		to.push_back( *I ); \
}


namespace tw { namespace maple {namespace as {namespace symbol {

ScopePtr Findable::findPackage( Scope* stable, const std::string& pkgs_name )
{

	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{
//		std::cerr << " findPackage iterator to " <<(*I)->name() << std::endl;
		if( (*I)->name() == pkgs_name && (*I)->is( Symbol::T_SCOPE ) )
		{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_PACKAGE )
			{
				return pkg_symbol;
			}
		}
	}
	if( stable->m_parent )
		return findPackage( stable->m_parent, pkgs_name );
	return ScopePtr();
}


ScopePtr Findable::findClassType_downward( Scope* stable, const std::string& class_name )
{
	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{
		if( (*I)->name() == class_name && (*I)->is(Symbol::T_SCOPE) )
		{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_CLASS )
			{
				return pkg_symbol;
			}
		}
		if( (*I)->name() == "" && (*I)->is( Symbol::T_SCOPE) )	{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_PACKAGE ) {
				ScopePtr found = findClassType_downward( pkg_symbol.get() , class_name );
				if( found )
					return found;
			}
		}
	}
	return ScopePtr();
}

SymbolPtr Findable::findType( Scope* stable, const std::string& type_name )
{
	SymbolPtr found = findType_downward(stable, type_name );
	if( found ) return found;
	if( stable->m_parent )
		return findType( stable->m_parent, type_name );
	return SymbolPtr();
}
SymbolPtr Findable::findType_downward( Scope* stable, const std::string& type_name )
{
	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{

		if( (*I)->name() == type_name && (*I)->is(Symbol::T_SCOPE) )
		{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_CLASS )
			{
				return *I;
			}
		}
		if( (*I)->name() == type_name && (*I)->is(Symbol::T_PRIMITIVE_TYPE) )
		{
			return *I;
		}
		if( (*I)->name() == "" && (*I)->is( Symbol::T_SCOPE) )
		{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_PACKAGE ) {
				SymbolPtr found = findType_downward( pkg_symbol.get() , type_name );
				if( found )
					return found;
			}
		}
	}
	return SymbolPtr();
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
std::vector<SymbolPtr> Findable::findRHS_Candidates( Scope* stable, const std::string& var_name )
{
	std::vector<SymbolPtr> answers;
	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{
		if( (*I)->name() == var_name && (*I)->is( Symbol::T_VARIABLE ) )
		{
			answers . push_back( *I );
		}

		if( (*I)->name() == var_name && (*I)->getSymbolProperties() == Symbol::T_SCOPE)	{
			if( FunctionPtr func_ptr = DYNA_CAST( Function, *I ) )	{
				if( func_ptr->isGetter() )	{
					answers.push_back( *I );
				}
			}
		}
	}

	if( stable->m_inherit  )
	{
		std::vector<SymbolPtr> founds = findRHS_Candidates( stable->m_inherit, var_name );
		merge_and_copy( std::vector<SymbolPtr>, answers, founds);
	}
	if( stable->m_parent )
	{
		std::vector<SymbolPtr> founds = findRHS_Candidates( stable->m_parent, var_name );
		merge_and_copy( std::vector<SymbolPtr>, answers, founds);
	}
	return answers;
}

std::vector<SymbolPtr> Findable::findLHS_Candidates( Scope* stable, const std::string& var_name )
{
	std::vector<SymbolPtr> answers;
	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{
		if( (*I)->name() == var_name && (*I)->is( Symbol::T_VARIABLE ) )
		{
			answers . push_back( *I );
		}

		if( (*I)->name() == var_name && (*I)->getSymbolProperties() == Symbol::T_SCOPE)	{
			if( FunctionPtr func_ptr = DYNA_CAST( Function, *I ) )	{
				if( func_ptr->isSetter() )	{
					answers.push_back( *I );
				}
			}
		}
	}

	if( stable->m_inherit  )
	{
		std::vector<SymbolPtr> founds = findLHS_Candidates( stable->m_inherit, var_name );
		merge_and_copy( std::vector<SymbolPtr>, answers, founds);
	}
	if( stable->m_parent )
	{
		std::vector<SymbolPtr> founds = findLHS_Candidates( stable->m_parent, var_name );
		merge_and_copy( std::vector<SymbolPtr>, answers, founds);
	}
	return answers;
}

FunctionPtr Findable::findFunction_downward( Scope* stable, const std::string& function_name )
{
	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
			; I != B ; I ++ )
	{
		if( (*I)->name() == function_name && (*I)->is(Symbol::T_SCOPE) )
		{
			ScopePtr scope_symbol = DYNA_CAST( Scope, *I );
			if( scope_symbol->getScopeType() == Scope::T_FUNCTION )
			{
				FunctionPtr func_symbol = DYNA_CAST( Function, *I );
				return func_symbol;
			}
		}
		if( (*I)->name() == "" && (*I)->is( Symbol::T_SCOPE) )	{
			ScopePtr pkg_symbol = DYNA_CAST( Scope, *I );
			if( pkg_symbol->getScopeType() == Scope::T_PACKAGE ) {
				FunctionPtr found = findFunction_downward( pkg_symbol.get() , function_name );
				if( found )
					return found;
			}
		}
	}
	return FunctionPtr();
}

FunctionPtr Findable::findFunction( Scope* stable, const std::string& function_name )
{
	FunctionPtr found = findFunction_downward(stable, function_name );
	if( found ) return found;
	if( stable->m_inherit )
		return findFunction( stable->m_inherit, function_name );
	if( stable->m_parent )
		return findFunction( stable->m_parent, function_name );
	return FunctionPtr();
}

std::vector<SymbolPtr> Findable::findClassMembers( Scope* stable, const std::string& name )
{
	std::vector<SymbolPtr> answers;
	if( ! stable->is( Scope::T_CLASS ) )
		return answers;

	for( std::vector<SymbolPtr>::iterator I = stable->m_childs.begin(), B = stable->m_childs.end()
				; I != B ; I ++ )
	{
		if( (*I) -> name() == name )
		{
			answers . push_back( *I );
		}
	}

	return answers;
}

}}}}//tw/maple/as/symbol

