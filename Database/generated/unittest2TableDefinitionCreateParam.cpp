#include "unittest2TableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "unittest2TableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

unittest2TableDefinitionCreateParam::unittest2TableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"unittest2") {

    CreateColumnDefinitions();
}

unittest2TableDefinitionCreateParam::~unittest2TableDefinitionCreateParam() {
}

void unittest2TableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(unittest2TableBase::GetDefinition_ID());

    //creating column definition for timestamp_test
    columnDefinitions.push_back(unittest2TableBase::GetDefinition_timestamp_test());

    //creating column definition for varchar_test
    columnDefinitions.push_back(unittest2TableBase::GetDefinition_varchar_test());

    //creating column definition for double_test
    columnDefinitions.push_back(unittest2TableBase::GetDefinition_double_test());

    //creating column definition for integer_test
    columnDefinitions.push_back(unittest2TableBase::GetDefinition_integer_test());


	std::vector<std::string> tmpCombined;

}

std::string unittest2TableDefinitionCreateParam::GetDatabaseName() {
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
