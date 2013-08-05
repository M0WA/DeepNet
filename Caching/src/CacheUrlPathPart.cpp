/**
 *
 * @file CacheUrlPathPart.cpp
 * @author Moritz Wagner
 * @date 03.08.2013
 *
 */

#include "CacheUrlPathPart.h"

#include "CachePathPart.h"

#include <vector>

#include <StringTools.h>
#include <ContainerTools.h>
#include <Logging.h>

#include <DatabaseLayer.h>
#include <TableColumn.h>
#include <WhereCondition.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <DatabaseException.h>

namespace caching {

CacheUrlPathPart CacheUrlPathPart::cacheInstance;

CacheUrlPathPart::CacheUrlPathPart(size_t limit)
: idUrlPathPart(limit, false) {
}

CacheUrlPathPart::~CacheUrlPathPart() {
}

void CacheUrlPathPart::SetCapacity(const size_t capacity)
{
	cacheInstance.idUrlPathPart.SetLimit(capacity);
}

void CacheUrlPathPart::Clear(void)
{
	cacheInstance.idUrlPathPart.ClearItems();
}

long long CacheUrlPathPart::GetIDByUrlPathPart(database::DatabaseConnection* db,const std::string& pathPart) {

/*
 * example statement:
SELECT
  t0.id
FROM deepnet.public.urlpathparts t0
INNER JOIN deepnet.public.urlpathparts t1
  ON  t1.id=t0.urlpathpart_id_next
WHERE
  ( t0.pathpart_id = 1 )
AND
  ( t1.pathpart_id = 2 )
*/

	if(pathPart.empty()) {
		//
		//TODO: throw exception
		//
		log::Logging::LogError("empty path part received");
		return -1; }

	std::vector<std::string> parts;
	tools::StringTools::SplitBy(pathPart, "/", parts);

	if(parts.size()==0) {
		//
		//TODO: throw exception
		//
		log::Logging::LogError("empty path part received");
		return -1; }

	//fetch all path part ids
	std::vector<long long> pathPartIDs;
	std::vector<std::string>::const_iterator iPathParts(parts.begin());
	for(;iPathParts!=parts.end();++iPathParts) {
		long long pathPartID(CachePathPart::GetIDByPathPart(db,*iPathParts));
		if(pathPartID == -1) {
			//
			//TODO: throw exception
			//
			log::Logging::LogError("invalid path part: %s",iPathParts->c_str());
			return -1; }
		pathPartIDs.push_back(pathPartID);
	}

	database::SelectStatement selectUrlPathPart(
		database::urlpathpartsTableBase::CreateTableDefinition(),"t0" );

	std::vector<database::WhereConditionTableColumn*> where;
	selectUrlPathPart.SelectAddColumn(database::urlpathpartsTableBase::GetDefinition_ID(),"t0","");

	std::vector<long long>::const_iterator i(pathPartIDs.begin());
	if(*i == -1) {
		//
		//TODO: throw exception
		//
		log::Logging::LogError("invalid path part: %s",parts.at(0).c_str());
		return -1; }
	else {
		std::string dumpPath;
		tools::ContainerTools::DumpVector(parts,dumpPath);
		log::Logging::LogTrace("splitted path parts:\n%s",dumpPath.c_str());
	}

	database::WhereConditionTableColumnCreateParam pathPartCreateParamBegin(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp());
	pathPartCreateParamBegin.tableNameAlias = "t0";

	database::urlpathpartsTableBase::GetWhereColumnsFor_PATHPART_ID(
		pathPartCreateParamBegin,
		*i,
		where);
	std::advance(i,1);

	for(size_t pos=1;i!=pathPartIDs.end();++i,++pos) {

		std::string joinTableAlias,referencedTableAlias, joinPathPartAlias, referencedPathPartAlias;
		tools::StringTools::FormatString(referencedTableAlias,"t%ld",pos);
		tools::StringTools::FormatString(joinTableAlias,"t%ld",pos-1);

		database::urlpathpartsTableBase::AddInnerJoinRightSideOn_URLPATHPART_ID_NEXT(
			joinTableAlias,	"",
			referencedTableAlias, "",
			selectUrlPathPart );

		database::WhereConditionTableColumnCreateParam createParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::And());
		createParam.tableNameAlias = referencedTableAlias;

		database::urlpathpartsTableBase::GetWhereColumnsFor_PATHPART_ID(
			createParam,
			*i,
			where);
	}

	selectUrlPathPart.Where().AddColumns(where);

	database::SelectResultContainer<database::TableBase> results;
	try{
		db->Select(selectUrlPathPart,results);
	}
	catch(database::DatabaseException& e) {
		//
		//TODO: throw exception
		//
		e.DisableLogging();
		log::Logging::LogError("exception while getting url path part: %s\n%s",pathPart.c_str(),e.Dump().c_str());
		return -1;
	}

	if(results.Size()>1) {
		//
		//TODO: throw exception
		//
		log::Logging::LogError("too many results while getting url path part: %s",pathPart.c_str());
		return -1; }

	if(results.Size()==1) {
		results.ResetIter();
		return results.GetIter()->GetConstColumnByName("ID")->Get<long long>();
	}
	else {
		return InsertUrlPathPart(db,pathPartIDs);
	}
}

long long CacheUrlPathPart::InsertUrlPathPart(database::DatabaseConnection* db, std::vector<long long>& pathPartIDs) {

	long long urlPathPartID(-1);

	db->TransactionStart();

	std::vector<long long>::const_reverse_iterator i(pathPartIDs.rbegin());
	for(;i!=pathPartIDs.rend();++i) {
		database::urlpathpartsTableBase urlPathPartTbl;

		urlPathPartTbl.Set_PATHPART_ID(*i);
		if(urlPathPartID==-1) {
			urlPathPartTbl.GetColumn_URLPATHPART_ID_NEXT()->SetNull(); }
		else {
			urlPathPartTbl.Set_URLPATHPART_ID_NEXT(urlPathPartID); }

		try {
			urlPathPartTbl.InsertOrUpdate(db);
			db->LastInsertID(urlPathPartID);
		}
		catch(database::DatabaseException& e) {
			db->TransactionRollback();
			//
			//TODO: throw exception
			//
			log::Logging::LogError("error while inserting url path part");
			return -1;
		}
	}

	db->TransactionCommit();
	return urlPathPartID;
}

std::string CacheUrlPathPart::GetUrlPathPartByID(database::DatabaseConnection* db,const long long& urlPathPartID) {

	std::vector<std::string> pathParts;
	long long nextUrlPathPartID(urlPathPartID);
	do {
		database::SelectResultContainer<database::urlpathpartsTableBase> urlpathpartTbl;
		database::urlpathpartsTableBase::GetBy_ID(db,nextUrlPathPartID,urlpathpartTbl);

		if(urlpathpartTbl.Size() != 1) {
			//
			//TODO: throw exception
			//
			log::Logging::LogError("");
			return ""; }

		urlpathpartTbl.ResetIter();
		long long pathPartID(-1);
		urlpathpartTbl.GetIter()->Get_PATHPART_ID(pathPartID);

		std::string pathPart(CachePathPart::GetPathPartByID(db,pathPartID));
		pathParts.push_back(pathPart);

		const database::TableColumn* nextID(urlpathpartTbl.GetIter()->GetConstColumn_URLPATHPART_ID_NEXT());
		if(nextID->IsNull())
			nextUrlPathPartID = -1;
		else
			nextID->Get(nextUrlPathPartID);

	} while(nextUrlPathPartID != -1);

	std::string combinedPath;
	tools::StringTools::VectorToString(pathParts,combinedPath,"/");
	return combinedPath;
}

}
