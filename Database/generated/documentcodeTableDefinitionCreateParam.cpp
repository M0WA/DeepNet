#include "documentcodeTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "documentcodeTableBase.h"

namespace database {

documentcodeTableDefinitionCreateParam::documentcodeTableDefinitionCreateParam()
: TableDefinitionCreateParam("contents","documentcode") {

    CreateColumnDefinitions();
}

documentcodeTableDefinitionCreateParam::~documentcodeTableDefinitionCreateParam() {
}

void documentcodeTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(documentcodeTableBase::GetDefinition_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(documentcodeTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for code
    columnDefinitions.push_back(documentcodeTableBase::GetDefinition_code());

}

}
