#include "dataminingcustomersessionTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcustomersessionTableBase.h"
#include "DatabaseHelper.h"

namespace database {

dataminingcustomersessionTableDefinitionCreateParam::dataminingcustomersessionTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dataminingcustomersession") {

    CreateColumnDefinitions();
}

dataminingcustomersessionTableDefinitionCreateParam::~dataminingcustomersessionTableDefinitionCreateParam() {
}

void dataminingcustomersessionTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcustomersessionTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(dataminingcustomersessionTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for session
    columnDefinitions.push_back(dataminingcustomersessionTableBase::GetDefinition_session());

}

std::string dataminingcustomersessionTableDefinitionCreateParam::GetDatabaseName() {
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
