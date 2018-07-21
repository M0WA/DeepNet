/*
 * KeywordMatch.cpp
 *
 *  Created on: Jun 10, 2017
 *      Author: Moritz Wagner
 */

#include "KeywordMatch.h"

namespace queryserver {

KeywordMatch::KeywordMatch(const QueryKeyword* keyword)
: keyword(keyword) {
}

KeywordMatch::~KeywordMatch() {
}

void KeywordMatch::GetAllDictIDs(std::vector<long long>& dictIDs) const {

	KeywordMatchEntry::const_iterator i(entry.begin());
	for(; i != entry.end(); ++i) {
		dictIDs.insert(dictIDs.end(),i->second.begin(),i->second.end());
	}
}

}
