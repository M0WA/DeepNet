/*
 * @file RegisterCrawlerThread.h
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <Thread.h>

namespace database {
	class DatabaseConfig;
}

namespace toolbot {
	class UnitTestSyncingRegisterCrawler;
}

namespace syncing {

/**
 * @brief thread to register new crawlers
 */
class RegisterCrawlerThread: public threading::Thread {

friend class toolbot::UnitTestSyncingRegisterCrawler;

public:
	typedef struct _RegisterCrawlerThreadParam : threading::Thread::THREAD_PARAM {
		virtual ~_RegisterCrawlerThreadParam() {}
		database::DatabaseConfig* dbConf;
	} RegisterCrawlerThreadParam;

public:
	RegisterCrawlerThread();
	virtual ~RegisterCrawlerThread();

public:
	/**
	 * gets crawler id
	 * @return crawler id
	 */
	long long GetCrawlerID() const { return crawlerID; }

private:
	static void* RegisterCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param);

private:
	virtual const char* GetThreadName() const { return "RegisterCrawlerThread"; }

private:
	long long crawlerID;
};

}
