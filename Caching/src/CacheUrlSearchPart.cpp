/**
 *
 * @file CacheUrlSearchPart.cpp
 * @author Moritz Wagner
 * @date 06.08.2013
 *
 */

#include "CacheUrlSearchPart.h"

#include <sstream>

#include <HashTools.h>
#include <DatabaseLayer.h>

#include <DatabaseException.h>
#include "URLInvalidUrlSearchPartIDException.h"

namespace caching {

CacheUrlSearchPart CacheUrlSearchPart::cacheInstance;

CacheUrlSearchPart::CacheUrlSearchPart(size_t limit)
: idUrlSearchPart(limit, false) {
}

CacheUrlSearchPart::~CacheUrlSearchPart() {
}

void CacheUrlSearchPart::SetCapacity(const size_t capacity) {
	cacheInstance.idUrlSearchPart.SetLimit(capacity);
}

void CacheUrlSearchPart::Clear(void) {
	cacheInstance.idUrlSearchPart.ClearItems();
}

void CacheUrlSearchPart::GetUrlSearchPartByID(
	database::DatabaseConnection* db,
	const long long& urlSearchPartID,
	std::string& searchPart) {

	bool isInCache(cacheInstance.idUrlSearchPart.GetItem(urlSearchPartID,searchPart));
	if(isInCache)
		return;

	database::SelectResultContainer<database::urlsearchpartsTableBase> results;
	try {
		database::urlsearchpartsTableBase::GetBy_ID(db,urlSearchPartID,results);
	}
	catch(database::DatabaseException& e) {
		e.DisableLogging();
		std::stringstream ss;
		ss << "exception while getting url search part: " << searchPart << std::endl
		   << "original exception: " << std::endl << e.Dump();
		THROW_EXCEPTION(URLInvalidUrlSearchPartIDException, ss.str());
		return;
	}

	if(results.Size() != 1) {
		std::stringstream ss;
		ss << "invalid result size while getting url search part: " << searchPart << std::endl;
		THROW_EXCEPTION(URLInvalidUrlSearchPartIDException, ss.str());
		return;
	}

	results.ResetIter();
	results.GetIter()->Get_searchpart(searchPart);

	cacheInstance.idUrlSearchPart.AddItem(urlSearchPartID,searchPart);
}

void CacheUrlSearchPart::GetIDByUrlSearchPart(
	database::DatabaseConnection* db,
	const std::string& urlSearchPart,
	long long& urlSearchPartID) {

	bool isInCache(cacheInstance.idUrlSearchPart.GetByValue(urlSearchPart,urlSearchPartID));
	if(isInCache)
		return;

	database::urlsearchpartsTableBase tblInsert;
	tblInsert.Set_searchpart(urlSearchPart);
	tblInsert.Set_md5(tools::HashTools::GetMD5(urlSearchPart));

	try {
		tblInsert.InsertOrUpdate(db);
		db->LastInsertID(urlSearchPartID);
	}
	catch(database::DatabaseException& e) {
		e.DisableLogging();
		std::stringstream ss;
		ss << "exception while inserting url search part: " << urlSearchPart << std::endl
		   << "original exception: " << std::endl << e.Dump();
		THROW_EXCEPTION(URLInvalidUrlSearchPartIDException, ss.str());
		return;
	}

	if(urlSearchPartID == -1) {
		std::stringstream ss;
		ss << "invalid id while inserting url search part: " << urlSearchPart << std::endl;
		THROW_EXCEPTION(URLInvalidUrlSearchPartIDException, ss.str());
	}
}


}
