/*
 * DataminingCriteria.h
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <set>

#include <DatabaseLayer.h>


namespace indexing {

class Word;
class DataminingCriteria : public database::dataminingcriteriaTableBase {

private:
	DataminingCriteria(const database::TableBase& base);

public:
	DataminingCriteria();
	virtual ~DataminingCriteria();

	bool operator< (const DataminingCriteria& rhs) const {
		return keyword < rhs.keyword; }

public:
	bool Match(const std::set<Word>& words) const;

private:
	std::string keyword;
	long long   type;
};

}
