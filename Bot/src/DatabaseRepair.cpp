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

bool DatabaseRepair::ValidateCrawlerSessionTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs) {

	std::vector<database::WhereConditionTableColumn*> where;

	if(oldCrawlerSessionIDs.size() == 0) {
		database::crawlersessionsTableBase::GetWhereColumnsFor_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::NotEquals(),
				database::WhereCondition::InitialComp()	),
			0,
			where );
	}
	else {
		database::crawlersessionsTableBase::GetWhereColumnsFor_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::InitialComp()	),
			oldCrawlerSessionIDs,
			where );
	}

	database::SelectStatement selectCrawlerSessionStmt(database::crawlersessionsTableBase::CreateTableDefinition());
	selectCrawlerSessionStmt.SelectAddCountColumn(database::crawlersessionsTableBase::GetDefinition_ID(),"","crawlerSessionCount");
	selectCrawlerSessionStmt.Where().AddColumns(where);

	database::SelectResultContainer<database::TableBase> resultCrawlerSession;
	db->Select(selectCrawlerSessionStmt,resultCrawlerSession);

	if(resultCrawlerSession.Size() == 0) {
		log::Logging::LogError("error while selecting count for crawler sessions");
		return false; }

	resultCrawlerSession.ResetIter();
	for(;!resultCrawlerSession.IsIterEnd();resultCrawlerSession.Next())
	{
		const database::TableBase* resultCrawlerSessionTbl = resultCrawlerSession.GetIter();
		const database::TableColumn* crawlerSession = resultCrawlerSessionTbl->GetConstColumnByName(std::string("crawlerSessionCount"));
		if(!crawlerSession) {
			log::Logging::LogError("error while getting count for crawler sessions");
			return false;}

		long long crawlerSessionCount = -1;
		crawlerSession->Get(crawlerSessionCount);

		if(crawlerSessionCount > 0) {
			log::Logging::LogError("error, count for crawler sessions is not 0");
			return false; }
	}

	log::Logging::LogTrace("CrawlerSessionTable was already in a clean state, nothing to be done here");
	return true;
}

bool DatabaseRepair::ValidateSecondLevelLockTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs) {

	std::vector<database::WhereConditionTableColumn*> where;

	if(oldCrawlerSessionIDs.size() == 0) {
		database::locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::NotEquals(),
				database::WhereCondition::InitialComp()	),
			0,
			where );
	}
	else {
		database::locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::InitialComp()	),
			oldCrawlerSessionIDs,
			where );
	}

	database::SelectStatement selectSndLockStmt(database::locksecondleveldomainTableBase::CreateTableDefinition());
	selectSndLockStmt.SelectAddCountColumn(database::locksecondleveldomainTableBase::GetDefinition_CRAWLERSESSION_ID(),"","lockedUrlCount");
	selectSndLockStmt.Where().AddColumns(where);

	database::SelectResultContainer<database::TableBase> resultSndLock;
	db->Select(selectSndLockStmt,resultSndLock);

	if(resultSndLock.Size() == 0) {
		log::Logging::LogError("error while selecting count for locked second level domains");
		return false; }

	resultSndLock.ResetIter();
	for(;!resultSndLock.IsIterEnd();resultSndLock.Next())
	{
		const database::TableBase* resultSndTbl = resultSndLock.GetIter();
		const database::TableColumn* lockedUrl = resultSndTbl->GetConstColumnByName(std::string("lockedUrlCount"));
		if(!lockedUrl) {
			log::Logging::LogError("error while getting count for locked second level domains");
			return false;}

		long long lockedUrlCount = -1;
		lockedUrl->Get(lockedUrlCount);

		if(lockedUrlCount > 0) {
			log::Logging::LogError("error, count for locked second level domains is %ll, should be 0",lockedUrlCount);
			return false; }
	}

	log::Logging::LogTrace("SyncSecondLevelTable was already in a clean state, nothing to be done here");
	return true;
}

bool DatabaseRepair::ValidateSyncUrlTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs) {

	std::vector<database::WhereConditionTableColumn*> where;

	if(oldCrawlerSessionIDs.size() == 0) {
		database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::NotEquals(),
				database::WhereCondition::InitialComp()	),
			0,
			where );
	}
	else {
		database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::InitialComp()	),
			oldCrawlerSessionIDs,
			where );
	}

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
			log::Logging::LogError("count for reserved urls is %ll, should be 0",reservedUrlCount);
			return false; }
	}

	log::Logging::LogTrace("SyncUrlTable was already in a clean state, nothing to be done here");
	return true;
}

bool DatabaseRepair::ValidateSyncTables(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs) {

	if(oldCrawlerSessionIDs.size() == 0) {
		log::Logging::LogWarn("validating all sync tables, please ensure that no other instance is using the database"); }

	bool success = true;
	success &= ValidateSyncUrlTable(db,oldCrawlerSessionIDs);
	success &= ValidateSecondLevelLockTable(db,oldCrawlerSessionIDs);
	success &= ValidateCrawlerSessionTable(db,oldCrawlerSessionIDs);
	return success;
}

bool DatabaseRepair::FixUncleanShutdown(database::DatabaseConnection* db, const bool validateBeforeFix, const std::vector<long long>& oldCrawlerSessionIDs) {

	if(oldCrawlerSessionIDs.size() == 0) {
		log::Logging::LogWarn("cleaning all sync tables, please ensure that no other instance is using the database"); }

	bool isValidated = validateBeforeFix && ValidateSyncUrlTable(db,oldCrawlerSessionIDs);
	if( !isValidated && !FixSyncUrlTable(db,oldCrawlerSessionIDs))
		return false;

	isValidated = validateBeforeFix && ValidateSecondLevelLockTable(db,oldCrawlerSessionIDs);
	if(!isValidated && !FixSecondLevelLockTable(db,oldCrawlerSessionIDs))
		return false;

	isValidated = validateBeforeFix && ValidateCrawlerSessionTable(db,oldCrawlerSessionIDs);
	if(!isValidated && !FixCrawlerSessionTable(db,oldCrawlerSessionIDs))
		return false;

	return true;
}

bool DatabaseRepair::FixSyncUrlTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs) {

	database::syncurlsTableBase syncUrlTbl;
	syncUrlTbl.Set_CRAWLERSESSION_ID(0);
	syncUrlTbl.Set_schedule(tools::TimeTools::NowUTC());

	std::vector<database::WhereConditionTableColumn*> whereCols;
	if(oldCrawlerSessionIDs.size() == 0) {
		database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(), database::WhereCondition::InitialComp()),
			0,
			whereCols );
	}
	else {
		database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::InitialComp()),
			oldCrawlerSessionIDs,
			whereCols );
	}

	database::UpdateStatement updSyncUrl(
		&syncUrlTbl,
		whereCols,
		std::vector<database::OrderByColumn>(),
		true);

	db->Update(updSyncUrl);
	return true;
}

bool DatabaseRepair::FixSecondLevelLockTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs) {

	database::locksecondleveldomainTableBase lockSndDomainTbl;
	lockSndDomainTbl.Set_CRAWLERSESSION_ID(0);
	lockSndDomainTbl.Set_schedule(tools::TimeTools::NowUTC());

	std::vector<database::WhereConditionTableColumn*> whereCols;
	if(oldCrawlerSessionIDs.size() == 0) {
		database::locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(), database::WhereCondition::InitialComp()),
			0,
			whereCols );
	}
	else {
		database::locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::InitialComp()),
			oldCrawlerSessionIDs,
			whereCols );
	}

	database::UpdateStatement updLockSndDomain(
		&lockSndDomainTbl,
		whereCols,
		std::vector<database::OrderByColumn>(),
		true);

	db->Update(updLockSndDomain);
	return true;
}

bool DatabaseRepair::FixCrawlerSessionTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs) {

	std::vector<database::WhereConditionTableColumn*> whereCols;
	if(oldCrawlerSessionIDs.size() != 0) {
		database::crawlersessionsTableBase::GetWhereColumnsFor_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::InitialComp()),
			oldCrawlerSessionIDs,
			whereCols );
	}

	database::DeleteStatement delCrawlSess(database::crawlersessionsTableBase::CreateTableDefinition());
	if(whereCols.size() > 0) {
		delCrawlSess.Where().AddColumns(whereCols);	}
	db->Delete(delCrawlSess);
	return true;
}

}
