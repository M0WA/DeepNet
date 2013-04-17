#include "customersyncurlTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customersyncurlTableBase.h"

namespace database {

customersyncurlTableDefinitionCreateParam::customersyncurlTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customersyncurl") {

    CreateColumnDefinitions();
}

customersyncurlTableDefinitionCreateParam::~customersyncurlTableDefinitionCreateParam() {
}

void customersyncurlTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customersyncurlTableBase::GetDefinition_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(customersyncurlTableBase::GetDefinition_URL_ID());

    //creating column definition for scheduled
    columnDefinitions.push_back(customersyncurlTableBase::GetDefinition_scheduled());

}

}
