#include "topleveldomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "topleveldomainsTableBase.h"

namespace database {

topleveldomainsTableDefinitionCreateParam::topleveldomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam("documents","topleveldomains") {

    CreateColumnDefinitions();
}

topleveldomainsTableDefinitionCreateParam::~topleveldomainsTableDefinitionCreateParam() {
}

void topleveldomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(topleveldomainsTableBase::GetDefinition_ID());

    //creating column definition for tld
    columnDefinitions.push_back(topleveldomainsTableBase::GetDefinition_tld());

}

}
