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

	/**
	 * initializes dictIDs for this keyword group
	 * @param db database connection
	 * @return true on success, false on error
	 */
	bool Init(database::DatabaseConnection *db);

public:
	/**
	 * gets keywords of this group
	 * @return keywords of this group
	 */
	const std::vector<queryserver::QueryKeyword>& GetKeywords() const { return groups; }

	/**
	 * checks if group is mandatory
	 * @return true if mandatory, false if optional
	 */
	const bool& IsMandatory(void) const { return isMandatory; }

	/**
	 * checks if group is case insensitive
	 * @return true if case insensitive, false if case sensitive
	 */
	const bool& IsCaseInsensitive(void) const { return isCaseInsensitive; }

	/**
	 * checks if group matches similar results
	 * @return true if it can match similar results, false if not
	 */
	const bool& IsSimilar(void) const { return isSimilar; }

private:
	std::vector<queryserver::QueryKeyword> groups;

	bool isMandatory;
	bool isCaseInsensitive;
	bool isSimilar;
};

}

