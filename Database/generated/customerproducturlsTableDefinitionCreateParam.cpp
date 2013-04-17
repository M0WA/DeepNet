#include "customerproducturlsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproducturlsTableBase.h"

namespace database {

customerproducturlsTableDefinitionCreateParam::customerproducturlsTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customerproducturls") {

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

}
