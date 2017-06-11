/**
 *
 * @file Query.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <vector>
#include <string>

#include "QueryProperties.h"
#include "QueryKeyword.h"

namespace queryserver {

/**
 * @brief encapsulates query keywords and their properties
 */
class Query {
public:
	Query();
	virtual ~Query();

public:
	/**
	 * appends a keyword at a given position
	 * @param position position of keyword to append
	 * @param keyword keyword to append
	 * @param caseSensitive true if keyword is case sensitive
	 * @param occuranceMandatory true if occurance of keyword is mandatory
	 * @param exactMatch true if keyword needs to be matched exactly
	 */
	void AppendKeyword(const long long& position,const std::string& keyword,const bool& caseSensitive,const bool& occuranceMandatory,const bool& exactMatch);

	/**
	 * gets query string
	 */
	const std::string& GetQueryString(void) const { return rawQueryString; }

	/**
	 * gets query keywords
	 */
	const std::vector<QueryKeyword>& GetQueryKeywords(void) const { return queryKeywords; }

	/**
	 * gets query keywords as strings
	 */
	void GetQueryKeywords(std::vector<std::string>& keywords) const;

	/**
	 * dump query into human readable string
	 * @param dump string to dump to
	 */
	void DumpQuery(std::string& dump) const;

public:
	/**
	 * query's properties
	 */
	QueryProperties properties;

private:
	/**
	 * query's keywords
	 */
	std::vector<QueryKeyword> queryKeywords;

	/**
	 * normalized query string
	 */
	std::string rawQueryString;


	long long nextGroupID;
};

}

