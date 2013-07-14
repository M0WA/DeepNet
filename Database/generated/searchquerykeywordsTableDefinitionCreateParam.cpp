#include "searchquerykeywordsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "searchquerykeywordsTableBase.h"
#include "DatabaseHelper.h"

namespace database {

searchquerykeywordsTableDefinitionCreateParam::searchquerykeywordsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"searchquerykeywords") {

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

std::string searchquerykeywordsTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "queryserver";
    case DB_IBM_DB2:
      return "deepnet";
    case DB_POSTGRESQL:
      return "deepnet.public";
    case DB_INVALID_TYPE:
    default:
      return "";
    }
}

}
