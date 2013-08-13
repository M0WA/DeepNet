/**
 *
 * @file QuerySubdomainThread.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include "QueryThread.h"

namespace queryserver {

class QuerySubdomainThread: public queryserver::QueryThread {
public:
	QuerySubdomainThread();
	virtual ~QuerySubdomainThread();

private:
	virtual void OnInitThreadInstance();
	virtual void OnDestroyThreadInstance();
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QuerySubdomainThread"; }
};

}

