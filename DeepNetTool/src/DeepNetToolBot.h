/*
 * DeepNetToolBot.h
 *
 *  Created on: 20.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Bot.h>

namespace toolbot {

/**
 * @brief main class for DeepNetTool application
 */
class DeepNetToolBot : public bot::Bot{
public:
	DeepNetToolBot();
	virtual ~DeepNetToolBot();

protected:
	virtual bool OnPreInit();
	virtual bool OnInit();
	virtual bool OnRun();
	virtual bool OnShutdown();

private:
	void RegisterRobotTxtParams();
	void RegisterDatabaseRepairParams();
	void RegisterUrlInserterParams();
	void RegisterHtmlTestParams();
	void RegisterCommerceSearchParams();
	void RegisterDataminingParams();
	void RegisterPCRERegexTestParams();
	void RegisterExceptionTestParams();
	void RegisterHtmlClientCURLParams();
	void RegisterHtmlDocumentFactoryParams();
	void RegisterIndexerExParams();
	void RegisterDatabaseUnitTestParams();
	void RegisterSyncingTestParams();

private:
	bool ProcessUnitTests();
};

}
