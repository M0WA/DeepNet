/*
 * Indexer.h
 *
 *  Created on: 08.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Thread.h>

#include "IndexerThread.h"
#include "IndexerParam.h"

namespace database {
	class DatabaseConfig;
}

namespace indexing {

class Indexer : public threading::Thread {

protected:
	Indexer(const IndexerParam* param);
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
	const IndexerParam* indexerParam;
	std::map<IndexerThread*,IndexerThread::IndexerThreadParam*> indexerThreads;
};

}
