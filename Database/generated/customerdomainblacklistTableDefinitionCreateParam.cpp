#include "customerdomainblacklistTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerdomainblacklistTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customerdomainblacklistTableDefinitionCreateParam::customerdomainblacklistTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerdomainblacklist") {

    CreateColumnDefinitions();
}

customerdomainblacklistTableDefinitionCreateParam::~customerdomainblacklistTableDefinitionCreateParam() {
}

void customerdomainblacklistTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for path
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_path());

    //creating column definition for isPathRegex
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_isPathRegex());


	std::vector<std::string> tmpCombined;

}

std::string customerdomainblacklistTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "commercesearch";
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
