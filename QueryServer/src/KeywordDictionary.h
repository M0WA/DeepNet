/*
 * KeywordDictionary.h
 *
 *  Created on: Jun 10, 2017
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>
#include <map>

#include "KeywordMatchType.h"
#include "KeywordMatch.h"

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

class Query;
class QueryKeyword;

/**
 * @brief contains information about a keyword from query string
 */
class KeywordDictionary {

public:
	typedef struct _DictIDInfo {
		KeywordMatchType type;
		long long position;
		long long groupID;
	} DictIDInfo;

public:
	KeywordDictionary();
	virtual ~KeywordDictionary();

public:
	/**
	 * initialize from query
	 * @param dbConn database connection
	 * @param query query to initialize from
	 * @return false on error
	 */
	bool Init(database::DatabaseConnection* dbConn,const Query& query);

	/**
	 * gets all dictionary ids
	 * @param dictIDs container for dictionary ids
	 */
	void GetAllIDs(std::vector<long long>& dictIDs) const;

	bool GetDictIDInfo(const long long& dictID, DictIDInfo& info) const;

private:
	bool InitByKeyword(database::DatabaseConnection* dbConn,const QueryKeyword& kw);

private:
	std::vector< KeywordMatch > keywords;
};

}
