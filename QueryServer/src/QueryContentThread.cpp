/**
 *
 * @file QueryContentThread.cpp
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#include "QueryContentThread.h"

#include "Query.h"

#include <iterator>

#include <DatabaseLayer.h>
#include <DatabaseHelper.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <ContainerTools.h>
#include <StringTools.h>
#include <Pointer.h>
#include <Logging.h>

#include <DatabaseException.h>

namespace queryserver {

QueryContentThread::QueryContentThread()
: queryserver::QueryThread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryContentThread::QueryContentThreadFunction)))
, params(0)
{
}

QueryContentThread::~QueryContentThread() {
}

bool QueryContentThread::InitThreadInstance() {

	log::Logging::RegisterThreadID("QueryContentThread");

	if(!params) {
		return false; }

	if(dbHelper.CreateConnection(params->config)) {
		return false; }

	keywordIDs.resize(params->query.keywords.size(),-1);

	if(!params->query.properties.caseSensitive) {
		lowerKeywords.assign(params->query.keywords.begin(),params->query.keywords.end());
		tools::StringTools::LowerStringsInVector(lowerKeywords);
		caseInsensitiveKeywordIDs.resize(params->query.keywords.size(),std::vector<long long>()); }

	return true;
}

bool QueryContentThread::DestroyThreadInstance(){

	dbHelper.DestroyConnection();

	if(params)
		delete params;
	params = 0;

	keywordIDs.clear();

	lowerKeywords.clear();
	caseInsensitiveKeywordIDs.clear();

	return true;
}

void* QueryContentThread::QueryContentThreadFunction(threading::Thread::THREAD_PARAM* threadParam)
{
	QueryContentThread* instance(dynamic_cast<QueryContentThread*>(threadParam->instance));
	instance->params = reinterpret_cast<QueryContentThreadParam*>(threadParam->pParam);

	try {
		if(!instance->InitThreadInstance()) {
			instance->DestroyThreadInstance();
			return 0; }

		if(!instance->GetIDsForKeywords()) {
			instance->DestroyThreadInstance();
			return 0; }

		if(!instance->GetIDsForCaseInsensitiveKeywords()) {
			instance->DestroyThreadInstance();
			return 0; }

		if(!instance->GetUrlsForKeywords()) {
			instance->DestroyThreadInstance();
			return 0; }
	}
	catch(...) {
		//
		//TODO: log this error
		//
	}

	instance->DestroyThreadInstance();
	return 0;
}

bool QueryContentThread::GetIDsForKeywords() {

	database::SelectResultContainer<database::dictTableBase> results;

	try {
		database::dictTableBase::GetBy_keyword(dbHelper.Connection(),params->query.keywords,results);
	}
	catch(database::DatabaseException& e) {
		std::string keywordsDump;
		tools::ContainerTools::DumpVector(params->query.keywords,keywordsDump);
		log::Logging::LogTrace("error while selecting keywords\n%s",keywordsDump.c_str());
		return false;
	}

	std::string tmpKey;
	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		results.GetConstIter()->Get_keyword(tmpKey);

		std::vector<std::string>::const_iterator iKeyFind(std::find(params->query.keywords.begin(),params->query.keywords.end(),tmpKey));
		if(iKeyFind == params->query.keywords.end()) {
			log::Logging::LogTrace("could not find keyword %s, skipping it",iKeyFind->c_str());
			continue; }

		std::vector<long long>::iterator iKeyID(keywordIDs.begin());
		std::advance(iKeyID,std::distance(params->query.keywords.begin(), iKeyFind));

		results.GetConstIter()->Get_ID(*iKeyID);
	}

	return true;
}

bool QueryContentThread::GetIDsForCaseInsensitiveKeywords() {

	if(params->query.properties.caseSensitive)
		return true;

	std::vector<database::WhereConditionTableColumn*> where;
	database::dictTableBase::GetWhereColumnsFor_keyword(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Like(),database::WhereCondition::InitialComp()),
		lowerKeywords,
		where );

	database::dictTableBase::GetWhereColumnsFor_keyword(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(),database::WhereCondition::And()),
		lowerKeywords,
		where );

	tools::Pointer<database::TableDefinition> defDictPtr(database::dictTableBase::CreateTableDefinition());
	database::SelectStatement selectCaseInsensitive(defDictPtr.GetConst());
	selectCaseInsensitive.SelectAllColumns();
	selectCaseInsensitive.Where().AddColumns(where);

	database::SelectResultContainer<database::dictTableBase> results;
	try {
		dbHelper.Connection()->Select(selectCaseInsensitive,results);
	}
	catch(database::DatabaseException& e) {
		return false;
	}

	std::string tmpInsensitiveKey;
	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		results.GetConstIter()->Get_keyword(tmpInsensitiveKey);

		std::vector<std::string>::iterator iKeyInsensitiveFind(
			std::find(lowerKeywords.begin(),lowerKeywords.end(),tools::StringTools::ToLowerIP(tmpInsensitiveKey)) );
		if(iKeyInsensitiveFind == lowerKeywords.end()) {
			log::Logging::LogTrace("could not find keyword %s, skipping it",iKeyInsensitiveFind->c_str());
			continue; }

		std::vector< std::vector<long long> >::iterator iKeyWordID(caseInsensitiveKeywordIDs.begin());
		std::advance(iKeyWordID,std::distance(lowerKeywords.begin(), iKeyInsensitiveFind));

		long long keywordID(-1);
		results.GetConstIter()->Get_ID(keywordID);
		iKeyWordID->push_back(keywordID);
	}

	return true;
}

bool QueryContentThread::GetUrlsForKeywords() {

	std::vector<long long> allKeywordIDs;
	allKeywordIDs.insert(allKeywordIDs.end(),keywordIDs.begin(),keywordIDs.end());

	if(!params->query.properties.caseSensitive) {
		tools::ContainerTools::AppendFlattenedVector(caseInsensitiveKeywordIDs,allKeywordIDs);	}

	tools::ContainerTools::MakeUniqueVector(allKeywordIDs,true);

	tools::Pointer<database::TableDefinition> tblDefPtr(database::dockeyTableBase::CreateTableDefinition());
	database::SelectStatement select(tblDefPtr.GetConst());

	select.SelectAddColumn(database::dockeyTableBase::GetDefinition_DICT_ID());
	select.SelectAddColumn(database::latesturlstagesTableBase::GetDefinition_URL_ID());

	database::dockeyTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID(select);

	std::vector<database::WhereConditionTableColumn*> where;
	database::dockeyTableBase::GetWhereColumnsFor_DICT_ID(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()),
		allKeywordIDs,
		where);

	select.Where().AddColumns(where);

	//
	//TODO: 1. add reasonable limit to number of results
	//      as it might be huge a number.
	//
	//		2. therefore we might also order results, to
	//      make sure they are based on relevancy, and
	//      not random by database order as it is now.
	//
	select.SetLimit(10000);

	database::SelectResultContainer<database::TableBase> results;
	try {
		dbHelper.Connection()->Select(select,results);
	}
	catch(database::DatabaseException& e) {
		return false;
	}

	return ProcessResults(results);
}

bool QueryContentThread::ProcessResults(database::SelectResultContainer<database::TableBase>& results) {

	tools::Pointer<database::TableColumnDefinition>
		colDefUrlIDPtr(database::latesturlstagesTableBase::GetDefinition_URL_ID()),
		colDefDictIDPtr(database::dockeyTableBase::GetDefinition_DICT_ID());

	const database::TableColumnDefinition
		*colDefUrlID(colDefUrlIDPtr.GetConst()),
		*colDefDictID(colDefDictIDPtr.GetConst());

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		const database::TableBase* curTbl(results.GetConstIter());

		const database::TableColumn
			*colUrlID(curTbl->GetConstColumnByName(colDefUrlID->GetColumnName())),
			*colUrlstageID(curTbl->GetConstColumnByName(colDefDictID->GetColumnName()));

		if(!colUrlID || !colUrlstageID) {
			//
			//TODO: throw exception, invalid result row
			//
			continue;
		}

		long long urlID(-1),urlStageID(-1);
		colUrlID->Get(urlID);
		colUrlstageID->Get(urlStageID);

		resultEntries.push_back(QueryContentResultEntry(urlID,urlStageID));
	}

	return true;
}

}
