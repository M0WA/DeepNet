#include "dataminingalertsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingalertsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

dataminingalertsTableDefinitionCreateParam::dataminingalertsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dataminingalerts") {

    CreateColumnDefinitions();
}

dataminingalertsTableDefinitionCreateParam::~dataminingalertsTableDefinitionCreateParam() {
}

void dataminingalertsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingalertsTableBase::GetDefinition_ID());

    //creating column definition for type
    columnDefinitions.push_back(dataminingalertsTableBase::GetDefinition_type());

    //creating column definition for param
    columnDefinitions.push_back(dataminingalertsTableBase::GetDefinition_param());


	std::vector<std::string> tmpCombined;

}

std::string dataminingalertsTableDefinitionCreateParam::GetDatabaseName() {
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
