/**
 *
 * @file QuerySecondLevelDomainThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QuerySecondLevelDomainThread.h"

#include "Query.h"
#include "QueryProperties.h"
#include "QueryThreadParam.h"

#include <DatabaseLayer.h>
#include <TableDefinition.h>
#include <WhereCondition.h>
#include <WhereConditionTableColumnCreateParam.h>
#include <WhereConditionTableColumn.h>

#include <StringTools.h>
#include <Pointer.h>
#include <Exception.h>

namespace queryserver {

QuerySecondLevelDomainThread::QuerySecondLevelDomainThread() {
}

QuerySecondLevelDomainThread::~QuerySecondLevelDomainThread() {
}

void QuerySecondLevelDomainThread::OnInitThreadInstance(){
	const QueryThreadParam* queryparam(queryThreadParam.GetConst());
	const std::vector<std::string>& vecKey(queryparam->query.keywords);

	if(!queryparam->query.properties.caseSensitive) {
		lowerKeywords.assign(vecKey.begin(),vecKey.end());
		tools::StringTools::LowerStringsInVector(lowerKeywords);}
}

void QuerySecondLevelDomainThread::OnDestroyThreadInstance(){
	lowerKeywords.clear();
}

void* QuerySecondLevelDomainThread::OnRun(){

	const QueryProperties& queryProperties(queryThreadParam.GetConst()->query.properties);

	tools::Pointer<database::TableDefinition> ptrTblDef(database::secondleveldomainsTableBase::CreateTableDefinition());
	database::SelectStatement select(ptrTblDef.GetConst());

	//select.SelectAllColumns();

	std::vector<database::WhereConditionTableColumn*> where;
	database::secondleveldomainsTableBase::GetWhereColumnsFor_domain(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Like(),database::WhereCondition::InitialComp()),
		lowerKeywords,
		where );

	select.Where().AddColumns(where);

	if(queryProperties.maxResults != 0)
		select.SetLimit(queryProperties.maxResults);
	else {
		//
		//TODO: do not hardcode this limit here
		//
		select.SetLimit(10000);	}

	database::SelectResultContainer<database::TableBase> results;
	try {
		dbConn->Select(select,results);
	}
	catch(errors::Exception& e) {

	}

	//
	//TODO: process results
	//
	return 0;
}

}
