#include "cacherobotsTableBase.h"

#include "cacherobotsTableDefinitionCreateParam.h"
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

#include <NotImplementedException.h>





namespace database {

cacherobotsTableBase::cacherobotsTableBase()
: TableBase(cacherobotsTableBase::CreateTableDefinition()) {
}

cacherobotsTableBase::cacherobotsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy cacherobotsTableBase");
}

cacherobotsTableBase::~cacherobotsTableBase() {
}

TableDefinition* cacherobotsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(cacherobotsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void cacherobotsTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void cacherobotsTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void cacherobotsTableBase::Get_size(long long& out) const {
    GetConstColumnByName("size")->Get(out);
}

void cacherobotsTableBase::Set_size(const long long& in) {
    GetColumnByName("size")->Set(in);
}

void cacherobotsTableBase::Get_matches(long long& out) const {
    GetConstColumnByName("matches")->Get(out);
}

void cacherobotsTableBase::Set_matches(const long long& in) {
    GetColumnByName("matches")->Set(in);
}

void cacherobotsTableBase::Get_misses(long long& out) const {
    GetConstColumnByName("misses")->Get(out);
}

void cacherobotsTableBase::Set_misses(const long long& in) {
    GetColumnByName("misses")->Set(in);
}

void cacherobotsTableBase::Get_action_time(struct tm& out) const {
    GetConstColumnByName("action_time")->Get(out);
}

void cacherobotsTableBase::Set_action_time(const struct tm& in) {
    GetColumnByName("action_time")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void cacherobotsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_size(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_size(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cacherobotsTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<cacherobotsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacherobotsTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cacherobotsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//


//
// template: TableBase_WhereColumns.inc.cpp
//
void cacherobotsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_size();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_size();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_matches();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_matches();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_misses();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_misses();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_action_time();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cacherobotsTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cacherobotsTableBase::GetDefinition_action_time();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* cacherobotsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "cacherobots";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = true;
    createParam.isAutoGenerated    = true;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* cacherobotsTableBase::GetDefinition_size() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "size";
    createParam.tableName          = "cacherobots";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* cacherobotsTableBase::GetDefinition_matches() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "matches";
    createParam.tableName          = "cacherobots";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* cacherobotsTableBase::GetDefinition_misses() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "misses";
    createParam.tableName          = "cacherobots";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* cacherobotsTableBase::GetDefinition_action_time() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "action_time";
    createParam.tableName          = "cacherobots";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_TIMESTAMP;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
