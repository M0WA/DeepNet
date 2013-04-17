#include "dataminingcustomersessionTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcustomersessionTableBase.h"

namespace database {

dataminingcustomersessionTableDefinitionCreateParam::dataminingcustomersessionTableDefinitionCreateParam()
: TableDefinitionCreateParam("datamining","dataminingcustomersession") {

    CreateColumnDefinitions();
}

dataminingcustomersessionTableDefinitionCreateParam::~dataminingcustomersessionTableDefinitionCreateParam() {
}

void dataminingcustomersessionTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcustomersessionTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(dataminingcustomersessionTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for session
    columnDefinitions.push_back(dataminingcustomersessionTableBase::GetDefinition_session());

}

}
