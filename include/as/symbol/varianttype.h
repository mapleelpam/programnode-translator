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

#ifndef __TW_MAPLE_AS_SYMBOL_VARIANT_TYPE_H__
#define __TW_MAPLE_AS_SYMBOL_VARIANT_TYPE_H__

#include <as/symbol/symbol.h>

namespace tw { namespace maple { namespace as { namespace symbol {

struct VariantType : public Symbol
{
	VariantType()
		: Symbol( "variant", Symbol::T_PRIMITIVE_TYPE )
	{
	}


	virtual const std::string toString() const
	{
		return "type:variant";
	}

	virtual const std::string getFQN() const
	{
		return "";
	}
	virtual const std::string getFQN_and_m_mappedName() const
	{
		return "";
	}
	virtual bool isPrimitiveType( ) const
	{
		return true;
	}

	virtual const std::string getFQN_and_instanceName() const
	{
		return "";
	}

};

typedef SHARED_PTR(VariantType) VariantTypePtr;

}}}}//tw/maple/as/symbol

#endif

