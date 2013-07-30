#include "unittest2TableBase.h"

#include "unittest2TableDefinitionCreateParam.h"
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

unittest2TableBase::unittest2TableBase()
: TableBase(unittest2TableBase::CreateTableDefinition()) {
}

unittest2TableBase::unittest2TableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy unittest2TableBase");
}

unittest2TableBase::~unittest2TableBase() {
}

TableDefinition* unittest2TableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(unittest2TableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void unittest2TableBase::Get_ID(long long& out) const {

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

void unittest2TableBase::Set_ID(const long long& in) {

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

void unittest2TableBase::Get_timestamp_test(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "timestamp_test";
      break;
    case DB_IBM_DB2:
      fieldName = "timestamp_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("timestamp_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "timestamp_test";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void unittest2TableBase::Set_timestamp_test(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "timestamp_test";
      break;
    case DB_IBM_DB2:
      fieldName = "timestamp_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("timestamp_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "timestamp_test";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void unittest2TableBase::Get_varchar_test(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "varchar_test";
      break;
    case DB_IBM_DB2:
      fieldName = "varchar_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("varchar_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "varchar_test";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void unittest2TableBase::Set_varchar_test(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "varchar_test";
      break;
    case DB_IBM_DB2:
      fieldName = "varchar_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("varchar_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "varchar_test";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void unittest2TableBase::Get_double_test(double& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "double_test";
      break;
    case DB_IBM_DB2:
      fieldName = "double_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("double_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "double_test";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void unittest2TableBase::Set_double_test(const double& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "double_test";
      break;
    case DB_IBM_DB2:
      fieldName = "double_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("double_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "double_test";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void unittest2TableBase::Get_integer_test(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "integer_test";
      break;
    case DB_IBM_DB2:
      fieldName = "integer_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("integer_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "integer_test";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void unittest2TableBase::Set_integer_test(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "integer_test";
      break;
    case DB_IBM_DB2:
      fieldName = "integer_test";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("integer_test");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "integer_test";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void unittest2TableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_timestamp_test(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_timestamp_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_timestamp_test(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_timestamp_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_varchar_test(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_varchar_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_varchar_test(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_varchar_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_double_test(
        DatabaseConnection* db, 
        const double& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_double_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_double_test(
        DatabaseConnection* db, 
        const std::vector<double>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_double_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_integer_test(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_integer_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void unittest2TableBase::GetBy_integer_test(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest2TableBase::GetWhereColumnsFor_integer_test(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(unittest2TableBase::CreateTableDefinition());
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
void unittest2TableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_timestamp_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_timestamp_test();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_timestamp_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_timestamp_test();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_varchar_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_varchar_test();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_varchar_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_varchar_test();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_double_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const double& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_double_test();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_double_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<double>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_double_test();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_integer_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_integer_test();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void unittest2TableBase::GetWhereColumnsFor_integer_test(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = unittest2TableBase::GetDefinition_integer_test();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* unittest2TableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "ID";
      createParam.tableName    = "unittest2";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "unittest2";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest2");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_INTEGER;
    createParam.isPrimaryKey        = true;
    createParam.isAutoGenerated     = true;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* unittest2TableBase::GetDefinition_timestamp_test() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "timestamp_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "timestamp_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("timestamp_test");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest2");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_TIMESTAMP;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* unittest2TableBase::GetDefinition_varchar_test() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "varchar_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "varchar_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("varchar_test");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest2");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_LARGE_TEXT;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* unittest2TableBase::GetDefinition_double_test() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "double_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "double_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("double_test");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest2");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_DOUBLE;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = true;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* unittest2TableBase::GetDefinition_integer_test() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "integer_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "integer_test";
      createParam.tableName    = "unittest2";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("integer_test");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest2");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_INTEGER;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
