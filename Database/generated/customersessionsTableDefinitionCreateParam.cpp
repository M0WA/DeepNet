#include "customersessionsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customersessionsTableBase.h"

namespace database {

customersessionsTableDefinitionCreateParam::customersessionsTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customersessions") {

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

}

}
