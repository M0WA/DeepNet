#include "customersessionsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customersessionsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customersessionsTableDefinitionCreateParam::customersessionsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customersessions") {

    CreateColumnDefinitions();
}

customersessionsTableDefinitionCreateParam::~customersessionsTableDefinitionCreateParam() {
}

void customersessionsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customersessionsTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(customersessionsTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for session
    columnDefinitions.push_back(customersessionsTableBase::GetDefinition_session());


	std::vector<std::string> tmpCombined;

}

std::string customersessionsTableDefinitionCreateParam::GetDatabaseName() {
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
