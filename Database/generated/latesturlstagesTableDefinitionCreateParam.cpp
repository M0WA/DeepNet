#include "latesturlstagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "latesturlstagesTableBase.h"

namespace database {

latesturlstagesTableDefinitionCreateParam::latesturlstagesTableDefinitionCreateParam()
: TableDefinitionCreateParam("contents","latesturlstages") {

    CreateColumnDefinitions();
}

latesturlstagesTableDefinitionCreateParam::~latesturlstagesTableDefinitionCreateParam() {
}

void latesturlstagesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(latesturlstagesTableBase::GetDefinition_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(latesturlstagesTableBase::GetDefinition_URL_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(latesturlstagesTableBase::GetDefinition_URLSTAGE_ID());

}

}
