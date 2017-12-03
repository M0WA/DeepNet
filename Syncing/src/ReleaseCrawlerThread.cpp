/*
 * @file ReleaseCrawlerThread.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "ReleaseCrawlerThread.h"

#include "Sync.h"

#include <PerformanceCounter.h>
#include <DatabaseHelper.h>
#include <DatabaseLayer.h>
#include <TableDefinition.h>
#include <TableColumn.h>
#include <TableBase.h>
#include <OrderByClauseDirection.h>

#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

namespace syncing {

ReleaseCrawlerThread::ReleaseCrawlerThread()
: threading::Thread(ReleaseCrawlerThreadFunc,false) {
}

ReleaseCrawlerThread::~ReleaseCrawlerThread() {
}

void* ReleaseCrawlerThread::ReleaseCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param) {

	log::Logging::RegisterThreadID("ReleaseCrawlerThread");

	ReleaseCrawlerThreadParam* p(reinterpret_cast<ReleaseCrawlerThreadParam*>(param->pParam));

	database::DatabaseHelper helper;
	database::DatabaseConnection* db(helper.CreateConnection(p->dbConf));

	PERFORMANCE_LOG_START;
	Sync::UnlockSecondLevelDomain(db,p->crawlerID,-1);

	database::TableDefinition* tblDef(database::crawlersessionsTableBase::CreateTableDefinition());
	database::DeleteStatement del(tblDef);

	std::vector<database::WhereConditionTableColumn*> where;
	database::crawlersessionsTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::InitialComp()),
		p->crawlerID,
		where
	);
	del.Where().AddColumns(where);
	db->Delete(del);

	delete tblDef;

	long long aff(0);
	db->AffectedRows(aff);
	if(aff <= 0) {
		return (void*)1; }

	PERFORMANCE_LOG_STOP("ReleaseCrawler overall");

	delete p;
	return NULL;
}

}
