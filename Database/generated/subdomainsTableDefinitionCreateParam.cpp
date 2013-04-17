#include "subdomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "subdomainsTableBase.h"

namespace database {

subdomainsTableDefinitionCreateParam::subdomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam("documents","subdomains") {

    CreateColumnDefinitions();
}

subdomainsTableDefinitionCreateParam::~subdomainsTableDefinitionCreateParam() {
}

void subdomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(subdomainsTableBase::GetDefinition_ID());

    //creating column definition for subdomain
    columnDefinitions.push_back(subdomainsTableBase::GetDefinition_subdomain());

}

}
