#include "customersynccrawlerTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customersynccrawlerTableBase.h"

namespace database {

customersynccrawlerTableDefinitionCreateParam::customersynccrawlerTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customersynccrawler") {

    CreateColumnDefinitions();
}

customersynccrawlerTableDefinitionCreateParam::~customersynccrawlerTableDefinitionCreateParam() {
}

void customersynccrawlerTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customersynccrawlerTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for CRAWLERSESSION_ID
    columnDefinitions.push_back(customersynccrawlerTableBase::GetDefinition_CRAWLERSESSION_ID());

    //creating column definition for scheduled
    columnDefinitions.push_back(customersynccrawlerTableBase::GetDefinition_scheduled());

}

}
