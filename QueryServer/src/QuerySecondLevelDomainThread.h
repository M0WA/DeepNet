/**
 *
 * @file QuerySecondLevelDomainThread.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include "QueryThread.h"

namespace queryserver {

class QuerySecondLevelDomainThread: public queryserver::QueryThread {
public:
	QuerySecondLevelDomainThread();
	virtual ~QuerySecondLevelDomainThread();

private:
	virtual void OnInitThreadInstance();
	virtual void OnDestroyThreadInstance();
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QuerySecondLevelDomainThread"; }
};

}

