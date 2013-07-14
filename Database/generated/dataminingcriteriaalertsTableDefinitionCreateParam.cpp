#include "dataminingcriteriaalertsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcriteriaalertsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

dataminingcriteriaalertsTableDefinitionCreateParam::dataminingcriteriaalertsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dataminingcriteriaalerts") {

    CreateColumnDefinitions();
}

dataminingcriteriaalertsTableDefinitionCreateParam::~dataminingcriteriaalertsTableDefinitionCreateParam() {
}

void dataminingcriteriaalertsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for DATAMININGALERT_ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGALERT_ID());

    //creating column definition for DATAMININGCRITERIA_ID
    columnDefinitions.push_back(dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGCRITERIA_ID());

}

std::string dataminingcriteriaalertsTableDefinitionCreateParam::GetDatabaseName() {
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
