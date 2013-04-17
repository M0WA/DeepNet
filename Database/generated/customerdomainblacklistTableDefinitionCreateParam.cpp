#include "customerdomainblacklistTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerdomainblacklistTableBase.h"

namespace database {

customerdomainblacklistTableDefinitionCreateParam::customerdomainblacklistTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customerdomainblacklist") {

    CreateColumnDefinitions();
}

customerdomainblacklistTableDefinitionCreateParam::~customerdomainblacklistTableDefinitionCreateParam() {
}

void customerdomainblacklistTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for path
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_path());

    //creating column definition for isPathRegex
    columnDefinitions.push_back(customerdomainblacklistTableBase::GetDefinition_isPathRegex());

}

}
