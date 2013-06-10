#include "customersyncurlTableBase.h"

#include "customersyncurlTableDefinitionCreateParam.h"
#include "TableDefinition.h"
#include "TableColumnDefinition.h"
#include "TableColumn.h"
#include "WhereConditionTableColumnCreateParam.h"
#include "WhereConditionTableColumn.h"

#include "DatabaseConnection.h"

#include "SelectStatement.h"
#include "UpdateStatement.h"

#include "InnerJoinEntry.h"

#include <NotImplementedException.h>



#include "urlsTableBase.h"


namespace database {

customersyncurlTableBase::customersyncurlTableBase()
: TableBase(customersyncurlTableBase::CreateTableDefinition()) {
}

customersyncurlTableBase::customersyncurlTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customersyncurlTableBase");
}

customersyncurlTableBase::~customersyncurlTableBase() {
}

TableDefinition* customersyncurlTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customersyncurlTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customersyncurlTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void customersyncurlTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void customersyncurlTableBase::Get_URL_ID(long long& out) const {
    GetConstColumnByName("URL_ID")->Get(out);
}

void customersyncurlTableBase::Set_URL_ID(const long long& in) {
    GetColumnByName("URL_ID")->Set(in);
}

void customersyncurlTableBase::Get_scheduled(struct tm& out) const {
    GetConstColumnByName("scheduled")->Get(out);
}

void customersyncurlTableBase::Set_scheduled(const struct tm& in) {
    GetColumnByName("scheduled")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customersyncurlTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersyncurlTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersyncurlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersyncurlTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersyncurlTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersyncurlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersyncurlTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersyncurlTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersyncurlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersyncurlTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersyncurlTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersyncurlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersyncurlTableBase::GetBy_scheduled(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersyncurlTableBase::GetWhereColumnsFor_scheduled(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersyncurlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersyncurlTableBase::GetBy_scheduled(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersyncurlTableBase::GetWhereColumnsFor_scheduled(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersyncurlTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customersyncurlTableBase::AddInnerJoinLeftSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = customersyncurlTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customersyncurlTableBase::GetDefinition_URL_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersyncurlTableBase::AddInnerJoinLeftSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URL_ID("","","","",stmt);
}

void customersyncurlTableBase::AddInnerJoinRightSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customersyncurlTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customersyncurlTableBase::GetDefinition_URL_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersyncurlTableBase::AddInnerJoinRightSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URL_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customersyncurlTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersyncurlTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customersyncurlTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersyncurlTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customersyncurlTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersyncurlTableBase::GetDefinition_URL_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customersyncurlTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersyncurlTableBase::GetDefinition_URL_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customersyncurlTableBase::GetWhereColumnsFor_scheduled(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersyncurlTableBase::GetDefinition_scheduled();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customersyncurlTableBase::GetWhereColumnsFor_scheduled(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customersyncurlTableBase::GetDefinition_scheduled();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* customersyncurlTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "customersyncurl";
    createParam.databaseName       = "commercesearch";
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
TableColumnDefinition* customersyncurlTableBase::GetDefinition_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "URL_ID";
    createParam.tableName          = "customersyncurl";
    createParam.databaseName       = "commercesearch";
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
TableColumnDefinition* customersyncurlTableBase::GetDefinition_scheduled() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "scheduled";
    createParam.tableName          = "customersyncurl";
    createParam.databaseName       = "commercesearch";
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
