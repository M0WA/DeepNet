/**
 *
 * @file QueryKeyword.h
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#pragma once

#include <string>
#include <vector>
#include <map>

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

/**
 * @brief encapsulates a single keyword in a QueryKeywordGroup
 */
class QueryKeyword {
public:
	typedef enum {

		/**
		 * invalid match type
		 */
		INVALID_MATCH_TYPE = 0,

		/**
		 * matches exactly
		 */
		EXACT_MATCH 			= 0x01,

		/**
		 * matches case insensitive
		 */
		CASEINSENSITIVE_MATCH	= 0x02,

		/**
		 * is similar to keyword
		 */
		SIMILAR_MATCH	        = 0x04,
	} QueryKeywordType;

private:
	typedef struct _QueryKeyWordEntry {
		_QueryKeyWordEntry();
		std::string keyword;
		long long id;
	} QueryKeyWordEntry;

private:
	QueryKeyword();

public:
	/**
	 * constructs keywords from string and match type
	 * @param keyword keyword string
	 * @param type match type
	 */
	QueryKeyword(const std::string& keyword);
	virtual ~QueryKeyword();

public:
	/**
	 * initialize keyword
	 * @param db database connection
	 * @param initTypes types to initialize
	 * @return true on success, false on error
	 */
	bool Init(database::DatabaseConnection *db, QueryKeyword::QueryKeywordType initTypes);

private:
	bool InitExact(database::DatabaseConnection *db);
	bool InitCaseInsensitive(database::DatabaseConnection *db);
	bool InitSimilar(database::DatabaseConnection *db);

private:
	std::string keyword;

private:
	std::map< QueryKeywordType, std::vector<QueryKeyWordEntry>  > map;
};

}

