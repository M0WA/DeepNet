/**
 *
 * @file QueryThread.h
 * @author Moritz Wagner
 * @date Aug 12, 2013
 *
 */

#pragma once

#include <Thread.h>

namespace queryserver {

class QueryThread: public threading::Thread {
public:
	QueryThread(threading::Thread::ThreadFunction func);
	virtual ~QueryThread();
};

}

