#include "pathpartsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "pathpartsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

pathpartsTableDefinitionCreateParam::pathpartsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"pathparts") {

    CreateColumnDefinitions();
}

pathpartsTableDefinitionCreateParam::~pathpartsTableDefinitionCreateParam() {
}

void pathpartsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(pathpartsTableBase::GetDefinition_ID());

    //creating column definition for path
    columnDefinitions.push_back(pathpartsTableBase::GetDefinition_path());


	std::vector<std::string> tmpCombined;

}

std::string pathpartsTableDefinitionCreateParam::GetDatabaseName() {
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
