#include "dockeyTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dockeyTableBase.h"

namespace database {

dockeyTableDefinitionCreateParam::dockeyTableDefinitionCreateParam()
: TableDefinitionCreateParam("lexicon","dockey") {

    CreateColumnDefinitions();
}

dockeyTableDefinitionCreateParam::~dockeyTableDefinitionCreateParam() {
}

void dockeyTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_DICT_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for occurrence
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_occurrence());

}

}
