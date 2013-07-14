#include "dataminingcustomerTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcustomerTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

dataminingcustomerTableDefinitionCreateParam::dataminingcustomerTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dataminingcustomer") {

    CreateColumnDefinitions();
}

dataminingcustomerTableDefinitionCreateParam::~dataminingcustomerTableDefinitionCreateParam() {
}

void dataminingcustomerTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcustomerTableBase::GetDefinition_ID());

    //creating column definition for login
    columnDefinitions.push_back(dataminingcustomerTableBase::GetDefinition_login());

    //creating column definition for password
    columnDefinitions.push_back(dataminingcustomerTableBase::GetDefinition_password());

}

std::string dataminingcustomerTableDefinitionCreateParam::GetDatabaseName() {
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
