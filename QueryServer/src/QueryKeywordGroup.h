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
	 * @return true on success, false on error
	 */
	bool ParseFromString(const std::string& querygroup, const bool isMandatory, const bool isCaseSensitive, const bool isSimilar);

public:
	/**
	 * gets keywords of this group
	 * @return keywords of this group
	 */
	const std::vector<queryserver::QueryKeyword>& GetKeywords() const { return groups; }

	/**
	 * check if group is mandatory
	 * @return true if mandatory, false if not mandatory
	 */
	const bool IsMandatory() const { return isMandatory; }

public:
	bool GetKeywordVariations(std::vector<std::string>& words, std::vector<std::string>& caseInsensitive, std::vector<std::string>& similar) const;
	bool Init(database::DatabaseConnection *db);

private:
	std::vector<queryserver::QueryKeyword> groups;
	bool isMandatory;
	bool isCaseSensitive;
	bool isSimilar;
};

}

