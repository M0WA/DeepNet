#include "hyperlinksTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "hyperlinksTableBase.h"
#include "DatabaseHelper.h"

namespace database {

hyperlinksTableDefinitionCreateParam::hyperlinksTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"hyperlinks") {

    CreateColumnDefinitions();
}

hyperlinksTableDefinitionCreateParam::~hyperlinksTableDefinitionCreateParam() {
}

void hyperlinksTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(hyperlinksTableBase::GetDefinition_ID());

    //creating column definition for TARGET_URL_ID
    columnDefinitions.push_back(hyperlinksTableBase::GetDefinition_TARGET_URL_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(hyperlinksTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for count
    columnDefinitions.push_back(hyperlinksTableBase::GetDefinition_count());

}

std::string hyperlinksTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "contents";
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
