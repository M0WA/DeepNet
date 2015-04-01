/*
 * HtmlParserBase.h
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <map>
#include <Thread.h>

namespace parser {

class HtmlParserParam;
class HtmlParserThread;

class HtmlParserBase : public threading::Thread {
protected:
	HtmlParserBase(const HtmlParserParam* parserParam);
public:
	virtual ~HtmlParserBase();

private:
	static void* HtmlParserThreadFunc(threading::Thread::THREAD_PARAM* threadParam);

private:
	virtual bool StartParser()=0;

private:
	bool StopParser();
	bool WatchDog();

protected:
	const HtmlParserParam* parserParam;
	std::map<HtmlParserThread*, HtmlParserParam*> htmlParserThreads;
};

}
