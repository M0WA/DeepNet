/**
 *
 * @file QueryXmlResponse.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryXmlResponse.h"

#include <algorithm>
#include <sstream>

#include "Query.h"
#include "QueryProperties.h"
#include "QueryXmlRequest.h"
#include "QueryThreadResultEntry.h"
#include "QueryThreadManager.h"
#include "Relevance.h"

#include <FastCGIRequest.h>
#include <FastCGIServerThread.h>

#include <DatabaseLayer.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>
#include <DatabaseException.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <CacheDatabaseUrl.h>
#include <DatabaseUrl.h>
#include <HttpUrlParser.h>
#include <Dictionary.h>

#include <ContainerTools.h>
#include <Logging.h>
#include <TimeTools.h>

namespace queryserver {

QueryXmlResponse::QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest)
: fastcgiserver::FastCGIResponse(dynamic_cast<fastcgiserver::FastCGIRequest*>(xmlQueryRequest))
, queryManager(queryManager)
, xmlQueryRequest(xmlQueryRequest){
}

QueryXmlResponse::~QueryXmlResponse() {
}

void QueryXmlResponse::MergeDuplicateSecondLevel(std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	std::map<long long,size_t> secondLvlIDPos;

	size_t org_size(responseEntries.size());
	log::Logging::LogTrace("merging duplicate secondleveldomain, got %d results",org_size);

	std::vector<QueryXmlResponseResultEntry>::iterator i(responseEntries.begin());
	for(size_t pos(0);i!=responseEntries.end();++i) {
		tools::Pointer<htmlparser::DatabaseUrl> ptrUrl;
		caching::CacheDatabaseUrl::GetByUrlID(db,i->GetUrlID(),ptrUrl);
		long long secondLevelID(ptrUrl.GetConst()->GetSecondLevelID());

		if(secondLvlIDPos.count(secondLevelID) > 0) {
			responseEntries.at(secondLvlIDPos[secondLevelID]).AddResult(*i);
			responseEntries.erase(i);
			--i;
		}
		else {
			secondLvlIDPos[secondLevelID]=pos;
			++pos;
		}
	}
	log::Logging::LogTrace("merged duplicate secondleveldomain, got %d => %d results",org_size,responseEntries.size());
}

void QueryXmlResponse::MergeDuplicateURLs(const std::vector<const QueryThreadResultEntry*>& threadResults, std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	log::Logging::LogTrace("merging duplicate urls, got %zd results",threadResults.size());

	std::map<long long,size_t> urlIDPos;
	std::vector<const QueryThreadResultEntry*>::const_iterator iRes(threadResults.begin());
	for(;iRes != threadResults.end(); ++iRes) {
		long long urlID((*iRes)->urlID);
		if(urlIDPos.count(urlID) > 0) {
			size_t pos(urlIDPos.at(urlID));
			responseEntries.at(pos).AddResult((*iRes));
		}
		else {
			size_t pos(responseEntries.size());
			responseEntries.push_back(QueryXmlResponseResultEntry(*iRes));
			urlIDPos[urlID] = pos;
		}
	}

	log::Logging::LogTrace("merged duplicate urls, got %d => %d results",threadResults.size(),responseEntries.size());
}

void QueryXmlResponse::SortResults(std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	log::Logging::LogTrace("sorting %d results",responseEntries.size());

	//sort response entries by relevance (descending, therefore we use reverse iterator)
	std::sort(responseEntries.rbegin(), responseEntries.rend());

	log::Logging::LogTrace("sorted %d results",responseEntries.size());
}

bool QueryXmlResponse::CreateQuery(
		long long& queryId,
		const std::string& sessionID,
		const std::string& rawQueryString) {

	const Query& query(xmlQueryRequest->GetQuery());

	queryManager.BeginQuery(query);

	//waiting for all results to arrive
	std::vector<const QueryThreadResultEntry*> results;
	queryManager.WaitForResults(results);

	//container for final results
	std::vector<QueryXmlResponseResultEntry> responseEntries;

	//group results by url id
	MergeDuplicateURLs(results,responseEntries);

	//group results by secondlevel domain if requested
	if(query.properties.groupBySecondLevelDomain) {
		MergeDuplicateSecondLevel(responseEntries);}

	//sort results
	SortResults(responseEntries);

	//save results to database
	InsertResults(queryId,sessionID,rawQueryString,responseEntries);

	//releasing the query invalidates
	//all pointers to it's results
	results.clear();
	queryManager.ReleaseQuery();

	return true;
}

bool QueryXmlResponse::Process(FCGX_Request& request) {

	const Query& query(xmlQueryRequest->GetQuery());

	const std::string& sessionID(fcgiRequest->GetCookieValueByName("SIRIDIAID"));
	if(sessionID.empty()) {
		log::Logging::LogWarn("empty session id (SIRIDIAID) received, cannot process query request");
		return false; }

	const std::string& rawQueryString(xmlQueryRequest->GetRawQueryString());
	if(rawQueryString.empty()) {
		log::Logging::LogWarn("empty query string received, cannot process query request");
		return false; }

	long long relevantQueryID(query.properties.queryId);
	if(!ValidateQueryData(sessionID,rawQueryString))
		relevantQueryID = -1;

	//if query does not exist in database, create it
	if(relevantQueryID <= 0) {
		if(!CreateQuery(relevantQueryID,sessionID,rawQueryString))
			return false;
	}

	if(!LoadQuery(relevantQueryID,sessionID,rawQueryString))
		return false;

	return FastCGIResponse::Process(request);
}

bool QueryXmlResponse::ValidateQueryData(
		const std::string& sessionID,
		const std::string& rawQueryString) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	if(query.properties.queryId > 0) {

		// check if query is associated with session
		std::vector<database::WhereConditionTableColumn*> where;

		database::searchqueryTableBase::GetWhereColumnsFor_session(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
			sessionID,
			where );

		database::searchqueryTableBase::GetWhereColumnsFor_query(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
			rawQueryString,
			where );

		database::searchqueryTableBase::GetWhereColumnsFor_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
			query.properties.queryId,
			where);

		tools::Pointer<database::TableDefinition> ptrSearchQuery(database::searchqueryTableBase::CreateTableDefinition());
		database::SelectStatement selectSearchQuery(ptrSearchQuery);
		selectSearchQuery.SelectAllColumns();
		selectSearchQuery.Where().AddColumns(where);

		database::SelectResultContainer<database::searchqueryTableBase> resultSearchQuery;
		try {
			db->Select(selectSearchQuery,resultSearchQuery);
		}
		CATCH_EXCEPTION(database::DatabaseException,e,1)
			return false; }

		if(resultSearchQuery.Size() > 1) {
			log::Logging::LogWarn("too many results for search query, cannot process request");
			return false; }

		if(resultSearchQuery.Size() == 1) {
			return true; }
		else {
			log::Logging::LogInfo("client specified invalid query id for it's session, creating new query");
			return false; }
	}

	return false;
}

bool QueryXmlResponse::ResultToXML(const database::searchqueryresultTableBase* curTbl,std::string& entryXML) {

	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());
	std::ostringstream xml;
	long long urlID(-1);
	curTbl->Get_URL_ID(urlID);

	tools::Pointer<htmlparser::DatabaseUrl> dbUrl;
	caching::CacheDatabaseUrl::GetByUrlID(db,urlID,dbUrl);
	std::string encodedURL(dbUrl.GetConst()->GetFullUrl());
	network::HttpUrlParser::EncodeUrl(encodedURL);

	xml << "<url id=\"" << urlID << "\">" << encodedURL << "</url>";

	std::vector<database::WhereConditionTableColumn*> whereUrlStage;

	database::urlstagesTableBase::GetWhereColumnsFor_URL_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		urlID,
		whereUrlStage );

	tools::Pointer<database::TableDefinition> ptrUrlStageDef(database::urlstagesTableBase::CreateTableDefinition());
	database::SelectStatement selectUrlStage(ptrUrlStageDef);

	database::TableColumnDefinition
		*colDefUrlStageID(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		*colDefFoundDate(database::urlstagesTableBase::GetDefinition_found_date()),
		*colDefLastChange(database::urlstagesTableBase::GetDefinition_last_change());

	selectUrlStage.SelectAllColumns();
	selectUrlStage.SelectAddColumnAlias(colDefUrlStageID,colDefUrlStageID->GetColumnName());
	selectUrlStage.SelectAddColumnAlias(colDefFoundDate,colDefFoundDate->GetColumnName());
	selectUrlStage.SelectAddColumnAlias(colDefLastChange,colDefLastChange->GetColumnName());

	selectUrlStage.Where().AddColumns(whereUrlStage);
	selectUrlStage.SetLimit(1);

	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(selectUrlStage);

	database::SelectResultContainer<database::TableBase> urlstageresults;
	try {
		db->Select(selectUrlStage,urlstageresults); }
	CATCH_EXCEPTION(database::DatabaseException,e,1)
		return false; }

	if(urlstageresults.Size() != 1) {
		return false;
	}

	long long urlstageID(-1);
	for(urlstageresults.ResetIter();!urlstageresults.IsIterEnd();urlstageresults.Next()) {
		const database::TableBase* urlstage(urlstageresults.GetConstIter());

		const database::TableColumn
			*colUrlStageID(urlstage->GetConstColumnByName(colDefUrlStageID->GetColumnName())),
			*colFoundDate(urlstage->GetConstColumnByName(colDefFoundDate->GetColumnName())),
			*colLastChange(urlstage->GetConstColumnByName(colDefLastChange->GetColumnName()));

		colUrlStageID->Get(urlstageID);

		struct tm found;
		colFoundDate->Get(found);
		xml << "<lastVisited>" << (tools::TimeTools::IsZero(found) ? "" : tools::TimeTools::DumpTm(found)) << "</lastVisited>";

		struct tm changed;
		colLastChange->Get(changed);
		xml << "<lastChanged>" << (tools::TimeTools::IsZero(changed) ? "" : tools::TimeTools::DumpTm(changed)) << "</lastChanged>";
	}

	//lookup meta information for this url
	std::vector<database::WhereConditionTableColumn*> whereMeta;
	database::metainfoTableBase::GetWhereColumnsFor_URLSTAGE_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		urlstageID,
		whereMeta);

	std::vector<long long> metaTypes;
	metaTypes.push_back(indexing::Dictionary::META_TITLE);
	metaTypes.push_back(indexing::Dictionary::META_DESCRIPTION);
	database::metainfoTableBase::GetWhereColumnsFor_type(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
		metaTypes,
		whereMeta);

	tools::Pointer<database::TableDefinition> ptrMetaDef(database::metainfoTableBase::CreateTableDefinition());
	database::SelectStatement selectMeta(ptrMetaDef.GetConst());
	selectMeta.SelectAllColumns();
	selectMeta.Where().AddColumns(whereMeta);

	std::string	encodedTitle, encodedDescription;
	database::SelectResultContainer<database::metainfoTableBase> metaresults;
	db->Select(selectMeta,metaresults);
	for(metaresults.ResetIter();!metaresults.IsIterEnd();metaresults.Next()) {
		long long metaType(-1);
		metaresults.GetConstIter()->Get_type(metaType);

		switch(metaType) {
		case indexing::Dictionary::META_TITLE:
			metaresults.GetConstIter()->Get_value(encodedTitle);
			network::HttpUrlParser::EncodeUrl(encodedTitle);
			xml << "<title>" << encodedTitle << "</title>";
			break;

		case indexing::Dictionary::META_DESCRIPTION:
			metaresults.GetConstIter()->Get_value(encodedDescription);
			network::HttpUrlParser::EncodeUrl(encodedDescription);
			xml << "<description>" << encodedDescription << "</description>";
			break;

		default:
			break;
		}
	}

	/*
"<type>" << ResultTypeToString(type) << "</type>";
	*/

	entryXML = xml.str();
	return true;

}

void QueryXmlResponse::AssembleXMLResult(
		const database::SelectResultContainer<database::searchqueryresultTableBase>& queryResults,
		const size_t& total,
		const long long& queryId) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	std::vector<std::string> keywordsStrings;
	query.GetKeywords(keywordsStrings);
	tools::ContainerTools::MakeUniqueVector(keywordsStrings,true);

	std::ostringstream keywordsPart;
	std::vector<std::string>::iterator iKey(keywordsStrings.begin());
	for(;iKey!=keywordsStrings.end();++iKey) {
		network::HttpUrlParser::EncodeUrl(*iKey);
		keywordsPart << "<keyword>" << *iKey << "</keyword>"; }

	//assemble xml entries from results
	std::ostringstream xmlResultEntries;
	for(queryResults.ResetIter();!queryResults.IsIterEnd();queryResults.Next()) {

		const database::searchqueryresultTableBase* curTbl(queryResults.GetConstIter());

		std::string entryXML;
		if(!ResultToXML(curTbl,entryXML)){
			continue;
		}

		long long searchqueryresultID(-1);
		curTbl->Get_ID(searchqueryresultID);

		std::ostringstream xml;
		xml <<
		"<result id=\"" << searchqueryresultID << "\">"
		"<keywords>" << keywordsPart.str() << "</keywords>";
		xml << entryXML;

		// deal with search result entry infos
		database::SelectResultContainer<database::searchqueryresultinfoTableBase> infoResults;
		try {
			database::searchqueryresultinfoTableBase::GetBy_SEARCHQUERYRESULT_ID(db,searchqueryresultID,infoResults); }
		CATCH_EXCEPTION(database::DatabaseException,e,1)
			continue; }

		for(infoResults.ResetIter();!infoResults.IsIterEnd();infoResults.Next()) {
			const database::searchqueryresultinfoTableBase* curInfo(infoResults.GetConstIter());

			long long infoType(-1);
			curInfo->Get_infotype(infoType);

			std::string info;
			curInfo->Get_type(info);

			switch(infoType)
			{
			case QueryXmlResponseResultEntry::RESULTINFO_TYPECOUNT:
			{
				std::string typeCount = "n/a";
				size_t count = 0;
				QueryXmlResponseResultEntry::ParseTypeCount(info, typeCount, count);
				xml << "<type count=\""<< count << "\">" << typeCount << "</type>";
			}
				break;
			case QueryXmlResponseResultEntry::RESULTINFO_RELEVANCY:
				xml << "<relevancy>" << info << "</relevancy>";
				break;
			case QueryXmlResponseResultEntry::RESULTINFO_WRELEVANCY:
				xml << "<relevancyWeighted>" << info << "</relevancyWeighted>";
				break;
			case QueryXmlResponseResultEntry::RESULTINFO_WEIGHT:
				xml << "<weight>" << info << "</weight>";
				break;
			default:
				break;
			}
		}
		xml << "</result>";
		xmlResultEntries << xml.str();
	}

	//assemble complete xml response including header etc.
	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"<response>"
		"<queryId>" << queryId << "</queryId>"
		"<pageNo>" << query.properties.pageNo << "</pageNo>"
		"<totalResults>" << total << "</totalResults>" <<
		xmlResultEntries.str() <<
		"</response>\n";

	//set xml string as response's content
	content = xmlResult.str();
}

bool QueryXmlResponse::LoadQuery(
		const long long& queryId,
		const std::string& sessionID,
		const std::string& rawQueryString) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	database::SelectResultContainer<database::searchqueryTableBase> results;
	try {
		database::searchqueryTableBase::GetBy_ID(db,queryId,results); }
	CATCH_EXCEPTION(database::DatabaseException,e,1)
		return false; }

	results.ResetIter();
	std::string sessionIDTmp, rawQueryStringTmp;
	long long sizeTotal(0);
	results.GetConstIter()->Get_session(sessionIDTmp);
	results.GetConstIter()->Get_query(rawQueryStringTmp);
	results.GetConstIter()->Get_total(sizeTotal);

	if( sessionIDTmp.compare(sessionID) != 0 ||
		rawQueryStringTmp.compare(rawQueryString) != 0 )
	{
		log::Logging::LogWarn("invalid session id or query string received for this query id, cannot process request");
		return false; }

	long long startPosition(query.properties.pageNo * query.properties.maxResults);
	long long endPosition(startPosition + query.properties.maxResults);

	std::vector<database::WhereConditionTableColumn*> where;

	database::searchqueryresultTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		queryId,
		where );

	database::searchqueryresultTableBase::GetWhereColumnsFor_position(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::GreaterOrEqual(),database::WhereCondition::And()),
		startPosition,
		where );

	database::searchqueryresultTableBase::GetWhereColumnsFor_position(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Smaller(),database::WhereCondition::And()),
		endPosition,
		where );

	tools::Pointer<database::TableDefinition> ptrSearchQueryResultDef(database::searchqueryresultTableBase::CreateTableDefinition());
	database::SelectStatement selectQueryResults(ptrSearchQueryResultDef);
	selectQueryResults.SelectAllColumns();
	selectQueryResults.Where().AddColumns(where);

	selectQueryResults.OrderBy().AddColumn(database::searchqueryresultTableBase::GetDefinition_position(),database::ASCENDING);
	selectQueryResults.SetLimit(query.properties.maxResults);

	database::SelectResultContainer<database::searchqueryresultTableBase> queryResults;
	try {
		db->Select(selectQueryResults,queryResults); }
	CATCH_EXCEPTION(database::DatabaseException,e,1)
		return false; }

	AssembleXMLResult(queryResults,sizeTotal,queryId);
	return true;
}

void QueryXmlResponse::InsertResults(
	long long& queryId,
	const std::string& sessionID,
	const std::string& rawQueryString,
	const std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	log::Logging::LogTrace("inserting %d results",responseEntries.size());

	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	//insert search query itself at first
	database::searchqueryTableBase insertSearchQuery;
	insertSearchQuery.Set_session(sessionID);
	insertSearchQuery.Set_query(rawQueryString);
	insertSearchQuery.Set_age(tools::TimeTools::NowUTC());
	insertSearchQuery.Set_total(responseEntries.size());

	try {
		insertSearchQuery.Insert(db);
		db->LastInsertID(queryId);
	}
	CATCH_EXCEPTION(database::DatabaseException,e,1)
		return; }

	if(queryId == -1) {
		log::Logging::LogWarn("could not insert results for query: " + rawQueryString);
		return;	}

	//insert all results
	std::vector<QueryXmlResponseResultEntry>::const_iterator i(responseEntries.begin());
	for(size_t resultPosition(0);i!=responseEntries.end();++i,++resultPosition) {
		i->Insert(db,queryId,resultPosition);
	}

	log::Logging::LogTrace("inserted %d results",responseEntries.size());
}

}
