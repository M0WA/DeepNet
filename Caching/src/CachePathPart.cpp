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

#include <HashTools.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>

namespace caching {

CachePathPart CachePathPart::cacheInstance;

CachePathPart::CachePathPart(size_t limit)
: idPathPart(limit,false) {
}

CachePathPart::~CachePathPart() {
}

void CachePathPart::SetCapacity(const size_t capacity)
{
	cacheInstance.idPathPart.SetLimit(capacity);
}

void CachePathPart::Clear(void)
{
	cacheInstance.idPathPart.ClearItems();
}

void CachePathPart::GetIDByPathPart(database::DatabaseConnection* db,const std::string& pathPart,long long& pathPartID) {

	pathPartID = -1;
	bool isInCache(cacheInstance.idPathPart.GetByValue(pathPart,pathPartID));
	isInCache &= (pathPartID != -1);
	if(isInCache)
		return;

	database::pathpartsTableBase pathPartTbl;
	pathPartTbl.Set_path(pathPart);
	pathPartTbl.Set_md5(tools::HashTools::GetMD5(pathPart));
	try {
		pathPartTbl.InsertOrUpdate(db);
		db->LastInsertID(pathPartID);
	}
	CATCH_EXCEPTION(database::DatabaseException,e,0)
		std::stringstream ss;
		ss << "exception while getting path part: " << pathPart << std::endl
		   << "original exception: " << std::endl << e.Dump();
		THROW_EXCEPTION(URLInvalidPathPartIDException, ss.str());
		return;
	}

	cacheInstance.idPathPart.AddItem(pathPartID,pathPart);

	if(pathPartID == -1) {
		std::stringstream ss;
		ss << "exception while getting path part: " << pathPart << std::endl;
		THROW_EXCEPTION(URLInvalidPathPartIDException, ss.str());
		return;
	}
}

void CachePathPart::GetPathPartByID(database::DatabaseConnection* db, const long long pathPartID,std::string& pathPart) {

	bool isInCache(cacheInstance.idPathPart.GetItem(pathPartID,pathPart));
	if(isInCache)
		return;

	database::SelectResultContainer<database::pathpartsTableBase> pathPartTbl;

	try {
		database::pathpartsTableBase::GetBy_ID(db,pathPartID,pathPartTbl);
	}
	CATCH_EXCEPTION(database::DatabaseException,e,0)
		std::stringstream ss;
		ss << "exception while getting path part  for pathpart ID: " << pathPartID << std::endl
		   << "original exception:"  << std::endl << e.Dump();
		THROW_EXCEPTION(URLInvalidPathPartIDException,ss.str());
		return;
	}

	if(pathPartTbl.Size() != 1) {
		std::stringstream ss;
		ss << "exception while getting path part for pathpart ID: " << pathPartID;
		THROW_EXCEPTION(URLInvalidPathPartIDException, ss.str());
		return;
	}

	pathPartTbl.ResetIter();
	pathPartTbl.GetIter()->Get_path(pathPart);
	cacheInstance.idPathPart.AddItem(pathPartID,pathPart);
	return;
}

}
