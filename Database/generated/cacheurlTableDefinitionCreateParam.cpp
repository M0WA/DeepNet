#include "cacheurlTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "cacheurlTableBase.h"
#include "DatabaseHelper.h"

namespace database {

cacheurlTableDefinitionCreateParam::cacheurlTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"cacheurl") {

    CreateColumnDefinitions();
}

cacheurlTableDefinitionCreateParam::~cacheurlTableDefinitionCreateParam() {
}

void cacheurlTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_ID());

    //creating column definition for size
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_size());

    //creating column definition for matches
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_matches());

    //creating column definition for misses
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_misses());

    //creating column definition for action_time
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_action_time());

}

std::string cacheurlTableDefinitionCreateParam::GetDatabaseName() {
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
