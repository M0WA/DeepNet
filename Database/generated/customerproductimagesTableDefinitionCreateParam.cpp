#include "customerproductimagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproductimagesTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customerproductimagesTableDefinitionCreateParam::customerproductimagesTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerproductimages") {

    CreateColumnDefinitions();
}

customerproductimagesTableDefinitionCreateParam::~customerproductimagesTableDefinitionCreateParam() {
}

void customerproductimagesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerproductimagesTableBase::GetDefinition_ID());

    //creating column definition for PRODUCT_ID
    columnDefinitions.push_back(customerproductimagesTableBase::GetDefinition_PRODUCT_ID());

    //creating column definition for imageUrl
    columnDefinitions.push_back(customerproductimagesTableBase::GetDefinition_imageUrl());


	std::vector<std::string> tmpCombined;

}

std::string customerproductimagesTableDefinitionCreateParam::GetDatabaseName() {
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
