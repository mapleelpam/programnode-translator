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

#ifndef __TW_MAPLE_AS_AST_SATEMENTS_CLASS_DEFINE_H__
#define __TW_MAPLE_AS_AST_SATEMENTS_CLASS_DEFINE_H__

#include <global.h>
#include <as/ast/abstract/statement.h>
#include "SyntaxTree_types.h"

namespace tw { namespace maple { namespace as { namespace ast {

struct ClassDefinition : public Statement
{
	ClassDefinition( std::string name
			, const std::vector<std::string>& inherits
			, const std::vector<std::string>& interfaces
			, const std::vector<std::string>& attrs
			 )
		: Statement(Node::NodeType::T_CLASS_DEFINE)
	 	, m_has_base_class( false )
		, m_has_base_interface( false )
		, m_has_attribute( false )
		, m_has_statement( false )
		, m_is_abstract( false )
//		, m_is_intrinsic( false )
		, m_classname( name )
		, m_inherits( inherits )
		, m_implements( interfaces )
		, m_attributes( attrs )
	{
	}

	NodePtr classAttribute(){
		return m_has_attribute?  node_childs[0] : NodePtr();
	}
	NodePtr classStmt(){
		return m_has_statement? node_childs[ node_childs.size() - 1] : NodePtr();
	}

	std::string toString()  {	return "node::class_define"; };

	void setHasBaseClass( bool b )	{	m_has_base_class = b;	}
	void setHasInterface( bool b )	{	m_has_base_interface = b;	}
	void setHasAttribute( bool b )	{	m_has_attribute = b;	}
	void setHasStatement( bool b )	{	m_has_statement = b;	}
	void setIsAbstract( bool b) 	{	m_is_abstract = b;	}
//	void setIntrinsic( bool b )	{	m_is_intrinsic = b;	}

	bool hasBaseClass()	{	return m_has_base_class; }
	bool hasInterface()	{	return m_has_base_interface;}
	bool hasAttribute()	{	return m_has_attribute;	}
	bool hasStatement()	{	return m_has_statement;	}
	bool isAbstract()	{	return m_is_abstract;	}
//	bool isIntrinsic()	{	return m_is_intrinsic;	}

	std::string getClassName()	const {	return m_classname;	}
	const std::vector<std::string>& Inherits()	{	return m_inherits;	}
	const std::vector<std::string>& Implements()	{	return m_implements;	}

	void setMetaData( tw::maple::generated::MetaData& md )
	{
		m_metadata = md;
	}
	/* advaned methods */
	bool isNativeClass( )
	{
//		std::cerr << "native class '"<<m_metadata.id<<"'"<<std::endl;
		if(m_metadata.id == "native")
			return true;
		else
			return false;
	}
	std::string getMappedClassName( /*bool& OK*/)
	{
//		OK = false;
		if(m_metadata.id == "native")
		{
			if(m_metadata.keyvalues.find("cls") != m_metadata.keyvalues.end() )
			{
//				OK = true;
				return m_metadata.keyvalues["cls"];
			}
		}
		return getClassName();
	}
	bool isIntrinsic()
	{
		for( std::vector<std::string>::iterator itr = m_attributes.begin(), E = m_attributes.end()
				; itr != E ; itr ++ )
		{
			if( *itr == "intrinsic" )
				return true;
		}
		return false;
	}

public:
    void setClassSymbol( ASYM::ScopePtr s )	{	_related_class_symbol = s;	}
    ASYM::ScopePtr getClassSymbol( )	{	return _related_class_symbol;	}
protected:
    ASYM::ScopePtr	_related_class_symbol;
private:
	bool m_has_base_class;
	bool m_has_base_interface;
	bool m_has_attribute;
	bool m_has_statement;
	bool m_is_abstract;
//	bool m_is_intrinsic;

	std::string					m_classname;
    std::vector<std::string>	m_inherits;
    std::vector<std::string>	m_implements;

    std::vector<std::string>	m_attributes;


    tw::maple::generated::MetaData	m_metadata;
};
typedef SHARED_PTR(ClassDefinition) ClassDefinitionPtr;


} } } }

#endif
