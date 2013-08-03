/*
 * XMLQueryResponse.cpp
 *
 *  Created on: 16.03.2012
 *      Author: Moritz Wagner
 */

#include "XMLQueryResponse.h"

#include <Logging.h>
#include <HttpCookie.h>
#include <HttpUrlParser.h>
#include <CacheDatabaseUrl.h>
#include <StringTools.h>
#include <ContainerTools.h>

#include <DatabaseHelper.h>
#include <DatabaseLayer.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>
#include <TableColumnDefinitionCreateParam.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>

#include "XMLQueryRequest.h"
#include "Relevance.h"
#include "KeywordEntry.h"
#include "UrlStageEntry.h"
#include "BackLinkEntry.h"
#include "PageInfo.h"

namespace queryserver {

XMLQueryResponse::XMLQueryResponse(database::DatabaseHelper& dbHelper,XMLQueryRequest* xmlQueryRequest)
: fastcgiserver::FastCGIResponse(xmlQueryRequest)
, xmlQueryRequest(xmlQueryRequest)
, dbHelper(dbHelper)
, countResults(-1)
{
}

XMLQueryResponse::~XMLQueryResponse()
{
}

bool XMLQueryResponse::Process(FCGX_Request& request)
{
	//fetch keywords from request
	const std::list<std::string>& allKeyWords = xmlQueryRequest->QueryParts();
	std::vector<std::string> vecKeywords;
	tools::ContainerTools::ListToVector(allKeyWords,vecKeywords);

	bool isExisting(false);
	if(!LogQuery(vecKeywords,isExisting))
		return false;

	if(!isExisting)
		ProcessNewQuery(vecKeywords);

	ProcessExistQuery();
	return fastcgiserver::FastCGIResponse::Process(request);
}

bool XMLQueryResponse::ProcessExistQuery()
{
	long long startResult(xmlQueryRequest->Params().PageNumber() * xmlQueryRequest->Params().MaxResults());
	long long stopResult(startResult + xmlQueryRequest->Params().MaxResults() -1);
	if(stopResult<startResult)
		stopResult=startResult+1;

	database::SelectResultContainer<database::queryresultsTableBase> results;
	std::vector<database::WhereConditionTableColumn*> whereContainer;

	database::queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		xmlQueryRequest->Params().QueryID(),
		whereContainer );

	database::queryresultsTableBase::GetWhereColumnsFor_order_position(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::GreaterOrEqual(),database::WhereCondition::And()),
		startResult,
		whereContainer );

	database::queryresultsTableBase::GetWhereColumnsFor_order_position(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(),database::WhereCondition::And()),
		stopResult,
		whereContainer );

	database::SelectStatement selectResults(database::queryresultsTableBase::CreateTableDefinition());
	selectResults.SelectAllColumns();
	selectResults.Where().AddColumns(whereContainer);
	selectResults.OrderBy().AddColumn(database::queryresultsTableBase::GetDefinition_SEARCHQUERY_ID(), database::ASCENDING);

	dbHelper.Connection()->Select(selectResults,results);
	if(results.Size() == 0)
		return false;

	std::vector<long long> sortedUrlStageIDs;
	std::map<long long, long long> mapUrlStageIDUrlID;

	results.ResetIter();
	for( ;!results.IsIterEnd(); results.Next()) {
		long long urlStageID(-1), urlID(-1);

		const database::queryresultsTableBase* pRow(results.GetIter());

		pRow->Get_URLSTAGE_ID(urlStageID);
		pRow->Get_URL_ID(urlID);

		sortedUrlStageIDs.push_back(urlStageID);
		mapUrlStageIDUrlID[urlStageID] = urlID;
	}

	//fetch title and description for pages
	std::map<long long, PageInfo> mapUrlStageIDPageInfo;
	GetPageInfoByUrlStageID(sortedUrlStageIDs, mapUrlStageIDPageInfo);

	//fetch all urls
	std::vector<long long> urlIDs;
	tools::ContainerTools::Map2ToVector(mapUrlStageIDUrlID,urlIDs);
	std::map<long long, htmlparser::DatabaseUrl> mapUrls;
	caching::CacheDatabaseUrl::GetByUrlID(dbHelper.Connection(),urlIDs,mapUrls);

	if(mapUrls.size() == 0){
		//no results found
		return true; }

	//fetch result count in case it is not set yet by SaveResults() function
	if(countResults == -1) {

		std::vector<database::WhereConditionTableColumn*> whereContainerCount;

		database::queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
			xmlQueryRequest->Params().QueryID(),
			whereContainerCount	);

		database::TableColumnDefinition* countColDef(database::queryresultsTableBase::GetDefinition_ID());
		database::SelectStatement selectResultTotal(database::queryresultsTableBase::CreateTableDefinition());
		selectResultTotal.SelectAddCountColumn(countColDef,"","count_col");
		selectResultTotal.Where().AddColumns(whereContainerCount);

		database::SelectResultContainer<database::TableBase> resultsTotal;
		dbHelper.Connection()->Select(selectResultTotal,resultsTotal);
		if(resultsTotal.Size() != 1)
			return false;

		resultsTotal.ResetIter();
		resultsTotal.GetIter()->GetConstColumnByName("count_col")->Get(countResults);
	}

	OutputResults(sortedUrlStageIDs, mapUrlStageIDUrlID, mapUrlStageIDPageInfo, mapUrls);
	return true;
}

bool XMLQueryResponse::ProcessNewQuery(std::vector<std::string>& vecKeywords)
{
	//get ids for keywords
	std::map<long long, KeywordEntry> idKeywords;
	GetKeywordIDs(vecKeywords,idKeywords);
	if(idKeywords.size()==0) {
		//no keywords found
		return true; }

	//get relevant urls
	std::vector<long long> sortedUrlStageIDs;
	std::map<long long, long long> mapUrlStageIDUrlID;
	std::map<long long, UrlStageEntry> mapUrlStages;
	GetResultsFromDatasources(idKeywords, sortedUrlStageIDs, mapUrlStageIDUrlID, mapUrlStages);
	if(sortedUrlStageIDs.size()==0) {
		//no results found
		return true; }
	SaveResults(sortedUrlStageIDs, mapUrlStageIDUrlID);
	return true;
}

bool XMLQueryResponse::GetResultsFromDatasources(
		const std::map<long long, KeywordEntry>& idKeywords,
		std::vector<long long>& orderedUrlStages,
		std::map<long long, long long>& mapUrlStageIDUrlID,
		std::map<long long, UrlStageEntry>& mapUrlStages )
{
	std::vector<long long> sortedUrlStageIDs;
	std::map<long long, std::vector<KeywordEntry> > idUrlStage;
	std::map<long long, BackLinkEntry> urlStageIDBackLinks;

	const unsigned long long& critFlag(xmlQueryRequest->Params().CriteriaFlag());
	bool allFlags = critFlag & XMLQueryRequest::CRITERIA_ALL;
	if( allFlags || ((critFlag & XMLQueryRequest::CRITERIA_META) ||
		(critFlag & XMLQueryRequest::CRITERIA_TITLE) )){
		GetPagesByMeta(idKeywords, idUrlStage);}
	if( allFlags || (critFlag & XMLQueryRequest::CRITERIA_DOMAIN)){
		GetPagesByDomain(idKeywords, idUrlStage);}
	if( allFlags || (critFlag & XMLQueryRequest::CRITERIA_CONTENT)){
		GetPagesByContent(idKeywords, idUrlStage);}
	if( allFlags || (critFlag & XMLQueryRequest::CRITERIA_PATH)){
		GetPagesByUrlPath(idKeywords, idUrlStage);}

	std::map<long long,UrlStageProperties> mapUrlStageProperties;
	GetPageUrlStageInfo(idUrlStage, mapUrlStageIDUrlID, mapUrlStageProperties);

	if(mapUrlStages.size()) {
		if( allFlags || (critFlag & XMLQueryRequest::CRITERIA_LINKS)) {
			GetPageRelevanceByBacklinks(mapUrlStageIDUrlID, urlStageIDBackLinks); }
	}

	//assemble url list
	std::map<long long,UrlStageProperties>::const_iterator iterStageProperties(mapUrlStageProperties.begin());
	for(;iterStageProperties != mapUrlStageProperties.end();++iterStageProperties){
		const long long urlStageID(iterStageProperties->first);
		if(mapUrlStageProperties.count(urlStageID) == 0) {
			log::Logging::LogWarn("could not find urlstage properties");
			continue; }
		const UrlStageProperties& stageProperties(mapUrlStageProperties.at(urlStageID));
		const std::vector<KeywordEntry>& keywords(idUrlStage[urlStageID]);
		const BackLinkEntry& backlinkEntry(urlStageIDBackLinks[urlStageID]);
		mapUrlStages.insert(std::pair<long long,UrlStageEntry>(urlStageID, UrlStageEntry(stageProperties,keywords,backlinkEntry)));
	}

	std::map<long long, Relevance> urlStageRelevance;
	SortResults(mapUrlStages, urlStageIDBackLinks, sortedUrlStageIDs,urlStageRelevance);
	OrderedResults orderedResults;
	GroupResults(mapUrlStages, sortedUrlStageIDs,orderedResults);

	//TODO: !!!dirty hack, do not copy here!!!!
	orderedUrlStages = orderedResults.sortedUrlStageIDs;
	return true;
}

bool XMLQueryResponse::GetPagesByMeta(const std::map<long long, KeywordEntry>& idKeywords, std::map<long long, std::vector<KeywordEntry> >& idUrlStage )
{
	std::vector<database::WhereConditionTableColumn*> whereContainer;

	std::vector<long long> idKeywordVector;
	tools::ContainerTools::Map1ToVector(idKeywords,idKeywordVector);
	database::WhereConditionTableColumnCreateParam paramDict(database::WhereCondition::Equals(),database::WhereCondition::InitialComp());
	paramDict.tableNameAlias = "theDocMeta";
	database::docmetaTableBase::GetWhereColumnsFor_DICT_ID(
		paramDict,
		idKeywordVector,
		whereContainer);

	const unsigned long long& critFlag(xmlQueryRequest->Params().CriteriaFlag());
	if ((critFlag & XMLQueryRequest::CRITERIA_META) &&
	    (critFlag & XMLQueryRequest::CRITERIA_TITLE)) {
		//we want to select all types
	}
	else if (critFlag & XMLQueryRequest::CRITERIA_META) {
		std::vector<long long> vecTypes;
		vecTypes.push_back(1);
		vecTypes.push_back(2);

		database::WhereConditionTableColumnCreateParam paramMeta(database::WhereCondition::Equals(),database::WhereCondition::And());
		paramMeta.tableNameAlias = "theDocMeta";
		database::metainfoTableBase::GetWhereColumnsFor_type(
			paramMeta,
			vecTypes,
			whereContainer);
	}
	else if (critFlag & XMLQueryRequest::CRITERIA_TITLE) {
		database::WhereConditionTableColumnCreateParam paramMeta(database::WhereCondition::Equals(),database::WhereCondition::And());
		paramMeta.tableNameAlias = "theDocMeta";
		database::metainfoTableBase::GetWhereColumnsFor_type(
			paramMeta,
			3,
			whereContainer);
	}

	database::SelectStatement docMeta(database::docmetaTableBase::CreateTableDefinition(),"theDocMeta");
	docMeta.SelectAllColumns();
	docMeta.Where().AddColumns(whereContainer);
	docMeta.OrderBy().AddColumn(database::docmetaTableBase::GetDefinition_occurrence(),database::DESCENDING,"theDocMeta","occurrence");

	database::docmetaTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID("theDocMeta", "URLSTAGE_ID", "theStage", "ID", docMeta);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID("theLatest", "URLSTAGE_ID", "theStage", "ID", docMeta);
	database::metainfoTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID("theMetaInfo", "URLSTAGE_ID", "theStage", "ID", docMeta);

	database::SelectResultContainer<database::docmetaTableBase> vecDocMeta;
	dbHelper.Connection()->Select(docMeta,vecDocMeta);
	if( vecDocMeta.Size() == 0 ) {
		return false; }

	vecDocMeta.ResetIter();
	for(;!vecDocMeta.IsIterEnd(); vecDocMeta.Next()) {
		//TODO: maybe set weight
		double weight(1.0);
		long long urlStageID(-1), dictID(-1), occurrence(-1);

		const database::docmetaTableBase* pRow(vecDocMeta.GetConstIter());

		pRow->Get_URLSTAGE_ID(urlStageID);
		pRow->Get_DICT_ID(dictID);
		pRow->Get_occurrence(occurrence);

		std::map<long long, KeywordEntry>::const_iterator posKeyword(idKeywords.find(dictID));
		if(posKeyword == idKeywords.end()) {
			log::Logging::LogError("could not find keyword matching for meta information");
			continue; }

		idUrlStage[urlStageID].push_back(
			KeywordEntry(KeywordEntry::META_KEYWORD_TYPE, xmlQueryRequest->Params().MetaRelevance(), weight, posKeyword->second.GetKeyword(), dictID, occurrence)
		);
	}
	return true;
}

bool XMLQueryResponse::GetPagesByDomain(const std::map<long long, KeywordEntry>& idKeywords, std::map<long long, std::vector<KeywordEntry> >& idUrlStage )
{
	std::vector<KeywordEntry> entries;
	tools::ContainerTools::Map2ToVector(idKeywords,entries);
	std::vector<KeywordEntry>::const_iterator iterEntries = entries.begin();
	std::vector<std::string> keywordsLC;
	for(;iterEntries != entries.end();++iterEntries) {
		keywordsLC.push_back(tools::StringTools::ToLowerNP(iterEntries->GetKeyword()));	}

	database::SelectResultContainer<database::secondleveldomainsTableBase> resSnd;
	database::secondleveldomainsTableBase::GetBy_domain(dbHelper.Connection(),keywordsLC,resSnd);
	if(resSnd.Size() == 0) {
		return false; }

	std::map<long long,std::string> mapSecondLevelIDKeyword;
	resSnd.ResetIter();
	for(;!resSnd.IsIterEnd();resSnd.Next()) {
		database::secondleveldomainsTableBase* pRow = resSnd.GetIter();
		long long sndID(-1);
		std::string domain;
		pRow->Get_ID(sndID);
		pRow->Get_domain(domain);
		mapSecondLevelIDKeyword[sndID] = domain; }

	std::vector<long long> secondLevelID;
	tools::ContainerTools::Map1ToVector(mapSecondLevelIDKeyword,secondLevelID);

	std::vector<database::WhereConditionTableColumn*> whereContainer;

	database::WhereConditionTableColumnCreateParam paramSecondLevel(database::WhereCondition::Equals(),database::WhereCondition::InitialComp());
	paramSecondLevel.tableNameAlias = "theUrls";
	database::urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
		paramSecondLevel,
		secondLevelID,
		whereContainer );

	database::SelectStatement selectUrlStages(database::urlsTableBase::CreateTableDefinition(),"theUrls");
	selectUrlStages.SelectAllColumns();
	selectUrlStages.SelectAddColumn(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID(),"theLatest","URLSTAGE_ID");
	selectUrlStages.Where().AddColumns(whereContainer);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID("theLatest","URL_ID","theUrls","ID",selectUrlStages);

	database::SelectResultContainer<database::TableBase> vecRows;
	dbHelper.Connection()->Select(selectUrlStages,vecRows);
	if( vecRows.Size() == 0 ) {
		return false; }

	vecRows.ResetIter();
	for(;!vecRows.IsIterEnd();vecRows.Next()) {
		long long secondLevelDomain(-1), urlID(-1), urlStageID(-1);

		const database::TableBase* pRow(vecRows.GetConstIter());

		pRow->GetConstColumnByName("SECONDLEVELDOMAIN_ID")->Get(secondLevelDomain);
		pRow->GetConstColumnByName("ID")->Get(urlID);
		pRow->GetConstColumnByName("URLSTAGE_ID")->Get(urlStageID);

		std::map<long long, std::string>::const_iterator posKeyword(mapSecondLevelIDKeyword.find(secondLevelDomain));
		if(posKeyword == mapSecondLevelIDKeyword.end()) {
			log::Logging::LogError("could not find keyword matching for domain information");
			continue; }

		idUrlStage[urlStageID].push_back(
			KeywordEntry(KeywordEntry::DOMAIN_KEYWORD_TYPE, xmlQueryRequest->Params().DomainRelevance(), 1.0, posKeyword->second, -1, 1)
		);
	}
	return true;
}

bool XMLQueryResponse::GetPagesByContent(const std::map<long long, KeywordEntry>& idKeywords, std::map<long long, std::vector<KeywordEntry> >& idUrlStage )
{
	std::vector<database::WhereConditionTableColumn*> whereContainer;

	std::vector<long long> idKeywordVector;
	tools::ContainerTools::Map1ToVector(idKeywords,idKeywordVector);

	database::WhereConditionTableColumnCreateParam dictParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp());
	dictParam.tableNameAlias = "theDocKey";
	database::dockeyTableBase::GetWhereColumnsFor_DICT_ID(
		dictParam,
		idKeywordVector,
		whereContainer );

	database::SelectStatement dockeyInfo(database::dockeyTableBase::CreateTableDefinition(),"theDocKey");
	dockeyInfo.SelectAllColumns();
	dockeyInfo.Where().AddColumns(whereContainer);
	dockeyInfo.OrderBy().AddColumn(database::dockeyTableBase::GetDefinition_occurrence(), database::DESCENDING);
	database::dockeyTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID("theDocKey", "URLSTAGE_ID" ,"theStage", "ID", dockeyInfo);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID("theLatest", "URLSTAGE_ID", "theStage", "ID" ,dockeyInfo);

	database::SelectResultContainer<database::dockeyTableBase> vecDocKey;
	dbHelper.Connection()->Select(dockeyInfo,vecDocKey);
	if( vecDocKey.Size() == 0 ) {
		return false; }

	vecDocKey.ResetIter();
	for(;!vecDocKey.IsIterEnd();vecDocKey.Next()) {

		const database::dockeyTableBase* pRow(vecDocKey.GetConstIter());

		//TODO: maybe set weight
		double weight(1.0);
		long long urlStageID(-1), dictID(-1), occurrence(-1);
		pRow->Get_URLSTAGE_ID(urlStageID);
		pRow->Get_DICT_ID(dictID);
		pRow->Get_occurrence(occurrence);

		std::map<long long, KeywordEntry>::const_iterator posKeyword(idKeywords.find(dictID));
		if(posKeyword == idKeywords.end()) {
			log::Logging::LogError("could not find keyword matching for content information");
			continue; }

		idUrlStage[urlStageID].push_back(
			KeywordEntry(KeywordEntry::CONTENT_KEYWORD_TYPE, xmlQueryRequest->Params().ContentRelevance(), weight, posKeyword->second.GetKeyword(), dictID, occurrence)
		);
	}
	return true;
}

bool XMLQueryResponse::GetKeywordIDs(const std::vector<std::string>& vecKeywords, std::map<long long, KeywordEntry>& idKeywords)
{
	if(vecKeywords.size() == 0)
		return false;

	std::vector<database::WhereConditionTableColumn*> whereContainer;

	database::dictTableBase::GetWhereColumnsFor_keyword(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Like(),database::WhereCondition::InitialComp()),
		vecKeywords,
		whereContainer );

	database::SelectStatement selectKeyWord(database::dictTableBase::CreateTableDefinition());
	selectKeyWord.SelectAllColumns();
	selectKeyWord.Where().AddColumns(whereContainer);
	selectKeyWord.OrderBy().AddColumn(database::dictTableBase::GetDefinition_occurrence(), database::DESCENDING);

	database::SelectResultContainer<database::dictTableBase> results;
	dbHelper.Connection()->Select(selectKeyWord,results);
	if(results.Size() == 0) {
		return false; }

	//fetch all information for keywords
	results.ResetIter();
	for(;!results.IsIterEnd(); results.Next()) {

		const database::dictTableBase* pRow(results.GetConstIter());

		//TODO: set relevance and weight to something with sense
		double relevance(1.0), weight(1.0);
		std::string keyword;
		long long dictID(-1), occurrence(-1);
		pRow->Get_ID(dictID);
		pRow->Get_occurrence(occurrence);
		pRow->Get_keyword(keyword);

		idKeywords.insert(std::pair<long long, KeywordEntry>(dictID,KeywordEntry(KeywordEntry::UNKNOWN_KEYWORD_TYPE, relevance, weight,keyword,dictID, occurrence)));
	}
	return true;
}

bool XMLQueryResponse::GetPageInfoByUrlStageID(const std::vector<long long>& vecUrlStageID, std::map<long long, PageInfo>& mapUrlStageIDPageInfo)
{
	std::vector<long long> metaTypes;
	//metaTypes.push_back(1); //keywords
	metaTypes.push_back(2); //description
	metaTypes.push_back(3); //title

	std::vector<database::WhereConditionTableColumn*> whereContainer;
	database::metainfoTableBase::GetWhereColumnsFor_URLSTAGE_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		vecUrlStageID,
		whereContainer );

	database::metainfoTableBase::GetWhereColumnsFor_type(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
		metaTypes,
		whereContainer );

	database::SelectStatement selectMetaInfo(database::metainfoTableBase::CreateTableDefinition());
	selectMetaInfo.SelectAllColumns();
	selectMetaInfo.Where().AddColumns(whereContainer);

	database::SelectResultContainer<database::metainfoTableBase> vecMetaInfoTbls;
	dbHelper.Connection()->Select(selectMetaInfo,vecMetaInfoTbls);

	vecMetaInfoTbls.ResetIter();
	for(;!vecMetaInfoTbls.IsIterEnd(); vecMetaInfoTbls.Next()) {

		const database::metainfoTableBase* pRow(vecMetaInfoTbls.GetConstIter());
		long long type(-1), urlStageID(-1);
		pRow->Get_type(type);
		pRow->Get_URLSTAGE_ID(urlStageID);

		switch(type)
		{
		case 2:
			pRow->Get_value(mapUrlStageIDPageInfo[urlStageID].description);
			break;
		case 3:
			pRow->Get_value(mapUrlStageIDPageInfo[urlStageID].title);
			break;
		default:
			continue;
		}
	}
	return true;
}

bool XMLQueryResponse::GetPageUrlStageInfo(const std::map<long long, std::vector<KeywordEntry> >& idUrlStage, std::map<long long, long long>& mapUrlStageIDUrlID, std::map<long long, UrlStageProperties>& mapUrlStages)
{
	std::vector<long long> vecUrlStageID;
	tools::ContainerTools::Map1ToVector(idUrlStage,vecUrlStageID);
	if(vecUrlStageID.size()==0)
		return false;

	std::vector<database::WhereConditionTableColumn*> whereContainer;

	database::WhereConditionTableColumnCreateParam paramUrlStagesID(database::WhereCondition::Equals(),database::WhereCondition::InitialComp());
	paramUrlStagesID.tableNameAlias = "theStages";
	database::urlstagesTableBase::GetWhereColumnsFor_ID(
		paramUrlStagesID,
		vecUrlStageID,
		whereContainer );

	database::SelectStatement selectUrlStages(database::urlstagesTableBase::CreateTableDefinition(), "theStages");
	selectUrlStages.SelectAllColumns();
	selectUrlStages.SelectAddColumn(database::urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID(),"theUrls","SECONDLEVELDOMAIN_ID");
	selectUrlStages.Where().AddColumns(whereContainer);
	database::urlstagesTableBase::AddInnerJoinRightSideOn_URL_ID("theStages","URL_ID","theUrls","ID",selectUrlStages);

	database::SelectResultContainer<database::TableBase> vecUrlStages;
	dbHelper.Connection()->Select(selectUrlStages,vecUrlStages);
	if(vecUrlStages.Size() == 0) {
		return false; }

	vecUrlStages.ResetIter();
	for(;!vecUrlStages.IsIterEnd();vecUrlStages.Next()) {

		const database::TableBase* pRow(vecUrlStages.GetConstIter());

		//TODO: do more with urlstage data
		long long urlStageID(-1), urlID(-1), secondLevelDomainID(-1), contentSize(-1);
		struct tm lastVisited,lastChanged;

		pRow->GetConstColumnByName("ID")->Get(urlStageID);
		pRow->GetConstColumnByName("URL_ID")->Get(urlID);
		pRow->GetConstColumnByName("found_date")->Get(lastVisited);
		pRow->GetConstColumnByName("last_change")->Get(lastChanged);
		pRow->GetConstColumnByName("content_length")->Get(contentSize);
		pRow->GetConstColumnByName("SECONDLEVELDOMAIN_ID")->Get(secondLevelDomainID);

		mapUrlStages.insert(std::pair<long long,UrlStageProperties>(urlStageID,UrlStageProperties(urlStageID,urlID, secondLevelDomainID,lastVisited,lastChanged,contentSize)));
		mapUrlStageIDUrlID[urlStageID] = urlID;
	}
	return true;
}

bool XMLQueryResponse::GetPageRelevanceByBacklinks(const std::map<long long, long long>& mapUrlStageIDUrlID, std::map<long long, BackLinkEntry>& urlStageIDBackLinks )
{
	std::map<long long, long long>::const_iterator iterUrlStagesUrl(mapUrlStageIDUrlID.begin());
	for(;iterUrlStagesUrl != mapUrlStageIDUrlID.end(); ++iterUrlStagesUrl) {
		long long urlStageID(iterUrlStagesUrl->first);
		long long urlID(iterUrlStagesUrl->second);

		std::map<long long,htmlparser::DatabaseUrl> mapIDUrls;
		htmlparser::DatabaseUrl::GetBackLinks(dbHelper.Connection(), urlID, mapIDUrls);

		std::vector<htmlparser::DatabaseUrl> vecURLs;
		tools::ContainerTools::Map2ToVector(mapIDUrls,vecURLs);
		urlStageIDBackLinks.insert(std::pair<long long, BackLinkEntry>(urlStageID,BackLinkEntry(xmlQueryRequest->Params().BackLinkRelevance(),1.0,urlStageID,vecURLs)));
	}
	return true;
}

bool XMLQueryResponse::SortResults(const std::map<long long, UrlStageEntry >& idUrlStages, const std::map<long long, BackLinkEntry>& urlStageIDBackLinks, std::vector<long long>& sortedUrlStageIDs, std::map<long long, Relevance>& urlStageRelevance )
{
	std::map<long long, UrlStageEntry >::const_iterator iterUrlStageEntries(idUrlStages.begin());
	for(;iterUrlStageEntries != idUrlStages.end(); ++iterUrlStageEntries) {

		long long urlStageID(iterUrlStageEntries->first);
		const UrlStageEntry& urlStageEntry(iterUrlStageEntries->second);

		std::pair<long long, Relevance> insertPair(urlStageID,urlStageEntry.GetTotalRelevance());
		urlStageRelevance.insert(insertPair);

		if(urlStageIDBackLinks.count(urlStageID) > 0 && urlStageIDBackLinks.at(urlStageID).UrlStageID() != -1) {

			const BackLinkEntry& backlinks(urlStageIDBackLinks.at(urlStageID));

			//TODO: maybe give per link relevance (i.e. based on the links relevancy/quality itself, PageRank etc.)
			/*
			const std::vector<URL>& backlinksUrls = backlinks.BackLinks();
			std::vector<URL>::const_iterator iterBackLinks = backlinksUrls.begin();
			for(;iterBackLinks != backlinksUrls.end();++iterBackLinks) {
			}
			*/

			if(urlStageRelevance.count(urlStageID) == 0) {
				urlStageRelevance.insert(std::pair<long long, Relevance>(urlStageID,(const Relevance&)backlinks));
			}
			else{
				Relevance totalRelevance(urlStageRelevance.at(urlStageID) + (const Relevance&)backlinks);
				std::pair<long long, Relevance> insertPair(urlStageID,totalRelevance);
				std::pair< std::map<long long,Relevance>::iterator, bool > ret(urlStageRelevance.insert(insertPair));
				if(!ret.second)	{ ret.first->second = insertPair.second; }
			}
		}
	}

	std::map<double, std::vector<long long> > mapRelevanceUrlStageID;
	std::map<long long, Relevance>::const_iterator iterUrlStageIDRelevance(urlStageRelevance.begin());
	for(;iterUrlStageIDRelevance != urlStageRelevance.end();++iterUrlStageIDRelevance) {
		mapRelevanceUrlStageID[iterUrlStageIDRelevance->second.GetWeightedRelevance()].push_back(iterUrlStageIDRelevance->first); }

	std::map<double, std::vector<long long> >::const_iterator sortUrlStageIDs(mapRelevanceUrlStageID.begin());
	for(;sortUrlStageIDs != mapRelevanceUrlStageID.end();++sortUrlStageIDs) {
		const std::vector<long long>& vecUrlStages(sortUrlStageIDs->second);
		std::vector<long long>::const_iterator iterUrlStages(vecUrlStages.begin());
		for(;iterUrlStages != vecUrlStages.end();++iterUrlStages) {
			sortedUrlStageIDs.insert(sortedUrlStageIDs.begin(),*iterUrlStages);	}
	}
	return true;
}

bool XMLQueryResponse::OutputResults(
		const std::vector<long long>& sortedUrlStageIDs,
		const std::map<long long, long long>& mapUrlStageIDUrlID,
		const std::map<long long, PageInfo>& mapUrlStagePageInfo,
		const std::map<long long, htmlparser::DatabaseUrl>& mapUrls)
{
	std::stringstream xmlContent;
	xmlContent <<
		"<?xml version=\"1.0\"?>\n"
		"<response>"
		"<queryId>" << xmlQueryRequest->Params().QueryID() << "</queryId>"
		"<pageNo>" << xmlQueryRequest->Params().PageNumber() << "</pageNo>"
		"<totalResults>" << countResults << "</totalResults>";
	std::vector<long long>::const_iterator iterSortedUrlStage(sortedUrlStageIDs.begin());
	for(int i = 1;iterSortedUrlStage != sortedUrlStageIDs.end();i++,++iterSortedUrlStage) {
		const long long& urlStageID(*iterSortedUrlStage);

		if(	mapUrlStageIDUrlID.count(urlStageID)  == 0 ||
			mapUrlStagePageInfo.count(urlStageID) == 0 ) {
				std::stringstream ssStream;
				ssStream << "could not find information for urlstage id: " << urlStageID;
				log::Logging::LogError(ssStream.str());
				continue; }

		const long long urlID(mapUrlStageIDUrlID.at(urlStageID));
		const PageInfo& pageInfo(mapUrlStagePageInfo.at(urlStageID));
		if(	mapUrls.count(urlID) == 0 ){
			std::stringstream ssStream;
			ssStream << "could not find information for url id: " << urlID;
			log::Logging::LogError(ssStream.str());
			continue; }

		const htmlparser::DatabaseUrl& url(mapUrls.at(urlID));

		//const UrlStageEntry& urlStageEntry         = mapUrlStageEntry.at(urlStageID);
		//const UrlStageProperties& urlStageProperty = urlStageEntry.UrlStageProperty();

		std::string lastVisitedString, lastChangedString;
/*
		const struct tm& lastVisited = urlStageProperty.LastVisited();
		const struct tm& lastChanged = urlStageProperty.LastChanged();
		if( lastVisited.tm_year != 0)
			database::DatabaseHelper::TmToDateTime(lastVisited,lastVisitedString);
		if( lastChanged.tm_year != 0)
			database::DatabaseHelper::TmToDateTime(lastChanged,lastChangedString);
*/
		std::string encodedURL(url.GetFullUrl());
		network::HttpUrlParser::EncodeUrl(encodedURL);

		std::string encodedTitle(pageInfo.Title());
		network::HttpUrlParser::EncodeUrl(encodedTitle);

		std::string encodedDescription(pageInfo.Description());
		network::HttpUrlParser::EncodeUrl(encodedDescription);

		std::vector<std::string> encodedKeywordEntries;
		/*
		const std::vector<KeywordEntry>& keywords = urlStageEntry.Keywords();
		std::vector<KeywordEntry>::const_iterator iterKeywords = keywords.begin();
		for(;iterKeywords != keywords.end();++iterKeywords) {
			std::stringstream ssKeywordPart;
			std::string encodedKeyword = iterKeywords->GetKeyword();
			UrlParser::EncodeUrl(encodedKeyword);
			ssKeywordPart
				<< "<keyword relevancy=\"" << iterKeywords->GetWeightedRelevance() << "\" type=\"" << KeywordEntryTypeConverter::ToString(iterKeywords->GetType()) << "\">" << encodedKeyword << "</keyword>";
			encodedKeywordEntries.push_back(ssKeywordPart.str());
		}
		*/

		std::string dumpEncoded;
		tools::StringTools::VectorToString(encodedKeywordEntries,dumpEncoded);

		xmlContent <<
		"<result id=\"" << i << "\">"
		"<url id=\"" << urlID << "\">" << encodedURL << "</url>"
		"<title>" << encodedTitle << "</title>"
		"<description>" << encodedDescription << "</description>"
		"<lastVisited>" << lastVisitedString << "</lastVisited>"
		"<lastChanged>" << lastChangedString << "</lastChanged>"
		"<keywords>" << dumpEncoded << "</keywords>"
//		"\t<relevancyWeighted>" << urlStageEntry.GetTotalRelevance().GetWeightedRelevance() << "</relevancyWeighted>\n"
//		"\t<relevancy>" << urlStageEntry.GetTotalRelevance().GetRelevance() << "</relevancy>\n"
//		"\t<weight>" << urlStageEntry.GetTotalRelevance().GetWeight() << "</weight>\n"
		"</result>";
	}
	xmlContent << "</response>\n";
	content = xmlContent.str();
	return true;
}

bool XMLQueryResponse::GetPagesByUrlPath(const std::map<long long, KeywordEntry>& idKeywords, std::map<long long, std::vector<KeywordEntry> >& idUrlStage )
{
	std::vector<database::WhereConditionTableColumn*> whereContainer;

	database::WhereConditionTableColumnCreateParam whereDictParam(
		database::WhereCondition::Equals(),
		database::WhereCondition::InitialComp());
	whereDictParam.tableNameAlias = "doc";

	std::vector<long long> idKeywordVector;
	tools::ContainerTools::Map1ToVector(idKeywords,idKeywordVector);
	database::docurlTableBase::GetWhereColumnsFor_DICT_ID(
		whereDictParam,
		idKeywordVector,
		whereContainer );

	database::SelectStatement dockeyInfo(database::docurlTableBase::CreateTableDefinition(),"doc");
	dockeyInfo.SelectAllColumns();
	dockeyInfo.Where().AddColumns(whereContainer);
	database::docurlTableBase::AddInnerJoinRightSideOn_URL_ID("doc", "URL_ID","theUrl","ID",dockeyInfo);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID("latest", "URL_ID", "theUrl","ID", dockeyInfo);

	database::SelectResultContainer<database::TableBase> vecDocRows;
	dbHelper.Connection()->Select(dockeyInfo,vecDocRows);
	if( vecDocRows.Size() == 0 ) {
		return false; }

	vecDocRows.ResetIter();
	for(;!vecDocRows.IsIterEnd(); vecDocRows.Next()) {

		const database::TableBase* pRow(vecDocRows.GetConstIter());
		long long dictID(-1), urlStageID(-1);

		pRow->GetConstColumnByName("DICT_ID")->Get(dictID);
		pRow->GetConstColumnByName("URLSTAGE_ID")->Get(urlStageID);

		std::map<long long, KeywordEntry>::const_iterator posKeyword = idKeywords.find(dictID);
		if(posKeyword == idKeywords.end()) {
			log::Logging::LogError("could not find keyword matching for content information");
			continue; }

		//TODO: maybe set weight
		double weight(1.0);
		long long occurrence(1);
		idUrlStage[urlStageID].push_back(
			KeywordEntry(KeywordEntry::URL_KEYWORD_TYPE,xmlQueryRequest->Params().UrlPathRelevance(), weight, posKeyword->second.GetKeyword(), dictID, occurrence)
		);
	}
	return true;
}

bool XMLQueryResponse::GroupResults(std::map<long long, UrlStageEntry >& idUrlStages, const std::vector<long long>& sortedUrlStageIDs, OrderedResults& orderedResults)
{
	std::vector<long long>::const_iterator iterSorted(sortedUrlStageIDs.begin());
	const unsigned long long& groupFlag(xmlQueryRequest->Params().GroupingFlag());

	if(groupFlag & XMLQueryRequest::GROUPING_DOMAIN) {

		for(;iterSorted != sortedUrlStageIDs.end();++iterSorted) {

			if(idUrlStages.count(*iterSorted) == 0) {
				log::Logging::LogError("could not find urlstage id for grouping results");
				continue;}

			UrlStageEntry& urlStageEntry(idUrlStages.find(*iterSorted)->second);
			long long secondLevelDomainID(urlStageEntry.UrlStageProperty().SecondLevelDomainID());
			long long urlStageID(urlStageEntry.UrlStageProperty().UrlStageID());

			orderedResults.groupedSecondLevelDomainIDUrlStageID[secondLevelDomainID].push_back(urlStageID);

			//add secondleveldomain only if it is not already there
			std::vector<long long>::const_iterator iterFound(
				std::find(
						orderedResults.sortedSecondLevelDomainID.begin(),
						orderedResults.sortedSecondLevelDomainID.end(),
						secondLevelDomainID	)
			);
			if( iterFound == orderedResults.sortedSecondLevelDomainID.end()){
				orderedResults.sortedUrlStageIDs.push_back( urlStageEntry.UrlStageProperty().UrlStageID() );
				orderedResults.sortedSecondLevelDomainID.push_back(secondLevelDomainID); }
		}
	} else {
		//no grouping
		orderedResults.sortedUrlStageIDs = sortedUrlStageIDs;
	}
	return true;
}

bool XMLQueryResponse::LogQuery(const std::vector<std::string>& vecKeywords, bool& isExistent)
{
	//is a new query,insert for logging
	if(xmlQueryRequest->Params().QueryID() == -1) {

		network::HttpCookie sessionCookie;
		if(!network::HttpCookieHelper::GetCookieByKey("SIRIDIAID",xmlQueryRequest->Cookies(),sessionCookie)){
			log::Logging::LogError("no session id found");
			return false; }

		database::searchqueryTableBase tblQuery;
		tblQuery.Set_session(sessionCookie.GetValue());
		tblQuery.Insert(dbHelper.Connection());

		if( !dbHelper.Connection()->LastInsertID( xmlQueryRequest->Params().queryID ) ) {
			return false; }

		std::vector<std::string>::const_iterator iterKeywords(vecKeywords.begin());
		for(;iterKeywords != vecKeywords.end();++iterKeywords) {

			const std::string& keyword(*iterKeywords);

			database::keywordqueryTableBase tblKeywordQuery;
			tblKeywordQuery.Set_query_part(keyword);
			tblKeywordQuery.InsertOrUpdate(dbHelper.Connection());

			long long keywordQueryID(-1);
			if( !dbHelper.Connection()->LastInsertID(keywordQueryID) || keywordQueryID == -1) {
				log::Logging::LogError("error while inserting keyword id: " + keyword);
				return false; }

			database::searchquerykeywordsTableBase searchQueryKeyword;
			searchQueryKeyword.Set_KEYWORDQUERY_ID(keywordQueryID);
			searchQueryKeyword.Set_SEARCHQUERY_ID(xmlQueryRequest->Params().QueryID());
			searchQueryKeyword.InsertOrUpdate(dbHelper.Connection());
		}
	}
	else {
		//TODO: check if combination of search query id and session id exists and is valid, i.e. so that nobody can list each others results
		isExistent = true;
	}
	return true;
}

bool XMLQueryResponse::SaveResults(
		const std::vector<long long>& sortedUrlStageIDs,
		const std::map<long long, long long>& mapUrlStageIDUrlID)
{
	bool success(true);
	countResults = sortedUrlStageIDs.size();
	std::vector<long long>::const_iterator iterSortedUrlStage = sortedUrlStageIDs.begin();
	for(int i = 0;iterSortedUrlStage != sortedUrlStageIDs.end();i++,++iterSortedUrlStage) {
		const long long urlStageID = *iterSortedUrlStage;
		const long long urlID      = mapUrlStageIDUrlID.at(urlStageID);

		database::queryresultsTableBase tblResult;
		tblResult.Set_SEARCHQUERY_ID(xmlQueryRequest->Params().QueryID());
		tblResult.Set_URLSTAGE_ID(urlStageID);
		tblResult.Set_URL_ID(urlID);
		tblResult.Set_order_position(i);
		tblResult.Insert(dbHelper.Connection());
	}

	if( !success ) {
		log::Logging::LogError("error while inserting results"); }
	return success;
}

}
