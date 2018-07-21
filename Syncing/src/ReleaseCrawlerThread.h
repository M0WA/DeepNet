/*
 * @file ReleaseCrawlerThread.h
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <Thread.h>

namespace database {
	class DatabaseConfig;
}

namespace toolbot {
	class UnitTestSyncing;
}

namespace syncing {

/**
 * @brief thread to release a crawler registration
 */
class ReleaseCrawlerThread : public threading::Thread {

friend class toolbot::UnitTestSyncing;

public:
	typedef struct _ReleaseCrawlerThreadParam : threading::Thread::THREAD_PARAM {
		virtual ~_ReleaseCrawlerThreadParam() {}
		database::DatabaseConfig* dbConf;
		long long crawlerID;
	} ReleaseCrawlerThreadParam;

public:
	ReleaseCrawlerThread();
	virtual ~ReleaseCrawlerThread();

private:
	static void* ReleaseCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param);

private:
	virtual const char* GetThreadName() const { return "ReleaseCrawlerThread"; }
};

}
