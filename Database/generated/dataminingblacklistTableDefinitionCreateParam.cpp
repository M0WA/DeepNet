#include "dataminingblacklistTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingblacklistTableBase.h"
#include "DatabaseHelper.h"

namespace database {

dataminingblacklistTableDefinitionCreateParam::dataminingblacklistTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dataminingblacklist") {

    CreateColumnDefinitions();
}

dataminingblacklistTableDefinitionCreateParam::~dataminingblacklistTableDefinitionCreateParam() {
}

void dataminingblacklistTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingblacklistTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(dataminingblacklistTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for domain
    columnDefinitions.push_back(dataminingblacklistTableBase::GetDefinition_domain());

}

std::string dataminingblacklistTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "datamining";
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
