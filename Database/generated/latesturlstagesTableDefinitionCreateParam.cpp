#include "latesturlstagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "latesturlstagesTableBase.h"
#include "DatabaseHelper.h"

namespace database {

latesturlstagesTableDefinitionCreateParam::latesturlstagesTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"latesturlstages") {

    CreateColumnDefinitions();
}

latesturlstagesTableDefinitionCreateParam::~latesturlstagesTableDefinitionCreateParam() {
}

void latesturlstagesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(latesturlstagesTableBase::GetDefinition_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(latesturlstagesTableBase::GetDefinition_URL_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(latesturlstagesTableBase::GetDefinition_URLSTAGE_ID());

}

std::string latesturlstagesTableDefinitionCreateParam::GetDatabaseName() {
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
