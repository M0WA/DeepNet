#include "cacheurlsearchpartsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "cacheurlsearchpartsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

cacheurlsearchpartsTableDefinitionCreateParam::cacheurlsearchpartsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"cacheurlsearchparts") {

    CreateColumnDefinitions();
}

cacheurlsearchpartsTableDefinitionCreateParam::~cacheurlsearchpartsTableDefinitionCreateParam() {
}

void cacheurlsearchpartsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(cacheurlsearchpartsTableBase::GetDefinition_ID());

    //creating column definition for size
    columnDefinitions.push_back(cacheurlsearchpartsTableBase::GetDefinition_size());

    //creating column definition for matches
    columnDefinitions.push_back(cacheurlsearchpartsTableBase::GetDefinition_matches());

    //creating column definition for misses
    columnDefinitions.push_back(cacheurlsearchpartsTableBase::GetDefinition_misses());

    //creating column definition for action_time
    columnDefinitions.push_back(cacheurlsearchpartsTableBase::GetDefinition_action_time());


	std::vector<std::string> tmpCombined;

}

std::string cacheurlsearchpartsTableDefinitionCreateParam::GetDatabaseName() {
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
