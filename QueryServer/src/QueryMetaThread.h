/**
 *
 * @file QueryMetaThread.h
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#pragma once

#include "QueryDictionaryThread.h"

namespace queryserver {

/**
 * @brief queries for search results matching in the meta content of a webpage
 */
class QueryMetaThread : public queryserver::QueryDictionaryThread {
public:
	QueryMetaThread();
	virtual ~QueryMetaThread();

private:
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QueryMetaThread"; }
};

}
