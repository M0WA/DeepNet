/**
 *
 * @file CachePathPart.cpp
 * @author Moritz Wagner
 * @date 05.08.2013
 *
 */

#include "CachePathPart.h"

#include <sstream>

#include "URLInvalidPathPartIDException.h"

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
		e.DisableLogging();
		std::stringstream ss;
		ss << "exception while getting path part: " << pathPart << std::endl
		   << "original exception: " << std::endl << e.Dump();
		THROW_EXCEPTION(URLInvalidPathPartIDException, ss.str() );
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

	try {
		database::pathpartsTableBase::GetBy_ID(db,pathPartID,pathPartTbl);
	}
	catch(database::DatabaseException& e) {
		e.DisableLogging();
		std::stringstream ss;
		ss << "exception while getting path part  for pathpart ID: " << pathPartID << std::endl
		   << "original exception:"  << std::endl << e.Dump();
		THROW_EXCEPTION(URLInvalidPathPartIDException,ss.str());
		return "";
	}

	if(pathPartTbl.Size() != 1) {
		std::stringstream ss;
		ss << "exception while getting path part for pathpart ID: " << pathPartID;
		THROW_EXCEPTION(URLInvalidPathPartIDException, ss.str());
		return "";
	}

	pathPartTbl.ResetIter();
	pathPartTbl.GetIter()->Get_path(pathPart);

	cacheInstance.idPathPart.AddItem(pathPartID,pathPart);
	return pathPart;
}

}
