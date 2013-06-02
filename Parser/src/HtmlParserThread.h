/*
 * HtmlParserThread.h
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <map>
#include <vector>

#include <Thread.h>
#include <DatabaseLayer.h>
#include <Pointer.h>
#include <IHtmlParser.h>

#include "HtmlParserParam.h"
#include "HtmlParserEntry.h"


namespace htmlparser {
	class DatabaseUrl;
}

namespace parser {

class HtmlParserThread : public threading::Thread {
public:
	HtmlParserThread();
	virtual ~HtmlParserThread();

protected:
	database::DatabaseHelper& DB() {return databaseHelper;}

private:
	static void* HtmlParserThreadFunction(THREAD_PARAM* threadParam);

private:
	virtual bool ParsePage(const HtmlParserEntry& entry,tools::Pointer<htmlparser::IHtmlParserResult>& result)=0;
	virtual void InitParserThread() {}

private:
	bool ParsePages(const std::vector<HtmlParserEntry>& entries);
	bool GetNextPages(std::vector<HtmlParserEntry>& entries);
	void OnIdle();

private:
	database::DatabaseHelper databaseHelper;
	HtmlParserParam* parserParam;
};

}
