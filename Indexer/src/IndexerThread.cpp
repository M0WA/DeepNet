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

#include "Dictionary.h"
#include "ContentIndexer.h"
#include "MetaIndexer.h"

namespace indexing {

IndexerThread::IndexerThread()
: Thread((Thread::ThreadFunction)&(IndexerThread::IndexerThreadFunc))
, indexerMeta(0)
, indexerContent(0)
{
}

IndexerThread::~IndexerThread()
{
}

void* IndexerThread::IndexerThreadFunc(threading::Thread::THREAD_PARAM* threadParam)
{
	log::Logging::RegisterThreadID("IndexerThread");

	IndexerThread* instance = (IndexerThread*)(threadParam->instance);
	instance->indexerThreadParam = *((IndexerThread::IndexerThreadParam*)threadParam->pParam);

	PERFORMANCE_LOG_START;
	bool connectedDB = instance->DB().CreateConnection(instance->indexerThreadParam.databaseConfig) ? true : false;
	PERFORMANCE_LOG_STOP("connect to database");

	if(	connectedDB )
	{
		instance->indexerMeta    = instance->CreateIndexer();
		instance->indexerContent = instance->CreateIndexer();
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
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not start indexer. check database configuration."); }

	delete instance->indexerMeta;
	delete instance->indexerContent;

	return 0;
}

bool IndexerThread::GetNextPages(std::map<long long,caching::CacheParsed::CacheParsedEntry>& entries)
{
	PERFORMANCE_LOG_START;
	bool success = caching::CacheParsed::Get(entries,indexerThreadParam.maxPerSelect);
	PERFORMANCE_LOG_STOP("getting pages from cache for indexer");

	if(!entries.size()) {
		OnIdle();
		return true; }
	return success && entries.size();
}

bool IndexerThread::ParsePages(std::map<long long,caching::CacheParsed::CacheParsedEntry>& entries)
{
	std::map<long long,caching::CacheParsed::CacheParsedEntry>::iterator iterEntries = entries.begin();
	for( ; iterEntries != entries.end(); ++iterEntries ) {

		indexerContent->GetDictionary().SetUrlID(iterEntries->second.urlID, iterEntries->second.urlStageID);

		std::vector< std::string >::iterator iterContent = iterEntries->second.content.begin();
		for(size_t iParagraph = 0;iterContent != iterEntries->second.content.end();++iParagraph,++iterContent) {
			indexerContent->Parse(*iterContent,iParagraph); }
		indexerContent->GetDictionary().CommitContent();

		indexerMeta   ->GetDictionary().SetUrlID(iterEntries->second.urlID, iterEntries->second.urlStageID);
		std::vector< std::pair<std::string,std::string> >::iterator iterMeta = iterEntries->second.meta.begin();
		for(;iterMeta != iterEntries->second.meta.end();++iterMeta)
		{
			if (( iterMeta->first.compare("keywords") == 0 )||
				( iterMeta->first.compare("description") == 0 )
			   ){
				indexerMeta->Parse(iterMeta->second,-1);
			}
		}
		indexerMeta->GetDictionary().CommitMeta();
	}
	return true;
}

void IndexerThread::OnIdle()
{
	for(int i = 0; i < indexerThreadParam.waitOnIdle && !ShallEnd(); i++){
		sleep(1);}
}

}
