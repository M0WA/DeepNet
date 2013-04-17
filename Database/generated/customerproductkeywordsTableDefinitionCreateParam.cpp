#include "customerproductkeywordsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproductkeywordsTableBase.h"

namespace database {

customerproductkeywordsTableDefinitionCreateParam::customerproductkeywordsTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customerproductkeywords") {

    CreateColumnDefinitions();
}

customerproductkeywordsTableDefinitionCreateParam::~customerproductkeywordsTableDefinitionCreateParam() {
}

void customerproductkeywordsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerproductkeywordsTableBase::GetDefinition_ID());

    //creating column definition for PRODUCT_ID
    columnDefinitions.push_back(customerproductkeywordsTableBase::GetDefinition_PRODUCT_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(customerproductkeywordsTableBase::GetDefinition_DICT_ID());

}

}
