#include "metainfoTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "metainfoTableBase.h"

namespace database {

metainfoTableDefinitionCreateParam::metainfoTableDefinitionCreateParam()
: TableDefinitionCreateParam("contents","metainfo") {

    CreateColumnDefinitions();
}

metainfoTableDefinitionCreateParam::~metainfoTableDefinitionCreateParam() {
}

void metainfoTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for type
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_type());

    //creating column definition for value
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_value());

}

}
