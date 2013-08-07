/*
 * IndexerThread.cpp
 *
 *  Created on: 08.03.2012
 *      Author: Moritz Wagner
 */

#include "IndexerThread.h"

#include <TLD.h>
#include <PerformanceCounter.h>
#include <DatabaseLayer.h>
#include <StringTools.h>

#include "Dictionary.h"
#include "IIndexer.h"

namespace indexing {

IndexerThread::IndexerThread()
: Thread((Thread::ThreadFunction)&(IndexerThread::IndexerThreadFunc))
{
}

IndexerThread::~IndexerThread()
{
}

void* IndexerThread::IndexerThreadFunc(threading::Thread::THREAD_PARAM* threadParam)
{
	log::Logging::RegisterThreadID("IndexerThread");

	IndexerThread* instance(dynamic_cast<IndexerThread*>(threadParam->instance));
	instance->indexerThreadParam = *((IndexerThread::IndexerThreadParam*)threadParam->pParam);

	PERFORMANCE_LOG_START;
	bool connectedDB(instance->DB().CreateConnection(instance->indexerThreadParam.databaseConfig) ? true : false);
	PERFORMANCE_LOG_STOP("connect to database");

	if(	connectedDB ){

		instance->OnCreateIndexer(instance->indexerMeta,instance->indexerContent);

		std::map<long long,caching::CacheParsed::CacheParsedEntry> entries;
		while( !instance->ShallEnd() ) {

			PERFORMANCE_LOG_RESTART;

			instance->GetNextPages(entries);
			instance->ParsePages(entries);
			entries.clear();

			PERFORMANCE_LOG_STOP("indexer run");
		}

		PERFORMANCE_LOG_RESTART;
		instance->DB().DestroyConnection();
		PERFORMANCE_LOG_STOP("disconnect to databases");
	}
	else {
		log::Logging::LogError("could not start indexer. check database configuration."); }

	return 0;
}

bool IndexerThread::GetNextPages(std::map<long long,caching::CacheParsed::CacheParsedEntry>& entries)
{
	PERFORMANCE_LOG_START;
	bool success(caching::CacheParsed::Get(entries,indexerThreadParam.maxPerSelect));
	PERFORMANCE_LOG_STOP("getting pages from cache for indexer");

	if(!entries.size()) {
		OnIdle();
		return true; }
	return success && entries.size();
}

bool IndexerThread::ParsePages(std::map<long long,caching::CacheParsed::CacheParsedEntry>& entries)
{
	std::map<long long,caching::CacheParsed::CacheParsedEntry>::const_iterator iterEntries(entries.begin());
	for( ; iterEntries != entries.end(); ++iterEntries ) {

		indexerContent.Get()->GetDictionary().SetUrlID(iterEntries->second.urlID, iterEntries->second.urlStageID);

		std::vector< std::string >::const_iterator iterContent(iterEntries->second.content.begin());
		for(size_t iParagraph = 0;iterContent != iterEntries->second.content.end();++iParagraph,++iterContent) {
			indexerContent.Get()->Parse(*iterContent,iParagraph); }
		indexerContent.Get()->GetDictionary().CommitContent();

		indexerMeta.Get()->GetDictionary().SetUrlID(iterEntries->second.urlID, iterEntries->second.urlStageID);
		std::vector< std::pair<std::string,std::string> >::const_iterator iterMeta(iterEntries->second.meta.begin());
		for(;iterMeta != iterEntries->second.meta.end();++iterMeta)	{
			std::string lowerName(tools::StringTools::ToLowerNP(iterMeta->first));

			Dictionary::MetaInformationType type = Dictionary::META_UNKNOWN;
			if(lowerName.compare("description") == 0) {
				type = Dictionary::META_DESCRIPTION;}
			else if(lowerName.compare("keywords") == 0) {
				type = Dictionary::META_KEYWORDS;}
			else if(lowerName.compare("title") == 0) {
				type = Dictionary::META_TITLE;}
			else if(lowerName.compare("author") == 0) {
				type = Dictionary::META_AUTHOR;	}
			else if(lowerName.compare("copyright") == 0) {
				type = Dictionary::META_COPYRIGHT; }
			else if (log::Logging::IsLogLevelTrace()) {
				log::Logging::LogTrace("unknown meta type: " + iterMeta->first);}

			indexerMeta.Get()->ParseMeta(iterMeta->second,type);
		}
		indexerMeta.Get()->GetDictionary().CommitMeta();
	}
	return true;
}

void IndexerThread::OnIdle()
{
	for(int i = 0; i < indexerThreadParam.waitOnIdle && !ShallEnd(); i++){
		sleep(1);}
}

}
