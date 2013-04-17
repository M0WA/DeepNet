#include "dataminingcriteriaalertsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcriteriaalertsTableBase.h"

namespace database {

dataminingcriteriaalertsTableDefinitionCreateParam::dataminingcriteriaalertsTableDefinitionCreateParam()
: TableDefinitionCreateParam("datamining","dataminingcriteriaalerts") {

    CreateColumnDefinitions();
}

dataminingcriteriaalertsTableDefinitionCreateParam::~dataminingcriteriaalertsTableDefinitionCreateParam() {
}

void dataminingcriteriaalertsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for DATAMININGALERT_ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGALERT_ID());

    //creating column definition for DATAMININGCRITERIA_ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGCRITERIA_ID());

}

}
