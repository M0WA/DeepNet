#include "cachesubdomainTableBase.h"

#include "cachesubdomainTableDefinitionCreateParam.h"
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

cachesubdomainTableBase::cachesubdomainTableBase()
: TableBase(cachesubdomainTableBase::CreateTableDefinition()) {
}

cachesubdomainTableBase::cachesubdomainTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy cachesubdomainTableBase");
}

cachesubdomainTableBase::~cachesubdomainTableBase() {
}

TableDefinition* cachesubdomainTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(cachesubdomainTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void cachesubdomainTableBase::Get_ID(long long& out) const {

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

void cachesubdomainTableBase::Set_ID(const long long& in) {

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

void cachesubdomainTableBase::Get_size(long long& out) const {

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

void cachesubdomainTableBase::Set_size(const long long& in) {

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

void cachesubdomainTableBase::Get_matches(long long& out) const {

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

void cachesubdomainTableBase::Set_matches(const long long& in) {

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

void cachesubdomainTableBase::Get_misses(long long& out) const {

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

void cachesubdomainTableBase::Set_misses(const long long& in) {

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

void cachesubdomainTableBase::Get_action_time(struct tm& out) const {

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

void cachesubdomainTableBase::Set_action_time(const struct tm& in) {

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
void cachesubdomainTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_size(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_size(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void cachesubdomainTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<cachesubdomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cachesubdomainTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(cachesubdomainTableBase::CreateTableDefinition());
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
void cachesubdomainTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_size();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_size();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_matches();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_matches();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_misses();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_misses();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_action_time();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void cachesubdomainTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = cachesubdomainTableBase::GetDefinition_action_time();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* cachesubdomainTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "ID";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachesubdomain");
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
TableColumnDefinition* cachesubdomainTableBase::GetDefinition_size() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "size";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "size";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("size");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachesubdomain");
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
TableColumnDefinition* cachesubdomainTableBase::GetDefinition_matches() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "matches";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "matches";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("matches");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachesubdomain");
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
TableColumnDefinition* cachesubdomainTableBase::GetDefinition_misses() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "misses";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "misses";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("misses");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachesubdomain");
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
TableColumnDefinition* cachesubdomainTableBase::GetDefinition_action_time() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "action_time";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "action_time";
      createParam.tableName    = "cachesubdomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("action_time");
      createParam.tableName    = tools::StringTools::ToLowerNP("cachesubdomain");
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
