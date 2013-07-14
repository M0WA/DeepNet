#include "syncurlsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "syncurlsTableBase.h"
#include "DatabaseHelper.h"

namespace database {

syncurlsTableDefinitionCreateParam::syncurlsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"syncurls") {

    CreateColumnDefinitions();
}

syncurlsTableDefinitionCreateParam::~syncurlsTableDefinitionCreateParam() {
}

void syncurlsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_URL_ID());

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

    //creating column definition for CRAWLERSESSION_ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_CRAWLERSESSION_ID());

    //creating column definition for schedule
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_schedule());

}

std::string syncurlsTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "sync";
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
