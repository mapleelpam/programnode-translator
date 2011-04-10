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

#ifndef __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CLASS_DEFINE_H__
#define __TW_MAPLE_BACKEDN_CPP_INTERPRET_STMT_CLASS_DEFINE_H__

#include <as/ast/class_define.h>
#include <as/ast/call.h>
#include <backend/cpp/interpret/interpreter.h>

namespace tw { namespace maple { namespace backend { namespace cpp { namespace interpret {

namespace AST = ::tw::maple::as::ast;

struct ClassDefine : public Interpreter
{   
	void interpret( AST::NodePtr node, cpp::Context* ctx )
	{

		AST::ClassDefinePtr _class_define_ = std::tr1::static_pointer_cast<AST::ClassDefine>(node);
		ctx->tree_depth ++;

		ctx->ofs_stream << ctx->indent() << "class  ";
			dispatchDo(_class_define_->className(), ctx);
		ctx->ofs_stream << "{\n";
			dispatchDo(_class_define_->classStmt(), ctx);
		ctx->ofs_stream << "" << ctx->indent()<<"};";

		ctx->tree_depth --;
	}
};

};


} } } } 

#endif 
