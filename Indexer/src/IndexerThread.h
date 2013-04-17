/*
 * IndexerThread.h
 *
 *  Created on: 08.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <CacheParsed.h>
#include <Thread.h>
#include <DatabaseHelper.h>

namespace database {
	class DatabaseConfig;
}

namespace indexing {

class IndexerBase;
class ContentIndexer;
class IndexerThread : public threading::Thread
{
public:
	struct IndexerThreadParam
	{
		IndexerThreadParam()
		: maxPerSelect(-1)
		, waitOnIdle(-1)
		, databaseConfig(0)
		{ }

		IndexerThreadParam(
				const int maxPerSelect,
				const int waitOnIdle,
				database::DatabaseConfig* databaseConfig)
		: maxPerSelect(maxPerSelect)
		, waitOnIdle(waitOnIdle)
		, databaseConfig(databaseConfig)
		{ }

		int maxPerSelect;
		int waitOnIdle;
		database::DatabaseConfig* databaseConfig;
	};

protected:
	IndexerThread();
public:
	virtual ~IndexerThread();

private:
	virtual ContentIndexer* CreateContentIndexer()=0;

private:
	static void* IndexerThreadFunc(threading::Thread::THREAD_PARAM* threadParam);

private:
	bool GetNextPages(std::map<long long,caching::CacheParsed::CacheParsedEntry>& entries);
	bool ParsePages(std::map<long long,caching::CacheParsed::CacheParsedEntry>& entries);
	void OnIdle();

protected:
	database::DatabaseHelper& DB() { return databaseHelper; }

private:
	IndexerThreadParam indexerThreadParam;
	database::DatabaseHelper databaseHelper;
	ContentIndexer* indexerMeta;
	ContentIndexer* indexerContent;
};

}
