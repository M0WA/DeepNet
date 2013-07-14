#include "matchcriteriaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "matchcriteriaTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

matchcriteriaTableDefinitionCreateParam::matchcriteriaTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"matchcriteria") {

    CreateColumnDefinitions();
}

matchcriteriaTableDefinitionCreateParam::~matchcriteriaTableDefinitionCreateParam() {
}

void matchcriteriaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(matchcriteriaTableBase::GetDefinition_ID());

    //creating column definition for regex
    columnDefinitions.push_back(matchcriteriaTableBase::GetDefinition_regex());

}

std::string matchcriteriaTableDefinitionCreateParam::GetDatabaseName() {
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
