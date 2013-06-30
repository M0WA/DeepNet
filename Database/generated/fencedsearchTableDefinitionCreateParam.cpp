#include "fencedsearchTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "fencedsearchTableBase.h"

namespace database {

fencedsearchTableDefinitionCreateParam::fencedsearchTableDefinitionCreateParam()
: TableDefinitionCreateParam("datamining","fencedsearch") {

    CreateColumnDefinitions();
}

fencedsearchTableDefinitionCreateParam::~fencedsearchTableDefinitionCreateParam() {
}

void fencedsearchTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(fencedsearchTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(fencedsearchTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

}

}
