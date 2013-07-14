#include "customerproducturlsTableBase.h"

#include "customerproducturlsTableDefinitionCreateParam.h"
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



#include "customerproductsTableBase.h"
#include "urlsTableBase.h"


namespace database {

customerproducturlsTableBase::customerproducturlsTableBase()
: TableBase(customerproducturlsTableBase::CreateTableDefinition()) {
}

customerproducturlsTableBase::customerproducturlsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customerproducturlsTableBase");
}

customerproducturlsTableBase::~customerproducturlsTableBase() {
}

TableDefinition* customerproducturlsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customerproducturlsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customerproducturlsTableBase::Get_ID(long long& out) const {

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

void customerproducturlsTableBase::Set_ID(const long long& in) {

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

void customerproducturlsTableBase::Get_PRODUCT_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PRODUCT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PRODUCT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PRODUCT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PRODUCT_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerproducturlsTableBase::Set_PRODUCT_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PRODUCT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PRODUCT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PRODUCT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PRODUCT_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customerproducturlsTableBase::Get_URL_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerproducturlsTableBase::Set_URL_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customerproducturlsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproducturlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproducturlsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproducturlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproducturlsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproducturlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproducturlsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproducturlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproducturlsTableBase::GetBy_PRODUCT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproducturlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproducturlsTableBase::GetWhereColumnsFor_PRODUCT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproducturlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproducturlsTableBase::GetBy_PRODUCT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproducturlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproducturlsTableBase::GetWhereColumnsFor_PRODUCT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproducturlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproducturlsTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproducturlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproducturlsTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproducturlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproducturlsTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproducturlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproducturlsTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproducturlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customerproducturlsTableBase::AddInnerJoinLeftSideOn_PRODUCT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customerproductsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customerproductsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = customerproducturlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customerproducturlsTableBase::GetDefinition_PRODUCT_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproducturlsTableBase::AddInnerJoinLeftSideOn_PRODUCT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_PRODUCT_ID("","","","",stmt);
}

void customerproducturlsTableBase::AddInnerJoinRightSideOn_PRODUCT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customerproducturlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customerproducturlsTableBase::GetDefinition_PRODUCT_ID();
    TableDefinition*       joinTableDef        = customerproductsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customerproductsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproducturlsTableBase::AddInnerJoinRightSideOn_PRODUCT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_PRODUCT_ID("","","","",stmt);
}
void customerproducturlsTableBase::AddInnerJoinLeftSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = customerproducturlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customerproducturlsTableBase::GetDefinition_URL_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproducturlsTableBase::AddInnerJoinLeftSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URL_ID("","","","",stmt);
}

void customerproducturlsTableBase::AddInnerJoinRightSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customerproducturlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customerproducturlsTableBase::GetDefinition_URL_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproducturlsTableBase::AddInnerJoinRightSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URL_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customerproducturlsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproducturlsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerproducturlsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproducturlsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerproducturlsTableBase::GetWhereColumnsFor_PRODUCT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproducturlsTableBase::GetDefinition_PRODUCT_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerproducturlsTableBase::GetWhereColumnsFor_PRODUCT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproducturlsTableBase::GetDefinition_PRODUCT_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerproducturlsTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproducturlsTableBase::GetDefinition_URL_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerproducturlsTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproducturlsTableBase::GetDefinition_URL_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* customerproducturlsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerproducturls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerproducturls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproducturls");
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
TableColumnDefinition* customerproducturlsTableBase::GetDefinition_PRODUCT_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "PRODUCT_ID";
      createParam.tableName    = "customerproducturls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "PRODUCT_ID";
      createParam.tableName    = "customerproducturls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("PRODUCT_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproducturls");
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
TableColumnDefinition* customerproducturlsTableBase::GetDefinition_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "customerproducturls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "customerproducturls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URL_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproducturls");
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

}
