/**
 *
 * @file QueryKeywordGroup.h
 * @author Moritz Wagner
 * @date 02.02.2014
 *
 */

#pragma once

#include <vector>
#include <string>

#include "QueryKeyword.h"

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

/**
 * @brief this class contains multiple queryserver::QueryKeywords
 */
class QueryKeywordGroup {
public:
	QueryKeywordGroup();
	virtual ~QueryKeywordGroup();

public:
	/**
	 * parse a single group from a string
	 * @param querygroup group to parse
	 * @param isMandatory is group mandatory
	 * @param isCaseSensitive is group case insensitive
	 * @param isSimilar group matches similar results
	 * @return true on success, false on error
	 */
	bool ParseFromString(const std::string& querygroup, const bool isMandatory, const bool isCaseSensitive, const bool isSimilar);

public:
	/**
	 * gets keywords of this group
	 * @return keywords of this group
	 */
	const std::vector<queryserver::QueryKeyword>& GetKeywords() const { return groups; }

public:
	/**
	 * initializes dictIDs for this keyword group
	 * @param db database connection
	 * @return true on success, false on error
	 */
	bool Init(database::DatabaseConnection *db);

private:
	std::vector<queryserver::QueryKeyword> groups;
	bool isMandatory;
	bool isCaseInsensitive;
	bool isSimilar;
};

}

