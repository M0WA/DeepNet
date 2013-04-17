#include "matchcriteriaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "matchcriteriaTableBase.h"

namespace database {

matchcriteriaTableDefinitionCreateParam::matchcriteriaTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","matchcriteria") {

    CreateColumnDefinitions();
}

matchcriteriaTableDefinitionCreateParam::~matchcriteriaTableDefinitionCreateParam() {
}

void matchcriteriaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(matchcriteriaTableBase::GetDefinition_ID());

    //creating column definition for regex
    columnDefinitions.push_back(matchcriteriaTableBase::GetDefinition_regex());

}

}
