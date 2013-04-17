/*
 * CommerceSearchMatchCriteria.h
 *
 *  Created on: 08.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include <DatabaseLayer.h>
#include <NotImplementedException.h>

#include "CommerceSearchMatchGroup.h"

namespace parser {

enum CommerceSearchMatchCriteriaType {
	UNKNOWN_CRITERIA_TYPE = 0,

	URL_CRITERIA_TYPE     = 1,
	META_CRITERIA_TYPE    = 2,
	CONTENT_CRITERIA_TYPE = 3,
	TITLE_CRITERIA_TYPE   = 4,
};

class CommerceSearchMatchCriteria : public database::customermatchcriteriaTableBase {

private:
	CommerceSearchMatchCriteria(const database::TableBase& base);

public:
	CommerceSearchMatchCriteria();
	virtual ~CommerceSearchMatchCriteria();

public:
	const CommerceSearchMatchCriteriaType& GetCriteriaType() const { return matchType; }

public:
	static void GetAll(database::DatabaseConnection* db,database::SelectResultContainer<CommerceSearchMatchCriteria>& criterias);

public:
	void Init(database::DatabaseConnection* db);
	bool Match(database::DatabaseConnection* db,const std::string& target) const;

private:
	long long customerMatchCriteriaID;
	long long matchCriteriaID;

	CommerceSearchMatchCriteriaType matchType;

	std::string regex;
	std::map<size_t,CommerceSearchMatchGroup> posGroup;
};

}

