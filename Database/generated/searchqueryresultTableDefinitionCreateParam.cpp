#include "searchqueryresultTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "searchqueryresultTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

searchqueryresultTableDefinitionCreateParam::searchqueryresultTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"searchqueryresult") {

    CreateColumnDefinitions();
}

searchqueryresultTableDefinitionCreateParam::~searchqueryresultTableDefinitionCreateParam() {
}

void searchqueryresultTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(searchqueryresultTableBase::GetDefinition_ID());

    //creating column definition for SEARCHQUERY_ID
    columnDefinitions.push_back(searchqueryresultTableBase::GetDefinition_SEARCHQUERY_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(searchqueryresultTableBase::GetDefinition_URL_ID());

    //creating column definition for position
    columnDefinitions.push_back(searchqueryresultTableBase::GetDefinition_position());


	std::vector<std::string> tmpCombined;

}

std::string searchqueryresultTableDefinitionCreateParam::GetDatabaseName() {
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
