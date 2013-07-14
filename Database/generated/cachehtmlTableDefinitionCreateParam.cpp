#include "cachehtmlTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "cachehtmlTableBase.h"
#include "DatabaseHelper.h"

namespace database {

cachehtmlTableDefinitionCreateParam::cachehtmlTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"cachehtml") {

    CreateColumnDefinitions();
}

cachehtmlTableDefinitionCreateParam::~cachehtmlTableDefinitionCreateParam() {
}

void cachehtmlTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(cachehtmlTableBase::GetDefinition_ID());

    //creating column definition for size
    columnDefinitions.push_back(cachehtmlTableBase::GetDefinition_size());

    //creating column definition for matches
    columnDefinitions.push_back(cachehtmlTableBase::GetDefinition_matches());

    //creating column definition for misses
    columnDefinitions.push_back(cachehtmlTableBase::GetDefinition_misses());

    //creating column definition for action_time
    columnDefinitions.push_back(cachehtmlTableBase::GetDefinition_action_time());

}

std::string cachehtmlTableDefinitionCreateParam::GetDatabaseName() {
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
