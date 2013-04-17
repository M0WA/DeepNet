#include "cacheurlTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "cacheurlTableBase.h"

namespace database {

cacheurlTableDefinitionCreateParam::cacheurlTableDefinitionCreateParam()
: TableDefinitionCreateParam("logging","cacheurl") {

    CreateColumnDefinitions();
}

cacheurlTableDefinitionCreateParam::~cacheurlTableDefinitionCreateParam() {
}

void cacheurlTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_ID());

    //creating column definition for size
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_size());

    //creating column definition for matches
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_matches());

    //creating column definition for misses
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_misses());

    //creating column definition for action_time
    columnDefinitions.push_back(cacheurlTableBase::GetDefinition_action_time());

}

}
