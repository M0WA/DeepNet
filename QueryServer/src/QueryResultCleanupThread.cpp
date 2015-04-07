/**
 * @file QueryResultCleanupThread.cpp
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#include "QueryResultCleanupThread.h"

#include <algorithm>
#include <unistd.h>

#include <Pointer.h>
#include <TimeTools.h>
#include <Logging.h>
#include <DatabaseException.h>
#include <TableDefinition.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>
#include <DatabaseHelper.h>
#include <DatabaseLayer.h>

namespace queryserver {

QueryResultCleanupThread::QueryResultCleanupThread(database::DatabaseConfig* databaseConfig,unsigned long long requery_after)
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryResultCleanupThread::QueryResultCleanupThreadFunc)),false)
, databaseConfig(databaseConfig)
, requery_after(requery_after){
}

QueryResultCleanupThread::~QueryResultCleanupThread() {
}

void QueryResultCleanupThread::GetExpiredQueries(database::DatabaseConnection* db, std::vector<long long>& ids)
{
	std::vector<database::WhereConditionTableColumn*> where;
	database::searchqueryTableBase::GetWhereColumnsFor_modified(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Smaller(),database::WhereCondition::InitialComp()),
		tools::TimeTools::NowUTCAddSeconds(requery_after*-1),
		where);
	database::searchqueryTableBase::GetWhereColumnsFor_finished(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
		1,
		where);

	database::SelectStatement selectSearchQuery(database::searchqueryTableBase::CreateTableDefinition());
	selectSearchQuery.SelectAddColumn(database::searchqueryTableBase::GetDefinition_ID());
	selectSearchQuery.Where().AddColumns(where);

	database::SelectResultContainer<database::searchqueryTableBase> resultSearchQuery;
	try {
		db->Select(selectSearchQuery,resultSearchQuery);
	}
	catch(database::DatabaseException& e) {
		return; }

	if(!resultSearchQuery.Size()) {
		return; }

	for(resultSearchQuery.ResetIter();!resultSearchQuery.IsIterEnd();resultSearchQuery.Next()){
		long long id;
		resultSearchQuery.GetConstIter()->Get_ID(id);
		ids.push_back(id);	}
}

void QueryResultCleanupThread::InvalidateQueries(database::DatabaseConnection* db,const std::vector<long long>& ids)
{
	database::TableBaseUpdateParam param;
	param.limit = -1;
	param.onlyDirtyColumns = true;

	std::vector<database::WhereConditionTableColumn*> where;
	database::searchqueryTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		ids,
		param.whereCols);

	database::searchqueryTableBase tbl;
	tbl.Set_finished(0);
	try {
		tbl.Update(db,param); }
	catch(database::DatabaseException& e) {
		return; }
}

void QueryResultCleanupThread::DeleteResults(database::DatabaseConnection* db,const std::vector<long long>& ids)
{
	database::queryresultsTableBase tbl;

	std::vector<database::WhereConditionTableColumn*> where;
	database::queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		ids,
		where);

	tools::Pointer<database::TableDefinition> pDef;
	pDef.Set(database::queryresultsTableBase::CreateTableDefinition(),true);

	database::DeleteStatement delResults(pDef.GetConst());
	delResults.Where().AddColumns(where);

	try {
		db->Delete(delResults); }
	catch(database::DatabaseException& e) {
		return; }
}

void QueryResultCleanupThread::DeleteQueries(database::DatabaseConnection* db,const std::vector<long long>& ids)
{
	std::vector<database::WhereConditionTableColumn*> where;
	database::searchqueryTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		ids,
		where);

	tools::Pointer<database::TableDefinition> pDef;
	pDef.Set(database::searchqueryTableBase::CreateTableDefinition(),true);

	database::DeleteStatement delSearchQuery(pDef.GetConst());
	delSearchQuery.Where().AddColumns(where);
	try {
		db->Delete(delSearchQuery); }
	catch(database::DatabaseException& e) {
		return; }
}

unsigned long long QueryResultCleanupThread::Cleanup() {

	time_t start(time(0));

	database::DatabaseHelper dh;
	database::DatabaseConnection* db(dh.CreateConnection(databaseConfig));
	if(!db) {
		log::Logging::LogError("could not establish database connection for QueryResultCleanupThread");
		return 0; }

	std::vector<long long> ids;
	GetExpiredQueries(db,ids);
	if(!ids.size()){
		log::Logging::LogTrace("no queries ready for cleanup");
		goto CALC_DURATION; }

	log::Logging::LogTrace("%zu queries expired, purging...",ids.size());

	InvalidateQueries(db,ids);
	DeleteResults(db,ids);
	DeleteQueries(db,ids);

CALC_DURATION:
	return time(0) - start;
}

void* QueryResultCleanupThread::QueryResultCleanupThreadFunc(threading::Thread::THREAD_PARAM* param) {

	log::Logging::RegisterThreadID("QueryResultCleanupThread");
	QueryResultCleanupThread* instance(dynamic_cast<QueryResultCleanupThread*>(param->instance));

	while(!instance->ShallEnd()){
		unsigned long long rest(instance->requery_after);
		unsigned long long duration(instance->Cleanup());

		rest -= std::min(rest,duration);

		log::Logging::LogTrace("cleanup of query results ran %llu seconds, sleeping for %llu seconds",duration,rest);

		if(rest>0){
			sleep(rest); }
	}

	return 0;
}

}
