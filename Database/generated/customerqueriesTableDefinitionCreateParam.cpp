#include "customerqueriesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerqueriesTableBase.h"

namespace database {

customerqueriesTableDefinitionCreateParam::customerqueriesTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customerqueries") {

    CreateColumnDefinitions();
}

customerqueriesTableDefinitionCreateParam::~customerqueriesTableDefinitionCreateParam() {
}

void customerqueriesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerqueriesTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customerqueriesTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for query
    columnDefinitions.push_back(customerqueriesTableBase::GetDefinition_query());

}

}
