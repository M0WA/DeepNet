#include "imagelinksTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "imagelinksTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

imagelinksTableDefinitionCreateParam::imagelinksTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"imagelinks") {

    CreateColumnDefinitions();
}

imagelinksTableDefinitionCreateParam::~imagelinksTableDefinitionCreateParam() {
}

void imagelinksTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(imagelinksTableBase::GetDefinition_ID());

    //creating column definition for TARGET_URL_ID
    columnDefinitions.push_back(imagelinksTableBase::GetDefinition_TARGET_URL_ID());

    //creating column definition for IMAGE_URL_ID
    columnDefinitions.push_back(imagelinksTableBase::GetDefinition_IMAGE_URL_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(imagelinksTableBase::GetDefinition_URLSTAGE_ID());

}

std::string imagelinksTableDefinitionCreateParam::GetDatabaseName() {
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
