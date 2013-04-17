#include "customermatchcriteriagrouptypeTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customermatchcriteriagrouptypeTableBase.h"

namespace database {

customermatchcriteriagrouptypeTableDefinitionCreateParam::customermatchcriteriagrouptypeTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customermatchcriteriagrouptype") {

    CreateColumnDefinitions();
}

customermatchcriteriagrouptypeTableDefinitionCreateParam::~customermatchcriteriagrouptypeTableDefinitionCreateParam() {
}

void customermatchcriteriagrouptypeTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERMATCHCRITERIA_ID
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID());

    //creating column definition for type
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_type());

    //creating column definition for groupPosition
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition());

    //creating column definition for isPrimaryKey
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey());

}

}
