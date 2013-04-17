#include "dataminingcustomerTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcustomerTableBase.h"

namespace database {

dataminingcustomerTableDefinitionCreateParam::dataminingcustomerTableDefinitionCreateParam()
: TableDefinitionCreateParam("datamining","dataminingcustomer") {

    CreateColumnDefinitions();
}

dataminingcustomerTableDefinitionCreateParam::~dataminingcustomerTableDefinitionCreateParam() {
}

void dataminingcustomerTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcustomerTableBase::GetDefinition_ID());

    //creating column definition for login
    columnDefinitions.push_back(dataminingcustomerTableBase::GetDefinition_login());

    //creating column definition for password
    columnDefinitions.push_back(dataminingcustomerTableBase::GetDefinition_password());

}

}
