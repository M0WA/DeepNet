#include "customerdomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerdomainsTableBase.h"

namespace database {

customerdomainsTableDefinitionCreateParam::customerdomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customerdomains") {

    CreateColumnDefinitions();
}

customerdomainsTableDefinitionCreateParam::~customerdomainsTableDefinitionCreateParam() {
}

void customerdomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for domain
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_domain());

    //creating column definition for revisitInterval
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_revisitInterval());

    //creating column definition for isDomainRegex
    columnDefinitions.push_back(customerdomainsTableBase::GetDefinition_isDomainRegex());

}

}
