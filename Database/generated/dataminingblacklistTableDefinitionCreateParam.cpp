#include "dataminingblacklistTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingblacklistTableBase.h"

namespace database {

dataminingblacklistTableDefinitionCreateParam::dataminingblacklistTableDefinitionCreateParam()
: TableDefinitionCreateParam("datamining","dataminingblacklist") {

    CreateColumnDefinitions();
}

dataminingblacklistTableDefinitionCreateParam::~dataminingblacklistTableDefinitionCreateParam() {
}

void dataminingblacklistTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingblacklistTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(dataminingblacklistTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for domain
    columnDefinitions.push_back(dataminingblacklistTableBase::GetDefinition_domain());

}

}
