#include "dataminingcriteriaalertsTableBase.h"

#include "dataminingcriteriaalertsTableDefinitionCreateParam.h"
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



#include "dataminingcustomerTableBase.h"
#include "dataminingalertsTableBase.h"
#include "dataminingcriteriaTableBase.h"


namespace database {

dataminingcriteriaalertsTableBase::dataminingcriteriaalertsTableBase()
: TableBase(dataminingcriteriaalertsTableBase::CreateTableDefinition()) {
}

dataminingcriteriaalertsTableBase::dataminingcriteriaalertsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy dataminingcriteriaalertsTableBase");
}

dataminingcriteriaalertsTableBase::~dataminingcriteriaalertsTableBase() {
}

TableDefinition* dataminingcriteriaalertsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(dataminingcriteriaalertsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void dataminingcriteriaalertsTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void dataminingcriteriaalertsTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void dataminingcriteriaalertsTableBase::Get_CUSTOMER_ID(long long& out) const {
    GetConstColumnByName("CUSTOMER_ID")->Get(out);
}

void dataminingcriteriaalertsTableBase::Set_CUSTOMER_ID(const long long& in) {
    GetColumnByName("CUSTOMER_ID")->Set(in);
}

void dataminingcriteriaalertsTableBase::Get_DATAMININGALERT_ID(long long& out) const {
    GetConstColumnByName("DATAMININGALERT_ID")->Get(out);
}

void dataminingcriteriaalertsTableBase::Set_DATAMININGALERT_ID(const long long& in) {
    GetColumnByName("DATAMININGALERT_ID")->Set(in);
}

void dataminingcriteriaalertsTableBase::Get_DATAMININGCRITERIA_ID(long long& out) const {
    GetConstColumnByName("DATAMININGCRITERIA_ID")->Get(out);
}

void dataminingcriteriaalertsTableBase::Set_DATAMININGCRITERIA_ID(const long long& in) {
    GetColumnByName("DATAMININGCRITERIA_ID")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void dataminingcriteriaalertsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaalertsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaalertsTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaalertsTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaalertsTableBase::GetBy_DATAMININGALERT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGALERT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaalertsTableBase::GetBy_DATAMININGALERT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGALERT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaalertsTableBase::GetBy_DATAMININGCRITERIA_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaalertsTableBase::GetBy_DATAMININGCRITERIA_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaalertsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void dataminingcriteriaalertsTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dataminingcustomerTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dataminingcustomerTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = dataminingcriteriaalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dataminingcriteriaalertsTableBase::GetDefinition_CUSTOMER_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMER_ID("","","","",stmt);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dataminingcriteriaalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dataminingcriteriaalertsTableBase::GetDefinition_CUSTOMER_ID();
    TableDefinition*       joinTableDef        = dataminingcustomerTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dataminingcustomerTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMER_ID("","","","",stmt);
}
void dataminingcriteriaalertsTableBase::AddInnerJoinLeftSideOn_DATAMININGALERT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dataminingalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dataminingalertsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = dataminingcriteriaalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGALERT_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinLeftSideOn_DATAMININGALERT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_DATAMININGALERT_ID("","","","",stmt);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinRightSideOn_DATAMININGALERT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dataminingcriteriaalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGALERT_ID();
    TableDefinition*       joinTableDef        = dataminingalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dataminingalertsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinRightSideOn_DATAMININGALERT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_DATAMININGALERT_ID("","","","",stmt);
}
void dataminingcriteriaalertsTableBase::AddInnerJoinLeftSideOn_DATAMININGCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dataminingcriteriaTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dataminingcriteriaTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = dataminingcriteriaalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGCRITERIA_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinLeftSideOn_DATAMININGCRITERIA_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_DATAMININGCRITERIA_ID("","","","",stmt);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinRightSideOn_DATAMININGCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dataminingcriteriaalertsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGCRITERIA_ID();
    TableDefinition*       joinTableDef        = dataminingcriteriaTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dataminingcriteriaTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dataminingcriteriaalertsTableBase::AddInnerJoinRightSideOn_DATAMININGCRITERIA_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_DATAMININGCRITERIA_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_CUSTOMER_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_CUSTOMER_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGALERT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGALERT_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGALERT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGALERT_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGCRITERIA_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcriteriaalertsTableBase::GetWhereColumnsFor_DATAMININGCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGCRITERIA_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* dataminingcriteriaalertsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "dataminingcriteriaalerts";
    createParam.databaseName       = "datamining";
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
TableColumnDefinition* dataminingcriteriaalertsTableBase::GetDefinition_CUSTOMER_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "CUSTOMER_ID";
    createParam.tableName          = "dataminingcriteriaalerts";
    createParam.databaseName       = "datamining";
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
TableColumnDefinition* dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGALERT_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "DATAMININGALERT_ID";
    createParam.tableName          = "dataminingcriteriaalerts";
    createParam.databaseName       = "datamining";
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
TableColumnDefinition* dataminingcriteriaalertsTableBase::GetDefinition_DATAMININGCRITERIA_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "DATAMININGCRITERIA_ID";
    createParam.tableName          = "dataminingcriteriaalerts";
    createParam.databaseName       = "datamining";
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
