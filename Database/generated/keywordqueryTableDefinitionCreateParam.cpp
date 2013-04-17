#include "keywordqueryTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "keywordqueryTableBase.h"

namespace database {

keywordqueryTableDefinitionCreateParam::keywordqueryTableDefinitionCreateParam()
: TableDefinitionCreateParam("queryserver","keywordquery") {

    CreateColumnDefinitions();
}

keywordqueryTableDefinitionCreateParam::~keywordqueryTableDefinitionCreateParam() {
}

void keywordqueryTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(keywordqueryTableBase::GetDefinition_ID());

    //creating column definition for query_part
    columnDefinitions.push_back(keywordqueryTableBase::GetDefinition_query_part());

}

}
