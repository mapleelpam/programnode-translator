/* ******************************************************************\
 * Copyright 2011 Kai-Feng Chou - mapleellpam at gmail dot com       *
 *                                                                   *
 * Licensed under the Apache License, Version 2.0 (the "License");   *
 * you may not use this file except in compliance with the License.  *
 * You may obtain a copy of the License at                           *
 *                                                                   *
 *   http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                   *
 * Unless required by applicable law or agreed to in writing,        *
 * software distributed under the License is distributed on an       *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY            *
 * KIND, either express or implied. See the License for the          *
 * specific language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2011 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 *     https://github.com/mapleelpam/programnode-translator          *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#ifndef __TW_MAPLE_SERVICE_LINLER_LINKER_H__
#define __TW_MAPLE_SERVICE_LINLER_LINKER_H__

#include <AstDumper.h>
#include <transport/TSimpleFileTransport.h>
//#include <protocol/TJSONProtocol.h>
#include <protocol/TBinaryProtocol.h>

//using namespace ::apache::thrift;
//using namespace ::apache::thrift::protocol;
//using namespace ::apache::thrift::transport;
//using namespace ::apache::thrift::server;

//#define printf(STRING) {};

namespace tw { namespace maple { namespace service { namespace linker {

class Linker: virtual public generated::AstDumperIf {

public:
	boost::shared_ptr<tw::maple::generated::AstDumperClient> pm_module;

	Linker(std::string fn) :
		pm_module() {
		boost::shared_ptr < apache::thrift::transport::TSimpleFileTransport
				> transport(
						new apache::thrift::transport::TSimpleFileTransport(fn,
								true, true));
		//boost::shared_ptr<apache::thrift::protocol::TProtocol> protocol( new  apache::thrift::protocol::TJSONProtocol(transport) );
		boost::shared_ptr < apache::thrift::protocol::TProtocol > protocol(
				new apache::thrift::protocol::TBinaryProtocol(transport));

		pm_module.reset(new tw::maple::generated::AstDumperClient(protocol));
	}

	void startProgram(const std::string& version, const int64_t counter) {

		printf("startProgram\n");
	}

	void endProgram() {

		printf("endProgram\n");
	}

	void startPackage(const std::vector<std::string> & id) {

		printf("startPackage\n");
		pm_module->startPackage(id);
	}

	void endPackage(const std::vector<std::string> & IDs) {

		printf("endPackage\n");
		pm_module->endPackage(IDs);
	}

	void startFunctionDefinition(const bool isAbstract) {

		printf("startFunctionDefinition\n");
		pm_module->startFunctionDefinition(isAbstract);
	}

	void functionAttribute(const std::vector<std::string> & attrs) {

		printf("functionAttribute\n");
		pm_module->functionAttribute(attrs);
	}

	void functionName(const std::string& name,
			tw::maple::generated::FunctionType::type t) {

		printf("functionName\n");
		pm_module->functionName(name, t);
	}

	void startFunctionCommon() {

		printf("startFunctionCommon\n");
		pm_module->startFunctionCommon();
	}

	void startFunctionSignature(const std::string& type) {

		printf("startFunctionSignature\n");
		pm_module->startFunctionSignature(type);
	}

	void startFunctionSignatureParameters() {

		printf("startFunctionSignatureParameters\n");
		pm_module->startFunctionSignatureParameters();
	}

	void functionParameter(const std::string& name, const std::vector<
			std::string>& type, bool has_init, const std::string& init) {

		printf("functionParameter\n");
		pm_module->functionParameter(name, type, has_init, init);
	}

	void endFunctionSignatureParameters() {

	   printf("endFunctionSignatureParameters\n");
	   pm_module->endFunctionSignatureParameters();
	}

	void endFunctionSignature() {

		printf("endFunctionSignature\n");
		pm_module->endFunctionSignature();
	}

	void endFunctionCommon() {

		printf("endFunctionCommon\n");
		pm_module->endFunctionCommon();
	}

	void endFunctionDefinition() {

		printf("endFunctionDefinition\n");
		pm_module->endFunctionDefinition();
	}

	void startReturnStatement() {

		printf("startReturnStatement\n");
		pm_module->startReturnStatement();
	}

	void endReturnStatement() {

		printf("endReturnStatement\n");
		pm_module->endReturnStatement();
	}

	//  void startExprCondition() {
	//
	//    printf("startExprCondition\n");
	//    pm_module->startExprCondition();
	//  }
	//
	//  void endExprCondition() {
	//
	//    printf("endExprCondition\n");
	//    pm_module->endExprCondition();
	//  }

	void startIfStatement() {

		printf("startIfStatement\n");
		pm_module->startIfStatement();
	}

	void endIfStatement() {

		printf("endIfStatement\n");
		pm_module->endIfStatement();
	}

	void startStmtExpression() {

		printf("startStmtExpression\n");
		pm_module->startStmtExpression();
	}

	void endStmtExpression() {
		printf("endStmtExpression\n");
		pm_module->endStmtExpression();
	}
	void functionParameterRest(const std::string& name) {
		pm_module->functionParameterRest(name);
	}
	void startSuperInit() {
		printf("startSuperInit\n");
		pm_module->startSuperInit();
	}
	void endSuperInit() {
		printf("endSuperInit\n");
		pm_module->endSuperInit();
	}
	void startExpressionList() {
		printf("startExpressionList\n");
		pm_module->startExpressionList();
	}

	void startCallExpression(const generated::CallExpression& call) {

		printf("startCallExpression\n");
		pm_module->startCallExpression(call);
	}

	void startArgumentList() {

		printf("startArgumentList\n");
		pm_module->startArgumentList();
	}

	void startOneArgument() {

		printf("startOneArgument\n");
		pm_module->startOneArgument();
	}

	void endOneArgument() {

		printf("endOneArgument\n");
		pm_module->endOneArgument();
	}

	void endArgumentList() {
		printf("endArgumentList\n");
		pm_module->endArgumentList();
	}

	void endCallExpression() {
		printf("endCallExpression\n");
		pm_module->endCallExpression();
	}
	void startInvokeExpression(const generated::CallExpression& call) {
		printf("startInvokeExpression\n");
		pm_module->startInvokeExpression(call);
	}
	void endInvokeExpression() {
		printf("endInvokeExpression\n");
		pm_module->endInvokeExpression();
	}
	void startBinaryExpression(const generated::BinaryExpression& op) {

		printf("startBinaryExpression\n");
		pm_module->startBinaryExpression(op);
	}

	void endBinaryExpression() {

		printf("endBinaryExpression\n");
		pm_module->endBinaryExpression();
	}

	void startInstanceOfExpression() {

		printf("startInstanceOfExpression\n");
		pm_module->startInstanceOfExpression();
	}

	void endInstanceOfExpression() {

		printf("endInstanceOfExpression\n");
		pm_module->endInstanceOfExpression();
	}

	void startIsOperator() {

		printf("startIsOperator\n");
		pm_module->startIsOperator();
	}

	void endIsOperator() {

		printf("endIsOperator\n");
		pm_module->endIsOperator();
	}

	void startAsOperator( const std::string& t) {

		printf("startAsOperator\n");
		pm_module->startAsOperator( t );
	}

	void endAsOperator() {

		printf("endAsOperator\n");
		pm_module->endAsOperator();
	}
	void startUnaryExpression(const generated::UnaryExpression& op) {

		printf("startUnaryExpression\n");
		pm_module->startUnaryExpression(op);
	}

	void endUnaryExpression() {

		printf("endUnaryExpression\n");
		pm_module->endUnaryExpression();
	}

	void startVariableDeclare(const generated::VariableDeclare& var_decl) {

		printf("startVariableDeclare\n");
		pm_module->startVariableDeclare(var_decl);
	}

	void endVariableDeclare() {

		printf("endVariableDeclare\n");
		pm_module->endVariableDeclare();
	}

	void startGetExpression(const std::string& s) {
		printf("startGetExpression\n");
		pm_module->startGetExpression(s);
	}
	void endGetExpression() {
		printf("-----------> endGetExpression\n");
		pm_module->endGetExpression();
	}
	void startSetExpression(const std::string& s) {
		printf("startSetExpression\n");
		pm_module->startSetExpression(s);
	}
	void endSetExpression() {
		printf("endSetExpression\n");
		pm_module->endSetExpression();
	}

	void startTypeExpression() {
		printf("startTypeExpression\n");
		pm_module->startTypeExpression();
	}
	void endTypeExpression() {
		printf("endTypeExpression\n");
		pm_module->endTypeExpression();
	}
	virtual void thisExpression() {
		pm_module->thisExpression();
	}
	virtual void superExpression() {
		pm_module->superExpression();
	}
	void identifierExpression(const generated::Identifier& id) {

		printf("identifierExpression\n");
		pm_module->identifierExpression(id);
	}
	void attributeIdentifierExpression(const generated::Identifier& id) {

		printf("aatributeIdentifierExpression\n");
		pm_module->attributeIdentifierExpression(id);
	}

	void literalXMLExpression( const std::string & str) {
		printf("literalXMLExpression\n");
		pm_module->literalXMLExpression(str);
	}
	void literalStringExpression( const std::string & str) {
		printf("literalStringExpression\n");
		pm_module->literalStringExpression(str);
	}
	void literalArrayBegin()
	{
		pm_module->literalArrayBegin();
	}
	void literalArrayEnd()
	{
		pm_module->literalArrayEnd();
	}
	void literalNumberExpression( const std::string & str) {

		printf("literalNumberExpression\n");
		pm_module->literalNumberExpression(str);
	}

	void literalBooleanExpression( const std::string & str) {
		printf("literalBooleanExpression\n");
		pm_module->literalBooleanExpression(str);
	}

	void literalNull() {
		printf("literalNull\n");
		pm_module->literalNull();
	}

	void endExpressionList() {
		printf("endExpressionList\n");
		pm_module->endExpressionList();
	}

	void addImport(const std::vector<std::string> & packages) {
		printf("addImport\n");
		pm_module->addImport(packages);
	}

	void startStmtList() {
		printf("startStmtList\n");
		pm_module->startStmtList();
	}

	void endStmtList() {

		printf("endStmtList\n");
		pm_module->endStmtList();
	}

	void startScope() {

		printf("startScope\n");
		pm_module->startScope();
	}

	void endScope() {

		printf("endScope\n");
		pm_module->endScope();
	}

	void startClassDefinition(const generated::ClassDefinition& class_define) {

		printf("startClassDefinition\n");
		pm_module->startClassDefinition(class_define);
	}

	void startClassStmt() {

		printf("startClassStmt\n");
		pm_module->startClassStmt();
	}

	void endClassStmt() {

		printf("endClassStmt\n");
		pm_module->endClassStmt();
	}

	void endClassDefinition() {

		printf("endClassDefinition\n");
		pm_module->endClassDefinition();
	}

	//  void startAttributeList() {
	//
	//    printf("startAttributeList\n");
	//    pm_module->startAttributeList();
	//  }
	//
	//  void endAttributelist() {
	//
	//    printf("endAttributelist\n");
	//    pm_module->endAttributelist();
	//  }

	void startMemberExpression() {

		printf("startMemberExpression\n");
		pm_module->startMemberExpression();
	}

	void endMemberExpression() {

		printf("endMemberExpression\n");
		pm_module->endMemberExpression();
	}

	void startForStatement() {

		printf("startForStatement\n");
		pm_module->startForStatement();
	}

	void startForInit() {

		printf("startForInit\n");
		pm_module->startForInit();
	}

	void endForInit() {

		printf("endForInit\n");
		pm_module->endForInit();
	}

	void startForStep() {

		printf("startForStep\n");
		pm_module->startForStep();
	}

	void endForStep() {

		printf("endForStep\n");
		pm_module->endForStep();
	}

	void endForStatement() {

		printf("endForStatement\n");
		pm_module->endForStatement();
	}
	void executeImport(const std::vector<std::string> & IDs) {
		pm_module->executeImport(IDs);
	}

	void startDoStatement() {

		printf("startDoStatement\n");
		pm_module->startDoStatement();
	}

	void endDoStatement() {

		printf("endDoStatement\n");
		pm_module->endDoStatement();
	}

	void startWhileStatement() {

		printf("startWhileStatement\n");
		pm_module->startWhileStatement();
	}

	void endWhileStatement() {

		printf("endWhileStatement\n");
		pm_module->endWhileStatement();
	}

	void startConditionExpression() {
		pm_module->startConditionExpression();
	}

	void endConditionExpression() {
		pm_module->endConditionExpression();
	}
	void empty() {
		printf("empty\n");
		pm_module->empty();
	}

	void defineMetaData(const generated::MetaData& metadata) {

		printf("defineMetaData\n");
		pm_module->defineMetaData(metadata);
	}
	void startIncrementExpression(const generated::IncrementType::type type,
			const std::string& token) {
		pm_module-> startIncrementExpression(type, token);
	}

	void endIncrementExpression() {
		pm_module-> endIncrementExpression();
	}

	void startTryStatement() {
		pm_module->startTryStatement();
	}

	void endTryStatement() {
		pm_module->endTryStatement();

	}

	void startFilter() {
		pm_module->startFilter();
	}

	void endFilter() {
		pm_module->endFilter();

	}
	void beginDeleteExpression( const std::string& mode ) {
		pm_module->beginDeleteExpression( mode );
	}

	void endDeleteExpression() {
		pm_module->endDeleteExpression();
	}

	void startThrowStatement() {
		pm_module->startThrowStatement();
	}

	void endThrowStatement() {

		pm_module->endThrowStatement();
	}

	void startCatchClauseStatement() {
		pm_module->startCatchClauseStatement();
	}

	void endCatchClauseStatement() {

		pm_module->endCatchClauseStatement();
	}

	void startFinallyClauseStatement() {
		pm_module->startFinallyClauseStatement();
	}

	void endFinallyClauseStatement() {
		pm_module->endFinallyClauseStatement();
	}
	void startSwitchStatement() {
		pm_module->startSwitchStatement();
	}
	void endSwitchStatement() {
		pm_module->endSwitchStatement();
	}
	void startCaseLabel() {
		pm_module->startCaseLabel();
	}
	void endCaseLabel() {
		pm_module->endCaseLabel();
	}
	void defaultCaseLabel() {
		pm_module->defaultCaseLabel();
	}
	void breakStatement() {
		pm_module->breakStatement();
	}
	void continueStatement() {
		pm_module->continueStatement();
	}
	void startStoreRegister() {
		pm_module->startStoreRegister();
	}

	void endStoreRegister() {
		pm_module->endStoreRegister();
	}
	void startLoadRegister() {
		pm_module->startLoadRegister();
	}
	void endLoadRegister() {
		pm_module->endLoadRegister();
	}

	void registerNode(const int32_t reg) {
		pm_module->registerNode( reg );
	}

	void startHasNext() {
		pm_module->startHasNext();
	}

	void endHasNext() {
		pm_module->endHasNext();
	}
    void startCoerce() {
		pm_module->startCoerce();
    }

    void endCoerce() {
		pm_module->endCoerce();
    }
};

} } } } //tw::maple::service::linker

#undef printf

#endif
