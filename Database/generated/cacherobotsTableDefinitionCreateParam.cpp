#include "cacherobotsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "cacherobotsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

cacherobotsTableDefinitionCreateParam::cacherobotsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"cacherobots") {

    CreateColumnDefinitions();
}

cacherobotsTableDefinitionCreateParam::~cacherobotsTableDefinitionCreateParam() {
}

void cacherobotsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_ID());

    //creating column definition for size
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_size());

    //creating column definition for matches
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_matches());

    //creating column definition for misses
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_misses());

    //creating column definition for action_time
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_action_time());


	std::vector<std::string> tmpCombined;

}

std::string cacherobotsTableDefinitionCreateParam::GetDatabaseName() {
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
