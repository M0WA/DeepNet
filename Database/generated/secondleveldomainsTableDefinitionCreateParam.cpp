#include "secondleveldomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "secondleveldomainsTableBase.h"

namespace database {

secondleveldomainsTableDefinitionCreateParam::secondleveldomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam("documents","secondleveldomains") {

    CreateColumnDefinitions();
}

secondleveldomainsTableDefinitionCreateParam::~secondleveldomainsTableDefinitionCreateParam() {
}

void secondleveldomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(secondleveldomainsTableBase::GetDefinition_ID());

    //creating column definition for domain
    columnDefinitions.push_back(secondleveldomainsTableBase::GetDefinition_domain());

}

}
