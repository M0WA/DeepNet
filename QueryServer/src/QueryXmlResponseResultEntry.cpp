/**
 *
 * @file QueryXmlResponseResultEntry.cpp
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#include "QueryXmlResponseResultEntry.h"

#include <algorithm>
#include <map>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <HttpUrlParser.h>
#include <ContainerTools.h>
#include <Logging.h>
#include <StringTools.h>
#include <PerformanceCounter.h>

#include "Query.h"
#include "QueryThreadResultEntry.h"

namespace queryserver {

QueryXmlResponseResultEntry::QueryXmlResponseResultEntry(const QueryThreadResultEntry* result)
: queryserver::Relevance(result->relevance) {
	threadResults.push_back(result);
}

QueryXmlResponseResultEntry::~QueryXmlResponseResultEntry() {
}

bool QueryXmlResponseResultEntry::operator< (const QueryXmlResponseResultEntry& rhs) const {

	return dynamic_cast<const Relevance&>(*this) < dynamic_cast<const Relevance&>(rhs);
}

void QueryXmlResponseResultEntry::AddResult(const QueryXmlResponseResultEntry& result) {

	threadResults.insert(threadResults.end(),result.threadResults.begin(),result.threadResults.end());

	(*this) += dynamic_cast<const Relevance&>(result);
}

void QueryXmlResponseResultEntry::AddResult(const QueryThreadResultEntry* result) {

	threadResults.push_back(result);

	(*this) += dynamic_cast<const Relevance&>(result->relevance);
}

void QueryXmlResponseResultEntry::Insert(database::DatabaseConnection* db,const long long& queryId,const size_t& position) const {

        PERFORMANCE_LOG_START

	database::searchqueryresultTableBase insertSearchResult;
	insertSearchResult.Set_SEARCHQUERY_ID(queryId);
	insertSearchResult.Set_URL_ID(GetUrlID());
	insertSearchResult.Set_position(position);

	long long resultID(-1);
	try {
		insertSearchResult.Insert(db);
		db->LastInsertID(resultID);
	}
	CATCH_EXCEPTION(database::DatabaseException,e,1)
		return; }

	if(resultID == -1) {
		log::Logging::LogWarn("could not insert result for query: %d",queryId);
		return;	}

	std::map<QueryThreadResultType,size_t> typeCounts;
	std::vector<const QueryThreadResultEntry*>::const_iterator iRes(threadResults.begin());
	for(;iRes != threadResults.end(); ++iRes) {
		const QueryThreadResultEntry* res((*iRes));
		typeCounts[res->type]++;
	}

	std::map<QueryThreadResultType,size_t>::const_iterator iTypes(typeCounts.begin());
	for(;iTypes != typeCounts.end(); ++iTypes) {
		database::searchqueryresultinfoTableBase info;
		info.Set_SEARCHQUERYRESULT_ID(resultID);
		info.Set_infotype(RESULTINFO_TYPECOUNT);

		std::ostringstream ss;
		ss << static_cast<long long>(iTypes->first) << ":" << static_cast<long long>(iTypes->second);
		info.Set_type(ss.str());

		try {
			info.Insert(db);
		}
		CATCH_EXCEPTION(database::DatabaseException,e,1)
			return; }
	}

	for(int i(RESULTINFO_INVALID+1);i < RESULTINFO_MAX; i++) {
		database::searchqueryresultinfoTableBase info;
		std::ostringstream ss;
		switch(i)
		{
		case RESULTINFO_TYPECOUNT:
			continue;
		case RESULTINFO_RELEVANCY:
			ss << GetRelevance();
			break;
		case RESULTINFO_WRELEVANCY:
			ss << GetWeightedRelevance();
			break;
		case RESULTINFO_WEIGHT:
			ss << GetWeight();
			break;
		default:
			log::Logging::LogWarn("not a valid result info type %d for result for query: %d",i,queryId);
			continue;
		}
		info.Set_type(ss.str());
		info.Set_SEARCHQUERYRESULT_ID(resultID);
		info.Set_infotype(i);
		try {
			info.Insert(db);
		}
		CATCH_EXCEPTION(database::DatabaseException,e,1)
			continue; }
	}

        PERFORMANCE_LOG_STOP("QueryXmlResponseResultEntry::Insert()")
}

bool QueryXmlResponseResultEntry::ParseTypeCount(const std::string& parse, std::string& type, size_t& count) {
	std::vector<std::string> words;
	tools::StringTools::SplitBy(parse,":",words);
	if(words.size() != 2) {
		return false;
	}
	int tc = -1;
	tools::StringTools::TransformString(words.at(0), tc);
	type = QueryThreadResultEntry::ResultTypeToString(static_cast<queryserver::QueryThreadResultType>(tc));
	tools::StringTools::TransformString(words.at(1), tc);
	count = tc;
	return true;
}

long long QueryXmlResponseResultEntry::GetUrlID() const {

	return threadResults.at(0)->urlID;
}

}
