#include "dictTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dictTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

dictTableDefinitionCreateParam::dictTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dict") {

    CreateColumnDefinitions();
}

dictTableDefinitionCreateParam::~dictTableDefinitionCreateParam() {
}

void dictTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dictTableBase::GetDefinition_ID());

    //creating column definition for keyword
    columnDefinitions.push_back(dictTableBase::GetDefinition_keyword());

    //creating column definition for occurrence
    columnDefinitions.push_back(dictTableBase::GetDefinition_occurrence());

}

std::string dictTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "lexicon";
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
