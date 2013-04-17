#include "crawlersessionsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "crawlersessionsTableBase.h"

namespace database {

crawlersessionsTableDefinitionCreateParam::crawlersessionsTableDefinitionCreateParam()
: TableDefinitionCreateParam("sync","crawlersessions") {

    CreateColumnDefinitions();
}

crawlersessionsTableDefinitionCreateParam::~crawlersessionsTableDefinitionCreateParam() {
}

void crawlersessionsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(crawlersessionsTableBase::GetDefinition_ID());

}

}
