#include "queryresultsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "queryresultsTableBase.h"

namespace database {

queryresultsTableDefinitionCreateParam::queryresultsTableDefinitionCreateParam()
: TableDefinitionCreateParam("queryserver","queryresults") {

    CreateColumnDefinitions();
}

queryresultsTableDefinitionCreateParam::~queryresultsTableDefinitionCreateParam() {
}

void queryresultsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_ID());

    //creating column definition for SEARCHQUERY_ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_SEARCHQUERY_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_URL_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for order_position
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_order_position());

}

}
