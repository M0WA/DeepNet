/**
 *
 * @file QueryUrlPathThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryUrlPathThread.h"

#include "Query.h"
#include "QueryThreadParam.h"

#include <DatabaseLayer.h>
#include <WhereConditionTableColumnCreateParam.h>
#include <WhereConditionTableColumn.h>
#include <TableDefinition.h>

#include <Pointer.h>

namespace queryserver {

QueryUrlPathThread::QueryUrlPathThread() {
}

QueryUrlPathThread::~QueryUrlPathThread() {
}

void QueryUrlPathThread::OnInitThreadInstance(){
}

void QueryUrlPathThread::OnDestroyThreadInstance(){
}

void* QueryUrlPathThread::OnRun(){

	const Query& query(queryThreadParam.GetConst()->query);

	std::vector<database::WhereConditionTableColumn*> where;
	database::pathpartsTableBase::GetWhereColumnsFor_path(
		database::WhereConditionTableColumnCreateParam(
			database::LIKE,
			database::INITIAL_COMPOSITE_OPERATOR_TYPE,
			database::WILDCARD_BOTH),
		query.lowerKeywords,
		where);

	tools::Pointer<database::TableDefinition> pathPartDef(database::pathpartsTableBase::CreateTableDefinition());
	database::SelectStatement selectPathParts(pathPartDef.GetConst());
	selectPathParts.Where().AddColumns(where);

	//
	//TODO: limit results
	//

	database::SelectResultContainer<database::pathpartsTableBase> resultPathParts;
	dbConn->Select(selectPathParts,resultPathParts);

	for(resultPathParts.ResetIter();!resultPathParts.IsIterEnd();resultPathParts.Next()) {
		const database::pathpartsTableBase* pathPartTbl(resultPathParts.GetConstIter());
		long long pathPartID(-1);
		pathPartTbl->Get_ID(pathPartID);
		pathPartIDs.push_back(pathPartID); }
	resultPathParts.ReleaseAll();

	database::SelectResultContainer<database::urlpathpartsTableBase> resultsUrlPathParts;
	database::urlpathpartsTableBase::GetBy_PATHPART_ID(dbConn,pathPartIDs,resultsUrlPathParts);

	for(resultsUrlPathParts.ResetIter();!resultsUrlPathParts.IsIterEnd(); resultsUrlPathParts.Next()) {

		//
		//TODO:
		//
	}

	return 0;
}

}
