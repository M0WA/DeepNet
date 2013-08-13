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

/**
 * @brief queries for search results matching in the meta content of a webpage
 */
class QueryMetaThread : public queryserver::QueryThread {
public:
	QueryMetaThread();
	virtual ~QueryMetaThread();

private:
	virtual void OnInitThreadInstance();
	virtual void OnDestroyThreadInstance();
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QueryMetaThread"; }
};

}
