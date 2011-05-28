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
		, m_no_contrucotr(true)
	{	}

	Scope( Scope *parent = NULL )
		: Symbol( "", Symbol::T_SCOPE ), Registrable( this )
		, m_scope_type( T_ANONYMOUS )
		, m_parent( parent )
		, m_no_contrucotr(true)
	{
		std::ostringstream ss;
		ss << "anonymous"<<m_parent->m_childs.size();
		m_name = ss.str();
	}

//	void setScopeType( ScopeType p ) {	m_scope_type = p;	};
	ScopeType getScopeType( ) const {	return m_scope_type;	}

	virtual std::string toString()
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
		std::cerr << " query " <<std::endl;
		for( int idx = 0 ; idx < query.size() ; idx ++ )
		{
			std::cerr << " query "<<query[idx]<<std::endl;
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
				std::cerr << "  = = 2'" << query[0] <<"'" << std::endl;
			else
				std::cerr << "  = = " << child->getSymbolProperties() << std::endl;
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

		return ( m_parent == NULL )? SymbolPtr() : m_parent->findType( type_name ) ;
	}
	virtual std::string getFQN()
	{
		if( m_parent )
			return m_parent->getFQN()+"::"+name();
		else if( m_scope_type == T_PROGRAM_ROOT)
			return "";
		else
			return name();
	}
	SymbolPtr findSymbol( std::string type_name )
	{
		for( std::vector<SymbolPtr>::iterator sitr = m_childs.begin() ; sitr != m_childs.end() ; sitr++)
		{
			std::cout << name() << " child "<<(*sitr)->name()<<std::endl;
			if( (*sitr)->name() == type_name ) {
				return (*sitr);
			}
		}
		std::cout << "can't find type_name "<<type_name<< " in this scope "<<name()<<std::endl;
		return ( m_parent == NULL )? SymbolPtr() : m_parent->findSymbol( type_name ) ;
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
	bool noContructor() { return m_no_contrucotr; }
	void setNoConstrtuctor( bool b ) { m_no_contrucotr = b; }
private:
	ScopeType m_scope_type;
	std::vector<SymbolPtr>	m_childs;

	Scope*	m_parent;
	bool	m_no_contrucotr;
//friend class Scope;
};

}}}}//tw/maple/as/symbol

#endif


