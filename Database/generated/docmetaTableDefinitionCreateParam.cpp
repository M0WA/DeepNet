#include "docmetaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "docmetaTableBase.h"

namespace database {

docmetaTableDefinitionCreateParam::docmetaTableDefinitionCreateParam()
: TableDefinitionCreateParam("lexicon","docmeta") {

    CreateColumnDefinitions();
}

docmetaTableDefinitionCreateParam::~docmetaTableDefinitionCreateParam() {
}

void docmetaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_DICT_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for occurrence
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_occurrence());

    //creating column definition for type
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_type());

}

}
