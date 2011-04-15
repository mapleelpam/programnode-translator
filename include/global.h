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
// Copyright 2010 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple



#ifndef __TW_MAPLE_GLOBAL_H__
#define __TW_MAPLE_GLOBAL_H__

#include <iostream>
#include <stack>

#define USE_STD_SMART_PTR

#ifdef USE_STD_SMART_PTR
	#include <tr1/memory>
	#define SHARED_PTR(X) std::tr1::shared_ptr<X>
	#define STATIC_CAST(T,X) std::tr1::static_pointer_cast<T>(X)

#endif



#endif
