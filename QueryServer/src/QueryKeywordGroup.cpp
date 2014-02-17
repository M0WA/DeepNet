/**
 *
 * @file QueryKeywordGroup.cpp
 * @author Moritz Wagner
 * @date 02.02.2014
 *
 */

#include "QueryKeywordGroup.h"
#include "QueryKeyword.h"

#include <StringTools.h>

namespace queryserver {

QueryKeywordGroup::QueryKeywordGroup() {
}

QueryKeywordGroup::~QueryKeywordGroup() {
}

bool QueryKeywordGroup::GetKeywordVariations(std::vector<std::string>& wordsVec, std::vector<std::string>& caseInsensitive, std::vector<std::string>& similar) const {

	/*
	std::vector<std::string>::const_iterator i(words.begin());
	for(;i != words.end(); ++i) {

		wordsVec.push_back(i->GetKeyword());

		if(!IsCaseSensitive()) {
			caseInsensitive.push_back(i->GetLoweredKeyword());}

		//
		//TODO: fill similiar vector
		//
	}
	*/
	return false;
}

bool QueryKeywordGroup::ParseFromString(const std::string& querygroup, const bool isMandatory) {

	std::vector<std::string> words;
	tools::StringTools::SplitBy(querygroup," ",words);
	this->isMandatory = isMandatory;
	if(!words.size()) {
		return false; }

	std::vector<std::string>::const_iterator i(words.begin());
	for(;i != words.end(); ++i) {
		//
		//TODO: is this correct: caseSensitive == isMandatory ??
		//
		bool caseSensitive(isMandatory);
		groups.push_back( queryserver::QueryKeyword(*i) );
	}
	return true;
}

}
