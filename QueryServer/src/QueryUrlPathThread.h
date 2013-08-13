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

/**
 * @brief queries for search results matching in the path part of an URL
 */
class QueryUrlPathThread: public queryserver::QueryThread {
public:
	QueryUrlPathThread();
	virtual ~QueryUrlPathThread();

private:
	virtual void OnInitThreadInstance();
	virtual void OnDestroyThreadInstance();
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QueryUrlPathThread"; }
};

}

