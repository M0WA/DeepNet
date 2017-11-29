/*
 * @file ReleaseCrawlerThread.h
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <Thread.h>

namespace syncserver {

class ReleaseCrawlerThread : public threading::Thread {
public:
	ReleaseCrawlerThread();
	virtual ~ReleaseCrawlerThread();

private:
	static void* ReleaseCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param);

private:
	virtual const char* GetThreadName() const { return "ReleaseCrawlerThread"; }
};

}
