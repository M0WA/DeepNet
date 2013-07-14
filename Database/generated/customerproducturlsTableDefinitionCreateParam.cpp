#include "customerproducturlsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproducturlsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customerproducturlsTableDefinitionCreateParam::customerproducturlsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerproducturls") {

    CreateColumnDefinitions();
}

customerproducturlsTableDefinitionCreateParam::~customerproducturlsTableDefinitionCreateParam() {
}

void customerproducturlsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerproducturlsTableBase::GetDefinition_ID());

    //creating column definition for PRODUCT_ID
    columnDefinitions.push_back(customerproducturlsTableBase::GetDefinition_PRODUCT_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(customerproducturlsTableBase::GetDefinition_URL_ID());

}

std::string customerproducturlsTableDefinitionCreateParam::GetDatabaseName() {
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
