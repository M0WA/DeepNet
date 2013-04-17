#include "customermatchcriteriaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customermatchcriteriaTableBase.h"

namespace database {

customermatchcriteriaTableDefinitionCreateParam::customermatchcriteriaTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customermatchcriteria") {

    CreateColumnDefinitions();
}

customermatchcriteriaTableDefinitionCreateParam::~customermatchcriteriaTableDefinitionCreateParam() {
}

void customermatchcriteriaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for MATCHCRITERIA_ID
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_MATCHCRITERIA_ID());

    //creating column definition for type
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_type());

}

}
