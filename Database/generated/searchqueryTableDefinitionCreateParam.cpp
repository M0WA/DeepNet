#include "searchqueryTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "searchqueryTableBase.h"

namespace database {

searchqueryTableDefinitionCreateParam::searchqueryTableDefinitionCreateParam()
: TableDefinitionCreateParam("queryserver","searchquery") {

    CreateColumnDefinitions();
}

searchqueryTableDefinitionCreateParam::~searchqueryTableDefinitionCreateParam() {
}

void searchqueryTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_ID());

    //creating column definition for session
    columnDefinitions.push_back(searchqueryTableBase::GetDefinition_session());

}

}
