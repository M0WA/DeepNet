#include "cachesecondleveldomainTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "cachesecondleveldomainTableBase.h"
#include "DatabaseHelper.h"

namespace database {

cachesecondleveldomainTableDefinitionCreateParam::cachesecondleveldomainTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"cachesecondleveldomain") {

    CreateColumnDefinitions();
}

cachesecondleveldomainTableDefinitionCreateParam::~cachesecondleveldomainTableDefinitionCreateParam() {
}

void cachesecondleveldomainTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(cachesecondleveldomainTableBase::GetDefinition_ID());

    //creating column definition for size
    columnDefinitions.push_back(cachesecondleveldomainTableBase::GetDefinition_size());

    //creating column definition for matches
    columnDefinitions.push_back(cachesecondleveldomainTableBase::GetDefinition_matches());

    //creating column definition for misses
    columnDefinitions.push_back(cachesecondleveldomainTableBase::GetDefinition_misses());

    //creating column definition for action_time
    columnDefinitions.push_back(cachesecondleveldomainTableBase::GetDefinition_action_time());

}

std::string cachesecondleveldomainTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "logging";
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
