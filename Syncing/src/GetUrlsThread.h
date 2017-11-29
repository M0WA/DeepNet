/*
 * @file GetUrlsThread.h
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <vector>

#include <Thread.h>

namespace database {
	class DatabaseConnection;
}

namespace syncing {

class GetUrlsThread : public threading::Thread {
public:
	typedef struct _GetUrlsThreadParam : threading::Thread::THREAD_PARAM {
		virtual ~_GetUrlsThreadParam() {}
		database::DatabaseConnection* dbConn;
		long long crawlerID;
		long long secondlevelDomain;
		long long urlCount;
		long long minAge;
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
	bool GetUrls(GetUrlsThreadParam* p);
	bool UnlockSecondLevelDomain(long long& sld);
	bool GetNextUrls(GetUrlsThreadParam* p, long long& sld);
	bool LockSecondLevelDomain(GetUrlsThreadParam* p, long long& sld);

private:
	std::vector<long long> urlIDs;
};

}
