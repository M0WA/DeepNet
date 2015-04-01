#include "metainfoTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "metainfoTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

metainfoTableDefinitionCreateParam::metainfoTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"metainfo") {

    CreateColumnDefinitions();
}

metainfoTableDefinitionCreateParam::~metainfoTableDefinitionCreateParam() {
}

void metainfoTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for type
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_type());

    //creating column definition for value
    columnDefinitions.push_back(metainfoTableBase::GetDefinition_value());


	std::vector<std::string> tmpCombined;

}

std::string metainfoTableDefinitionCreateParam::GetDatabaseName() {
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
