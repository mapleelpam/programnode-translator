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
 * downward language governing permissions and limitations
 * under the License.
 *
 * ProgrameNode Translator
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.
 *
 * https://github.com/mapleelpam/programnode-translator
 *
 * Author: mapleelpam at gmail.com - Kai-Feng Chou - maple
 * ***************************************************************/

#ifndef _TW_MAPLE_AS_AST_SYMBOL_ASCTION_H__
#define _TW_MAPLE_AS_AST_SYMBOL_ASCTION_H__

#include <as/symbol/symbol.h>

namespace tw {namespace maple {namespace as {namespace symbol {

struct Function;
typedef SHARED_PTR(Function) FunctionPtr;

struct Scope;
typedef SHARED_PTR(Scope) ScopePtr;

struct Variable;
typedef SHARED_PTR(Variable) VariablePtr;

struct Findable {

//	Findable(Scope* instance) :
//		_instance(instance) {
//	}

//	static ScopePtr findPackage( std::vector<std::string> pkgs_name);
	static ScopePtr findPackage( Scope* stable, const std::string& pkgs_name );
	static ScopePtr findPackage( ScopePtr stable, const std::string& pkgs_name )
		{ return findPackage( stable.get(), pkgs_name ); }
	static ScopePtr findClassType( Scope* stable, const std::string& class_name );
	static ScopePtr findClassType( ScopePtr stable, const std::string& class_name )
		{	return findClassType( stable.get(), class_name ); }
	static ScopePtr findClassType_downward( Scope* stable, const std::string& class_name );

	static SymbolPtr findType_downward( Scope* stable, const std::string& type_name );
	static SymbolPtr findType( Scope* stable, const std::string& type_name );
	static SymbolPtr findType( ScopePtr stable, const std::string& type_name )
		{	return findType( stable.get(), type_name ); }

	static FunctionPtr findFunction_downward( Scope* stable, const std::string& function_name );
	static FunctionPtr findFunction( Scope* stable, const std::string& type_name );
	static FunctionPtr findFunction( ScopePtr stable, const std::string& type_name )
		{	return findFunction( stable.get(), type_name ); }

	static std::vector<SymbolPtr> findRHS_Candidates( Scope* stable, const std::string& var_name );
	static std::vector<SymbolPtr> findRHS_Candidates( ScopePtr stable, const std::string& var_name )
		{	return findRHS_Candidates( stable.get(), var_name ); }

	static std::vector<SymbolPtr> findLHS_Candidates( Scope* stable, const std::string& var_name );
	static std::vector<SymbolPtr> findLHS_Candidates( ScopePtr stable, const std::string& var_name )
		{	return findLHS_Candidates( stable.get(), var_name ); }

	static ScopePtr findCallee( Scope* stable, const std::string& class_name );
	static ScopePtr findCallee( ScopePtr stable, const std::string& class_name )
		{	return findCallee( stable.get(), class_name ); }
private:

//	Scope* _instance;
};

}}}}//tw/maple/as/symbol

#endif /* REGISTRABLE_H_ */
