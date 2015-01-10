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

QueryKeywordGroup::QueryKeywordGroup()
: isMandatory(false)
, isCaseInsensitive(false)
, isSimilar(false) {
}

QueryKeywordGroup::~QueryKeywordGroup() {
}

bool QueryKeywordGroup::Init(database::DatabaseConnection *db) {

	QueryKeyword::QueryKeywordType types(QueryKeyword::EXACT_MATCH);
	if(isCaseInsensitive) {
		reinterpret_cast<unsigned long&>(types) |= QueryKeyword::CASEINSENSITIVE_MATCH; }
	if(isSimilar) {
		reinterpret_cast<unsigned long&>(types) |= QueryKeyword::SIMILAR_MATCH; }

	bool success(true);
	std::vector<queryserver::QueryKeyword>::iterator i(groups.begin());
	for(; i != groups.end(); ++i) {
		success &= i->Init(db,types); }

	return success;
}

bool QueryKeywordGroup::ParseFromString(const std::string& querygroup, const bool isMandatory, const bool isCaseInsensitive, const bool isSimilar) {

	std::vector<std::string> words;
	tools::StringTools::SplitBy(querygroup," ",words);

	if(!words.size()) {
		return false; }

	this->isMandatory = isMandatory;
	this->isCaseInsensitive = isCaseInsensitive;
	this->isSimilar = isSimilar;

	std::vector<std::string>::const_iterator i(words.begin());
	for(;i != words.end(); ++i) {
		groups.push_back( queryserver::QueryKeyword(*i) ); }
	return true;
}

}
