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

#ifndef __TW_MAPLE_AS_AST_SATEMENTS_CLASS_DEFINE_H__
#define __TW_MAPLE_AS_AST_SATEMENTS_CLASS_DEFINE_H__

#include <global.h>
#include <as/ast/statement.h>


namespace tw { namespace maple { namespace as { namespace ast {

struct ClassDefine : public Statement
{
	ClassDefine( std::string name
			, const std::vector<std::string>& inherits
			, const std::vector<std::string>& interfaces)
		: Statement(Node::NodeType::T_CLASS_DEFINE)
	 	, _has_base_class( false )
		, _has_base_interface( false )
		, _has_attribute( false )
		, _has_statement( false )
		, _is_abstract( false )
		, m_classname( name )
		, m_inherits( inherits )
		, m_implements( interfaces )
	{
	}

	NodePtr classAttribute(){
		return _has_attribute?  node_childs[0] : NodePtr();
	}
	NodePtr classStmt(){
		return _has_statement? node_childs[ node_childs.size() - 1] : NodePtr();
	}

	std::string toString()  {	return "node::class_define"; };

	void setHasBaseClass( bool b )	{	_has_base_class = b;	}
	void setHasInterface( bool b )	{	_has_base_interface = b;	}
	void setHasAttribute( bool b )	{	_has_attribute = b;	}
	void setHasStatement( bool b )	{	_has_statement = b;	}
	void setIsAbstract( bool b) 	{	_is_abstract = b;	}


	bool hasBaseClass()	{	return _has_base_class; }
	bool hasInterface()	{	return _has_base_interface;}
	bool hasAttribute()	{	return _has_attribute;	}
	bool hasStatement()	{	return _has_statement;	}
	bool isAbstract()	{	return _is_abstract;	}

	std::string getClassName()	const {	return m_classname;	}
	const std::vector<std::string>& Inherits()	{	return m_inherits;	}
	const std::vector<std::string>& Implements()	{	return m_implements;	}
private:
	bool _has_base_class;
	bool _has_base_interface;
	bool _has_attribute;
	bool _has_statement;
	bool _is_abstract;

	std::string					m_classname;
    std::vector<std::string>	m_inherits;
    std::vector<std::string>	m_implements;

};
typedef std::tr1::shared_ptr<ClassDefine> ClassDefinePtr;


} } } }

#endif
