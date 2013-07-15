/*
 * DeepNetToolBot.h
 *
 *  Created on: 20.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Bot.h>

namespace toolbot {

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
	void RegisterHtmlClientCURLParams();
	void RegisterHtmlDocumentFactoryParams();
	void RegisterIndexerExParams();
	void RegisterDatabaseUnitTestParams();

private:
	bool ProcessUnitTests();
};

}
