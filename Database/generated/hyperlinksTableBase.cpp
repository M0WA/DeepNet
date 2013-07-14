#include "hyperlinksTableBase.h"

#include "hyperlinksTableDefinitionCreateParam.h"
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



#include "urlsTableBase.h"
#include "urlstagesTableBase.h"


namespace database {

hyperlinksTableBase::hyperlinksTableBase()
: TableBase(hyperlinksTableBase::CreateTableDefinition()) {
}

hyperlinksTableBase::hyperlinksTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy hyperlinksTableBase");
}

hyperlinksTableBase::~hyperlinksTableBase() {
}

TableDefinition* hyperlinksTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(hyperlinksTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void hyperlinksTableBase::Get_ID(long long& out) const {

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

void hyperlinksTableBase::Set_ID(const long long& in) {

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

void hyperlinksTableBase::Get_TARGET_URL_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "TARGET_URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "TARGET_URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("TARGET_URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "TARGET_URL_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void hyperlinksTableBase::Set_TARGET_URL_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "TARGET_URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "TARGET_URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("TARGET_URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "TARGET_URL_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void hyperlinksTableBase::Get_URLSTAGE_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void hyperlinksTableBase::Set_URLSTAGE_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void hyperlinksTableBase::Get_count(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "count";
      break;
    case DB_IBM_DB2:
      fieldName = "count";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("count");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "count";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void hyperlinksTableBase::Set_count(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "count";
      break;
    case DB_IBM_DB2:
      fieldName = "count";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("count");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "count";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void hyperlinksTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void hyperlinksTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void hyperlinksTableBase::GetBy_TARGET_URL_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_TARGET_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void hyperlinksTableBase::GetBy_TARGET_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_TARGET_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void hyperlinksTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void hyperlinksTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void hyperlinksTableBase::GetBy_count(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_count(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void hyperlinksTableBase::GetBy_count(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<hyperlinksTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    hyperlinksTableBase::GetWhereColumnsFor_count(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(hyperlinksTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void hyperlinksTableBase::AddInnerJoinLeftSideOn_TARGET_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = hyperlinksTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = hyperlinksTableBase::GetDefinition_TARGET_URL_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void hyperlinksTableBase::AddInnerJoinLeftSideOn_TARGET_URL_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_TARGET_URL_ID("","","","",stmt);
}

void hyperlinksTableBase::AddInnerJoinRightSideOn_TARGET_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = hyperlinksTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = hyperlinksTableBase::GetDefinition_TARGET_URL_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void hyperlinksTableBase::AddInnerJoinRightSideOn_TARGET_URL_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_TARGET_URL_ID("","","","",stmt);
}
void hyperlinksTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlstagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlstagesTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = hyperlinksTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = hyperlinksTableBase::GetDefinition_URLSTAGE_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void hyperlinksTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URLSTAGE_ID("","","","",stmt);
}

void hyperlinksTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = hyperlinksTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = hyperlinksTableBase::GetDefinition_URLSTAGE_ID();
    TableDefinition*       joinTableDef        = urlstagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlstagesTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void hyperlinksTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URLSTAGE_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void hyperlinksTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void hyperlinksTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void hyperlinksTableBase::GetWhereColumnsFor_TARGET_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_TARGET_URL_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void hyperlinksTableBase::GetWhereColumnsFor_TARGET_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_TARGET_URL_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void hyperlinksTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_URLSTAGE_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void hyperlinksTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_URLSTAGE_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void hyperlinksTableBase::GetWhereColumnsFor_count(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_count();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void hyperlinksTableBase::GetWhereColumnsFor_count(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = hyperlinksTableBase::GetDefinition_count();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* hyperlinksTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "ID";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("hyperlinks");
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
TableColumnDefinition* hyperlinksTableBase::GetDefinition_TARGET_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "TARGET_URL_ID";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "TARGET_URL_ID";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("TARGET_URL_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("hyperlinks");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = true;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* hyperlinksTableBase::GetDefinition_URLSTAGE_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "URLSTAGE_ID";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URLSTAGE_ID";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("hyperlinks");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = true;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* hyperlinksTableBase::GetDefinition_count() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "count";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "count";
      createParam.tableName    = "hyperlinks";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("count");
      createParam.tableName    = tools::StringTools::ToLowerNP("hyperlinks");
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

}
