/**
 *
 * @file QueryKeyword.cpp
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#include "QueryKeyword.h"

#include <DatabaseLayer.h>

namespace queryserver {

QueryKeyword::_QueryKeyWordEntry::_QueryKeyWordEntry()
: keyword("")
, id(-1) {
}

QueryKeyword::QueryKeyword()
: keyword("") {
}

QueryKeyword::QueryKeyword(const std::string& keyword)
: keyword(keyword){
}

QueryKeyword::~QueryKeyword() {
}

bool QueryKeyword::InitSimilar(database::DatabaseConnection *db) {
	return false;
}

bool QueryKeyword::InitCaseInsensitive(database::DatabaseConnection *db) {
	return false;
}

bool QueryKeyword::InitExact(database::DatabaseConnection *db) {
	return false;
}

bool QueryKeyword::Init(database::DatabaseConnection *db, QueryKeyword::QueryKeywordType initTypes) {

	switch(initTypes)
	{
	case SIMILAR_MATCH:
		InitSimilar(db);
	case CASEINSENSITIVE_MATCH:
		InitCaseInsensitive(db);
	case EXACT_MATCH:
		InitExact(db);
		break;

	default:
		break;
	}

	return false;
}

}
