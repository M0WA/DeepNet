#include "customerproductimagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproductimagesTableBase.h"

namespace database {

customerproductimagesTableDefinitionCreateParam::customerproductimagesTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customerproductimages") {

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

}

}
