#include "cachehtmlTableBase.h"

#include "cachehtmlTableDefinitionCreateParam.h"
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





namespace database {

cachehtmlTableBase::cachehtmlTableBase()
: TableBase(cachehtmlTableBase::CreateTableDefinition()) {
}

cachehtmlTableBase::cachehtmlTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy cachehtmlTableBase");
}

cachehtmlTableBase::~cachehtmlTableBase() {
}

TableDefinition* cachehtmlTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(cachehtmlTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void cachehtmlTableBase::Get_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "ID";
      break;
    case DB_IBM_DB2:
      fieldName = "ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void cachehtmlTableBase::Set_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "ID";
      break;
    case DB_IBM_DB2:
      fieldName = "ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void cachehtmlTableBase::Get_size(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "size";
      break;
    case DB_IBM_DB2:
      fieldName = "size";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("size");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "size";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void cachehtmlTableBase::Set_size(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "size";
      break;
    case DB_IBM_DB2:
      fieldName = "size";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("size");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "size";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void cachehtmlTableBase::Get_matches(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "matches";
      break;
    case DB_IBM_DB2:
      fieldName = "matches";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("matches");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "matches";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void cachehtmlTableBase::Set_matches(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "matches";
      break;
    case DB_IBM_DB2:
      fieldName = "matches";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("matches");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "matches";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void cachehtmlTableBase::Get_misses(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "misses";
      break;
    case DB_IBM_DB2:
      fieldName = "misses";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("misses");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "misses";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void cachehtmlTableBase::Set_misses(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "misses";
      break;
    case DB_IBM_DB2:
      fieldName = "misses";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("misses");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "misses";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void cachehtmlTableBase::Get_action_time(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "action_time";
      break;
    case DB_IBM_DB2:
      fieldName = "action_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("action_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "action_time";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void cachehtmlTableBase::Set_action_time(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "action_time";
      break;
    case DB_IBM_DB2:
      fieldName = "action_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("action_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "action_time";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void cachehtmlTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_size(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_size(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachehtmlTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachehtmlTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachehtmlTableBase::CreateTableDefinition());
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
void cachehtmlTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_size();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_size();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_matches();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_matches();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_misses();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_misses();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_action_time();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachehtmlTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachehtmlTableBase::GetDefinition_action_time();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* cachehtmlTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "ID";
      createParam.tableName    = "cachehtml";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "cachehtml";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachehtml");
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
TableColumnDefinition* cachehtmlTableBase::GetDefinition_size() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "size";
      createParam.tableName    = "cachehtml";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "size";
      createParam.tableName    = "cachehtml";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("size");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachehtml");
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
TableColumnDefinition* cachehtmlTableBase::GetDefinition_matches() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "matches";
      createParam.tableName    = "cachehtml";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "matches";
      createParam.tableName    = "cachehtml";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("matches");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachehtml");
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
TableColumnDefinition* cachehtmlTableBase::GetDefinition_misses() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "misses";
      createParam.tableName    = "cachehtml";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "misses";
      createParam.tableName    = "cachehtml";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("misses");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachehtml");
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
TableColumnDefinition* cachehtmlTableBase::GetDefinition_action_time() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "action_time";
      createParam.tableName    = "cachehtml";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "action_time";
      createParam.tableName    = "cachehtml";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("action_time");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachehtml");
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
