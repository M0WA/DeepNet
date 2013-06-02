/*
 * HtmlParserThread.cpp
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#include "HtmlParserThread.h"

#include <sstream>
#include <Logging.h>
#include <PerformanceCounter.h>

#include <HtmlParserFactory.h>
#include <IHtmlParser.h>

#include <CacheParsed.h>
#include <CacheHtml.h>
#include <CacheHtmlEntry.h>

#include <TableDefinition.h>
#include <TableColumnDefinition.h>

#include <Exception.h>

using namespace threading;

namespace parser {

HtmlParserThread::HtmlParserThread()
: Thread((Thread::ThreadFunction)&(HtmlParserThread::HtmlParserThreadFunction)) {
}

HtmlParserThread::~HtmlParserThread() {
}

void* HtmlParserThread::HtmlParserThreadFunction(THREAD_PARAM* threadParam)
{
	log::Logging::RegisterThreadID("HtmlParserThread");

	HtmlParserThread* instance = dynamic_cast<HtmlParserThread*>(threadParam->instance);
	instance->parserParam      = (HtmlParserParam*)(threadParam->pParam);

	PERFORMANCE_LOG_START;
	bool connectedDB = instance->DB().CreateConnection(instance->parserParam->databaseConfig) != NULL ? true : false;
	PERFORMANCE_LOG_STOP("connect to databases");

	if(connectedDB) {

		instance->InitParserThread();

		std::vector<HtmlParserEntry> entries;
		while(!instance->ShallEnd()) {

			PERFORMANCE_LOG_RESTART;
			bool bSuccess = true;

			bSuccess &= instance->GetNextPages(entries);
			bSuccess &= instance->ParsePages(entries);
			entries.clear();

			PERFORMANCE_LOG_STOP("parser run");
		}

		PERFORMANCE_LOG_RESTART;
		instance->DB().DestroyConnection();
		PERFORMANCE_LOG_STOP("disconnect to databases");
	}

	return 0;
}

bool HtmlParserThread::GetNextPages(std::vector<HtmlParserEntry>& entries)
{
	PERFORMANCE_LOG_START;
	entries.clear();

	std::map<long long,caching::CacheHtmlEntry> cacheEntries;
	caching::CacheHtml::Get(cacheEntries,parserParam->maxPerSelect);

	std::map<long long, caching::CacheHtmlEntry>::iterator iterEntries = cacheEntries.begin();
	for(; iterEntries != cacheEntries.end(); ++iterEntries) {
		entries.push_back(
			parser::HtmlParserEntry(
				iterEntries->second.ID,
				iterEntries->second.url,
				iterEntries->second.html,
				iterEntries->second.urlStageID)
		);
	}
	PERFORMANCE_LOG_STOP("getting pages from cache");

	if( !entries.size() ) {
		OnIdle(); }

	return entries.size();
}

bool HtmlParserThread::ParsePages(const std::vector<HtmlParserEntry>& entries) {

	PERFORMANCE_LOG_START;

	std::vector<HtmlParserEntry>::const_iterator iterEntries = entries.begin();
	for(; iterEntries != entries.end(); ++iterEntries) {

		//parsing
		PERFORMANCE_LOG_RESTART;

		tools::Pointer<htmlparser::IHtmlParser> parser;
		htmlparser::HtmlParserFactory::CreateInstance(htmlparser::HtmlParserFactory::LIBXML,parser);

		tools::Pointer<htmlparser::IHtmlParserResult> result;
		if(!parser.Get()->Parse(iterEntries->html,result)) {
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "error while parsing from url: %s", iterEntries->url.GetFullUrl().c_str());
		}

		ParsePage(*iterEntries,result);

		//TODO: page ranking => bot to calculate ???

		PERFORMANCE_LOG_STOP("parsing single page");

	}

	return true;
}

void HtmlParserThread::OnIdle() {

	for(int i = 0; i < parserParam->waitOnIdle && !ShallEnd(); i++){
		sleep(1);}
}

}
