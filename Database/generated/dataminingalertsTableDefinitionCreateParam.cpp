#include "dataminingalertsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingalertsTableBase.h"

namespace database {

dataminingalertsTableDefinitionCreateParam::dataminingalertsTableDefinitionCreateParam()
: TableDefinitionCreateParam("datamining","dataminingalerts") {

    CreateColumnDefinitions();
}

dataminingalertsTableDefinitionCreateParam::~dataminingalertsTableDefinitionCreateParam() {
}

void dataminingalertsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingalertsTableBase::GetDefinition_ID());

    //creating column definition for type
    columnDefinitions.push_back(dataminingalertsTableBase::GetDefinition_type());

    //creating column definition for param
    columnDefinitions.push_back(dataminingalertsTableBase::GetDefinition_param());

}

}
