/**
 * @file QueryProcessManagerCleanupThread.h
 * @author Moritz Wagner
 * @date Apr 8, 2015
 */

#pragma once

#include "Thread.h"

namespace queryserver {

class QueryProcessManager;

/**
 * @brief cleans up finished queries for an instance of a QueryProcessManager
 */
class QueryProcessManagerCleanupThread : public threading::Thread {
public:
	QueryProcessManagerCleanupThread(QueryProcessManager& qpm);
	virtual ~QueryProcessManagerCleanupThread();

private:
	static void* QueryProcessManagerCleanupFunc(threading::Thread::THREAD_PARAM* param);

private:
	QueryProcessManager& qpm;
};

}
