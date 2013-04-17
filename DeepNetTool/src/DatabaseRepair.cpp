/*
 * DatabaseRepair.cpp
 *
 *  Created on: 03.12.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseRepair.h"

#include <TimeTools.h>

#include <DatabaseLayer.h>
#include <WhereConditionTableColumnCreateParam.h>

namespace toolbot {

DatabaseRepair::DatabaseRepair() {
}

DatabaseRepair::~DatabaseRepair() {
}

bool DatabaseRepair::FixUncleanShutdown(database::DatabaseConnection* db) {

	if(!FixSyncUrlTable(db))
		return false;

	if(!FixSecondLevelLockTable(db))
		return false;

	if(!FixCrawlerSessionTable(db))
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
