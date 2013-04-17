#include "__TMPL_TABLE_NAME__TableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "__TMPL_TABLE_NAME__TableBase.h"

namespace database {

__TMPL_TABLE_NAME__TableDefinitionCreateParam::__TMPL_TABLE_NAME__TableDefinitionCreateParam()
: TableDefinitionCreateParam("__TMPL_DATABASE_NAME__","__TMPL_TABLE_NAME__") {

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

}
