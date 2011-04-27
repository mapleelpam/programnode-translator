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


#ifndef __TW_MAPLE_AS_SYMBOL_SCOPE_H__
#define __TW_MAPLE_AS_SYMBOL_SCOPE_H__

#include "global.h"
#include <boost/assert.hpp>
#include <as/symbol/Symbol.h>
#include <as/symbol/action/Registrable.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct Scope;
typedef SHARED_PTR(Scope) ScopePtr;

struct Scope : public Symbol, public Registrable<Scope>
{
	enum Properties
	{
		T_NONE			,
		T_PACKAGE 		,
		T_FUNCTION		,
		T_CLASS			,
		T_ANONYMOUS		,

		T_PROGRAM_ROOT	,
	};

	Scope( std::string n, Properties t = T_NONE )
		: Symbol( n, Symbol::T_SCOPE ), Registrable<Scope>( this )
		, _m_scope_type( t )
	{	}

//	void setProperties( Properties p ) {	_m_scope_type = p;	};
	Properties getProperties( ) const {	return _m_scope_type;	}

	void getChilds( std::vector<SymbolPtr>& childs /*out*/ )	{	childs = _m_childs;	}

	virtual std::string toString()
	{
		std::string ans = "";

		switch( _m_scope_type ){
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
			std::cerr<<"can't resolve Scope Type" << _m_scope_type <<std::endl;
		}

		return ans+name();
	}


	bool isDeletable()
	{
		if( _m_scope_type != T_ANONYMOUS )	return false;
		if( _m_childs . size() == 0 )	return true;

		for( std::vector<SymbolPtr>::iterator sItr = _m_childs.begin() ; sItr != _m_childs.end() ; sItr++)
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

	bool removeChild( SymbolPtr s )
	{
		for( std::vector<SymbolPtr>::iterator sItr = _m_childs.begin() ; sItr != _m_childs.end() ; sItr++)
		{
			if( s == *sItr ) {
				_m_childs.erase( sItr );
				return true;
			}
		}
		return false;
	}
	void addChild( SymbolPtr s )
	{
		_m_childs . push_back( s );
	}
private:
	Properties _m_scope_type;
	std::vector<SymbolPtr>	_m_childs;

friend ScopePtr registerFunction(std::string);
friend class Registrable<Scope>;

};

}}}}//tw/maple/as/symbol

#endif


