/*
 * Symbol.cpp
 *
 *  Created on: Apr 21, 2011
 *      Author: maple
 */

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


#include <boost/assert.hpp>
#include <string>
#include <as/symbol/Symbol.h>
#include <as/symbol/Scope.h>
#include <as/symbol/action/Registrable.h>

namespace tw { namespace maple { namespace as { namespace symbol {

//
//SHARED_PTR(T) Registrable::rootScope()
//{
//	SHARED_PTR(T) root( new T("root") );
//	root->setProperties( T::T_PROGRAM_ROOT );
//	return root;
//}
//
//SHARED_PTR(T) Registrable::registerFunction(std::string name )
//{
//	SHARED_PTR(T) s( new T( name ) );
//	s -> setProperties( T::T_FUNCTIONE);
//	_m_childs . push_back( s );
//	return s;
//}
//SymbolPtr Registrable::registerVariable(std::string name )
//{
//	SymbolPtr symbol( new Symbol( name ) );
//	symbol -> setSymbolProperties( T::T_VARIABLE);
//	_m_childs . push_back( symbol );
//	return symbol;
//}

}}}}//tw/maple/as/symbol

