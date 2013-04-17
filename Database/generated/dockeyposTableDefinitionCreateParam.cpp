#include "dockeyposTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dockeyposTableBase.h"

namespace database {

dockeyposTableDefinitionCreateParam::dockeyposTableDefinitionCreateParam()
: TableDefinitionCreateParam("lexicon","dockeypos") {

    CreateColumnDefinitions();
}

dockeyposTableDefinitionCreateParam::~dockeyposTableDefinitionCreateParam() {
}

void dockeyposTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dockeyposTableBase::GetDefinition_ID());

    //creating column definition for DOCKEY_ID
    columnDefinitions.push_back(dockeyposTableBase::GetDefinition_DOCKEY_ID());

    //creating column definition for paragraph
    columnDefinitions.push_back(dockeyposTableBase::GetDefinition_paragraph());

    //creating column definition for position
    columnDefinitions.push_back(dockeyposTableBase::GetDefinition_position());

}

}
