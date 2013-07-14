#include "dockeyTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dockeyTableBase.h"
#include "DatabaseHelper.h"

namespace database {

dockeyTableDefinitionCreateParam::dockeyTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dockey") {

    CreateColumnDefinitions();
}

dockeyTableDefinitionCreateParam::~dockeyTableDefinitionCreateParam() {
}

void dockeyTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_DICT_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for occurrence
    columnDefinitions.push_back(dockeyTableBase::GetDefinition_occurrence());

}

std::string dockeyTableDefinitionCreateParam::GetDatabaseName() {
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
