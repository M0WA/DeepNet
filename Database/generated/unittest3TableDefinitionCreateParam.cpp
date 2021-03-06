#include "unittest3TableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "unittest3TableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

unittest3TableDefinitionCreateParam::unittest3TableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"unittest3") {

    CreateColumnDefinitions();
}

unittest3TableDefinitionCreateParam::~unittest3TableDefinitionCreateParam() {
}

void unittest3TableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(unittest3TableBase::GetDefinition_ID());

    //creating column definition for UNITTEST1_ID
    columnDefinitions.push_back(unittest3TableBase::GetDefinition_UNITTEST1_ID());

    //creating column definition for UNITTEST2_ID
    columnDefinitions.push_back(unittest3TableBase::GetDefinition_UNITTEST2_ID());


	std::vector<std::string> tmpCombined;

}

std::string unittest3TableDefinitionCreateParam::GetDatabaseName() {
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
