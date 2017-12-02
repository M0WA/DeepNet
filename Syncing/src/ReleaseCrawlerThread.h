/*
 * @file ReleaseCrawlerThread.h
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <Thread.h>

namespace database {
	class DatabaseConnection;
}

namespace toolbot {
	class UnitTestSyncingReleaseCrawler;
}

namespace syncing {

class ReleaseCrawlerThread : public threading::Thread {

friend class toolbot::UnitTestSyncingReleaseCrawler;

public:
	typedef struct _ReleaseCrawlerThreadParam : threading::Thread::THREAD_PARAM {
		virtual ~_ReleaseCrawlerThreadParam() {}
		database::DatabaseConnection* dbConn;
		long long crawlerID;
	} ReleaseCrawlerThreadParam;

public:
	ReleaseCrawlerThread(database::DatabaseConnection* dbConn);
	virtual ~ReleaseCrawlerThread();

private:
	static void* ReleaseCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param);

private:
	virtual const char* GetThreadName() const { return "ReleaseCrawlerThread"; }

private:
	database::DatabaseConnection* dbConn;
};

}
