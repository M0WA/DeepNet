#include "__TMPL_TABLE_NAME__TableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "__TMPL_TABLE_NAME__TableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

__TMPL_TABLE_NAME__TableDefinitionCreateParam::__TMPL_TABLE_NAME__TableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"__TMPL_TABLE_NAME__") {

    CreateColumnDefinitions();
}

__TMPL_TABLE_NAME__TableDefinitionCreateParam::~__TMPL_TABLE_NAME__TableDefinitionCreateParam() {
}

void __TMPL_TABLE_NAME__TableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //
__TMPL_TABLE_DEFINITION_CREATE_PARAM__CREATE_COLUMN_DEFINITIONS__
}

std::string __TMPL_TABLE_NAME__TableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "__TMPL_DATABASE_NAME__";
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
