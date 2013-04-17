#include "customersTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customersTableBase.h"

namespace database {

customersTableDefinitionCreateParam::customersTableDefinitionCreateParam()
: TableDefinitionCreateParam("commercesearch","customers") {

    CreateColumnDefinitions();
}

customersTableDefinitionCreateParam::~customersTableDefinitionCreateParam() {
}

void customersTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customersTableBase::GetDefinition_ID());

    //creating column definition for login
    columnDefinitions.push_back(customersTableBase::GetDefinition_login());

    //creating column definition for password
    columnDefinitions.push_back(customersTableBase::GetDefinition_password());

}

}
