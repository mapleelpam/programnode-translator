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

#ifndef __TW_MAPLE_AS_SYMBOL_SCOPE_H__
#define __TW_MAPLE_AS_SYMBOL_SCOPE_H__

#include "global.h"
#include <boost/assert.hpp>
#include <as/symbol/symbol.h>
#include <as/symbol/action/registrable.h>
#include <as/symbol/primitivetype.h>
#include <sstream>

namespace tw { namespace maple { namespace as { namespace symbol {

struct Scope;
typedef SHARED_PTR(Scope) ScopePtr;

struct Scope : public Symbol, public Registrable
{
	enum ScopeType
	{
		T_NONE			,
		T_PACKAGE 		,
		T_FUNCTION		,
		T_CLASS			,
		T_ANONYMOUS		,
		T_PROGRAM_ROOT	,
	};

	Scope( std::string n, ScopeType t = T_NONE, Scope *parent = NULL )
		: Symbol( n, Symbol::T_SCOPE ), Registrable( this )
		, m_scope_type( t )
		, m_parent( parent )
		, m_inherit( NULL )
		, m_no_contrucotr(true)
	{	}

	Scope( Scope *parent = NULL )
		: Symbol( "", Symbol::T_SCOPE ), Registrable( this )
		, m_scope_type( T_ANONYMOUS )
		, m_parent( parent )
		, m_inherit( NULL )
		, m_no_contrucotr(true)
	{
		std::ostringstream ss;
		ss << "anonymous"<<m_parent->m_childs.size();
		m_name = ss.str();
	}

	~Scope()
	{
		m_parent = NULL;
	}
//	void setScopeType( ScopeType p ) {	m_scope_type = p;	};
	ScopeType getScopeType( ) const {	return m_scope_type;	}

	virtual const std::string toString() const
	{
		std::string ans = "";

		switch( m_scope_type ){
		case T_PACKAGE:
			ans += "package:";
			break;
		case T_FUNCTION:
			ans += "function:";
			break;
		case T_CLASS:
			ans += "class:";
			break;
		case T_ANONYMOUS:
			ans += "anonymous:";
			break;
		default:
			std::cerr<<"can't resolve Scope Type" << m_scope_type <<std::endl;
		}

		return ans+name();
	}


	bool isDeletable()
	{
		if( m_scope_type != T_ANONYMOUS )	return false;
		if( m_childs . size() == 0 )	return true;

		for( std::vector<SymbolPtr>::iterator sItr = m_childs.begin() ; sItr != m_childs.end() ; sItr++)
		{
			if( ((*sItr)->getSymbolProperties() & Symbol::T_SCOPE ) )
			{
				ScopePtr scope = STATIC_CAST( Scope, *sItr );
				if( scope->isDeletable() )
					continue;
				else
					return false;
			} else
				return false;

		}
		return true;
	}

	bool isInstance( std::string query, std::string delimiter )
	{
		std::vector<std::string> query_tokens = tokenize(query,delimiter,false);

		std::cerr << " query "<<query<<std::endl;
		return isInstance( query_tokens, delimiter );
	}
	bool isInstance( std::vector<std::string> query, std::string delimiter )
	{
		std::cerr << name() << " query " <<std::endl;
		for( int idx = 0 ; idx < query.size() ; idx ++ )
		{
			std::cerr << "in here:"<< name() << " query "<<query[idx]<<std::endl;
		}
		SymbolPtr child = findSymbol( query[0] );
		if( child && child->getSymbolProperties() == T_VARIABLE)
		{
			if(query.size() == 1 )
				return true;
			else
				return false;
		} else if( child && child->getSymbolProperties() == T_SCOPE) {
			if (query.size() == 1)
				return false;
			else {
				ScopePtr child_scope = STATIC_CAST( Scope, child );
				std::vector < std::string > second_query = query;
				second_query . erase(second_query.begin());
				return child_scope->isInstance(second_query, delimiter);
			}
		} else {
			if( child == NULL)
				std::cerr << name() << "  = = 2'" << query[0] <<"'" << std::endl;
			else
				std::cerr << name() << "  = = " << child->getSymbolProperties() << std::endl;
			return false;
		}
		return true;
	}


	bool removeChild( SymbolPtr s )
	{
		for( std::vector<SymbolPtr>::iterator sItr = m_childs.begin() ; sItr != m_childs.end() ; sItr++)
		{
			if( s == *sItr ) {
				m_childs.erase( sItr );
				return true;
			}
		}
		return false;
	}
	void addChild( SymbolPtr s )
	{
		m_childs . push_back( s );
	}

	void getChilds( std::vector<SymbolPtr>& childs /*out*/ )
	{
		childs = m_childs;
	}

	SymbolPtr findType( std::string type_name )
	{
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() != type_name )
				continue;

			if( (*sitr)->getSymbolProperties() & Symbol::T_PRIMITIVE_TYPE )
			{
				return (*sitr);
			}
			else if( (*sitr)->getSymbolProperties() & Symbol::T_SCOPE )
			{
				ScopePtr scope = STATIC_CAST( Scope, *sitr );
				if( scope->getScopeType() == T_CLASS )
				{
					return (*sitr);
				}
			}
		}
		// find the anonymouse package
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() == ""  && (*sitr)->getSymbolProperties() == T_SCOPE ) {
				ScopePtr anonymous_package = DYNA_CAST( Scope, *sitr );
				if( anonymous_package -> getScopeType() == T_PACKAGE )
				{
					SymbolPtr found = anonymous_package -> findType_down( type_name );
					if( found )
						return found;
					else
						continue;
				}
			}
		}

		return ( m_parent == NULL )? SymbolPtr() : m_parent->findType( type_name ) ;
	}
	virtual const std::string getFQN( bool& is_annoymouse_scope /*out*/) const
	{
		is_annoymouse_scope = ( name() == "" );

		if( m_parent )
		{
			bool parent_is_anonymouse_scope = false;
			std::string parent_name = m_parent->getFQN( parent_is_anonymouse_scope );
			if( parent_is_anonymouse_scope && is_annoymouse_scope )
				return parent_name;
			else if( parent_is_anonymouse_scope )
				return parent_name+name();
			else
				return parent_name+"::"+name();
		}
		else if( m_scope_type == T_PROGRAM_ROOT)
			return "";
		else {
			return name();
		}
	}
	virtual const std::string getFQN_and_mappedName( bool& is_annoymouse_scope /*out*/ ) const
	{
		is_annoymouse_scope = ( mappedName() == "" );

		if( m_parent )
		{
			bool parent_is_anonymouse_scope = false;
			std::string parent_name = m_parent->getFQN( parent_is_anonymouse_scope );
			if( parent_is_anonymouse_scope && is_annoymouse_scope )
				return parent_name;
			else if( parent_is_anonymouse_scope )
				return parent_name+mappedName();
			else
				return parent_name+"::"+mappedName();
		}
		else if( m_scope_type == T_PROGRAM_ROOT)
			return "";
		else {
			return this->mappedName();
		}
	}
	virtual const std::string getFQN() const
	{
		bool dummy;
		return getFQN(dummy);
	}
	virtual const std::string getFQN_and_mappedName() const
	{
		bool dummy;
		return getFQN_and_mappedName(dummy);
	}
	SymbolPtr findSymbol( const std::string& type_name)
	{
		// this scope
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin(), E = m_childs.end() ; sitr != E ; sitr++)
		{
//			std::cout <<"Scope::FindSymbol("<<type_name<<")"<< name() << " child "<<(*sitr)->name()<<std::endl;
			if( (*sitr)->name() == type_name ) {
				return (*sitr);
			}
		}
		// find inherit
		if( getInherit() != NULL)
		{
			SymbolPtr found = getInherit() -> findSymbol( type_name );
			if( found != NULL)
				return found;
		}
		// find the anonymouse package
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin(), E = m_childs.end() ; sitr != E ; sitr++)
		{
			if( (*sitr)->name() == ""  && (*sitr)->getSymbolProperties() == T_SCOPE ) {
				ScopePtr anonymous_package = DYNA_CAST( Scope, *sitr );
				if( anonymous_package -> getScopeType() == T_PACKAGE )
				{
					SymbolPtr found = anonymous_package -> findSymbol_down( type_name );
					if( found )
						return found;
					else
						continue;
				}
			}
		}
		std::cout << "can't find type_name '"<<type_name<< "' in this scope '"<<name()<<"'"<<std::endl;
		return ( m_parent == NULL )? SymbolPtr() : m_parent->findSymbol( type_name ) ;
	}
	SymbolPtr findSymbol_down( const std::string& type_name )
	{
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() == type_name ) {
				return (*sitr);
			}
		}

		// find the anonymouse package
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() == ""  && (*sitr)->getSymbolProperties() == T_SCOPE ) {
				ScopePtr anonymous_package = DYNA_CAST( Scope, *sitr );
				if( anonymous_package -> getScopeType() == T_PACKAGE )
				{
					SymbolPtr found = anonymous_package -> findSymbol_down( type_name );
					if( found )
						return found;
					else
						continue;
				}
			}
		}

		return SymbolPtr();
	}
	std::vector<SymbolPtr> findSymbol_down2( const std::string& type_name )
	{
		std::vector<SymbolPtr> answers;

		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() == type_name ) {
				answers.push_back( *sitr );
			}
		}

		// find inherit
		if( getInherit() != NULL)
		{
			std::vector<SymbolPtr> founds = getInherit() -> findSymbol_down2( type_name );
			if( founds.size() > 0)
				answers = founds;
		}

		// find the anonymouse package
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() == ""  && (*sitr)->getSymbolProperties() == T_SCOPE ) {
				ScopePtr anonymous_package = DYNA_CAST( Scope, *sitr );
				if( anonymous_package -> getScopeType() == T_PACKAGE )
				{
					std::vector<SymbolPtr> founds = anonymous_package -> findSymbol_down2( type_name );
//					if( found )
//						return found;
//					else
//						continue;

					std::copy( founds.begin(), founds.end(), answers.end() );
				}
			}
		}

		return answers;
	}
	SymbolPtr findType_down( const std::string& type_name )
	{
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() == type_name  && (*sitr)->getSymbolProperties() & Symbol::T_SCOPE )
			{
				ScopePtr scope = STATIC_CAST( Scope, *sitr );
				if( scope->getScopeType() == T_CLASS )
				{
					return (*sitr);
				}
			}
		}

		// find the anonymouse package
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			if( (*sitr)->name() == ""  && (*sitr)->getSymbolProperties() == T_SCOPE ) {
				ScopePtr anonymous_package = DYNA_CAST( Scope, *sitr );
				if( anonymous_package -> getScopeType() == T_PACKAGE )
				{
					SymbolPtr found = anonymous_package -> findSymbol_down( type_name );
					if( found )
						return found;
					else
						continue;
				}
			}
		}

		return SymbolPtr();
	}
private:
	std::vector<std::string> tokenize(const std::string& str, const std::string& delimiters, bool allowEmptyTokenString) const
	{
		std::vector<std::string> tokens;
		std::string::size_type delimPos = 0, tokenPos = 0, pos = 0;

		if (str.length() < 1)
			return tokens;

		while (true)
		{
			delimPos = str.find_first_of(delimiters, pos);
			tokenPos = str.find_first_not_of(delimiters, pos);

			if (std::string::npos != delimPos)
			{
				if (std::string::npos != tokenPos)
				{
					if (tokenPos < delimPos)
					{
						tokens.push_back(str.substr(pos, delimPos - pos));
					}
					else
					{
						if (allowEmptyTokenString)	tokens.push_back("");
					}
				}
				else
				{
					if (allowEmptyTokenString) tokens.push_back("");
				}
				pos = delimPos + 1;
			}
			else
			{
				if (std::string::npos != tokenPos)
				{
					tokens.push_back(str.substr(pos));
				}
				else
				{
					if (allowEmptyTokenString) tokens.push_back("");
				}
				break;
			}
		}
		return tokens;
	}

public:
	Scope* getParent()
	{
		return m_parent;
	}

	Scope* getInherit()
	{
		if( getScopeType() == T_CLASS )
			return m_inherit;
		else
			return NULL;
	}
	Scope* setInhrit( Scope* inherit )
	{
		m_inherit = inherit;
	}

	bool noContructor() { return m_no_contrucotr; }
	void setNoConstrtuctor( bool b ) { m_no_contrucotr = b; }

	bool isIntrinsic(){	return m_is_intrinsic;	}
	void setIsIntrinsic( bool b ){	m_is_intrinsic = b;	}
private:
	ScopeType m_scope_type;
	std::vector<SymbolPtr>	m_childs;

	Scope*	m_parent; // could not be "shared_pointer, because will cause circular reference
	Scope*  m_inherit;
	bool	m_no_contrucotr;
	bool 	m_is_intrinsic;
//friend class Scope;
};

}}}}//tw/maple/as/symbol

#endif


