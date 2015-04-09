#include "searchqueryTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "searchqueryTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

searchqueryTableDefinitionCreateParam::searchqueryTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"searchquery") {

    CreateColumnDefinitions();
}

searchqueryTableDefinitionCreateParam::~searchqueryTableDefinitionCreateParam() {
}

void searchqueryTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_ID());

    //creating column definition for RESULTTHREAD_ID
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_RESULTTHREAD_ID());

    //creating column definition for session
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_session());

    //creating column definition for query
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_query());

    //creating column definition for started
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_started());

    //creating column definition for modified
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_modified());

    //creating column definition for finished
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_finished());

    //creating column definition for total
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_total());

    //creating column definition for identifier
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_identifier());


	std::vector<std::string> tmpCombined;
	tmpCombined.clear();
	tmpCombined.push_back("identifier");
	tmpCombined.push_back("session");
	combinedUniqueKeys.push_back(tmpCombined);

}

std::string searchqueryTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "queryserver";
    case DB_IBM_DB2:
      return "deepnet";
    case DB_POSTGRESQL:
      return "deepnet.public";
    case DB_INVALID_TYPE:
    default:
      return "";
    }
}

}
