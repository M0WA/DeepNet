/**
 *
 * @file QueryUrlThread.h
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#pragma once

#include "QueryThread.h"

namespace queryserver {

class QueryUrlThread : public queryserver::QueryThread {
public:
	QueryUrlThread();
	virtual ~QueryUrlThread();

private:
	virtual bool OnInitThreadInstance();
	virtual bool OnDestroyThreadInstance();
	virtual void* Run();
	virtual const char* GetThreadName() const { return "QueryUrlThread"; }
};

}
