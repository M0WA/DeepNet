/*
 * Indexer.cpp
 *
 *  Created on: 08.03.2012
 *      Author: Moritz Wagner
 */

#include "Indexer.h"

namespace indexing {

Indexer::Indexer()
: Thread((Thread::ThreadFunction)&(Indexer::IndexerThreadFunc))
{
}

Indexer::~Indexer() {
}

void* Indexer::IndexerThreadFunc(threading::Thread::THREAD_PARAM* threadParam)
{
	Indexer* instance = (Indexer*)threadParam->instance;
	instance->indexerParam = *((Indexer::IndexerParam*)threadParam->pParam);

	if(!instance->StartIndexer())
		return (void*)1;

	bool errorOccured = false;
	while(!instance->ShallEnd())
	{
		if(instance->WatchDog()) {
			errorOccured = true;
			break; }

		sleep(1);
	}

	bool bReturn = !instance->StopIndexer() || errorOccured;
	return (void*)bReturn;
}

bool Indexer::StartIndexer()
{
	for(int i = 0; i < indexerParam.threadCount; i++)
	{
		IndexerThread::IndexerThreadParam* threadParam = new IndexerThread::IndexerThreadParam(
				indexerParam.maxPerSelect,
				indexerParam.waitOnIdle,
				indexerParam.databaseConfig);

		indexing::IndexerThread* indexerThread = CreateIndexerThread();
		indexerThread->StartThread(threadParam);

		indexerThreads[indexerThread] = threadParam;
	}
	return true;
}

bool Indexer::StopIndexer()
{
	std::map< indexing::IndexerThread*, indexing::IndexerThread::IndexerThreadParam* >::iterator iterThreads = indexerThreads.begin();
	for(; iterThreads != indexerThreads.end(); iterThreads++)
	{
		iterThreads->first->SetShallEnd(true);
	}

	iterThreads = indexerThreads.begin();
	for(; iterThreads != indexerThreads.end(); ++iterThreads)
	{
		iterThreads->first->WaitForThread();
		delete iterThreads->first;
		delete iterThreads->second;
	}
	indexerThreads.clear();
	return true;
}

bool Indexer::WatchDog()
{
	std::map< indexing::IndexerThread*, indexing::IndexerThread::IndexerThreadParam* >::iterator iterThreads = indexerThreads.begin();

	//check if at least one thread is alive
	for(; iterThreads != indexerThreads.end(); ++iterThreads){
		if ( iterThreads->first->IsRunning() )
			return false;
	}
	return true;
}

}
