#pragma once

#include "TableBase.h"
#include "SelectResultContainer.h"

namespace database {

class WhereConditionTableColumn;
class WhereConditionTableColumnCreateParam;
class TableDefinition;
class TableColumnDefinition;
class DatabaseConnection;

/**
 * @brief wrapper class for database table __TMPL_TABLE_NAME__
 */
class __TMPL_TABLE_NAME__TableBase : public TableBase {

private:
    __TMPL_TABLE_NAME__TableBase(const TableBase& base);

public:
    __TMPL_TABLE_NAME__TableBase();
    virtual ~__TMPL_TABLE_NAME__TableBase();

public:
    /**
     * factory function for __TMPL_TABLE_NAME__'s table definition.
     * @return table definition.
     */
    static TableDefinition* CreateTableDefinition();

public:
//
// template: TableBase_GetSetFields.inc.h
//
__TMPL_TABLE_BASE__GETSET_FIELDS__

public:
//
// template: TableBase_GetByFields.inc.h
//
__TMPL_TABLE_BASE__GETBY_FIELDS__

public:
//
// template: TableBase_InnerJoin.inc.h
//
__TMPL_TABLE_BASE__INNER_JOIN_FIELDS__

public:
//
// template: TableBase_WhereColumns.inc.h
//
__TMPL_TABLE_BASE__WHERE_COLUMNS__

public:
//
// template: TableDefinitionCreateParam_CreateColumn.inc.h
//
__TMPL_TABLE_DEFINITION_CREATE_PARAM__CREATE_COLUMN__
};

}
