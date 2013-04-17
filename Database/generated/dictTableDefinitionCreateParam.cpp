#include "dictTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dictTableBase.h"

namespace database {

dictTableDefinitionCreateParam::dictTableDefinitionCreateParam()
: TableDefinitionCreateParam("lexicon","dict") {

    CreateColumnDefinitions();
}

dictTableDefinitionCreateParam::~dictTableDefinitionCreateParam() {
}

void dictTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dictTableBase::GetDefinition_ID());

    //creating column definition for keyword
    columnDefinitions.push_back(dictTableBase::GetDefinition_keyword());

    //creating column definition for occurrence
    columnDefinitions.push_back(dictTableBase::GetDefinition_occurrence());

}

}
