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

#include "URLInvalidUrlPathPartIDException.h"
#include <DatabaseException.h>

namespace caching {

CacheUrlPathPart CacheUrlPathPart::cacheInstance;

CacheUrlPathPart::CacheUrlPathPart(size_t limit)
: idUrlPathPart(limit, false)
, endUrlPathID(-1){
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

void CacheUrlPathPart::Init(database::DatabaseConnection* db) {

	long long endMarkerID(-1);
	CachePathPart::GetIDByPathPart(db,"__SPECIAL_DEEPNET_PATH_PART_END_MARKER__",endMarkerID);
	if(endMarkerID==-1) {
		THROW_EXCEPTION(URLInvalidUrlPathPartIDException, "could not find end marker for url path parts");
		return;
	}

	database::SelectResultContainer<database::urlpathpartsTableBase> results;
	database::urlpathpartsTableBase::GetBy_PATHPART_ID(db,endMarkerID,results);

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {
		long long tmp1(-1),tmp2(-1);
		results.GetIter()->Get_ID(tmp1);
		results.GetIter()->Get_URLPATHPART_ID_NEXT(tmp2);
		if(tmp1 == tmp2 && tmp1 != -1) {
			cacheInstance.endUrlPathID = tmp1;
			break; }
	}

	if(cacheInstance.endUrlPathID == -1) {
		THROW_EXCEPTION(URLInvalidUrlPathPartIDException, "could not find end url path part id for url path parts");
		return;
	}
}

void CacheUrlPathPart::GetIDByUrlPathPart(database::DatabaseConnection* db,const std::string& pathPart, long long& urlPathPartID) {

	bool isInCache(cacheInstance.idUrlPathPart.GetByValue(pathPart,urlPathPartID));
	isInCache &= (urlPathPartID != -1);
	if(isInCache) {
		return;}

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

	std::vector<std::string> parts;
	tools::StringTools::SplitBy(pathPart, "/", parts);

	if(parts.size()==0) {
		parts.push_back(""); }

	//fetch all path part ids
	std::vector<long long> pathPartIDs;
	std::vector<std::string>::const_iterator iPathParts(parts.begin());
	for(;iPathParts!=parts.end();++iPathParts) {
		long long pathPartID(-1);
		CachePathPart::GetIDByPathPart(db,*iPathParts,pathPartID);
		pathPartIDs.push_back(pathPartID);
	}

	database::SelectStatement selectUrlPathPart(
		database::urlpathpartsTableBase::CreateTableDefinition(),"t0" );

	std::vector<database::WhereConditionTableColumn*> where;
	selectUrlPathPart.SelectAddColumn(database::urlpathpartsTableBase::GetDefinition_ID(),"t0","");

	std::vector<long long>::const_iterator iPathPartIDs(pathPartIDs.begin());

	std::string lastTableAlias("t0");
	database::WhereConditionTableColumnCreateParam pathPartCreateParamBegin(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp());
	pathPartCreateParamBegin.tableNameAlias = "t0";

	database::urlpathpartsTableBase::GetWhereColumnsFor_PATHPART_ID(
		pathPartCreateParamBegin,
		*iPathPartIDs,
		where);

	std::advance(iPathPartIDs,1);
	for(size_t pos=1;iPathPartIDs!=pathPartIDs.end();++iPathPartIDs,++pos) {

		std::string joinTableAlias,referencedTableAlias, joinPathPartAlias, referencedPathPartAlias;
		tools::StringTools::FormatString(referencedTableAlias,"t%ld",pos);
		tools::StringTools::FormatString(joinTableAlias,"t%ld",pos-1);
		lastTableAlias = referencedTableAlias;

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
			*iPathPartIDs,
			where);
	}

	database::WhereConditionTableColumnCreateParam nextEndWhereParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::And());
	nextEndWhereParam.tableNameAlias = lastTableAlias;
	database::urlpathpartsTableBase::GetWhereColumnsFor_URLPATHPART_ID_NEXT(
		nextEndWhereParam,
		cacheInstance.endUrlPathID,
		where);

	selectUrlPathPart.Where().AddColumns(where);

	database::SelectResultContainer<database::TableBase> results;
	try{
		db->Select(selectUrlPathPart,results);
	}
	catch(database::DatabaseException& e) {
		e.DisableLogging();
		std::stringstream ss;
		ss << "exception while getting url path part: " << pathPart << std::endl
		   << "original exception: " << std::endl << e.Dump();
		THROW_EXCEPTION(URLInvalidUrlPathPartIDException, ss.str());
		return;
	}

	if(results.Size()>1) {
		std::stringstream ss;
		ss << "too many results while getting url path part: " << pathPart << std::endl;
		THROW_EXCEPTION(URLInvalidUrlPathPartIDException, ss.str());
		return; }

	if(results.Size()==1) {
		results.ResetIter();
		urlPathPartID = results.GetIter()->GetConstColumnByName("ID")->Get<long long>();
	}
	else {
		InsertUrlPathPart(db,pathPartIDs,urlPathPartID);
	}

	if(urlPathPartID != -1) {
		cacheInstance.idUrlPathPart.AddItem(urlPathPartID,pathPart);
	}
	else {
		std::stringstream ss;
		ss << "invalid url path part id (-1) for path part: " << pathPart << std::endl;
		THROW_EXCEPTION(URLInvalidUrlPathPartIDException, ss.str());
	}
}

void CacheUrlPathPart::InsertUrlPathPart(database::DatabaseConnection* db, std::vector<long long>& pathPartIDs,long long& urlPathPartID) {

	urlPathPartID = cacheInstance.endUrlPathID;

	db->TransactionStart();

	std::vector<long long>::const_reverse_iterator i(pathPartIDs.rbegin());
	for(;i!=pathPartIDs.rend();++i) {
		database::urlpathpartsTableBase urlPathPartTbl;

		urlPathPartTbl.Set_PATHPART_ID(*i);
		urlPathPartTbl.Set_URLPATHPART_ID_NEXT(urlPathPartID);

		try {
			urlPathPartTbl.InsertOrUpdate(db);
			db->LastInsertID(urlPathPartID);
		}
		catch(database::DatabaseException& e) {
			db->TransactionRollback();

			e.DisableLogging();
			std::stringstream ss;
			ss << "exception while inserting url path part ID: " << *i << " next url path part id: " << urlPathPartID << std::endl
			   << "original exception: " << std::endl << e.Dump();
			THROW_EXCEPTION(URLInvalidUrlPathPartIDException, ss.str());
			return;
		}

		if(urlPathPartID == -1) {
			db->TransactionRollback();
			std::stringstream ss;
			ss << "invalid id while inserting url path part: "<< std::endl
			   << "path part id: " << *i << std::endl
			   << "next url path part id: -1" << std::endl;
			THROW_EXCEPTION(URLInvalidUrlPathPartIDException, ss.str());
			return;
		}
	}

	db->TransactionCommit();
	return;
}

void CacheUrlPathPart::GetUrlPathPartByID(database::DatabaseConnection* db,const long long& urlPathPartID, std::string& pathPart) {

	std::vector<std::string> pathParts;
	long long nextUrlPathPartID(urlPathPartID);
	do {
		database::SelectResultContainer<database::urlpathpartsTableBase> urlpathpartTbl;

		try {
			database::urlpathpartsTableBase::GetBy_ID(db,nextUrlPathPartID,urlpathpartTbl);
		}
		catch(database::DatabaseException& e) {
			e.DisableLogging();
			std::stringstream ss;
			ss << "exception while getting url path part ID: " << nextUrlPathPartID << std::endl
			   << "original exception: " << std::endl << e.Dump();
			THROW_EXCEPTION(URLInvalidUrlPathPartIDException, ss.str());
		}

		if(urlpathpartTbl.Size() != 1) {
			std::stringstream ss;
			ss << "invalid result size while getting url path part: "<< std::endl
			   << "url path part id: " << urlPathPartID << std::endl
			   << "result size (should be 1): " << urlpathpartTbl.Size() << std::endl;
			THROW_EXCEPTION(URLInvalidUrlPathPartIDException, ss.str());
			return;
		}

		urlpathpartTbl.ResetIter();
		long long pathPartID(-1);
		urlpathpartTbl.GetIter()->Get_PATHPART_ID(pathPartID);

		std::string pathPart;
		CachePathPart::GetPathPartByID(db,pathPartID,pathPart);
		pathParts.push_back(pathPart);

		const database::TableColumn* nextID(urlpathpartTbl.GetIter()->GetConstColumn_URLPATHPART_ID_NEXT());
		nextID->Get(nextUrlPathPartID);

	} while(nextUrlPathPartID != cacheInstance.endUrlPathID);

	tools::StringTools::VectorToString(pathParts,pathPart,"/");
}

}
