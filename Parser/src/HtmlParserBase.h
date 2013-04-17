/*
 * HtmlParserBase.h
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HtmlParserThread.h"
#include "HtmlParserParam.h"

namespace parser {

class HtmlParserBase : public threading::Thread {
public:
	HtmlParserBase();
	virtual ~HtmlParserBase();

private:
	static void* HtmlParserThreadFunc(threading::Thread::THREAD_PARAM* threadParam);

private:
	virtual bool StartParser()=0;

private:
	bool StopParser();
	bool WatchDog();

protected:
	HtmlParserParam* parserParam;
	std::map<HtmlParserThread*, HtmlParserParam*> htmlParserThreads;
};

}
