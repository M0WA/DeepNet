#include "customerproductsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproductsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customerproductsTableDefinitionCreateParam::customerproductsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerproducts") {

    CreateColumnDefinitions();
}

customerproductsTableDefinitionCreateParam::~customerproductsTableDefinitionCreateParam() {
}

void customerproductsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerproductsTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customerproductsTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for productNo
    columnDefinitions.push_back(customerproductsTableBase::GetDefinition_productNo());

    //creating column definition for productName
    columnDefinitions.push_back(customerproductsTableBase::GetDefinition_productName());

    //creating column definition for productBrand
    columnDefinitions.push_back(customerproductsTableBase::GetDefinition_productBrand());


	std::vector<std::string> tmpCombined;

}

std::string customerproductsTableDefinitionCreateParam::GetDatabaseName() {
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
