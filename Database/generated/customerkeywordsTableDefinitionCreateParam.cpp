#include "customerkeywordsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerkeywordsTableBase.h"
#include "DatabaseHelper.h"

namespace database {

customerkeywordsTableDefinitionCreateParam::customerkeywordsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerkeywords") {

    CreateColumnDefinitions();
}

customerkeywordsTableDefinitionCreateParam::~customerkeywordsTableDefinitionCreateParam() {
}

void customerkeywordsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerkeywordsTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customerkeywordsTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for keyword
    columnDefinitions.push_back(customerkeywordsTableBase::GetDefinition_keyword());

    //creating column definition for target
    columnDefinitions.push_back(customerkeywordsTableBase::GetDefinition_target());

    //creating column definition for isKeywordRegex
    columnDefinitions.push_back(customerkeywordsTableBase::GetDefinition_isKeywordRegex());

}

std::string customerkeywordsTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "commercesearch";
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
