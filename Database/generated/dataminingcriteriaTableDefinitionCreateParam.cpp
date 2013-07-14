#include "dataminingcriteriaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "dataminingcriteriaTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

dataminingcriteriaTableDefinitionCreateParam::dataminingcriteriaTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"dataminingcriteria") {

    CreateColumnDefinitions();
}

dataminingcriteriaTableDefinitionCreateParam::~dataminingcriteriaTableDefinitionCreateParam() {
}

void dataminingcriteriaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(dataminingcriteriaTableBase::GetDefinition_ID());

    //creating column definition for keyword
    columnDefinitions.push_back(dataminingcriteriaTableBase::GetDefinition_keyword());

    //creating column definition for type
    columnDefinitions.push_back(dataminingcriteriaTableBase::GetDefinition_type());

}

std::string dataminingcriteriaTableDefinitionCreateParam::GetDatabaseName() {
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
