#include "customersynccrawlerTableBase.h"

#include "customersynccrawlerTableDefinitionCreateParam.h"
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



#include "customerdomainsTableBase.h"


namespace database {

customersynccrawlerTableBase::customersynccrawlerTableBase()
: TableBase(customersynccrawlerTableBase::CreateTableDefinition()) {
}

customersynccrawlerTableBase::customersynccrawlerTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customersynccrawlerTableBase");
}

customersynccrawlerTableBase::~customersynccrawlerTableBase() {
}

TableDefinition* customersynccrawlerTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customersynccrawlerTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customersynccrawlerTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void customersynccrawlerTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void customersynccrawlerTableBase::Get_CUSTOMERDOMAIN_ID(long long& out) const {
    GetConstColumnByName("CUSTOMERDOMAIN_ID")->Get(out);
}

void customersynccrawlerTableBase::Set_CUSTOMERDOMAIN_ID(const long long& in) {
    GetColumnByName("CUSTOMERDOMAIN_ID")->Set(in);
}

void customersynccrawlerTableBase::Get_CRAWLERSESSION_ID(long long& out) const {
    GetConstColumnByName("CRAWLERSESSION_ID")->Get(out);
}

void customersynccrawlerTableBase::Set_CRAWLERSESSION_ID(const long long& in) {
    GetColumnByName("CRAWLERSESSION_ID")->Set(in);
}

void customersynccrawlerTableBase::Get_scheduled(struct tm& out) const {
    GetConstColumnByName("scheduled")->Get(out);
}

void customersynccrawlerTableBase::Set_scheduled(const struct tm& in) {
    GetColumnByName("scheduled")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customersynccrawlerTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersynccrawlerTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersynccrawlerTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersynccrawlerTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersynccrawlerTableBase::GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersynccrawlerTableBase::GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersynccrawlerTableBase::GetBy_scheduled(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersynccrawlerTableBase::GetBy_scheduled(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersynccrawlerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customersynccrawlerTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customerdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customerdomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = customersynccrawlerTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersynccrawlerTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}

void customersynccrawlerTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customersynccrawlerTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID();
    TableDefinition*       joinTableDef        = customerdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customerdomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersynccrawlerTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customersynccrawlerTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customersynccrawlerTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_CRAWLERSESSION_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_CRAWLERSESSION_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_scheduled();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersynccrawlerTableBase::GetDefinition_scheduled();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "customersynccrawler";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
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
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "CUSTOMERDOMAIN_ID";
    createParam.tableName          = "customersynccrawler";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
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
    createParam.isForeignKey       = true;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_CRAWLERSESSION_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "CRAWLERSESSION_ID";
    createParam.tableName          = "customersynccrawler";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
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
    createParam.isIndex            = true;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_scheduled() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "scheduled";
    createParam.tableName          = "customersynccrawler";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
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
    createParam.isIndex            = true;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
