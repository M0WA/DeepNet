/*
 * Indexer.h
 *
 *  Created on: 08.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Thread.h>
#include "IndexerThread.h"

namespace database {
	class DatabaseConfig;
}

namespace indexing {

class Indexer : public threading::Thread {
public:
	struct IndexerParam
	{
		IndexerParam()
		{
			threadCount = 0;
			waitOnIdle = 0;
			maxPerSelect = 0;
		}

		IndexerParam(
			const int maxPerSelect,
			const int waitOnIdle,
			const int threadCount,
			database::DatabaseConfig* databaseConfig)
		{
			this->maxPerSelect = maxPerSelect;
			this->waitOnIdle = waitOnIdle;
			this->threadCount = threadCount;
			this->databaseConfig = databaseConfig;
		}

		int threadCount;
		int waitOnIdle;
		int maxPerSelect;
		database::DatabaseConfig* databaseConfig;
	};

protected:
	Indexer();
public:
	virtual ~Indexer();

private:
	bool StartIndexer();
	bool StopIndexer();
	bool WatchDog();

private:
	virtual IndexerThread* CreateIndexerThread()=0;

private:
	static void* IndexerThreadFunc(threading::Thread::THREAD_PARAM* threadParam);

private:
	Indexer::IndexerParam indexerParam;
	std::map<IndexerThread*,IndexerThread::IndexerThreadParam*> indexerThreads;
};

}
