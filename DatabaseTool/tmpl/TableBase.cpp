#include "__TMPL_TABLE_NAME__TableBase.h"

#include "__TMPL_TABLE_NAME__TableDefinitionCreateParam.h"
#include "TableDefinition.h"
#include "TableColumnDefinition.h"
#include "TableColumn.h"
#include "WhereConditionTableColumnCreateParam.h"
#include "WhereConditionTableColumn.h"

#include "DatabaseConnection.h"
#include "DatabaseHelper.h"

#include "SelectStatement.h"
#include "UpdateStatement.h"

#include "InnerJoinEntry.h"

#include <StringTools.h>
#include <NotImplementedException.h>

__TMPL_TABLE_BASE__INCLUDE_INNER_JOIN_FIELDS__

namespace database {

__TMPL_TABLE_NAME__TableBase::__TMPL_TABLE_NAME__TableBase()
: TableBase(__TMPL_TABLE_NAME__TableBase::CreateTableDefinition()) {
}

__TMPL_TABLE_NAME__TableBase::__TMPL_TABLE_NAME__TableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy __TMPL_TABLE_NAME__TableBase");
}

__TMPL_TABLE_NAME__TableBase::~__TMPL_TABLE_NAME__TableBase() {
}

TableDefinition* __TMPL_TABLE_NAME__TableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(__TMPL_TABLE_NAME__TableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
__TMPL_TABLE_BASE__GETSET_FIELDS__

//
// template: TableBase_GetByFields.inc.cpp
//
__TMPL_TABLE_BASE__GETBY_FIELDS__

//
// template: TableBase_InnerJoin.inc.cpp
//
__TMPL_TABLE_BASE__INNER_JOIN_FIELDS__

//
// template: TableBase_WhereColumns.inc.cpp
//
__TMPL_TABLE_BASE__WHERE_COLUMNS__

//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
__TMPL_TABLE_DEFINITION_CREATE_PARAM__CREATE_COLUMN__
}
