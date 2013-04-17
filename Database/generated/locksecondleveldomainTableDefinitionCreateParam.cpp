#include "locksecondleveldomainTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "locksecondleveldomainTableBase.h"

namespace database {

locksecondleveldomainTableDefinitionCreateParam::locksecondleveldomainTableDefinitionCreateParam()
: TableDefinitionCreateParam("sync","locksecondleveldomain") {

    CreateColumnDefinitions();
}

locksecondleveldomainTableDefinitionCreateParam::~locksecondleveldomainTableDefinitionCreateParam() {
}

void locksecondleveldomainTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(locksecondleveldomainTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

    //creating column definition for CRAWLERSESSION_ID
    columnDefinitions.push_back(locksecondleveldomainTableBase::GetDefinition_CRAWLERSESSION_ID());

    //creating column definition for schedule
    columnDefinitions.push_back(locksecondleveldomainTableBase::GetDefinition_schedule());

}

}
