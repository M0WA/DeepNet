#include "cacherobotsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "cacherobotsTableBase.h"

namespace database {

cacherobotsTableDefinitionCreateParam::cacherobotsTableDefinitionCreateParam()
: TableDefinitionCreateParam("logging","cacherobots") {

    CreateColumnDefinitions();
}

cacherobotsTableDefinitionCreateParam::~cacherobotsTableDefinitionCreateParam() {
}

void cacherobotsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_ID());

    //creating column definition for size
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_size());

    //creating column definition for matches
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_matches());

    //creating column definition for misses
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_misses());

    //creating column definition for action_time
    columnDefinitions.push_back(cacherobotsTableBase::GetDefinition_action_time());

}

}
