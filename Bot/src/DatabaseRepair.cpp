/**
 *
 * @file DatabaseRepair.cpp
 * @author Moritz Wagner
 * @date 02.07.2013
 *
 */

#include "DatabaseRepair.h"

#include <TimeTools.h>
#include <Logging.h>

#include <DatabaseLayer.h>
#include <TableBase.h>
#include <TableColumn.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

namespace bot {

DatabaseRepair::DatabaseRepair() {
}

DatabaseRepair::~DatabaseRepair() {
}

bool DatabaseRepair::ValidateSecondLevelLockTable(database::DatabaseConnection* db) {
	return false;
}

bool DatabaseRepair::ValidateCrawlerSessionTable(database::DatabaseConnection* db) {
	return false;
}

bool DatabaseRepair::ValidateSyncUrlTable(database::DatabaseConnection* db) {

	std::vector<database::WhereConditionTableColumn*> where;
	database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::NotEquals(),
			database::WhereCondition::InitialComp()	),
		0,
		where );

	database::SelectStatement selectSyncUrlStmt(database::syncurlsTableBase::CreateTableDefinition());
	selectSyncUrlStmt.SelectAddCountColumn(database::syncurlsTableBase::GetDefinition_CRAWLERSESSION_ID(),"","reservedUrlCount");
	selectSyncUrlStmt.Where().AddColumns(where);

	database::SelectResultContainer<database::TableBase> result;
	db->Select(selectSyncUrlStmt,result);

	if(result.Size() == 0) {
		log::Logging::LogError("error while selecting count for reserved urls");
		return false; }

	result.ResetIter();
	for(;!result.IsIterEnd();result.Next())
	{
		const database::TableBase* resultTbl = result.GetIter();
		const database::TableColumn* reservedCount = resultTbl->GetConstColumnByName(std::string("reservedUrlCount"));
		if(!reservedCount) {
			log::Logging::LogError("error while getting count for reserved urls");
			return false;}

		long long reservedUrlCount = -1;
		reservedCount->Get(reservedUrlCount);

		if(reservedUrlCount > 0) {
			log::Logging::LogError("error, count for reserved urls is not 0");
			return false; }
	}

	log::Logging::LogInfo("SyncUrlTable was already in a clean state, nothing to be done here");
	return true;
}

bool DatabaseRepair::ValidateSyncTables(database::DatabaseConnection* db) {
	bool success = true;
	success &= ValidateSyncUrlTable(db);
	success &= ValidateSecondLevelLockTable(db);
	success &= ValidateCrawlerSessionTable(db);
	return success;
}

bool DatabaseRepair::FixUncleanShutdown(database::DatabaseConnection* db) {

	if(!ValidateSyncUrlTable(db) && !FixSyncUrlTable(db))
		return false;

	if(!ValidateSecondLevelLockTable(db) && !FixSecondLevelLockTable(db))
		return false;

	if(!ValidateCrawlerSessionTable(db) && !FixCrawlerSessionTable(db))
		return false;

	return true;
}

bool DatabaseRepair::FixSyncUrlTable(database::DatabaseConnection* db) {

	database::syncurlsTableBase syncUrlTbl;
	syncUrlTbl.Set_CRAWLERSESSION_ID(0);
	syncUrlTbl.Set_schedule(tools::TimeTools::NowUTC());

	std::vector<database::WhereConditionTableColumn*> whereCols;
	database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(), database::WhereCondition::InitialComp()),
		0,
		whereCols );

	database::UpdateStatement updSyncUrl(
		&syncUrlTbl,
		whereCols,
		std::vector<database::OrderByColumn>(),
		true);

	db->Update(updSyncUrl);
	return true;
}

bool DatabaseRepair::FixSecondLevelLockTable(database::DatabaseConnection* db) {

	database::locksecondleveldomainTableBase lockSndDomainTbl;
	lockSndDomainTbl.Set_CRAWLERSESSION_ID(0);
	lockSndDomainTbl.Set_schedule(tools::TimeTools::NowUTC());

	std::vector<database::WhereConditionTableColumn*> whereCols;
	database::locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(), database::WhereCondition::InitialComp()),
		0,
		whereCols );

	database::UpdateStatement updLockSndDomain(
		&lockSndDomainTbl,
		whereCols,
		std::vector<database::OrderByColumn>(),
		true);

	db->Update(updLockSndDomain);
	return true;
}

bool DatabaseRepair::FixCrawlerSessionTable(database::DatabaseConnection* db) {

	database::DeleteStatement delCrawlSess(database::crawlersessionsTableBase::CreateTableDefinition());
	db->Delete(delCrawlSess);
	return true;
}

}
