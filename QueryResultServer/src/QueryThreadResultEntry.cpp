/**
 *
 * @file QueryThreadResultEntry.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryThreadResultEntry.h"

#include <StringTools.h>
#include <TimeTools.h>
#include <Pointer.h>

#include <DatabaseLayer.h>
#include <TableDefinition.h>

#include <CacheDatabaseUrl.h>
#include <DatabaseUrl.h>
#include <HttpUrlParser.h>
#include <Dictionary.h>

#include "Query.h"

namespace queryserver {

QueryThreadResultEntry::QueryThreadResultEntry(
	const QueryThreadResultType& type,
	const long long& urlID,
	const long long& urlStageID,
	const size_t&    keywordPos,
	const long long& occurrences,
	const double&    relevance)
: relevance(queryserver::Relevance(relevance))
, type(type)
, urlID(urlID)
, urlStageID(urlStageID)
, keywordPos(keywordPos)
, occurrences(occurrences){
	tools::TimeTools::InitTm(found);
}

QueryThreadResultEntry::QueryThreadResultEntry(
	const QueryThreadResultType& type,
	const long long& urlID,
	const long long& urlStageID,
	const size_t&    keywordPos,
	const long long& occurrences,
	const double&    relevance,
	const struct tm& found)
: relevance(queryserver::Relevance(relevance))
, type(type)
, urlID(urlID)
, urlStageID(urlStageID)
, keywordPos(keywordPos)
, occurrences(occurrences)
, found(found){
}

QueryThreadResultEntry::~QueryThreadResultEntry() {
}

void QueryThreadResultEntry::AppendToXML(database::DatabaseConnection* db,const querylib::Query& query,const size_t resultID,std::ostringstream& xml) const {

	tools::Pointer<htmlparser::DatabaseUrl> dbUrl;
	caching::CacheDatabaseUrl::GetByUrlID(db,urlID,dbUrl);

	std::vector<database::WhereConditionTableColumn*> where;
	database::metainfoTableBase::GetWhereColumnsFor_URLSTAGE_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		urlStageID,
		where);

	std::vector<long long> metaTypes;
	metaTypes.push_back(indexing::Dictionary::META_TITLE);
	metaTypes.push_back(indexing::Dictionary::META_DESCRIPTION);
	database::metainfoTableBase::GetWhereColumnsFor_type(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
		metaTypes,
		where);

	tools::Pointer<database::TableDefinition> ptrMetaDef(database::metainfoTableBase::CreateTableDefinition());
	database::SelectStatement selectMeta(ptrMetaDef.GetConst());
	selectMeta.SelectAllColumns();
	selectMeta.Where().AddColumns(where);

	std::string	encodedTitle, encodedDescription;
	database::SelectResultContainer<database::metainfoTableBase> results;
	db->Select(selectMeta,results);
	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		long long metaType(-1);
		results.GetConstIter()->Get_type(metaType);

		switch(metaType) {
		case indexing::Dictionary::META_TITLE:
			results.GetConstIter()->Get_value(encodedTitle);
			network::HttpUrlParser::EncodeUrl(encodedTitle);
			break;

		case indexing::Dictionary::META_DESCRIPTION:
			results.GetConstIter()->Get_value(encodedDescription);
			network::HttpUrlParser::EncodeUrl(encodedDescription);
			break;

		default:
			break;
		}
	}

	std::string	lastVisitedString(tools::TimeTools::DumpTm(found));

	std::string encodedURL(dbUrl.GetConst()->GetFullUrl());
	network::HttpUrlParser::EncodeUrl(encodedURL);

	xml <<
	"<url id=\"" << urlID << "\">" << encodedURL << "</url>"
	"<title>" << encodedTitle << "</title>"
	"<description>" << encodedDescription << "</description>"
	"<lastVisited>" << lastVisitedString << "</lastVisited>"
	"<lastChanged></lastChanged>"
	"<type>" << ResultTypeToString(type) << "</type>";
}

std::string QueryThreadResultEntry::ResultTypeToString(const QueryThreadResultType& type) {

	switch(type)
	{
	case CONTENT_RESULT:
		return "CONTENT_RESULT";
	case META_RESULT:
		return "META_RESULT";
	case SUBDOMAIN_RESULT:
		return "SUBDOMAIN_RESULT";
	case SECONDLEVELDOMAIN_RESULT:
		return "SECONDLEVELDOMAIN_RESULT";
	case URLPATH_RESULT:
		return "URLPATH_RESULT";
	default:
		return "UNKNOWN";
	}
}

}
