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

#ifndef __TW_MAPLE_AS_SYMBOL_PRIMITIVE_TYPE_H__
#define __TW_MAPLE_AS_SYMBOL_PRIMITIVE_TYPE_H__

#include <as/symbol/symbol.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct PrimitiveType : public Symbol
{
	PrimitiveType( std::string n, std::string another_name, std::string c /*bool _is_pointer = false*/ )
		: Symbol( n, Symbol::T_PRIMITIVE_TYPE )
//		, m_mappedName( another_name )
//		, is_pointer( _is_pointer )
	{
		setMappedName( another_name );
		m_mapped_name = another_name;
		class_name = c;
	}


	virtual const std::string toString() const
	{
		return "type:"+name()+":"+mappedName()+":"+getFQN_and_instanceName();
	}

	virtual const std::string getFQN() const
	{
		return name();
	}
	virtual const std::string getFQN_and_m_mappedName() const
	{
		return mappedName();
	}
	virtual bool isPrimitiveType( ) const
	{
		return true;
	}
//	virtual bool isVariant( ) const
//	{
//		return true;
//	}
	bool preferStack() const {	return true;	} // don't use heap, operator new
	std::string instanceName()	const {	return mappedName();	}

	std::string className() const { return class_name;	};
//	void setClassName( std::string s ) {	class_name = s;	}

	virtual const std::string getFQN_and_instanceName() const
	{
		return instanceName();
	}

//	bool is_pointer;

private:
	std::string class_name;
};

typedef SHARED_PTR(PrimitiveType) PrimitiveTypePtr;

}}}}//tw/maple/as/symbol

#endif

