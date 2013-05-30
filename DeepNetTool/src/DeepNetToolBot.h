/*
 * DeepNetToolBot.h
 *
 *  Created on: 20.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DeepNetToolBot.h"
#include <Bot.h>
#include <Logging.h>
#include <DatabaseLayer.h>
#include <Bot.h>

namespace toolbot {

class DeepNetToolBot : public bot::Bot{
public:
	DeepNetToolBot();
	virtual ~DeepNetToolBot();

protected:
	virtual void RegisterDefaultParams(void);
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

private:
	bool ProcessUnitTests();
};

}
