#include "customerproductsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproductsTableBase.h"

namespace database {

customerproductsTableDefinitionCreateParam::customerproductsTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customerproducts") {

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

}

}
