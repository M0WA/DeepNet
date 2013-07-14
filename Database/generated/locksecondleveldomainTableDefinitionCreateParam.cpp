#include "locksecondleveldomainTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "locksecondleveldomainTableBase.h"
#include "DatabaseHelper.h"

namespace database {

locksecondleveldomainTableDefinitionCreateParam::locksecondleveldomainTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"locksecondleveldomain") {

    CreateColumnDefinitions();
}

locksecondleveldomainTableDefinitionCreateParam::~locksecondleveldomainTableDefinitionCreateParam() {
}

void locksecondleveldomainTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(locksecondleveldomainTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

    //creating column definition for CRAWLERSESSION_ID
    columnDefinitions.push_back(locksecondleveldomainTableBase::GetDefinition_CRAWLERSESSION_ID());

    //creating column definition for schedule
    columnDefinitions.push_back(locksecondleveldomainTableBase::GetDefinition_schedule());

}

std::string locksecondleveldomainTableDefinitionCreateParam::GetDatabaseName() {
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
