#include "schemesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "schemesTableBase.h"

namespace database {

schemesTableDefinitionCreateParam::schemesTableDefinitionCreateParam()
: TableDefinitionCreateParam("documents","schemes") {

    CreateColumnDefinitions();
}

schemesTableDefinitionCreateParam::~schemesTableDefinitionCreateParam() {
}

void schemesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(schemesTableBase::GetDefinition_ID());

    //creating column definition for scheme
    columnDefinitions.push_back(schemesTableBase::GetDefinition_scheme());

}

}
