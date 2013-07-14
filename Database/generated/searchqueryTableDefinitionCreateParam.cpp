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

    //creating column definition for session
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_session());

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
