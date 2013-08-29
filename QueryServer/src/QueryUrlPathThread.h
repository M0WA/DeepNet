/**
 *
 * @file QueryUrlPathThread.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include "QueryThread.h"

#include <vector>
#include <map>

namespace queryserver {

/**
 * @brief queries for search results matching in the path part of an URL
 */
class QueryUrlPathThread: public queryserver::QueryThread {
public:
	QueryUrlPathThread();
	virtual ~QueryUrlPathThread();

private:
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QueryUrlPathThread"; }

private:
	bool GetPathPartIDs(std::vector<long long>& pathPartIDs,std::map<long long,size_t>& pathPartIDKeywordPos) const;
	bool ProcessResults(const std::vector<long long>& pathPartIDs,const std::map<long long,size_t>& pathPartIDKeywordPos);
};

}

