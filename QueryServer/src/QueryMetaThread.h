/**
 *
 * @file QueryMetaThread.h
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#pragma once

#include "QueryThread.h"

namespace queryserver {

class QueryMetaThread : public queryserver::QueryThread {
public:
	QueryMetaThread();
	virtual ~QueryMetaThread();

private:
	virtual bool OnInitThreadInstance();
	virtual bool OnDestroyThreadInstance();
	virtual void* Run();
	virtual const char* GetThreadName() const { return "QueryMetaThread"; }
};

}
