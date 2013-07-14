#include "schemesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "schemesTableBase.h"
#include "DatabaseHelper.h"

namespace database {

schemesTableDefinitionCreateParam::schemesTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"schemes") {

    CreateColumnDefinitions();
}

schemesTableDefinitionCreateParam::~schemesTableDefinitionCreateParam() {
}

void schemesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(schemesTableBase::GetDefinition_ID());

    //creating column definition for scheme
    columnDefinitions.push_back(schemesTableBase::GetDefinition_scheme());

}

std::string schemesTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "documents";
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
