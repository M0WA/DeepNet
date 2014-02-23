/**
 *
 * @file QueryDictionaryInfoThread.cpp
 * @author Moritz Wagner
 * @date 02.02.2014
 *
 */

#include "QueryDictionaryInfoThread.h"

#include <Logging.h>
#include <PerformanceCounter.h>

#include <DatabaseLayer.h>
#include <DatabaseHelper.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include "Query.h"
#include "QueryKeywordGroup.h"
#include "QueryThreadParam.h"

namespace queryserver {

QueryDictionaryInfoThread::_QueryDictionaryInfoThreadParam::_QueryDictionaryInfoThreadParam(Query& query,const database::DatabaseConfig *dbconf)
: query(query)
, dbconf(dbconf) {
}

QueryDictionaryInfoThread::QueryDictionaryInfoThread()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryDictionaryInfoThread::QueryDictionaryInfoThreadFunction)),false) {
}

QueryDictionaryInfoThread::~QueryDictionaryInfoThread() {
}

void* QueryDictionaryInfoThread::QueryDictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam) {

	log::Logging::RegisterThreadID("QueryDictionaryInfoThreadFunction");

	QueryDictionaryInfoThreadParam *qp(reinterpret_cast<QueryDictionaryInfoThreadParam*>(threadParam->pParam));
	Query& q(qp->query);
	//const QueryProperties& qpx(qp->query.GetQueryProperties());

	const database::DatabaseConfig *dbconf(qp->dbconf);
	database::DatabaseHelper dbHelp;
	database::DatabaseConnection *db(dbHelp.CreateConnection(dbconf));
	if(!db) {
		log::Logging::LogError("error while connecting to database to find dictIDs");
		free(qp);
		return 0; }

	PERFORMANCE_LOG_START;
	q.Init(db);
	PERFORMANCE_LOG_STOP("fetching dictIDs from database");

	dbHelp.DestroyConnection();
	free(qp);
	return 0;
}

}
