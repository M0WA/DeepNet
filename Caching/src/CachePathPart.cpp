/**
 *
 * @file CachePathPart.cpp
 * @author Moritz Wagner
 * @date 05.08.2013
 *
 */

#include "CachePathPart.h"

#include <DatabaseLayer.h>
#include <DatabaseException.h>

namespace caching {

CachePathPart CachePathPart::cacheInstance;

CachePathPart::CachePathPart(size_t limit)
: idPathPart(limit,false) {
}

CachePathPart::~CachePathPart() {
}

long long CachePathPart::GetIDByPathPart(database::DatabaseConnection* db,const std::string& pathPart) {

	long long pathPartID(-1);
	bool isInCache(cacheInstance.idPathPart.GetByValue(pathPart,pathPartID));
	isInCache &= (pathPartID != -1);
	if(isInCache)
		return pathPartID;

	database::pathpartsTableBase pathPartTbl;
	pathPartTbl.Set_path(pathPart);

	try {
		pathPartTbl.InsertOrUpdate(db);
		db->LastInsertID(pathPartID);
	}
	catch(database::DatabaseException& e) {
		//
		//TODO: throw exception
		//
		e.DisableLogging();
		e.Log();
		log::Logging::LogError("exception while getting path part: %s",pathPart.c_str());
		return -1;
	}

	cacheInstance.idPathPart.AddItem(pathPartID,pathPart);
	return pathPartID;
}

std::string CachePathPart::GetPathPartByID(database::DatabaseConnection* db, const long long pathPartID) {

	std::string pathPart;
	bool isInCache(cacheInstance.idPathPart.GetItem(pathPartID,pathPart));
	if(isInCache)
		return pathPart;

	database::SelectResultContainer<database::pathpartsTableBase> pathPartTbl;
	database::pathpartsTableBase::GetBy_ID(db,pathPartID,pathPartTbl);

	if(pathPartTbl.Size() != 1) {
		//
		//TODO: throw exception
		//
		log::Logging::LogError("");
		return ""; }

	pathPartTbl.ResetIter();
	pathPartTbl.GetIter()->Get_path(pathPart);

	cacheInstance.idPathPart.AddItem(pathPartID,pathPart);
	return pathPart;
}

}
