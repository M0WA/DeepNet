/*
 * @file GetUrlsThread.h
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <vector>

#include <Thread.h>

namespace syncserver {

class GetUrlsThread : public threading::Thread {
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
	std::vector<long long> urlIDs;
};

}
