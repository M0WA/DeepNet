#include "syncurlsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "syncurlsTableBase.h"

namespace database {

syncurlsTableDefinitionCreateParam::syncurlsTableDefinitionCreateParam()
: TableDefinitionCreateParam("sync","syncurls") {

    CreateColumnDefinitions();
}

syncurlsTableDefinitionCreateParam::~syncurlsTableDefinitionCreateParam() {
}

void syncurlsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_URL_ID());

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

    //creating column definition for CRAWLERSESSION_ID
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_CRAWLERSESSION_ID());

    //creating column definition for schedule
    columnDefinitions.push_back(syncurlsTableBase::GetDefinition_schedule());

}

}
