#include "queryresultsTableBase.h"

#include "queryresultsTableDefinitionCreateParam.h"
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



#include "searchqueryTableBase.h"


namespace database {

queryresultsTableBase::queryresultsTableBase()
: TableBase(queryresultsTableBase::CreateTableDefinition()) {
}

queryresultsTableBase::queryresultsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy queryresultsTableBase");
}

queryresultsTableBase::~queryresultsTableBase() {
}

TableDefinition* queryresultsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(queryresultsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void queryresultsTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void queryresultsTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void queryresultsTableBase::Get_SEARCHQUERY_ID(long long& out) const {
    GetConstColumnByName("SEARCHQUERY_ID")->Get(out);
}

void queryresultsTableBase::Set_SEARCHQUERY_ID(const long long& in) {
    GetColumnByName("SEARCHQUERY_ID")->Set(in);
}

void queryresultsTableBase::Get_URL_ID(long long& out) const {
    GetConstColumnByName("URL_ID")->Get(out);
}

void queryresultsTableBase::Set_URL_ID(const long long& in) {
    GetColumnByName("URL_ID")->Set(in);
}

void queryresultsTableBase::Get_URLSTAGE_ID(long long& out) const {
    GetConstColumnByName("URLSTAGE_ID")->Get(out);
}

void queryresultsTableBase::Set_URLSTAGE_ID(const long long& in) {
    GetColumnByName("URLSTAGE_ID")->Set(in);
}

void queryresultsTableBase::Get_order_position(long long& out) const {
    GetConstColumnByName("order_position")->Get(out);
}

void queryresultsTableBase::Set_order_position(const long long& in) {
    GetColumnByName("order_position")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void queryresultsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_order_position(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_order_position(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void queryresultsTableBase::GetBy_order_position(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_order_position(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(queryresultsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void queryresultsTableBase::AddInnerJoinLeftSideOn_SEARCHQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = searchqueryTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = searchqueryTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = queryresultsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = queryresultsTableBase::GetDefinition_SEARCHQUERY_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinLeftSideOn_SEARCHQUERY_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SEARCHQUERY_ID("","","","",stmt);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_SEARCHQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = queryresultsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = queryresultsTableBase::GetDefinition_SEARCHQUERY_ID();
    TableDefinition*       joinTableDef        = searchqueryTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = searchqueryTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_SEARCHQUERY_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SEARCHQUERY_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void queryresultsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_SEARCHQUERY_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_SEARCHQUERY_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_URL_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_URL_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_URLSTAGE_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_URLSTAGE_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_order_position(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_order_position();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_order_position(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = queryresultsTableBase::GetDefinition_order_position();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* queryresultsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "queryresults";
    createParam.databaseName       = "queryserver";
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
TableColumnDefinition* queryresultsTableBase::GetDefinition_SEARCHQUERY_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "SEARCHQUERY_ID";
    createParam.tableName          = "queryresults";
    createParam.databaseName       = "queryserver";
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
TableColumnDefinition* queryresultsTableBase::GetDefinition_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "URL_ID";
    createParam.tableName          = "queryresults";
    createParam.databaseName       = "queryserver";
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
TableColumnDefinition* queryresultsTableBase::GetDefinition_URLSTAGE_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "URLSTAGE_ID";
    createParam.tableName          = "queryresults";
    createParam.databaseName       = "queryserver";
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
TableColumnDefinition* queryresultsTableBase::GetDefinition_order_position() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "order_position";
    createParam.tableName          = "queryresults";
    createParam.databaseName       = "queryserver";
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

}
