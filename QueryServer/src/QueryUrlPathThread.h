/**
 *
 * @file QueryUrlPathThread.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include "QueryThread.h"

namespace queryserver {

class QueryUrlPathThread: public queryserver::QueryThread {
public:
	QueryUrlPathThread();
	virtual ~QueryUrlPathThread();

private:
	virtual bool OnInitThreadInstance();
	virtual bool OnDestroyThreadInstance();
	virtual void* Run();
	virtual const char* GetThreadName() const { return "QueryUrlPathThread"; }
};

}

