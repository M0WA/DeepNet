#include "customerdomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerdomainsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customerdomainsTableDefinitionCreateParam::customerdomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerdomains") {

    CreateColumnDefinitions();
}

customerdomainsTableDefinitionCreateParam::~customerdomainsTableDefinitionCreateParam() {
}

void customerdomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for domain
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_domain());

    //creating column definition for revisitInterval
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_revisitInterval());

    //creating column definition for isDomainRegex
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_isDomainRegex());


	std::vector<std::string> tmpCombined;

}

std::string customerdomainsTableDefinitionCreateParam::GetDatabaseName() {
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
