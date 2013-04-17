#include "dataminingcriteriaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcriteriaTableBase.h"

namespace database {

dataminingcriteriaTableDefinitionCreateParam::dataminingcriteriaTableDefinitionCreateParam()
: TableDefinitionCreateParam("datamining","dataminingcriteria") {

    CreateColumnDefinitions();
}

dataminingcriteriaTableDefinitionCreateParam::~dataminingcriteriaTableDefinitionCreateParam() {
}

void dataminingcriteriaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcriteriaTableBase::GetDefinition_ID());

    //creating column definition for keyword
    columnDefinitions.push_back(dataminingcriteriaTableBase::GetDefinition_keyword());

    //creating column definition for type
    columnDefinitions.push_back(dataminingcriteriaTableBase::GetDefinition_type());

}

}
