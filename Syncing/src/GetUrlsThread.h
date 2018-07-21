/*
 * @file GetUrlsThread.h
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <vector>

#include <Thread.h>

namespace database {
	class DatabaseConfig;
	class DatabaseConnection;
}

namespace toolbot {
	class UnitTestSyncing;
}

namespace syncing {

/**
 * @brief thread to aquire new url ids that are ready to be crawled
 */
class GetUrlsThread : public threading::Thread {

friend class toolbot::UnitTestSyncing;

public:
	typedef struct _GetUrlsThreadParam : threading::Thread::THREAD_PARAM {
		virtual ~_GetUrlsThreadParam() {}
		database::DatabaseConfig* dbConf;
		long long crawlerID;
		long long secondlevelDomain;
		long long urlCount;
	} GetUrlsThreadParam;

public:
	GetUrlsThread();
	virtual ~GetUrlsThread();

public:
	/**
	 * get url ids
	 * @return url ids
	 */
	const std::vector<long long>& GetUrlIDs() const { return urlIDs; }

private:
	static void* GetUrlsThreadFunc(threading::Thread::THREAD_PARAM* param);

private:
	virtual const char* GetThreadName() const { return "GetUrlsThread"; }

private:
	bool GetUrls(database::DatabaseConnection* db,GetUrlsThreadParam* p);
	bool GetNextUrls(database::DatabaseConnection* db,GetUrlsThreadParam* p, long long& sld);

private:
	std::vector<long long> urlIDs;
};

}
