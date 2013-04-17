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

#include <DocumentFactory.h>
#include <Document.h>

/*
#include <HtmlParser.h>
#include <HtmlParserException.h>
#include <HtmlDocument.h>
*/

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

		htmlparser::Document* pDoc = htmlparser::DocumentFactory::FromHtmlData(iterEntries->url,iterEntries->html);

		/*
		htmlparser::HtmlParser* pParser = 0;
		htmlparser::HtmlDocument* pDoc = 0;
		try {
			pParser = new htmlparser::HtmlParser(iterEntries->url,iterEntries->html);
			pDoc = pParser->Parse(DB().Connection());
		}
		catch(htmlparser::HtmlParserException& ex) {
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "invalid format from url: %s", iterEntries->url.GetFullUrl().c_str());
		}
		catch(...) {
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "error while parsing from url: %s", iterEntries->url.GetFullUrl().c_str());

			delete pParser;
			delete pDoc;
			continue;
		}

		if(!pDoc) {
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "invalid html from url: %s", iterEntries->url.GetFullUrl().c_str());
			delete pParser;
			continue;
		}
		*/

		UpdateUrlstageInfos(pDoc, iterEntries->url);

		if(!ParsePage(*iterEntries,pDoc)) {
			log::Logging::Log(log::Logging::LOGLEVEL_WARN, "could not parse html from url: %s", iterEntries->url.GetFullUrl().c_str());	}
		PERFORMANCE_LOG_STOP("parsing single page");

		delete pDoc;

		//TODO: page ranking => bot to calculate ???
	}
	return true;
}

void HtmlParserThread::UpdateUrlstageInfos(htmlparser::Document* pDoc, const htmlparser::DatabaseUrl& baseURL) {

	std::vector<htmlparser::DatabaseUrl> hyperLinks;

	//
	// TODO:
	//
	//pDoc->GetLinks(hyperLinks);

	long long internLinks = 0, externLinks = 0, secondLevelID = baseURL.GetSecondLevelID();

	std::vector<htmlparser::DatabaseUrl>::const_iterator iterLinks = hyperLinks.begin();
	for(;iterLinks != hyperLinks.end();++iterLinks) {

		if(iterLinks->GetSecondLevelID() == secondLevelID) {
			internLinks++;}
		else {
			externLinks++;}
	}

	//TODO: update parameter `html_errors` here also

	database::urlstagesTableBase tblUrl;
	tblUrl.Set_int_links(internLinks);
	tblUrl.Set_ext_links(externLinks);
	tblUrl.Update(DB().Connection(),database::TableBaseUpdateParam());
}

void HtmlParserThread::OnIdle() {

	for(int i = 0; i < parserParam->waitOnIdle && !ShallEnd(); i++){
		sleep(1);}
}

}
