#include "searchquerykeywordsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "searchquerykeywordsTableBase.h"

namespace database {

searchquerykeywordsTableDefinitionCreateParam::searchquerykeywordsTableDefinitionCreateParam()
: TableDefinitionCreateParam("queryserver","searchquerykeywords") {

    CreateColumnDefinitions();
}

searchquerykeywordsTableDefinitionCreateParam::~searchquerykeywordsTableDefinitionCreateParam() {
}

void searchquerykeywordsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(searchquerykeywordsTableBase::GetDefinition_ID());

    //creating column definition for KEYWORDQUERY_ID
    columnDefinitions.push_back(searchquerykeywordsTableBase::GetDefinition_KEYWORDQUERY_ID());

    //creating column definition for SEARCHQUERY_ID
    columnDefinitions.push_back(searchquerykeywordsTableBase::GetDefinition_SEARCHQUERY_ID());

}

}
